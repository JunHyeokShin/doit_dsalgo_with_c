#include <stdio.h>
#include <stdlib.h>

int bin_search(const int a[], int n, int key)
{
	int i;
	int pl = 0;
	int pr = n - 1;
	int pc;

	printf("  | ");
	for(i = 0; i < n; i++)
		printf("%2d ", i);
	printf("\n--+-");
	for(i = 0; i < n; i++)
		printf("---");
	printf("-\n");

	do {
		pc = (pl + pr) / 2;
		printf("  | ");
		printf("%*.*s", 3 * pl + 2, 1, "<");
		printf("%*.*s", 3 * (pc - pl), 1, "+");
		printf("%*.*s\n", 3 * (pr - pc), 1, ">");
		printf("%2d| ", pc);
		for(i = 0; i < n; i++)
			printf("%2d ", a[i]);
		putchar('\n');

		if(a[pc] == key)
			return pc;
		else if(a[pc] < key)
			pl = pc + 1;
		else
			pr = pc - 1;
		
		printf("  |\n");
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

	idx = bin_search(x, nx, ky);

	if(idx == -1)
		puts("�˻��� �����߽��ϴ�.");
	else
		printf("%d(��)�� x[%d]�� �ֽ��ϴ�.\n", ky, idx);
		
	free(x);

	return 0;
}