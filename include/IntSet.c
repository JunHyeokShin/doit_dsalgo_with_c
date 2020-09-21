#include <stdio.h>
#include <stdlib.h>
#include "IntSet.h"

//--- ���� �ʱ�ȭ ---
int Initialize(IntSet *s, int max)
{
	s->num = 0;
	if((s->set = calloc(max, sizeof(int))) == NULL) {
		s->max = 0;		//�迭 ������ ����
		return -1;
	}
	s->max = max;
	return 0;
}

//--- ���� s�� n�� ��� �ִ��� Ȯ�� ---
int IsMember(const IntSet *s, int n)
{
	int i;
	for(i = 0; i < s->num; i++)
		if(s->set[i] == n)
			return i;	//��� ����(�ε����� ��ȯ)
	return -1;			//��� ���� ����
}

//--- ������ ���� á���� Ȯ�� ---
int IsFull(const IntSet *s)
{
	return s->num >= s->max;
}

//--- ���� s�� n�� �߰� ---
void Add(IntSet *s, int n)
{
	if(s->num < s->max && IsMember(s, n) == -1)	//��� ���� ������
		s->set[s->num++] = n;					//�迭 ���� n�� �߰�
}

//--- ���� s���� n�� ���� ---
void Remove(IntSet *s, int n)
{
	int idx;
	if((idx = IsMember(s, n)) != -1) {
		s->set[idx] = s->set[--s->num];		//������ ��Ҹ� ���� ��ġ�� �ű�
	}
}

//--- ���� s�� ���� �� �ִ� �ִ��� ���� ������ ��ȯ ---
int Capacity(const IntSet *s)
{
	return s->max;
}

//--- ���� s�� ���� ���� ---
int Size(const IntSet *s)
{
	return s->num;
}

//--- ���� s2�� s1�� ���� ---
void Assign(IntSet *s1, const IntSet *s2)
{
	int i;
	int n = (s1->max < s2->num) ? s1->max : s2->num;	//�����ϴ� ������ ����
	for(i = 0; i < n; i++)
		s1->set[i] = s2->set[i];
	s1->num = n;
}

//--- ���� s1�� s2�� ������ Ȯ�� ---
int Equal(const IntSet *s1, const IntSet *s2)
{
	int i, j;
	if(Size(s1) != Size(s2))
		return 0;
	for(i = 0; i < s1->num; i++) {
		for(j = 0; j < s2->num; j++)
			if(s1->set[i] == s2->set[j])
				break;
		if(j == s2->num)
			return 0;
	}
	return 1;
}

//--- ���� s2�� s3�� �������� s1�� ���� ---
IntSet *Union(IntSet *s1, const IntSet *s2, const IntSet *s3)
{
	int i;
	Assign(s1, s2);
	for(i = 0; i < s3->num; i++)
		Add(s1, s3->set[i]);
	return s1;
}

//--- ���� s2�� s3�� �������� s1�� ���� ---
IntSet *Intersection(IntSet *s1, const IntSet *s2, const IntSet *s3)
{
	int i, j;
	s1->num = 0;	//s1�� ���������� ����ϴ�.
	for(i = 0; i < s2->num; i++)
		for(j = 0; j < s3->num; j++)
			if(s2->set[i] == s3->set[j])
				Add(s1, s2->set[i]);
	return s1;
}

//--- ���� s2���� s3�� �� �������� s1�� ���� ---
IntSet *Difference(IntSet *s1, const IntSet *s2, const IntSet *s3)
{
	int i, j;
	s1->num = 0;	//s1�� ���������� ����ϴ�.
	for(i = 0; i < s2->num; i++) {
		for(j = 0; j < s3->num; j++)
			if(s2->set[i] == s3->set[j])
				break;
		if(j == s3->num)
			Add(s1, s2->set[i]);
	}
	return s1;
}

//--- ���� s2, s3�� ��Ī ���� s1�� ���� ---
IntSet *SymmetricDifference(IntSet *s1, const IntSet *s2, const IntSet *s3)
{
	int i;
	s1->num = 0;
	for(i = 0; i < s2->num; i++)
		if(IsMember(s3, s2->set[i]) == -1)
			Add(s1, s2->set[i]);
	for(i = 0; i < s3->num; i++)
		if(IsMember(s2, s3->set[i]) == -1)
			Add(s1, s3->set[i]);
	return s1;
}

//--- ���� s1�� s2�� ��� ���Ҹ� �߰� ---
IntSet *ToUnion(IntSet *s1, const IntSet *s2)
{
	int i;
	for(i = 0; i < s2->num; i++)
		Add(s1, s2->set[i]);
	return s1;
}

//--- ���� s1���� s2�� ��� ���� ���� ��� ���Ҹ� ���� ---
IntSet *ToIntersection(IntSet *s1, const IntSet *s2)
{
	int i = 0;
	while(i < s1->num) {
		if(IsMember(s2, s1->set[i]) == -1)
			Remove(s1, s1->set[i]);
		else
			i++;
	}
	return s1;
}

//--- ���� s1���� s2�� ��� �ִ� ��� ���Ҹ� ���� ---
IntSet *ToDifference(IntSet *s1, const IntSet *s2)
{
	int i;
	for(i = 0; i < s2->num; i++)
		Remove(s1, s2->set[i]);
	return s1;
}

//--- ���� s1�� s2�� �κ��������� Ȯ�� ---
int IsSubset(const IntSet *s1, const IntSet *s2)
{
	int i, j;
	for(i = 0; i < s1->num; i++) {
		for(j = 0; j < s2->num; j++)
			if(s1->set[i] == s2->set[j])
				break;
		if(j == s2->num)
			return 0;
	}
	return -1;
}

//--- ���� s1�� s2�� ���κ��������� Ȯ�� ---
int IsProperSubset(const IntSet *s1, const IntSet *s2)
{
	int i;
	if(s1->num >= s2->num)
		return 0;
	return IsSubset(s1, s2);
}

//--- ���� s�� ��� ���Ҹ� ��� ---
void Print(const IntSet *s)
{
	int i;

	printf("{ ");
	for(i = 0; i < s->num; i++)
		printf("%d ", s->set[i]);
	printf("}");
}

//--- ���� s�� ��� ���Ҹ� ���(�� �ٲ� ���� ����) ---
void PrintLn(const IntSet *s)
{
	Print(s);
	putchar('\n');
}

//--- ������ ��� ���Ҹ� ���� ---
void Clear(IntSet *s)
{
	s->num = 0;
}

//--- ���� ���� ---
void Terminate(IntSet *s)
{
	if(s->set != NULL) {
		free(s->set);		//�迭 ����
		s->max = s->num = 0;
	}
}