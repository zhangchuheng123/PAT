#include <stdio.h>

int main(int argc, char const *argv[])
{
	int a,b;
	int sum;
	int seperateSum[10];
	int counter = 0;

	scanf("%d",&a);
	scanf("%d",&b);

	sum = a + b;

	// dealing with negative sign
	if (sum < 0)
	{
		printf("-");
		sum = (- sum);
	}

	// seperate the sum the two 
	do
	{
		seperateSum[counter++] = sum % 1000;
		sum = sum / 1000;
	} while (sum != 0);

	// output
	printf("%d", seperateSum[--counter]);
	while (counter > 0)
	{
		printf(",%03d", seperateSum[--counter]);
	}

	return 0;
}