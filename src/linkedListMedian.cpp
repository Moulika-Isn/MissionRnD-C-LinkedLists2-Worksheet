/*
OVERVIEW: Given a single sorted linked list find the median element of the single linked list.
Median is the middle element.
E.g.: 1->2->3->4->5, output is 3.

INPUTS: A sorted linked list.

OUTPUT: Return median of the linked list elements.

ERROR CASES: Return -1 for error cases.

NOTES: If length is even, return average of middle pair of numbers.
*/

#include <stdio.h>

struct node {
	int num;
	struct node *next;
};

int linkedListMedian(struct node *head) {
	if (head==NULL)
		return -1;
	int med = 0, i = 0, n, flag = 0;
	struct node *ptr, *h;
	ptr = h = head;
	while (ptr != NULL)
	{
		i++;
		ptr = ptr->next;
	}
	if (i % 2 == 0)
		flag = 1;
	for (n = 0; n < i; n++)
	{
		if ((n == i / 2) && (flag == 0))
			return h->num;
		if ((n == i/2-1) && (flag == 1))
		{
			med = h->num + h->next->num;
			return med/2;
		}
		h = h->next;
	}
	return 0;
}
