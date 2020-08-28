#include <stdio.h>
#include "IntQueue.h"

int main(void)
{
	IntQueue que;

	if(Initialize(&que, 64) == -1) {
		puts("ť�� ������ �����Ͽ����ϴ�.");
		return 1;
	}
	while(1) {
		int m, x, idx;

		printf("���� ������ �� : %d / %d\n", Size(&que), Capacity(&que));
		printf("1)Enque 2)Deque 3)Peek 4)Print 5)Search 6)Search2 7)Clear 8)Status 0)Exit : ");
		scanf("%d", &m);

		if(m == 0) break;

		switch(m) {
		case 1:
			printf("������ : ");
			scanf("%d", &x);
			if(Enque(&que, x) == -1)
				puts("\a���� : ��ť�� �����߽��ϴ�.");
			break;

		case 2:
			if(Deque(&que, &x) == -1)
				puts("\a���� : ��ť�� �����߽��ϴ�.");
			else
				printf("��ť�� �����ʹ� %d�Դϴ�.\n", x);
			break;

		case 3:
			if(Peek(&que, &x) == -1)
				puts("\a���� : ��ũ�� �����߽��ϴ�.");
			else
				printf("��ũ�� �����ʹ� %d�Դϴ�.\n", x);
			break;

		case 4:
			Print(&que);
			break;

		case 5:
			printf("�˻� ������ : ");
			scanf("%d", &x);
			if((idx = Search(&que, x)) == -1)
				puts("\a���� : �˻��� �����߽��ϴ�.");
			else
				printf("�����ʹ� �ε��� %d ��ġ�� �ֽ��ϴ�.\n", idx);
			break;

		case 6:
			printf("�˻� ������ : ");
			scanf("%d", &x);
			if((idx = Search2(&que, x)) == -1)
				puts("\a���� : �˻��� �����߽��ϴ�.");
			else
				printf("�����ʹ� ����Ʈ �������� %d ��ġ�� �ֽ��ϴ�.\n", idx);
			break;

		case 7:
			Clear(&que);
			break;

		case 8:
			printf("ť�� ��� %s.\n", IsEmpty(&que) ? "�ֽ��ϴ�" : "���� �ʽ��ϴ�");
			printf("ť�� ���� %s.\n", IsFull(&que) ? "á���ϴ�" : "���� �ʾҽ��ϴ�");
			break;
		}
	}

	Terminate(&que);
	
	return 0;
}