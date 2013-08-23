#include <stdio.h>
#include <gmp.h>

int main(int argc, char * argv[])
{
  // Init GMP integer
  mpz_t result;
  mpz_init(result);

  // result = 2 ^ 1000
  mpz_ui_pow_ui(result, 2, 1000);
  
  // Store result in a string in base 10
  char* numStr = mpz_get_str(NULL, 10, result);

  // Sum the digits
  int i, sum;
  for (i = 0, sum = 0; numStr[i]; ++i)
  {
    sum += numStr[i] - '0';
  }

  printf("The sum is %d\n", sum);
	return 0;
}
