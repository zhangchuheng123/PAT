/*

World Cup Betting

Sample Input

1.1 2.5 1.7
1.2 3.0 1.6
4.1 1.2 1.1

Sample Output

T T W 37.98
*/

#include <stdio.h>

#define EPS 0.00001

int main(int argc, char const *argv[])
{
	float o1,o2,o3,profit;
	profit = 1;

	for (int i = 0; i < 3; ++i)
	{
		if (i != 0)
		{
			printf(" ");
		}
		scanf("%f%f%f", &o1, &o2, &o3);
		if ((o1 >= o2) && (o1 >= o3))
		{
			profit *= o1;
			printf("W");
		} else if ((o2 >= o1) && (o2 >= o3))
		{
			profit *= o2;
			printf("T");
		} else if ((o3 >= o1) && (o3 >= o2))
		{
			profit *= o3;
			printf("L");
		}
	}

	profit = (profit * 0.65 - 1)*2;

	printf(" %.2f", profit+EPS);

	return 0;
}