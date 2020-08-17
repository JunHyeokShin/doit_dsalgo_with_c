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

	puts("���� �˻�");
	printf("��� ���� : ");
	scanf("%d", &nx);

	x = calloc(nx, sizeof(int));

	for(i = 0; i < nx; i++) {
		printf("x[%d] : ", i);
		scanf("%d", &x[i]);
	}

	printf("�˻��� : ");
	scanf("%d", &ky);

	idx = search(x, nx, ky);

	if(idx == -1)
		puts("�˻��� �����߽��ϴ�.");
	else
		printf("%d(��)�� x[%d]�� �ֽ��ϴ�.\n", ky, idx);
		
	free(x);

	return 0;
}