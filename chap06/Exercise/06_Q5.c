#include <stdio.h>
#include <stdlib.h>
#define swap(type, x, y) do {type t = x; x = y; y = t;} while(0)

void bubble(int a[], int n)
{
	int k = 0, i = 0, m;
	int count1 = 0, count2 = 0;
	while(k < n - 1) {
		int j;
		int last = n - 1;

		printf("패스%d:\n", ++i);
		for(j = n - 1; j > k; j--) {
			for(m = 0; m < j; m++)
				printf(" %d", a[m]);
			printf("%c", a[j - 1] > a[j] ? '+' : '-');
			for(m = j; m < n; m++)
				printf("%d ", a[m]);
			putchar('\n');

			count1++;
			if(a[j - 1] > a[j]) {
				count2++;
				swap(int, a[j - 1], a[j]);
				last = j;
			}
		}
		k = last;
	}
	printf("비교를 %d회 했습니다.\n", count1);
	printf("교환을 %d회 했습니다.\n", count2);
	putchar('\n');
}

int main(void)
{
	int i, nx;
	int *x;

	puts("버블 정렬");
	printf("요소 개수 : ");
	scanf("%d", &nx);
	x = calloc(nx, sizeof(int));

	for(i = 0; i < nx; i++) {
		printf("x[%d] : ", i);
		scanf("%d", &x[i]);
	}

	bubble(x, nx);

	puts("오름차순으로 정렬했습니다.");
	for(i = 0; i < nx; i++)
		printf("x[%d] = %d\n", i, x[i]);

	free(x);

	return 0;
}