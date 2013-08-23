#include <iostream>
using namespace std;

//note to self: this should use a sieve or other better method

int main()
{
	int count = 0;
	int i;                        //used to check for primes
	int j;                        //used to check for divisibility
	int status;                   //used to cancel additions to count

	for (i=2; i; i++)
	{
		status = 0;

		for (j=2; j<=(i/2); j++)
		{
			if(i%j==0)
				status=1;
		}

		if(status == 0)
			count++;
		
		if(count == 10001)
			break;
	}

	cout << i << " is the 10001th prime.\n";
	
	return 0;
}
