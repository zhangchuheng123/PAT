/*
	A+B problem for polynomials
	sample input:

2 1 2.4 0 3.2
2 2 1.5 1 0.5

*/

#include <stdio.h>

int main(int argc, char const *argv[])
{
	int k;
	double co[1010] = {0.0};
	int ex;
	double tmpCo;
	int counter = 0;

	for (int i = 0; i < 2; ++i)
	{
		scanf("%d", &k);
		for (int j = 0; j < k; ++j)
		{
			scanf("%d%lf", &ex, &tmpCo);
			co[ex] += tmpCo;
		}
	}

	for (int i = 0; i < 1010; ++i)
	{
		if (co[i] != 0.0)
		{
			counter++;
		}
	}

	printf("%d", counter);

	for (int i = 1009; i >= 0; --i)
	{
		if (co[i] != 0.0)
		{
			printf(" %d %.1lf", i, co[i]);
		}
	}

	return 0;
}