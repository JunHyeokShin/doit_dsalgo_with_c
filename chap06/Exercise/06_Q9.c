#include <stdio.h>
#include <stdlib.h>

void insertion(int a[], int n)
{
	int i, j;

	a[0] = -1;
	for(i = 2; i < n; i++) {
		int tmp = a[i];
		for(j = i; a[j - 1] > tmp; j--)
			a[j] = a[j - 1];
		a[j] = tmp;
	}
}

int main(void)
{
	int i, nx;
	int *x;		

	puts("단순 삽입 정렬");
	printf("요솟수 : ");
	scanf("%d", &nx);
	x = calloc(nx + 1, sizeof(int));

	for (i = 1; i < nx + 1; i++) {
		printf("x[%d] : ", i);
		scanf("%d", &x[i]);
	}

	insertion(x, nx + 1);				

	puts("오름차순으로 정렬했습니다.");
	for (i = 1; i < nx + 1; i++)
		printf("x[%d] = %d\n", i, x[i]);

	free(x);

	return 0;
}