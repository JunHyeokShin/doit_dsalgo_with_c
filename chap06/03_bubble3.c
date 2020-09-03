//버블 정렬
#include <stdio.h>
#include <stdlib.h>
#define swap(type, x, y) do {type t = x; x = y; y = t;} while(0)

//--- 버블 정렬(버전 3 : 스캔 범위를 제한합니다.) ---
void bubble(int a[], int n)
{
	int k = 0;		//a[k]보다 앞쪽의 요소는 정렬을 마친 상태입니다.
	while(k < n - 1) {
		int j;
		int last = n - 1;	//마지막으로 교환을 수행한 위치를 저장합니다.
		for(j = n - 1; j > k; j--)
			if(a[j - 1] > a[j]) {
				swap(int, a[j - 1], a[j]);
				last = j;
			}
		k = last;
	}
}

int main(void)
{
	int i, nx;
	int *x;				//배열의 첫 번째 요소에 대한 포인터

	puts("버블 정렬");
	printf("요소 개수 : ");
	scanf("%d", &nx);
	x = calloc(nx, sizeof(int));	//요소의 개수가 nx인 int형 배열을 생성

	for(i = 0; i < nx; i++) {
		printf("x[%d] : ", i);
		scanf("%d", &x[i]);
	}

	bubble(x, nx);					//배열 x를 버블 정렬

	puts("오름차순으로 정렬했습니다.");
	for(i = 0; i < nx; i++)
		printf("x[%d] = %d\n", i, x[i]);

	free(x);						//배열 해제

	return 0;
}