#include <stdio.h>
#include <stdlib.h>

void *seqsearch(const void *key, const void *base, size_t nmemb, size_t size, int (*compar)(const void *, const void *))
{
	size_t i;
	char *x = (char *)base;

	for(i = 0; i < nmemb; i++)
		if(!compar((const void *)&x[i * size], key))
			return &x[i * size];
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

	puts("seqsearch �Լ��� ����Ͽ� �˻�");
	printf("��ڼ� : ");
	scanf("%d", &nx);
	x = calloc(nx, sizeof(int));

	for(i = 0; i < nx; i++) {
		printf("x[%d] : ", i);
		scanf("%d", &x[i]);
	}

	printf("�˻��� : ");
	scanf("%d", &ky);

	p = seqsearch(&ky, x, nx, sizeof(int), (int (*)(const void *, const void *))int_cmp);

	if(p == NULL)
		puts("�˻��� �����߽��ϴ�.");
	else
		printf("%d�� x[%d]�� �ֽ��ϴ�.\n", ky, (int)(p - x));
	
	free(x);

	return 0;
}