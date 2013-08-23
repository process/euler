#include <stdio.h>

int row1[] = {75};
int row2[] = {95, 64};
int row3[] = {17, 47, 82};
int row4[] = {18, 35, 87, 10};
int row5[] = {20, 4, 82, 47, 65};
int row6[] = {19, 1, 23, 75, 3, 34};
int row7[] = {88, 2, 77, 73, 7, 63, 67};
int row8[] = {99, 65, 4, 28, 06, 16, 70, 92};
int row9[] = {41, 41, 26, 56, 83, 40, 80, 70, 33};
int row10[] = {41, 48, 72, 33, 47, 32, 37, 16, 94, 29};
int row11[] = {53, 71, 44, 65, 25, 43, 91, 52, 97, 51, 14};
int row12[] = {70, 11, 33, 28, 77, 73, 17, 78, 39, 68, 17, 57};
int row13[] = {91, 71, 52, 38, 17, 14, 91, 43, 58, 50, 27, 29, 48};
int row14[] = {63, 66, 4, 68, 89, 53, 67, 30, 73, 16, 69, 87, 40, 31};
int row15[] = {4, 62, 98, 27, 23, 9, 70, 98, 73, 93, 38, 53, 60, 04, 23};

int * triangle[15] = 
{
	row1,
	row2,
	row3,
	row4,
	row5,
	row6,
	row7,
	row8,
	row9,
	row10,
	row11,
	row12,
	row13,
	row14,
	row15
};

int max = 0;

void computemax(int row, int index, int sum)
{
	sum += triangle[row][index];

	if(row == 14)
	{
		if(sum > max)
			max = sum;
		return;
	}

	computemax(row+1, index, sum);
	computemax(row+1, index+1, sum);
}


int main(int argc, char * argv[])
{
	computemax(0,0,0);

	printf("%d\n", max);

	return 0;
}
