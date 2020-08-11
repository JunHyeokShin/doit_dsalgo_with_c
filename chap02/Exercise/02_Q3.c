#include <stdio.h>
#include <stdlib.h>

double aveof(const int a[], int n)
{
	int i;
	double sum = 0;
	for(i = 0; i < n; i++)
		sum += a[i];
	return sum / n;
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
	printf("����� %f�Դϴ�.\n", aveof(height, number));
	free(height);

	return 0;
}