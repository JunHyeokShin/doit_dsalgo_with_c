#include <stdio.h>
#include <stdlib.h>

int gcd(int a, int b)
{
	return b ? gcd(b, a % b) : a;
}

int gcd_array(const int a[], int n)
{
	if(n == 1)
		return (a[0]);
	else if(n == 2)
		return (gcd(a[0], a[1]));
	else
		return (gcd(a[0], gcd_array(&a[1], n - 1)));
}

int main(void)
{
	int i, nx;
	int *x;

	printf("정수 개수 : ");
	scanf("%d", &nx);
	x = calloc(nx, sizeof(int));

	for(i = 0; i < nx; i++) {
		printf("x[%d] : ", i);
		scanf("%d", &x[i]);
	}

	printf("최대 공약수는 %d입니다.\n", gcd_array(x, nx));

	free(x);

	return 0;
}