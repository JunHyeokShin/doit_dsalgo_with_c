//�Է¹��� ���� ���� ��ȣ(���/����/0)�� �Ǵ�
#include <stdio.h>

int main(void)
{
	int n;

	printf("������ �Է��ϼ��� : ");
	scanf("%d", &n);
	if(n > 0)
		printf("�� ���� ����Դϴ�.\n");
	else if(n < 0)
		printf("�� ���� �����Դϴ�.\n");
	else
		printf("�� ���� 0�Դϴ�.\n");
	return 0;
}