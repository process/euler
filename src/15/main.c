#include <stdio.h>
#include <string.h>

#define right 1
#define down size

int total;
int size;
unsigned long long paths[50];

//NOTE: The easiest way to actually solve this is to use 40C20
//There will be 40 movement total, with 20 x movements, and 20 y
//So the number of possible combinations is the solution.

unsigned long long getPaths(int pos)
{
	if(pos == total)
		return 1;

	else if(pos > total)
		return 0;

	else if(pos % size == size - 1 && pos != 0)	//End of row
		return getPaths(pos+down);

	else if(pos + down > total)	//End of column
		return getPaths(pos+right);

	else if(pos % size == pos / size && pos != 0)
		return paths[(size-(pos%size))-2];

	else
		return getPaths(pos+right) + getPaths(pos+down);
}

unsigned long long compute()
{
	int temp = size;

	if(paths[size-1])
		return paths[size-1];

	for(size=2; size < temp+2; size++) //2 is a 1x1
	{
		if(paths[size-2] == 0)
		{
			total = (size * size) - 1; //ie. a 2x2 square will have 3x3 points
			paths[size-2] = getPaths(0);
		}
	}

	return paths[size-3];
}

int main(int argc, char * argv[])
{
	printf("PE 15\n");
	memset(paths, 0, sizeof(paths));

	while(true)
	{
		printf("Size of square? ");
		scanf("%d", &size);

		if(size == 0)
			break;

		printf("There are %llu possible paths.\n", compute());
	}

	return 0;	
}
