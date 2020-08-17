#include <stdio.h>
#include <stdlib.h>

int search(int a[], int n, int key)
{
	int i, j;

	printf("  | ");
	for(i = 0; i < n; i++)
		printf("%2d ", i);
	printf("\n--+-");
	for(i = 0; i < n; i++)
		printf("---");
	printf("-\n");

	for(i = 0; i < n; i++) {
		printf("  | ");
		printf("%*.*s\n", 3 * i + 2, 1, "*");
		printf("%2d| ", i);
		for(j = 0; j < n; j++)
			printf("%2d ", a[j]);
		putchar('\n');

		if(a[i] == key)
			return i;

		printf("  |\n");
	}

	return -1;
}

int main(void)
{
	int i, nx, ky, idx;
	int *x;

	puts("선형 검색");
	printf("요소 개수 : ");
	scanf("%d", &nx);

	x = calloc(nx, sizeof(int));

	for(i = 0; i < nx; i++) {
		printf("x[%d] : ", i);
		scanf("%d", &x[i]);
	}

	printf("검색값 : ");
	scanf("%d", &ky);

	idx = search(x, nx, ky);

	if(idx == -1)
		puts("검색에 실패했습니다.");
	else
		printf("%d(은)는 x[%d]에 있습니다.\n", ky, idx);
		
	free(x);

	return 0;
}