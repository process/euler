#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void itoa(int n, char* str, int base)
{
  char buf[100];
  int i = 0;

  while (n > 0)
  {
    buf[i++] = (n % base) + '0';
    n /= base;
  }
  buf[i] = '\0';

  int numlen = strlen(buf);
  for (i = 0; i < numlen; ++i)
  {
    str[i] = buf[numlen-i-1];
  }
  str[i] = '\0';
}

void reverse(char * in, char * out)
{
	int i, j;

	for(i = strlen(in)-1, j = 0; i >= 0; i--, j++)
		out[j] = in[i];

	out[j] = 0;
}

int main()
{
	int total = 0;
	int n = 0;

	char numstring[21];
	char numstring2[21];
	
	for(n = 1; n < 1000000; n++)
	{
		itoa(n, numstring, 10);
		reverse(numstring, numstring2);
		if(strcmp(numstring, numstring2) == 0)
		{
			itoa(n, numstring, 2);
			reverse(numstring, numstring2);
			if(strcmp(numstring, numstring2) == 0)
				total += n;
		}
	}
	
	printf("%d\n", total);

	return 0;
}
