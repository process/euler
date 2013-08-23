#include <iostream>
using namespace std;

int main()
{
	long int sumTotal = 0;
	long int squareTotal = 0;

	//sum of squares
	for(int i = 1; i <=100; i++)
	{
		sumTotal += i * i;
	}
	cout << "Total sum of squares is " << sumTotal << endl;

	//square of sums
	for(int i = 1; i <= 100; i++)
	{
		squareTotal += i;
	}
	squareTotal*=squareTotal;

	cout << "Total square of sums is " << squareTotal << endl;
	cout << "The difference between the two is " << squareTotal-sumTotal << endl;

	return 0;
}
