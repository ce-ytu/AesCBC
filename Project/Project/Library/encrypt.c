
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <sys/stat.h>

#include <openssl/aes.h>
#include <openssl/evp.h>

#define FILE_NAME_ORGINAL   "libmuldiv.so"
#define FILE_NAME_ENCRYPT   "libmuldiv_enc.so"

static int write_file(const char *filename, uint8_t *buffer, long len)
{
    FILE *file;
    size_t res;
    
    if ((file = fopen(filename, "wb")) == NULL) {
        printf("File '%s' cannot be opened!\n", filename);
        return -1;
    }
    
    res = fwrite(buffer, sizeof(uint8_t), len, file);
    
    fclose(file);
    
    if ((long) res != len) {
        return -1;
    }
    
    return 0;
}

static uint8_t *read_file(const char *filename, long *plen)
{
    FILE *file;
    
    uint8_t *buffer;
    long file_size;
    size_t res;
    
    if ((file = fopen(filename, "rb")) == NULL) {
        printf("File '%s' cannot be opened!\n", filename);
        return NULL;
    }
    
    fseek(file, 0, SEEK_END);
    file_size = ftell(file);
    fseek(file, 0, SEEK_SET);
    
    buffer = malloc(file_size);
    
    res = fread(buffer, sizeof(uint8_t), file_size, file);
    
    fclose(file);
    
    if ((long) res != file_size) {
        free(buffer);
        *plen = 0;
        return NULL;
    }
    
    *plen = file_size;
    
    return buffer;
}

static int aes_init(unsigned char *key_data, int key_data_len, unsigned char *salt, EVP_CIPHER_CTX **e_ctx, EVP_CIPHER_CTX **d_ctx)
{
    int i, nrounds = 5;
    unsigned char key[32], iv[32];
    
    i = EVP_BytesToKey(EVP_aes_256_cbc(), EVP_sha1(), salt, key_data, key_data_len, nrounds, key, iv);
    
    if (i != 32) {
        printf("Key size is %d bits - should be 256 bits\n", i);
        return -1;
    }
    
    *e_ctx = EVP_CIPHER_CTX_new();
    EVP_EncryptInit_ex(*e_ctx, EVP_aes_256_cbc(), NULL, key, iv);
    *d_ctx = EVP_CIPHER_CTX_new();
    EVP_DecryptInit_ex(*d_ctx, EVP_aes_256_cbc(), NULL, key, iv);
    
    return 0;
}

static unsigned char *aes_encrypt(EVP_CIPHER_CTX *e, unsigned char *plaintext, int *len)
{
    int c_len = *len + AES_BLOCK_SIZE, f_len = 0;
    unsigned char *ciphertext = malloc(c_len);
    
    EVP_EncryptInit_ex(e, NULL, NULL, NULL, NULL);
    EVP_EncryptUpdate(e, ciphertext, &c_len, plaintext, *len);
    
    EVP_EncryptFinal_ex(e, ciphertext+c_len, &f_len);
    
    *len = c_len + f_len;
    
    return ciphertext;
}

static unsigned char *aes_decrypt(EVP_CIPHER_CTX *e, unsigned char *ciphertext, int *len)
{
    int p_len = *len, f_len = 0;
    unsigned char *plaintext = malloc(p_len);
    
    EVP_DecryptInit_ex(e, NULL, NULL, NULL, NULL);
    EVP_DecryptUpdate(e, plaintext, &p_len, ciphertext, *len);
    EVP_DecryptFinal_ex(e, plaintext+p_len, &f_len);
    
    *len = p_len + f_len;
    return plaintext;
}

void usage(const char *filename)
{
    printf("Usage: %s <encrytion key>\n", filename);
}

int main(int argc, char **argv)
{
    EVP_CIPHER_CTX *en, *de;
    
    unsigned int salt[] = {14531453, 35413541};
    char *key_data;
    int key_data_len;
    
    long size;
    int len;
    
    uint8_t *plaintext;
    uint8_t *ciphertext;
    uint8_t *output;
    
    if (argc < 2) {
        usage(argv[0]);
        exit(-1);
    }
    
    key_data = argv[1];
    key_data_len = strlen(key_data);
    
    if (aes_init((uint8_t *) key_data, key_data_len, (unsigned char *) &salt, &en, &de)) {
        printf("Couldn't initialize AES cipher\n");
        return -1;
    }

    plaintext = read_file(FILE_NAME_ORGINAL, &size);
    
    len = (int) size;
    
    ciphertext = aes_encrypt(en, plaintext, &len);
    
    write_file(FILE_NAME_ENCRYPT, ciphertext, len);
    
    output = aes_decrypt(de, ciphertext, &len);
    
    if (memcmp(plaintext, output, size)) 
        printf("Encrypted file generatio failed\n");
    else
        printf("Encrypted file '%s' generated\n", FILE_NAME_ENCRYPT);
    
    free(ciphertext);
    free(plaintext);
    
    EVP_CIPHER_CTX_free(en);
    EVP_CIPHER_CTX_free(de);
    
    return 0;
}
