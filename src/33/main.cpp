#include <stdio.h>

int NFinal = 1, DFinal = 1;

void check(int N, int D, int N_, int D_)
{
	if((float)N_/D_ == (float)N/D)
	{
		NFinal *= N;
		DFinal *= D;
	}
}

int main()
{
	int CurrFraction;

	int N, D;
	int N_, D_;

	for(D = 12; D < 100; D++)
	{
		for(N = 11; N < D; N++)
		{
			if(N/10 == D/10) //1+1
			{
				N_ = N%10; D_ = D%10;

				check(N, D, N_, D_);
			}

			if(N/10 == D%10) //1+2
			{
				N_ = N%10; D_ = D/10;

				check(N, D, N_, D_);
			}

			if(N%10 == D/10) //2+1
			{
				N_ = N/10; D_ = D%10;

				check(N, D, N_, D_);
			}

			if(N%10 == D%10) //2+2
			{
				if((N%10) == 0)
					continue;

				N_ = N/10; D_ = D/10;

				check(N, D, N_, D_);
			}
		}
	}

	printf("%d/%d\n",NFinal,DFinal);

	return 0;
}
