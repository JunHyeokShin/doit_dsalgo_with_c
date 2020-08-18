#include <stdio.h>
#include <stdlib.h>

int bin_search2(const int a[], int n, int key)
{
	int i;
	int pl = 0;
	int pr = n - 1;
	int pc;

	do {
		pc = (pl + pr) / 2;
		if(a[pc] == key) {
			for(; a[pc] == key; pc--);
			return pc + 1;
		}
		else if(a[pc] < key)
			pl = pc + 1;
		else
			pr = pc - 1;
	} while(pl <= pr);

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

	printf("������������ �Է��ϼ���.\n");
	printf("x[0] : ");
	scanf("%d", &x[0]);
	for(i = 1; i < nx; i++) {
		do {
			printf("x[%d] : ", i);
			scanf("%d", &x[i]);
		} while(x[i] < x[i - 1]);
	}

	printf("�˻��� : ");
	scanf("%d", &ky);

	idx = bin_search2(x, nx, ky);

	if(idx == -1)
		puts("�˻��� �����߽��ϴ�.");
	else
		printf("%d(��)�� x[%d]�� �ֽ��ϴ�.\n", ky, idx);
	
	free(x);

	return 0;
}