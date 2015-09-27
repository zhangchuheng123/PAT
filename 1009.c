/*

Product of polynomials
http://www.patest.cn/contests/pat-a-practise/1009

Sample Input:

2 1 2.4 0 3.2
2 2 1.5 1 0.5

Sample output:

3 3 3.6 2 6.0 1 1.6

*/

#include <stdio.h>

#define MAX_EXPO 1010
#define DOUBLE_MAX_EXPO 2020
#define MAX_EXPO_TIGHT 1001

float a[MAX_EXPO],b[MAX_EXPO],product[DOUBLE_MAX_EXPO];

int main(int argc, char const *argv[])
{
	int k, expo, count;
	float coef;

	scanf("%d", &k);
	for (int i = 0; i < k; ++i)
	{
		scanf("%d%f", &expo, &coef);
		a[expo] = coef;
	}

	scanf("%d", &k);
	for (int i = 0; i < k; ++i)
	{
		scanf("%d%f", &expo, &coef);
		b[expo] = coef;
	}

	for (int i = 0; i < MAX_EXPO_TIGHT; ++i)
	{
		if (a[i] != 0)
		{
			for (int j = 0; j < MAX_EXPO_TIGHT; ++j)
			{
				if (b[j] != 0)
				{
					product[i+j] += a[i] * b[j];
				}
			}
		}
	}

	count = 0;
	for (int i = 0; i < DOUBLE_MAX_EXPO; ++i)
	{
		if (product[i] != 0)
		{
			count++;
		}
	}
	printf("%d", count);

	for (int i = DOUBLE_MAX_EXPO; i >= 0; --i)
	{
		if (product[i] != 0)
		{
			printf(" %d %.1f", i, product[i]);
		}
	}

	return 0;
}
