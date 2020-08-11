#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define swap(type, x, y) do {type t = x; x = y; y = t;} while(0)

void shuffle(int a[], int n)
{
	int i, j;

	srand(time(NULL));
	for(i = 0; i < n; i++) {
		j = rand() % n;
		swap(int, a[i], a[j]);
	}
}

int main(void)
{
	int i, n;
	int *x;

	printf("요소 개수를 입력하세요 : ");
	scanf("%d", &n);
	x = calloc(n, sizeof(int));

	printf("요소 개수가 %d개인 배열에 정수를 저장합니다.\n", n);
	for(i = 0; i < n; i++) {
		printf("x[%d] : ", i);
		scanf("%d", &x[i]);
	}

	shuffle(x, n);

	printf("배열 x의 모든 요소를 셔플했습니다.\n");
	for(i = 0; i < n; i++)
		printf("x[%d] = %d\n", i, x[i]);

	free(x);

	return 0;
}