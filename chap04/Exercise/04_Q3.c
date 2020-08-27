#include <stdio.h>
#include "ArrayIntQueue.h"

int main(void)
{
	ArrayIntQueue q;

	if(Initialize(&q, 16) == -1) {
		puts("큐 생성에 실패하였습니다.");
		return 1;
	}

	while(1) {
		int menu, idx, x;

		printf("현재 데이터 수 : %d / %d\n", Size(&q), Capacity(&q));
		printf("1)Enque 2)Deque 3)Peek 4)Print 5)Search 6)Clear 7)Status 0)Exit : ");
		scanf("%d", &menu);

		if(menu == 0) break;
		
		switch(menu) {
		case 1:
			printf("데이터 : ");
			scanf("%d", &x);
			if(Enque(&q, x) == -1)
				puts("\a오류 : 인큐에 실패했습니다.");
			break;

		case 2:
			if(Deque(&q, &x) == -1)
				puts("\a오류 : 디큐에 실패했습니다.");
			else
				printf("디큐한 데이터는 %d입니다.\n", x);
			break;

		case 3:
			if(Peek(&q, &x) == -1)
				puts("\a오류 : 피크에 실패했습니다.");
			else
				printf("피크한 데이터는 %d입니다.\n", x);
			break;

		case 4:
			Print(&q);
			break;

		case 5:
			printf("검색 데이터 : ");
			scanf("%d", &x);
			if((idx = Search(&q, x)) == -1)
				puts("\a오류 : 검색에 실패했습니다.");
			else
				printf("데이는 인덱스 %d 위치에 있습니다.\n", idx);
			break;

		case 6:
			Clear(&q);
			break;

		case 7:
			printf("스택이 비어 %s.\n", IsEmpty(&q) ? "있습니다" : "있지 않습니다");
			printf("스택이 가득 %s.\n", IsFull(&q) ? "찼습니다" : "차지 않았습니다");
			break;
		}
	}

	Terminate(&q);

	return 0;
}