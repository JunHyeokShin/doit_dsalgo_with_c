#include <stdio.h>
#include <stdlib.h>
#define swap(type, x, y) do {type t = x; x = y; y = t;} while(0)

void bubble(int a[], int n)
{
	int i, j, k;
	int count1 = 0, count2 = 0;
	for(i = 0; i < n - 1; i++) {
		int exchg = 0;
		printf("�н�%d:\n", i + 1);
		for(j = n - 1; j > i; j--){
			for(k = 0; k < j; k++)
				printf(" %d", a[k]);
			printf("%c", a[j - 1] > a[j] ? '+' : '-');
			for(k = j; k < n; k++)
				printf("%d ", a[k]);
			putchar('\n');
			count1++;
			if(a[j - 1] > a[j]) {
				count2++;
				swap(int, a[j - 1], a[j]);
				exchg++;
			}
		}
		putchar('\n');
		if(exchg == 0) break;
	}
	printf("�񱳸� %dȸ �߽��ϴ�.\n", count1);
	printf("��ȯ�� %dȸ �߽��ϴ�.\n", count2);
	putchar('\n');
}

int main(void)
{
	int i, nx;
	int *x;

	puts("���� ����");
	printf("��� ���� : ");
	scanf("%d", &nx);
	x = calloc(nx, sizeof(int));

	for(i = 0; i < nx; i++) {
		printf("x[%d] : ", i);
		scanf("%d", &x[i]);
	}

	bubble(x, nx);

	puts("������������ �����߽��ϴ�.");
	for(i = 0; i < nx; i++)
		printf("x[%d] = %d\n", i, x[i]);

	free(x);

	return 0;
}