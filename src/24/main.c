#include <stdio.h>
	
int digits[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
int d = 9;

int getnext(int d)
{
	char s[] = "0123456789";
	int i;
	
	for(i = 0; i <= d; i++)
		s[digits[i]] = 0; 

	for(i = 0; i <= digits[d]; i++)
		s[i] = 0;

	for(i = 0; i < 10 && s[i] == 0; i++)
		;

	if(i == 10)
		return digits[d];

	return i;
}

int getlowest(int d)
{
	char s[] = "0123456789";
	int i;

	for(i = 0; i < d; i++)
		s[digits[i]] = 0;

	for(i = 0; s[i] == 0; i++)
		;

	return i;
}

int main()
{
	int p = 1;
	int c, i;

	while(p != 1000000)
	{
		if((c = getnext(d)) == digits[d])
			d--;

		else
		{
			digits[d] = c;
			for(i = d+1; i < 10; i++)
				digits[i] = getlowest(i);
			d=9;
			p++;
		}
	}

	for(i = 0; i < 10; i++)
		printf("%d", digits[i]);
	printf("\n");

	return 0;
}
