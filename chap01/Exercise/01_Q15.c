#include <stdio.h>

int main(void)
{
	int h, w, i, j;

	printf("���簢���� ����մϴ�.\n");

	do {
		printf("���� : ");
		scanf("%d", &h);
	} while(h <= 0);

	do {
		printf("�ʺ� : ");
		scanf("%d", &w);
	} while(w <= 0);

	for(i = 1; i <= h; i++) {
		for(j = 1; j <= w; j++)
			printf("* ");
		putchar('\n');
	}

	return 0;
}