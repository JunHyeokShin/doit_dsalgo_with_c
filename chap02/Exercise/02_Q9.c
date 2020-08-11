#include <stdio.h>
#include <stdlib.h>

void ary_rcopy(int a[], const int b[], int n)
{
	int i;
	for(i = 0; i < n; i++)
		a[i] = b[n - i - 1];
}

int main(void)

{
	int i, n;
	int *x, *y;

	printf("요소 개수를 입력하세요 : ");
	scanf("%d", &n);
	x = calloc(n, sizeof(int));
	y = calloc(n, sizeof(int));

	printf("요소 개수가 %d개인 배열에 정수를 저장합니다.\n", n);
	for(i = 0; i < n; i++) {
		printf("x[%d] : ", i);
		scanf("%d", &x[i]);
	}

	ary_rcopy(y, x, n);

	printf("배열 x의 모든 요소를 배열 y로 복사했습니다.\n");
	for(i = 0; i < n; i++)
		printf("y[%d] = %d\n", i, y[i]);

	free(x);
	free(y);

	return 0;
}