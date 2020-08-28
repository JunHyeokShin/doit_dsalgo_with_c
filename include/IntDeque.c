#include <stdio.h>
#include <stdlib.h>
#include "IntDeque.h"

int Initialize(IntDeque *q, int max)
{
	q->num = q->front = q->rear = 0;
	if((q->que = calloc(max, sizeof(int))) == NULL) {
		q->max = 0;
		return -1;
	}
	q->max = max;
	return 0;
}

int EnqueFront(IntDeque *q, int x)
{
	if(q->num >= q->max)
		return -1;
	else {
		q->num++;
		if(--q->front < 0)
			q->front = q->max - 1;
		q->que[q->front] = x;
		return 0;
	}
}

int EnqueRear(IntDeque *q, int x)
{
	if(q->num >= q->max)
		return -1;
	else {
		q->num++;
		q->que[q->rear++] = x;
		if(q->rear == q->max)
			q->rear = 0;
		return 0;
	}
}

int DequeFront(IntDeque *q, int *x)
{
	if(q->num <= 0)
		return -1;
	else {
		q->num--;
		*x = q->que[q->front++];
		if(q->front == q->max)
			q->front = 0;
		return 0;
	}
}

int DequeRear(IntDeque *q, int *x)
{
	if(q->num <= 0)
		return -1;
	else {
		q->num--;
		if(--q->rear < 0)
			q->rear = q->max - 1;
		*x = q->que[q->rear];
		return 0;
	}
}

int PeekFront(const IntDeque *q, int *x)
{
	if(q->num <= 0)
		return -1;
	*x = q->que[q->front];
	return 0;
}

int PeekRear(const IntDeque *q, int *x)
{
	int temp;

	if(q->num <= 0)
		return -1;
	if((temp = q->rear - 1) < 0)
		temp = q->max - 1;
	*x = q->que[temp];
	return 0;
}

void Clear(IntDeque *q)
{
	q->num = q->front = q->rear = 0;
}

int Capacity(const IntDeque *q)
{
	return q->max;
}

int Size(const IntDeque *q)
{
	return q->num;
}

int IsEmpty(const IntDeque *q)
{
	return q->num <= 0;
}

int IsFull(const IntDeque *q)
{
	return q->num >= q->max;
}

int Search(const IntDeque *q, int x)
{
	int i, idx;

	for(i = 0; i < q->num; i++) {
		if(q->que[idx = (i + q->front) % q->max] == x)
			return idx;
	}
	return -1;
}

int Search2(const IntDeque *q, int x)
{
	int i;

	for(i = 0; i < q->num; i++) {
		if(q->que[(i + q->front) % q->max] == x)
			return i;
	}
	return -1;
}

void Print(const IntDeque *q)
{
	int i;

	for(i = 0; i < q->num; i++)
		printf("%d ", q->que[(i + q->front) % q->max]);
	putchar('\n');
}

void Terminate(IntDeque *q)
{
	if(q->que != NULL)
		free(q->que);
	q->max = q->num = q->front = q->rear = 0;
}