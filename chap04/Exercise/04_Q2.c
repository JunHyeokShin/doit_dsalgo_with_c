#include <stdio.h>
#include "IntStack2.h"

int main(void)
{
	IntStack s;

	if(Initialize(&s, 12) == -1) {
		puts("스택 생성에 실패하였습니다.");
		return 1;
	}

	while(1) {
		int menu, idx, x, AorB;

		printf("현재 데이터 수 : A : %d B : %d / %d\n", Size(&s, StackA), Size(&s, StackB), Capacity(&s));
		printf("1)Push 2)Pop 3)Peek 4)Print 5)Search 6)Clear 7)Status 0)Exit : ");
		scanf("%d", &menu);

		if(menu == 0) break;
		
		switch(menu) {
		case 1:
			do {
				printf("스택을 선택하십시오(1 - A / 2 - B). : ");
				scanf("%d", &AorB);
			} while(AorB != 1 && AorB != 2);
			putchar('\n');
			printf("데이터 : ");
			scanf("%d", &x);
			if(Push(&s, AorB == 1 ? StackA : StackB, x) == -1)
				puts("\a오류 : 푸시에 실패했습니다.");
			break;

		case 2:
			do {
				printf("스택을 선택하십시오(1 - A / 2 - B). : ");
				scanf("%d", &AorB);
			} while(AorB != 1 && AorB != 2);
			putchar('\n');
			if(Pop(&s, AorB == 1 ? StackA : StackB, &x) == -1)
				puts("\a오류 : 팝에 실패했습니다.");
			else
				printf("팝한 데이터는 %d입니다.\n", x);
			break;

		case 3:
			do {
				printf("스택을 선택하십시오(1 - A / 2 - B). : ");
				scanf("%d", &AorB);
			} while(AorB != 1 && AorB != 2);
			putchar('\n');
			if(Peek(&s, AorB == 1 ? StackA : StackB, &x) == -1)
				puts("\a오류 : 피크에 실패했습니다.");
			else
				printf("피크한 데이터는 %d입니다.\n", x);
			break;

		case 4:
			do {
				printf("스택을 선택하십시오(1 - A / 2 - B). : ");
				scanf("%d", &AorB);
			} while(AorB != 1 && AorB != 2);
			putchar('\n');
			Print(&s, AorB == 1 ? StackA : StackB);
			break;

		case 5:
			do {
				printf("스택을 선택하십시오(1 - A / 2 - B). : ");
				scanf("%d", &AorB);
			} while(AorB != 1 && AorB != 2);
			printf("검색 데이터 : ");
			scanf("%d", &x);
			putchar('\n');
			if((idx = Search(&s, AorB == 1 ? StackA : StackB, x)) == -1)
				puts("\a오류 : 검색에 실패했습니다.");
			else
				printf("데이터는 인덱스 %d 위치에 있습니다.\n", idx);
			break;

		case 6:
			do {
				printf("스택을 선택하십시오(1 - A / 2 - B). : ");
				scanf("%d", &AorB);
			} while(AorB != 1 && AorB != 2);
			putchar('\n');
			Clear(&s, AorB == 1 ? StackA : StackB);
			break;

		case 7:
			putchar('\n');
			printf("스택 A는 비어 %s.\n", IsEmpty(&s, StackA) ? "있습니다" : "있지 않습니다");
			printf("스택 B는 비어 %s.\n", IsEmpty(&s, StackB) ? "있습니다" : "있지 않습니다");
			printf("스택은 가득 %s.\n", IsFull(&s) ? "찼습니다" : "차지 않았습니다");
			break;
		}
		putchar('\n');
	}

	Terminate(&s);

	return 0;
}