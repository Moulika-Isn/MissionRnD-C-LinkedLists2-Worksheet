/*
OVERVIEW: Given a single linked list insert a new node at every Kth node with value K.
E.g.: 1->2->3->4->5, k = 2, 1->2->2->3->4->2->5

INPUTS: A linked list and Value of K.

OUTPUT: Insert a new node at every Kth node with value K.

ERROR CASES: Return NULL for error cases.

NOTES:
*/

#include <stdio.h>
#include <malloc.h>

struct node {
	int num;
	struct node *next;
};

struct node * insertAtEveryKthNode(struct node *head, int K) {
	if ((head == NULL) || (K<=0))
		return NULL;
	struct node *ptr, *temp, *p;
	int i = 0;
	ptr = p = head;
	while (ptr != NULL)
	{
		i++;
		ptr = ptr->next;
	}
	if (K > i)
		return head;
	if (K == 1)
	{
		while (p != NULL)
		{
			temp = (node*)malloc(sizeof(node*));
			temp->num = K;
			temp->next = NULL;
			temp->next = p->next;
			p->next = temp;
			p = p->next->next;
		}
	}
	else
	{
		i = 0;
		while (p->next != NULL)
		{
			if (i == K - 1)
			{
				temp = (node*)malloc(sizeof(node*));
				temp->num = K;
				temp->next = NULL;
				temp->next = p->next;
				p->next = temp;
				p = p->next;
				i = -1;
			}
			else
			{
				i++;
				p = p->next;
			}
		}
	}
	return head;
}
