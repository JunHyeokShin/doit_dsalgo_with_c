#include <stdio.h>

int main(void)
{
	int a, b;

	printf("a�� �� : ");
	scanf("%d", &a);

	do {
		printf("b�� �� : ");
		scanf("%d", &b);
		if(b <= a)
			printf("a���� ū ���� �Է��ϼ���!\n");
	} while(b <= a);
	
	printf("b - a�� %d�Դϴ�.\n", b - a);

	return 0;
}