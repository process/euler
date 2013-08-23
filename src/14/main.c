#include <stdlib.h>
#include <stdio.h>

int main(int argc, char * argv[])
{
	unsigned int temp;
	int length = 0;
	int toplen = 0;

	for(int num = 1; num <= 1000000; num++)
	{
		temp = num;
		while(temp != 1)
		{
			if(!(temp % 2))
				temp /= 2;

			else temp = (3 * temp) + 1;

			length++;
		}

		if(length > toplen)
		{
			toplen = length;
			printf("Longest len = %d using num %d\r",toplen,num);
		}

		length = 0;
	}

  putchar('\n');
	return 0;
}
