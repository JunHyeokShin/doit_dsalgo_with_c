int Search2(const IntQueue *q, int x)
{
	int i;

	for(i = 0; i < q->num; i++) {
		if(q->que[(i + q->front) % q->max] == x)
			return i;
	}
	return -1;
}