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
	uint8_t d[65], out1[65], out2[65];
	int result = 0;

	blake2b_startup();
	for(size_t i = 0; i < 65; i++) d[i] = i;
	
	// for(size_t k = 1; k <= 6; k++)
		// for(size_t m = 1; m <= 6; m++) {
			// blake2b_keyed(out1, d, m, d, k);
			// crypto_blake2b_general(out2, 64, d, k, d, m);
			// result |= memcmp(out1, out2, 64);
			// printf("%d\n", result);
		// }
	blake2b_keyed(out1, d, 10, d, 10);
	crypto_blake2b_general(out2, 64, d, 10, d, 10);
	print_vector(out1, 64);
	print_vector(out2, 64);
	return result;
}
