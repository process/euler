#include <stdio.h>
#include "bignum.h"

bignum nums[9801];

int main()
{
	bignum base, result;
	int b, e, i = 0, j, k, len;

	for(b = 2; b <= 100; b++)
	{
		bigset(base, b);
		for(e = 2; e <= 100; e++)
		{
			bigpow(result, base, e);

			len = biglength(result);
			for(j = i; j >= 0; j--)
			{
				if(len != biglength(nums[j]))
					continue;

				for(k = 0; k < len; k++)
					if(nums[j]->num[k] != result->num[k])
						break;

				if(k == len)
					break;
			}

			if(j == -1)
				bigsetbig(nums[i++], result);
		}
	}


	printf("%d\n", i);

	return 0;
}
