#include "List.h"


void Get_Max(ListNode* pheader, int* maxi)
{
	ListNode* begin = pheader->next, *end = pheader->prev;
	int maxb = begin->data, maxe = end->data;
	int i = 0, j = 999;
	int indexb = 0, indexe = 999;
	for (; begin != end; begin = begin->next, end = end->prev)
	{
		if ((begin->data) > maxb)
		{
			maxb = begin->data;
			indexb = i;
		}
		if ((end->data) > maxe)
		{
			maxe = end->data;
			indexe = j;
		}
		++i;
		--j;
	}
	*maxi = maxb < maxe ? indexe : indexb;
}
int main()
{
	ListNode* pheader = ListInit();

	for (int i = 0; i < 1000; ++i)
	{
		ListPushFront(pheader, i + 1);
	}
	for_each(pheader);

	int ret = ListSize(pheader);
	printf("%d\n", ret);

	int maxi = 0;
	Get_Max(pheader, &maxi);
	printf("%d\n", maxi);

	ListPopBack(pheader);
	for_each(pheader);

	ListDestory(pheader);
	return 0;
}