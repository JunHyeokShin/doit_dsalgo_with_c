#include <stdio.h>
#include <stdlib.h>

void fsort2(int a[], int n, int min, int max)
{
	int i;
	int *f = calloc(max - min + 1, sizeof(int));
	int *b = calloc(n, sizeof(int));

	for(i = 0; i <= max - min + 1; i++) f[i] = 0;
	for(i = 0; i < n; i++) f[a[i] - min]++;
	for(i = 1; i <= max - min + 1; i++) f[i] += f[i - 1];
	for(i = n - 1; i >= 0; i--) b[--f[a[i] - min]] = a[i];
	for(i = 0; i < n; i++) a[i] = b[i];

	free(b);
	free(f);
}

int main(void)
{
	int i, nx;
	int *x;
	int min, max;

	puts("���� ����");
	printf("��� ���� : ");
	scanf("%d", &nx);
	x = calloc(nx, sizeof(int));

	printf("�ּڰ� : ");
	scanf("%d", &min);

	do {
		printf("�ִ� : ");
		scanf("%d", &max);
	} while(max <= min);

	printf("%d ~ %d�� ������ �Է��ϼ���.\n", min, max);
	for(i = 0; i < nx; i++) {
		do {
			printf("x[%d] : ", i);
			scanf("%d", &x[i]);
		} while(x[i] < min || x[i] > max);
	}

	fsort2(x, nx, min, max);
	puts("������������ �����߽��ϴ�.");

	for(i = 0; i < nx; i++)
		printf("x[%d] = %d\n", i, x[i]);

	free(x);

	return 0;
}