#include <stdlib.h>
#include <stdio.h>
#include <math.h>

//long long power(long long base, int exp)
//{
//	long long result = 1;
//	while(exp>0)
//	{
//		result*=base;
//		exp--;
//	}
//
//	return result;
//}

bool checknum(long long num)
{
	char string[20];
	string[19] = '\0';

	for(int i = 18; i >= 0; i--)
	{
		string[i] = (num % 10) + 48;
		num /= 10;
	}


	if( string [0] == '1' &&
		string [2] == '2' &&
		string [4] == '3' &&
		string [6] == '4' &&
		string [8] == '5' &&
		string[10] == '6' &&
		string[12] == '7' &&
		string[14] == '8' &&
		string[16] == '9' &&
		string[18] == '0') return true;

	return false;
}

int main(int argc, char * argv[])
{
	long long num = 1010101010;
	for(num; ; num+=10) 
		if(checknum(num*num)) break;

	printf("Result: %d \n", num);

	return 0;
}
