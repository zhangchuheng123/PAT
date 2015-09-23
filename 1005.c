/*

Spell it Right
http://www.patest.cn/contests/pat-a-practise/1005

Sample input:
12345

Sample output:
one five

*/

#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[])
{
	char ch;
	int sum = 0;
	const char NUMBER[][10] = 
		{"zero","one","two","three","four","five","six","seven","eight","nine"};
	int seperate[5];
	int count = 0;

	ch = getchar();
	while ((ch >= '0') && (ch <= '9'))
	{
		sum += (ch - '0');
		ch = getchar();
	}

	while (sum > 0)
	{
		seperate[count++] = sum % 10;
		sum /= 10;
	}

	printf("%s", NUMBER[seperate[--count]]);
	while (count > 0)
	{
		putchar(' ');
		printf("%s", NUMBER[seperate[--count]]);
	}
	
	return 0;
}