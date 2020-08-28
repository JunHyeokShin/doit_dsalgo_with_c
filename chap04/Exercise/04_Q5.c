#include <stdio.h>
#include "IntQueue.h"

int main(void)
{
	IntQueue que;

	if(Initialize(&que, 64) == -1) {
		puts("큐의 생성에 실패하였습니다.");
		return 1;
	}
	while(1) {
		int m, x, idx;

		printf("현재 데이터 수 : %d / %d\n", Size(&que), Capacity(&que));
		printf("1)Enque 2)Deque 3)Peek 4)Print 5)Search 6)Search2 7)Clear 8)Status 0)Exit : ");
		scanf("%d", &m);

		if(m == 0) break;

		switch(m) {
		case 1:
			printf("데이터 : ");
			scanf("%d", &x);
			if(Enque(&que, x) == -1)
				puts("\a오류 : 인큐에 실패했습니다.");
			break;

		case 2:
			if(Deque(&que, &x) == -1)
				puts("\a오류 : 디큐에 실패했습니다.");
			else
				printf("디큐한 데이터는 %d입니다.\n", x);
			break;

		case 3:
			if(Peek(&que, &x) == -1)
				puts("\a오류 : 피크에 실패했습니다.");
			else
				printf("피크한 데이터는 %d입니다.\n", x);
			break;

		case 4:
			Print(&que);
			break;

		case 5:
			printf("검색 데이터 : ");
			scanf("%d", &x);
			if((idx = Search(&que, x)) == -1)
				puts("\a오류 : 검색에 실패했습니다.");
			else
				printf("데이터는 인덱스 %d 위치에 있습니다.\n", idx);
			break;

		case 6:
			printf("검색 데이터 : ");
			scanf("%d", &x);
			if((idx = Search2(&que, x)) == -1)
				puts("\a오류 : 검색에 실패했습니다.");
			else
				printf("데이터는 프론트 기준으로 %d 위치에 있습니다.\n", idx);
			break;

		case 7:
			Clear(&que);
			break;

		case 8:
			printf("큐는 비어 %s.\n", IsEmpty(&que) ? "있습니다" : "있지 않습니다");
			printf("큐는 가득 %s.\n", IsFull(&que) ? "찼습니다" : "차지 않았습니다");
			break;
		}
	}

	Terminate(&que);
	
	return 0;
}