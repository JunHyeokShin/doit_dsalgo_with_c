//�ڷ����� int���̰� ��� ������ 5�� �迭
#include <stdio.h>

#define N	5		//�迭�� ��� ����
int main(void)
{
	int i;
	int a[N];		//�迭�� ����
	for(i = 0; i < N; i++) {	//�� ��ҿ� ���� �Է��մϴ�.
		printf("a[%d] : ", i);
		scanf("%d", &a[i]);
	}
	puts("�� ����� ��");
	for(i = 0; i < N; i++) {	//�� ����� ���� ����մϴ�.
		printf("a[%d] = %d\n", i, a[i]);
	}

	return 0;
}