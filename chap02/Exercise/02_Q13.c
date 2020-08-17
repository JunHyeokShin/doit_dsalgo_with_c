#include <stdio.h>

typedef struct {
	int y;
	int m;
	int d;
} Date;

Date After(Date x, int n);
Date Before(Date x, int n);

int mdays[2][12] = {
	{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
	{31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

int isleap(int y)
{
	return y % 4 == 0 && y % 100 != 0 || y % 400 == 0;
}

Date DateOf(int y, int m, int d)	//y년 m월 d일을 나타내는 구조체를 반환하는 함수
{
	Date temp;

	temp.y = y;
	temp.m = m;
	temp.d = d;

	return temp;
}

Date After(Date x, int n)	//날짜 x의 n일 뒤의 날짜를 반환하는 함수
{
	if(n < 0)
		return Before(x, -n);

	x.d += n;
	while(x.d > mdays[isleap(x.y)][x.m - 1]) {
		x.d -= mdays[isleap(x.y)][x.m - 1];
		if(++x.m > 12) {
			x.y++;
			x.m = 1;
		}
	}
	return x;
}

Date Before(Date x, int n)	//날짜 x의 n일 앞의 날짜를 반환하는 함수
{
	if(n < 0)
		return After(x, -n);
	
	x.d -= n;
	while(x.d < 1) {
		if(--x.m < 1) {
			x.y--;
			x.m = 12;
		}
		x.d += mdays[isleap(x.y)][x.m - 1];
	}
	return x;
}

void Print(Date x)
{
	int y = x.y;
	int m = x.m;
	int d = x.d;

	printf("%04d년 %02d월 %02d일\n", x.y, x.m, x.d);
}

int main(void)
{
	int n;
	int y, m, d;
	Date x;

	printf("날짜를 입력하세요.\n");
	printf("년 : "); scanf("%d", &y);
	printf("월 : "); scanf("%d", &m);
	printf("일 : "); scanf("%d", &d);

	x = DateOf(y, m, d);

	printf("며칠 앞/뒤의 날짜를 구할까요? : ");
	scanf("%d", &n);

	printf("%d일 뒤의 날짜 : ", n); Print(After(x, n));
	printf("%d일 앞의 날짜 : ", n); Print(Before(x, n));

	return 0;
}