/*

1007 Maximum Subsequence Sum

sample input

10
-10 1 2 3 4 -5 -23 3 7 -21

sample output

10 1 4

sample input

4
-10 -5 -23 -21

sample output

0 -10 -21

*/

#include <stdio.h>

#define FLAG_NEXT 1
#define FLAG_NONE 0

#define ENDNUM_UNSET_FLAG -1 	// if endNum is set, it is impossible that the last number will be negative

int main(int argc, char const *argv[])
{
	long startNum, endNum, maxSum, curSum, n, curNum, ansStartNum;
	short flag; 		//set the next num to curNum if flag == FLAG_NEXT 

	scanf("%ld", &n);

	flag = FLAG_NEXT;
	endNum = ENDNUM_UNSET_FLAG;

	//scan once
	for (int i = 0; i < n; ++i)
	{
		scanf("%ld", &curNum);

		// if there's a flag, assign the current integer as the start number
		// there is a flag if 1. it is the first number 2. last curSum < 0 

		//printf("Now dealing with %d\n", curNum);
		if (flag == FLAG_NEXT)
		{
			if (i == 0)
			{
				ansStartNum = curNum;
			}
			startNum = curNum;
			flag = FLAG_NONE;
			//printf("Set %d to startNum\n", curNum);
		}

		// there are 3 cases: 1. new maximum appears 2. not exceeding existed maximum but not negative 3. sum is negative
		if (curSum + curNum > maxSum)
		{
			curSum += curNum;
			maxSum = curSum;
			endNum = curNum;
			ansStartNum = startNum;
			//printf("Find max so far maxSum=%d, startNum=%d, endNum=%d\n", maxSum, startNum, endNum);
		} else if (curSum + curNum > 0)
		{
			curSum += curNum;
			//printf("Not the max but still couting, curSum=%d\n", curSum);
		} else if (curSum + curNum < 0)
		{
			curSum = 0;
			flag = FLAG_NEXT;
			//printf("Sum is negative\n");
		}
	}

	// if endNum is never set, all the interger must be negative
	if (endNum == ENDNUM_UNSET_FLAG)
	{
		endNum = curNum;
	}

	printf("%ld %ld %ld", maxSum, ansStartNum, endNum);

	return 0;
}