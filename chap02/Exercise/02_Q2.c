#include <stdio.h>
#include <stdlib.h>

int sumof(const int a[], int n)
{
	int i;
	int sum = 0;
	for(i = 0; i < n; i++)
		sum += a[i];
	return sum;
}

int main(void)
{
	int i;
	int *height;
	int number;

	printf("��� �� : ");
	scanf("%d", &number);
	height = calloc(number, sizeof(int));
	printf("%d ����� Ű�� �Է��ϼ���.\n", number);
	for(i = 0; i < number; i++) {
		printf("height[%d] : ", i);
		scanf("%d", &height[i]);
	}
	printf("�հ�� %d�Դϴ�.\n", sumof(height, number));
	free(height);

	return 0;
}