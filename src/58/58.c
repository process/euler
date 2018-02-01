#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#define PRIMEAMT 1000000000

char isPrime(unsigned int num) {
	unsigned int i;
	for (i = 2; i <= (unsigned int)sqrt((double)num); ++i)
		if (num % i == 0)
			return 0;
	return 1;
}

int main(int argc, char* argv[])
{
	unsigned int diagonal = 1, width = 1, diagonalCount = 1, primeCount = 0;
	int i;

	while (1) {
		width += 2;
		for (i = 0; i < 4; ++i) {
			diagonal = diagonal + (width - 1);
			if (isPrime(diagonal)) {
				primeCount += 1;
			}
		}
		diagonalCount += 4;
		if (primeCount * 10 < diagonalCount) {
			printf("ANSWER: %d\n", width);
			break;
		}
	}

	return 0;
}
