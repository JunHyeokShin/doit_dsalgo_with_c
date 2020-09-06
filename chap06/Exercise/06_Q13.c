#include <stdio.h>
#include <stdlib.h>

#define swap(type, x, y) do {type t = x; x = y; y = t;} while(0)

void quick_sort(int a[], int n)
{
	int pl = 0;
	int pr = n - 1;
	int x = a[(pl + pr) / 2];
	do {
		while(a[pl] < x) pl++;
		while(a[pr] > x) pr--;
		if(pl <= pr) {
			swap(int, a[pl], a[pr]);
			pl++;
			pr--;
		}
	} while(pl <= pr);
	if(0 < pr) quick_sort(a, pr + 1);
	if(pl < n - 1) quick_sort(a + pl, n - pl);
}

int main(void)
{
	int i, nx;
	int *x;
	puts("퀵 정렬");
	printf("요소 개수 : ");
	scanf("%d", &nx);
	x = calloc(nx, sizeof(int));
	for(i = 0; i < nx; i++) {
		printf("x[%d] : ", i);
		scanf("%d", &x[i]);
	}
	quick_sort(x, nx);
	puts("오름차순으로 정렬했습니다.");
	for(i = 0; i < nx; i++)
		printf("x[%d] = %d\n", i, x[i]);
	free(x);

	return 0;
}