#include <time.h>
#include <stdio.h>
#include <stdlib.h>

int maxof(const int a[], int n)
{
	int i;
	int max = a[0];
	for(i = 0; i < n; i++)
		if(a[i] > max) max = a[i];
	return max;
}

int main(void)
{
	int i;
	int *height;
	int number;
	srand(time(NULL));
	number = 5 + rand() % 16;
	height = calloc(number, sizeof(int));
	srand(time(NULL));
	for(i = 0; i < number; i++) {
		height[i] = 100 + rand() % 90;
		printf("height[%d] = %d\n", i, height[i]);
	}
	printf("최댓값은 %d입니다.\n", maxof(height, number));
	free(height);

	return 0;
}