#include <stdio.h>

int getCombinations_(int amount, int start)
{
	int n = 0;

	if(amount == 0)
		return 1;

	switch(start)
	{
		case 0:
			if(amount >= 200)
				n += getCombinations_(amount - 200, 0);
		case 1:
			if(amount >= 100)
				n += getCombinations_(amount - 100, 1);
		case 2:
			if(amount >= 50)
				n += getCombinations_(amount - 50, 2);
		case 3:
			if(amount >= 20)
				n += getCombinations_(amount - 20, 3);
		case 4:
			if(amount >= 10)
				n += getCombinations_(amount - 10, 4);
		case 5:
			if(amount >= 5)
				n += getCombinations_(amount - 5, 5);
		case 6:
			if(amount >= 2)
				n += getCombinations_(amount - 2, 6);
		case 7:
			if(amount >= 1)
				n += getCombinations_(amount - 1, 7);
	}
}

int main()
{
	printf("%d\n", getCombinations_(200,0));

	return 0;
}
