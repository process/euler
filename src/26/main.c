#include <stdio.h>

//http://en.wikipedia.org/wiki/Repeating_decimal#Reciprocals_of_composite_integers_coprime_to_10
int getperiod(int n)
{
	int a, b;

	for(b = 1, a = 10; ; b++, a *= 10)
		if((a %= n) == 1)
			break;

	return b;
}

int main()
{
	int i, p, max;

	for(i = 11, max = 1; i < 1000; i+=2)
		if(i % 5 && (p = getperiod(i)) > max) max = i;

	printf("%d\n", max);

	return 0;
}
