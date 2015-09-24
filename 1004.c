/*
	
Counting Leaves 

Sample input:
2 1
01 1 02

Sample output:
0 1

Sample input:
11 6
02 2 05 06
01 3 02 03 04
10 1 11
07 1 10
04 3 07 08 09
09 1 12

Sample output:
0 1 3 1 1

This is not a very good algorithm for the problem
*/

#include <stdio.h>

#define MAX_NODES 100
#define ROOT_ID 1
#define NOT_LEAVES 0
#define LEAVES 1
#define INITIAL_FLAG 119
#define FLAG_1 0
#define FLAG_2 1

short father[MAX_NODES];
short isLeave[MAX_NODES];
short level[MAX_NODES];
short count[MAX_NODES];
short maxLevel;

void DFS(short curNode, short curLevel);

int main(int argc, char const *argv[])
{
	int n,m,k;
	short id,tmpid;

	// in case there's some node's id == 00

	for (int i = 0; i < MAX_NODES; ++i)
	{
		father[i] = INITIAL_FLAG;
	}

	// Read and save the structure of the tree

	scanf("%d%d", &n, &m);

	for (int i = 0; i < m; ++i)
	{
		scanf("%hd%d", &id, &k);
		for (int j = 0; j < k; ++j)
		{
			scanf("%hd", &tmpid);
			father[tmpid] = id;
		}
	}

	// It should be a Breath-first Algorithm, but here
	// I just use Depth-first Algorithm for convience

	DFS(1,0);

	for (int i = 0; i < MAX_NODES; ++i)
	{
		if (isLeave[i] == LEAVES)
		{
			count[level[i]]++;
		}
	}

	printf("%d", count[0]);

	for (int i = 1; i <= maxLevel; ++i)
	{
		printf(" %d", count[i]);
	}

	return 0;
}

void DFS(short curNode, short curLevel)
{
	level[curNode] = curLevel;
	int flag = FLAG_1;
	for (int i = 0; i < MAX_NODES; ++i)
	{
		if (father[i] == curNode)
		{
			flag = FLAG_2;
			DFS(i,curLevel+1);
		}
	}
	if (flag == FLAG_1)
	{
		isLeave[curNode] = LEAVES;
		if (maxLevel < curLevel)
		{
			maxLevel = curLevel;
		}
	} else {
		isLeave[curNode] = NOT_LEAVES;
	}
}