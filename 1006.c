/*

Sign In and Sign Out
http://www.patest.cn/contests/pat-a-practise/1006

Sample input:

3
CS301111 15:30:28 17:00:10
SC3021234 08:00:00 11:25:25
CS301133 21:45:00 21:58:40

Sample output:
SC3021234 CS301133
*/

#include <stdio.h>
#include <stdlib.h>

#define MAXN 10000
#define MAX_ID_LENGTH 16

struct time
{
	int hour;
	int minute;
	int second;
};

int calTotal(struct time t);

int main(int argc, char const *argv[])
{
	int n;
	char* id_number[MAXN];
	struct time t1,t2;
	int early,early_id,late,late_id;

	late = 0;

	t1.hour = 23; 
	t1.minute = 59;
	t1.second = 59;
	early = calTotal(t1);

	scanf("%d",&n);

	for (int i = 0; i < n; ++i)
	{
		id_number[i] = malloc(MAX_ID_LENGTH*sizeof(char));
		scanf("%s%d:%d:%d%d:%d:%d",id_number[i],
			&(t1.hour), &(t1.minute), &(t1.second), &(t2.hour), &(t2.minute), &(t2.second));
		if (calTotal(t1) < early)
		{
			early = calTotal(t1);
			early_id = i;
		}
		if (calTotal(t2) > late)
		{
			late = calTotal(t2);
			late_id = i;
		}
	}

	printf("%s %s", id_number[early_id],id_number[late_id]);

	return 0;
}

int calTotal(struct time t)
{
	return ((t.hour * 60) + t.minute) * 60 + t.second;
}