#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char * words[5200];

void getwords()
{
	FILE * file = fopen("res/names.txt", "r");

	int i, j;
	int c;
	int len;
	char temp[25];

	for(i = 0; ; i++)
	{
		while((c = fgetc(file)) != '\"')
			if(c == EOF)
			{
				fclose(file);
				return;
			}		
		
		for(j = 0; ; j++)
		{
			c = fgetc(file);
			if(c == '\"')
			{
				temp[j] = '\0';
				break;
			}

			temp[j] = c;
		}

		len = strlen(temp) + 1;
		words[i] = (char*) malloc(len);
		memcpy(words[i], temp, len); 		
	}
}

void swapwords(int i)
{
	char * temp = words[i];
	words[i] = words[i+1];
	words[i+1] = temp;
}

void sortstrings()
{
	//This function uses the bubble sort algorithm

	int i, j;
	int complete;

	while(true)
	{
		complete = 1;

		for(i = 0; words[i+1] ; i++)
		{
			if(words[i+1][0] < words[i][0])
			{
				swapwords(i);
				complete = 0;
			}

			else if(words[i+1][0] == words[i][0])
			{
				for(j = 0; ; j++)
				{
					if(words[i+1][j] < words[i][j])
					{
						swapwords(i);
						complete = 0;
						break;
					}

					else if(words[i+1][j] > words[i][j])
						break;
				}
			}
		}

		if(complete)
			break;
	}
}

long long scorewords()
{
	long long score = 0;
	long long temp = 0;
	int i, j;

	for(i = 0; words[i]; i++)
	{
		for(j = 0; words[i][j]; j++)
		{
			temp += words[i][j] - 'A' + 1;
			temp *= i+1;
			score += temp;
			temp = 0;
		}
	}

	return score;
}

void freememory()
{
	int i = 0;

	while(words[i])
		free(words[i++]);
}

int main(int argc, char * argv[])
{
	getwords();
	sortstrings();

	long long score = scorewords();
	printf("%d\n", score);

	freememory();
	return 0;
}
