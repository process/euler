#include <stdio.h>

int singles[] = {0 /*padding*/, 3, 3, 5, 4, 4, 3, 5, 5, 4}; //1-9
int teens[] = {3, 6, 6, 8, 8, 7, 7, 9, 8, 8}; //10-19
int tens[] = {0, 0 /*padding*/, 6, 6, 5, 5, 5, 7, 6, 6}; //20, 30, 40...
int thousand = 8;
int hundred = 7;
int andlen = 3;

int main(int argc, char * argv[])
{
	int number;
	int temp;
	int total = 0;
	int i;

	for(i = 1; i <= 1000; i++)
	{
		number = i;

		if(temp = (number / 1000) % 10)
			total += singles[temp] + thousand;

		if(temp = (number / 100) % 10) //Check hundreds place
		{
			total += singles[temp] + hundred;
			if(number % 10 || (number/10) % 10)
				total += andlen;
		}

		if(temp = (number/10) % 10)
		{
			if(temp == 1) //teen number
			{
				total += teens[number % 10];
				continue; //teen is end of number
			}

			total += tens[temp];
		}

		if(temp = number % 10)
			total += singles[temp];
	}

	printf("%d\n", total);
	
	return 0;
}
