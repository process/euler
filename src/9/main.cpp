#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	double a;
	double b;
	double c;

	for ( a=2 ; a<700 ; a++)
	{
		for ( b=2 ; b<700 ; b++)
		{
			for ( c=2 ; c<700 ; c++)
			{
				if (pow(a,2) + pow(b,2) == pow(c,2))
				{
					cout << "a = " << a << "    b = " << b << "     c = " << c << "\r";
					if (a+b+c==1000)
					{
						int aAns = (int)a;
						int bAns = (int)b;
						int cAns = (int)c;

						cout << "\nANSWER FOUND! abc = " << aAns * bAns * cAns << endl;
					}
				}
			}
		}
	}
}
