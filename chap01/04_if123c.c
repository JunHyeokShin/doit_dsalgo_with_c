#include <stdio.h>

int main(void)
{
	int n;

	printf("������ �Է��ϼ��� : ");
	scanf("%d", &n);
	if(n == 1)
		printf("1�Դϴ�.\n");
	else if(n == 2)
		printf("2�Դϴ�.\n");
	else if(n == 3)
		printf("3�Դϴ�.\n");
	else
		;	//���鹮(������ �ƹ��͵� ���� �ʴ� ����)
	return 0;
}