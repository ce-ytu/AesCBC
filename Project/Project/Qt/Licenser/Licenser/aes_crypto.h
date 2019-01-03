#ifndef AES_CRYPTO_H
#define AES_CRYPTO_H

#ifdef __cplusplus
extern "C" {
#endif

#include <openssl/aes.h>
#include <openssl/evp.h>

int aes_init(unsigned char *key_data, int key_data_len, unsigned char *salt, EVP_CIPHER_CTX **e_ctx, EVP_CIPHER_CTX **d_ctx);
unsigned char *aes_encrypt(EVP_CIPHER_CTX *e, unsigned char *plaintext, int *len);
unsigned char *aes_decrypt(EVP_CIPHER_CTX *e, unsigned char *ciphertext, int *len);

#ifdef __cplusplus
}
#endif

#endif // AES_CRYPTO_H
