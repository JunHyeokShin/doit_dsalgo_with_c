#include <stdio.h>
#include "IntDeque.h"

int main(void)
{
	IntDeque que;

	if(Initialize(&que, 64) == -1) {
		puts("ť�� ������ �����߽��ϴ�.");
		return 1;
	}

	while(1) {
		int m, x;
		int idx;

		printf("���� �������� �� : %d / %d\n", Size(&que), Capacity(&que));
		printf("1)EnqueFront 2)EnqueRear 3)DequeFront 4)DequeRear 5)PeekFront 6)PeekRear 7)Print 8)Search 9)Search2 10)Clear 11)Status 0)Exit : ");
		scanf("%d", &m);

		if(m == 0) break;

		switch(m) {
		case 1:
			printf("������ : ");
			scanf("%d", &x);
			if(EnqueFront(&que, x) == -1)
				puts("\a���� : ��ť�� �����߽��ϴ�.");
			break;

		case 2:
			printf("������ : ");
			scanf("%d", &x);
			if(EnqueRear(&que, x) == -1)
				puts("\a���� : ��ť�� �����߽��ϴ�.");
			break;

		case 3:
			if(DequeFront(&que, &x) == -1)
				puts("\a���� : ��ť�� �����߽��ϴ�.");
			else
				printf("��ť�� �����ʹ� %d�Դϴ�.\n", x);
			break;
		
		case 4:
			if(DequeRear(&que, &x) == -1)
				puts("\a���� : ��ť�� �����߽��ϴ�.");
			else
				printf("��ť�� �����ʹ� %d�Դϴ�.\n", x);
			break;

		case 5:
			if(PeekFront(&que, &x) == -1)
				puts("\a���� : ��ũ�� �����߽��ϴ�.");
			else
				printf("��ũ�� �����ʹ� %d�Դϴ�.\n", x);
			break;

		case 6:
			if(PeekRear(&que, &x) == -1)
				puts("\a���� : ��ũ�� �����߽��ϴ�.");
			else
				printf("��ũ�� �����ʹ� %d�Դϴ�.\n", x);
			break;

		case 7:
			Print(&que);
			break;

		case 8:
			printf("�˻� ������ : ");
			scanf("%d", &x);
			if((idx = Search(&que, x)) == -1)
				puts("\a���� : �˻��� �����߽��ϴ�.");
			else
				printf("�����ʹ� �ε��� %d ��ġ�� �ֽ��ϴ�.\n", idx);
			break;

		case 9:
			printf("�˻� ������ : ");
			scanf("%d", &x);
			if((idx = Search2(&que, x)) == -1)
				puts("\a���� : �˻��� �����߽��ϴ�.");
			else
				printf("�����ʹ� ����Ʈ�κ��� %d ��ġ�� �ֽ��ϴ�.\n", idx);
			break;

		case 10:
			Clear(&que);
			break;

		case 11:
			printf("ť�� ��� %s.\n", IsEmpty(&que) ? "�ֽ��ϴ�" : "���� �ʽ��ϴ�");
			printf("ť�� ���� %s.\n", IsFull(&que) ? "á���ϴ�" : "���� �ʾҽ��ϴ�.");
			break;
		}
	}
	
	Terminate(&que);

	return 0;
}