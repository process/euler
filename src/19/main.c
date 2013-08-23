#include <stdio.h>

int months[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int main(int argc, char * argv[])
{
	int year = 1901;
	int month = 0;
	int day = 2; // Jan 01 1901 is a Tuesday

	int total = 0;

	while(year != 2001)
	{
		if(day == 0)
			total++;

		if(month == 1) //February
		{
			if(year % 4 == 0)
			{
				if(year % 100 == 0)
				{
					if(year % 400 == 0)
						day += 29 % 7;
				}

				else
					day += 29 % 7;
			}
		}

		else
			day += months[month] % 7;

		day %= 7;
		month++;

		if(month == 12)
		{
			month = 0;
			year++;
		}
	}

	printf("%d\n", total);

	return 0;
}
