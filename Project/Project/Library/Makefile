
CC = gcc
CFLAGS = -Wall -Wextra -g
CLFLAGS = -fPIC -Wall -Wextra -g
LDFLAGS = -shared
LIBS = -lcrypto

SHRLIB_ADDSUB = libaddsub.so
SHRLIB_MULDIV = libmuldiv.so

SRC_ADDSUB = addsub.c
SRC_MULDIV = muldiv.c
SRC_CRYPTO = encrypt.c

OBJ_ADDSUB = $(SRC_ADDSUB:.c=.o)
OBJ_MULDIV = $(SRC_MULDIV:.c=.o)

.PHONY: all

all: $(SHRLIB_ADDSUB) $(SHRLIB_MULDIV)
	$(CC) $(CFLAGS) -o encrypt $(SRC_CRYPTO) $(LIBS)

$(OBJ_ADDSUB): $(SRC_ADDSUB)
	$(CC) $(CLFLAGS) -c $<

$(OBJ_MULDIV): $(SRC_MULDIV)
	$(CC) $(CLFLAGS) -c $<
	
$(SHRLIB_ADDSUB): $(OBJ_ADDSUB)
	$(CC) $(LDFLAGS) -o $@ $^

$(SHRLIB_MULDIV): $(OBJ_MULDIV)
	$(CC) $(LDFLAGS) -o $@ $^
	
.PHONY: clean

clean:
	rm -rf *.o *.so *~ encrypt
