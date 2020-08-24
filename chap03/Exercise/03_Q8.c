#include <stdio.h>
#include <stdlib.h>

void *binsearch(const void *key, const void *base, size_t nmemb, size_t size, int (*compar)(const void *, const void *))
{
	size_t pl = 0;
	size_t pr = nmemb - 1;
	size_t pc;
	char *x = (char *)base;

	if(nmemb > 0) {
		while(1) {
			int comp = compar((const void *)&x[(pc = (pl + pr) / 2) * size], key);

			if(comp == 0)
				return &x[pc * size];
			else if(pl == pr)
				break;
			else if(comp < 0)
				pl = pc + 1;
			else
				pr = pc - 1;
		}
	}

	return NULL;
}

int int_cmp(const int *a, const int *b)
{
	if(*a < *b)
		return -1;
	else if(*a > *b)
		return 1;
	else
		return 0;
}

int main(void)
{
	int i, nx, ky;
	int *x;
	int *p;
	
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

	p = binsearch(&ky, x, nx, sizeof(int), (int (*)(const void *, const void *))int_cmp);

	if(p == NULL)
		puts("�˻��� �����߽��ϴ�.");
	else
		printf("%d�� x[%d]�� �ֽ��ϴ�.\n", ky, (int)(p - x));

	free(x);

	return 0;
}