/*

Emergency

Use DFS to search the shortest path between two given points

Sample input
5 6 0 2
1 2 1 5 3
0 1 1
0 2 2
0 3 1
1 2 1
2 4 1
3 4 1

Sample output
2 4

Frankly speaking, I have seen the code from my friend Bingzhang Dai(github) before I started coding this. 
I changed my mind from using Dijstra to using DFS after I saw the code.

*/

#include <stdio.h>
#include <limits.h>

#define MAX_NUM_OF_CITY 510
#define INF INT_MAX
#define NOT_VISITED 0
#define VISITED 1

void init();
void DFS(int cur, int des, int len, int accGroup);

int numOfCity, numOfRoad, currentCity, saveCity;
int groupInCity[MAX_NUM_OF_CITY];
int dist[MAX_NUM_OF_CITY][MAX_NUM_OF_CITY];
int shortestCount, shortestLen, maxGroup;
short label[MAX_NUM_OF_CITY];

int main(int argc, char const *argv[])
{
	init();

	label[currentCity] = VISITED;
	DFS(currentCity, saveCity, 0, groupInCity[currentCity]);

	printf("%d %d", shortestLen, maxGroup);

	return 0;
}

void init()
{
	int t1,t2,len;
	shortestCount = 0;
	shortestLen = INF;
	maxGroup = 0;
	scanf("%d%d%d%d", &numOfCity, &numOfRoad, &currentCity, &saveCity);
	for (int i = 0; i < numOfCity+1; ++i)
	{
		for (int j = 0; j < numOfCity+1; ++j)
		{
			dist[i][j] = INF;
		}
	}
	for (int i = 0; i < numOfCity; ++i)
	{
		scanf("%d", &groupInCity[i]);
	}
	for (int i = 0; i < numOfRoad; ++i)
	{
		scanf("%d%d%d", &t1, &t2, &len);
		dist[t1][t2] = len;
		dist[t2][t1] = len;
	}
	return;
}

void DFS(int cur, int des, int len, int accGroup)
{
	if (cur == des)
	{
		if (len < shortestLen)
		{
			shortestLen = len;
			shortestCount = 1;
			maxGroup = accGroup;
		} else if (len == shortestLen)
		{
			shortestCount++;
			if (maxGroup < accGroup)
			{
				maxGroup = accGroup;
			}
		} 
		return;
	}
	if (len > shortestLen)
	{
		return;
	}
	for (int i = 0; i < numOfCity; ++i)
	{
		if ((dist[cur][i] != INF) && (label[i] == NOT_VISITED))
		{
			label[i] = VISITED;
			DFS(i, des, len + dist[cur][i], accGroup + groupInCity[i]);
			label[i] = NOT_VISITED;
		}
	}
	return;
}