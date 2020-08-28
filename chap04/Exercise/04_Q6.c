#include <stdio.h>
#include "IntDeque.h"

int main(void)
{
	IntDeque que;

	if(Initialize(&que, 64) == -1) {
		puts("큐의 생성에 실패했습니다.");
		return 1;
	}

	while(1) {
		int m, x;
		int idx;

		printf("현재 데이터의 수 : %d / %d\n", Size(&que), Capacity(&que));
		printf("1)EnqueFront 2)EnqueRear 3)DequeFront 4)DequeRear 5)PeekFront 6)PeekRear 7)Print 8)Search 9)Search2 10)Clear 11)Status 0)Exit : ");
		scanf("%d", &m);

		if(m == 0) break;

		switch(m) {
		case 1:
			printf("데이터 : ");
			scanf("%d", &x);
			if(EnqueFront(&que, x) == -1)
				puts("\a오류 : 인큐에 실패했습니다.");
			break;

		case 2:
			printf("데이터 : ");
			scanf("%d", &x);
			if(EnqueRear(&que, x) == -1)
				puts("\a오류 : 인큐에 실패했습니다.");
			break;

		case 3:
			if(DequeFront(&que, &x) == -1)
				puts("\a오류 : 디큐에 실패했습니다.");
			else
				printf("디큐한 데이터는 %d입니다.\n", x);
			break;
		
		case 4:
			if(DequeRear(&que, &x) == -1)
				puts("\a오류 : 디큐에 실패했습니다.");
			else
				printf("디큐한 데이터는 %d입니다.\n", x);
			break;

		case 5:
			if(PeekFront(&que, &x) == -1)
				puts("\a오류 : 피크에 실패했습니다.");
			else
				printf("피크한 데이터는 %d입니다.\n", x);
			break;

		case 6:
			if(PeekRear(&que, &x) == -1)
				puts("\a오류 : 피크에 실패했습니다.");
			else
				printf("피크한 데이터는 %d입니다.\n", x);
			break;

		case 7:
			Print(&que);
			break;

		case 8:
			printf("검색 데이터 : ");
			scanf("%d", &x);
			if((idx = Search(&que, x)) == -1)
				puts("\a오류 : 검색에 실패했습니다.");
			else
				printf("데이터는 인덱스 %d 위치에 있습니다.\n", idx);
			break;

		case 9:
			printf("검색 데이터 : ");
			scanf("%d", &x);
			if((idx = Search2(&que, x)) == -1)
				puts("\a오류 : 검색에 실패했습니다.");
			else
				printf("데이터는 프론트로부터 %d 위치에 있습니다.\n", idx);
			break;

		case 10:
			Clear(&que);
			break;

		case 11:
			printf("큐가 비어 %s.\n", IsEmpty(&que) ? "있습니다" : "있지 않습니다");
			printf("큐가 가득 %s.\n", IsFull(&que) ? "찼습니다" : "차지 않았습니다.");
			break;
		}
	}
	
	Terminate(&que);

	return 0;
}