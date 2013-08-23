#include <stdio.h>
#include <string.h>
#include <math.h>

int Primes[1500];
int divisors[100];

void getprimes(int len) //Generates given number of primes
{
	Primes[0] = 2;
	int a = 3;
	int j = 0;
	int pos = 1;

	for(pos = 1; pos < len; a++)
	{
		for(j = 0; j < pos; j++)
			if(a % Primes[j] == 0)
				break;

		if(j == pos)
			Primes[pos++] = a;
	}
}

//int exist(int list[], int value)
//{
//	int i;
//	for(i = 0; list[i]; i++)
//		if(list[i] == value)
//			return 1;
//
//	return 0;
//}
//
//int sumdivisors(int list[])
//{
//	int sum = 0;
//	int i = 0;
//
//	while(list[i])
//		sum += list[i++];
//
//	return sum;
//}
//
//void getdivisors(int num, int list[]) 
//{
//	int i, j = 0, k;
//	int temp = num;
//
//	int primefactors[50];
//	memset(primefactors, 0, 50);
//	memset(list, 0, 100);
//	
//	primefactors[j++] = 1; //for easier multiplication later
//	for(i = 0; i < 1000 && temp != 1; i++)
//	{
//		if(temp % Primes[i] == 0)
//		{
//			if(num == Primes[i])
//				break;
//			primefactors[j++] = Primes[i];
//			temp /= Primes[i];
//			i--; //test prime until exhuasted
//		}
//	}
//
//	k = 0;
//	list[k++] = 1;
//	for(i = 0; primefactors[i]; i++)
//	{
//		for(j = 1; primefactors[i+j]; j++)
//		{
//			temp = primefactors[i] * primefactors[i+j];
//			if(!exist(list, temp) && temp != num)
//				list[k++] = temp;
//		}
//	}
//
//	for(i = 1; list[i]; i++) //skip list[0]=1
//	{
//		temp = num / list[i];
//		if(!exist(list, temp))
//			list[k++] = temp;
//	}
//}

int getdivisorsum(int num)
{
	int i;
	int temp = num;

  int count = 0;
  int totalsum = 1;
	
	for(i = 0; i < 1500 && temp != 1; i++)
	{
    count = 0;

	  while(temp % Primes[i] == 0)
		{
			temp /= Primes[i];
      count++;
		}

    totalsum *= (pow(Primes[i],count+1)-1)/(Primes[i]-1);
	}

	return totalsum - num;
}

int main(int argc, char * argv[])
{
	int sum;
	int amicablesum = 0;

	getprimes(1500);

  int i;
	for(i = 7; i <= 10000; i++)
	{
		sum = getdivisorsum(i);
		if(sum == i || sum == 1 || sum == 0)
			continue;
		if(getdivisorsum(sum) == i)
			amicablesum += i;
	}

	printf("%d\n", amicablesum);

	return 0;
}

