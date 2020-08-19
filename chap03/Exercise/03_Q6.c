#include <stdio.h>
#include <stdlib.h>

int cmpr(const long *a, const long *b)
{
	if(*a < *b)
		return 1;
	else if(*a > *b)
		return -1;
	else
		return 0;
}

int main(void)
{
	int i, nx;
	long ky;
	long *x;
	long *p;

	puts("bsearch �Լ��� ����Ͽ� �˻�");
	printf("��� ���� : ");
	scanf("%d", &nx);

	x = calloc(nx ,sizeof(long));

	printf("������������ �Է��ϼ���.\n");
	printf("x[0] : ");
	scanf("%ld", &x[0]);
	for(i = 1; i < nx; i++) {
		do {
			printf("x[%d] : ", i);
			scanf("%ld", &x[i]);
		} while(x[i] > x[i - 1]);
	}
	
	printf("�˻��� : ");
	scanf("%ld", &ky);

	p = bsearch(&ky, x, nx, sizeof(long), (int (*)(const void *, const void *))cmpr);
	
	if(p == NULL)
		puts("�˻��� �����߽��ϴ�.");
	else
		printf("%ld��(��) x[%d]�� �ֽ��ϴ�.\n", ky, (int)(p - x));
	
	free(x);

	return 0;
}