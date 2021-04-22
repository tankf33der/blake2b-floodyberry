#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <string.h>

#include "blake2b.h"
#include "monocypher.h"

void print_vector(const uint8_t *buf, size_t size)
{
    for(size_t i =0; i < size; i++) {
        printf("%x%x", buf[i] >> 4, buf[i] & 0x0f);
    }
    printf(":\n");
}

int main(void) {
	uint8_t d[64], out1[64], out2[64];
	blake2b_state ctx;

	blake2b_startup();
	
	for(size_t i = 0; i < 64; i++) d[i] = i;
	
	blake2b(out1, d, 10);
	crypto_blake2b(out2, d, 10);
	print_vector(out1, 64);
	print_vector(out2, 64);

	blake2b_keyed_init(&ctx, d, 10);
	blake2b_update(&ctx, d, 10);
	blake2b_final(&ctx, out1);
    print_vector(out1, 64);

	blake2b_keyed(out1, d, 10, d, 10);
	crypto_blake2b_general(out2, 64, d, 10, d, 10);
	print_vector(out1, 64);
	print_vector(out2, 64);

	return 0;	
}
