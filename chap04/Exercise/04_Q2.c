#include <stdio.h>
#include "IntStack2.h"

int main(void)
{
	IntStack s;

	if(Initialize(&s, 12) == -1) {
		puts("���� ������ �����Ͽ����ϴ�.");
		return 1;
	}

	while(1) {
		int menu, idx, x, AorB;

		printf("���� ������ �� : A : %d B : %d / %d\n", Size(&s, StackA), Size(&s, StackB), Capacity(&s));
		printf("1)Push 2)Pop 3)Peek 4)Print 5)Search 6)Clear 7)Status 0)Exit : ");
		scanf("%d", &menu);

		if(menu == 0) break;
		
		switch(menu) {
		case 1:
			do {
				printf("������ �����Ͻʽÿ�(1 - A / 2 - B). : ");
				scanf("%d", &AorB);
			} while(AorB != 1 && AorB != 2);
			putchar('\n');
			printf("������ : ");
			scanf("%d", &x);
			if(Push(&s, AorB == 1 ? StackA : StackB, x) == -1)
				puts("\a���� : Ǫ�ÿ� �����߽��ϴ�.");
			break;

		case 2:
			do {
				printf("������ �����Ͻʽÿ�(1 - A / 2 - B). : ");
				scanf("%d", &AorB);
			} while(AorB != 1 && AorB != 2);
			putchar('\n');
			if(Pop(&s, AorB == 1 ? StackA : StackB, &x) == -1)
				puts("\a���� : �˿� �����߽��ϴ�.");
			else
				printf("���� �����ʹ� %d�Դϴ�.\n", x);
			break;

		case 3:
			do {
				printf("������ �����Ͻʽÿ�(1 - A / 2 - B). : ");
				scanf("%d", &AorB);
			} while(AorB != 1 && AorB != 2);
			putchar('\n');
			if(Peek(&s, AorB == 1 ? StackA : StackB, &x) == -1)
				puts("\a���� : ��ũ�� �����߽��ϴ�.");
			else
				printf("��ũ�� �����ʹ� %d�Դϴ�.\n", x);
			break;

		case 4:
			do {
				printf("������ �����Ͻʽÿ�(1 - A / 2 - B). : ");
				scanf("%d", &AorB);
			} while(AorB != 1 && AorB != 2);
			putchar('\n');
			Print(&s, AorB == 1 ? StackA : StackB);
			break;

		case 5:
			do {
				printf("������ �����Ͻʽÿ�(1 - A / 2 - B). : ");
				scanf("%d", &AorB);
			} while(AorB != 1 && AorB != 2);
			printf("�˻� ������ : ");
			scanf("%d", &x);
			putchar('\n');
			if((idx = Search(&s, AorB == 1 ? StackA : StackB, x)) == -1)
				puts("\a���� : �˻��� �����߽��ϴ�.");
			else
				printf("�����ʹ� �ε��� %d ��ġ�� �ֽ��ϴ�.\n", idx);
			break;

		case 6:
			do {
				printf("������ �����Ͻʽÿ�(1 - A / 2 - B). : ");
				scanf("%d", &AorB);
			} while(AorB != 1 && AorB != 2);
			putchar('\n');
			Clear(&s, AorB == 1 ? StackA : StackB);
			break;

		case 7:
			putchar('\n');
			printf("���� A�� ��� %s.\n", IsEmpty(&s, StackA) ? "�ֽ��ϴ�" : "���� �ʽ��ϴ�");
			printf("���� B�� ��� %s.\n", IsEmpty(&s, StackB) ? "�ֽ��ϴ�" : "���� �ʽ��ϴ�");
			printf("������ ���� %s.\n", IsFull(&s) ? "á���ϴ�" : "���� �ʾҽ��ϴ�");
			break;
		}
		putchar('\n');
	}

	Terminate(&s);

	return 0;
}