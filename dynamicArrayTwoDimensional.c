#include <stdio.h>
#include <stdlib.h>

int findMax(int *p, int m, int n, int *pRow, int *pCol);

int main()
{
	int *pScore = NULL, i, j, m, n, maxSocre, row, col;

	printf("Please enter array size m,n:");
	scanf("%d, %d", &m, &n);

	pScore = (int *) calloc(m*n, sizeof(int));
	if(pScore == NULL)
	{
		printf("No enough memory!\n");
		exit(0);
	}

	printf("Please enter the score:\n");
	for (i = 0; i < m; i++)
	{
		for (j = 0; j < n; j++)
		{
			scanf("%d", &pScore[i*n+j]);
		}
	}

	maxSocre = findMax(pScore, m, n, &row, &col);

	printf("maxSocre = %d, class = %d, number = %d\n", maxSocre, row+1, col+1);

	free(pScore);

	return 0;
}

int findMax(int *p, int m, int n, int *pRow, int *pCol)
{
	int i, j, max;

	max = p[0];
	*pRow = 0;
	*pCol = 0;
	for (i = 0; i < m; i++)
	{
		for (j = 0; j < n; j++)
		{
			if (p[i*n+j] > max)
			{
				max = p[i*n+j];
				*pRow = i;
				*pCol = j;
			}
		}
	}

	return (max);
}