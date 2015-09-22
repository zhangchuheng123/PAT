/*
	Elevator

	Description:
	6 sec move up one floor
	4 sec move down one floor
	5 sec stop	
	start at 0th floor

	Example:
3 2 3 1
*/

#include <stdio.h>

#define UP_TIME 	6
#define DOWN_TIME 	4
#define STOP_TIME	5

int main(int argc, char const *argv[])
{
	int n;
	int nextFloor;
	int totalTime = 0;
	int currentFloor = 0;

	scanf("%d",&n);

	for (int i = 0; i < n; ++i)
	{
		scanf("%d",&nextFloor);
		if (nextFloor > currentFloor)
		{
			totalTime += (nextFloor - currentFloor) * UP_TIME;
			currentFloor = nextFloor;
		} else if (nextFloor < currentFloor)
		{
			totalTime += (currentFloor - nextFloor) * DOWN_TIME;
			currentFloor = nextFloor;
		} 
		totalTime += STOP_TIME;
	}

	printf("%d", totalTime);

	return 0;
}