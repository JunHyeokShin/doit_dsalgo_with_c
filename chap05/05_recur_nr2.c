#include <stdio.h>
#include "IntStack.h"

//--- ��� ȣ���� ������ recur �Լ� ---
void recur(int n)
{
	IntStack stk;				//����
	Initialize(&stk, 100);
Top:
	if(n > 0) {
		Push(&stk, n);			//n�� ���� Ǫ��
		n = n - 1;
		goto Top;
	}
	if(!IsEmpty(&stk)) {		//������ ��� ���� ������
		Pop(&stk, &n);			//���� �����ߴ� n�� ��
		printf("%d\n", n);
		n = n - 2;
		goto Top;
	}

	Terminate(&stk);
}

int main(void)
{
	int x;

	printf("������ �Է��ϼ���. : ");
	scanf("%d", &x);

	recur(x);

	return 0;
}