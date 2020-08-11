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

	printf("��� ������ �Է��ϼ��� : ");
	scanf("%d", &n);
	x = calloc(n, sizeof(int));

	printf("��� ������ %d���� �迭�� ������ �����մϴ�.\n", n);
	for(i = 0; i < n; i++) {
		printf("x[%d] : ", i);
		scanf("%d", &x[i]);
	}

	shuffle(x, n);

	printf("�迭 x�� ��� ��Ҹ� �����߽��ϴ�.\n");
	for(i = 0; i < n; i++)
		printf("x[%d] = %d\n", i, x[i]);

	free(x);

	return 0;
}