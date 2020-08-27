#include <stdio.h>
#include "ArrayIntQueue.h"

int main(void)
{
	ArrayIntQueue q;

	if(Initialize(&q, 16) == -1) {
		puts("ť ������ �����Ͽ����ϴ�.");
		return 1;
	}

	while(1) {
		int menu, idx, x;

		printf("���� ������ �� : %d / %d\n", Size(&q), Capacity(&q));
		printf("1)Enque 2)Deque 3)Peek 4)Print 5)Search 6)Clear 7)Status 0)Exit : ");
		scanf("%d", &menu);

		if(menu == 0) break;
		
		switch(menu) {
		case 1:
			printf("������ : ");
			scanf("%d", &x);
			if(Enque(&q, x) == -1)
				puts("\a���� : ��ť�� �����߽��ϴ�.");
			break;

		case 2:
			if(Deque(&q, &x) == -1)
				puts("\a���� : ��ť�� �����߽��ϴ�.");
			else
				printf("��ť�� �����ʹ� %d�Դϴ�.\n", x);
			break;

		case 3:
			if(Peek(&q, &x) == -1)
				puts("\a���� : ��ũ�� �����߽��ϴ�.");
			else
				printf("��ũ�� �����ʹ� %d�Դϴ�.\n", x);
			break;

		case 4:
			Print(&q);
			break;

		case 5:
			printf("�˻� ������ : ");
			scanf("%d", &x);
			if((idx = Search(&q, x)) == -1)
				puts("\a���� : �˻��� �����߽��ϴ�.");
			else
				printf("���̴� �ε��� %d ��ġ�� �ֽ��ϴ�.\n", idx);
			break;

		case 6:
			Clear(&q);
			break;

		case 7:
			printf("������ ��� %s.\n", IsEmpty(&q) ? "�ֽ��ϴ�" : "���� �ʽ��ϴ�");
			printf("������ ���� %s.\n", IsFull(&q) ? "á���ϴ�" : "���� �ʾҽ��ϴ�");
			break;
		}
	}

	Terminate(&q);

	return 0;
}