/*
OVERVIEW: Merge two sorted linked lists.
E.g.: 1->3->5 and 2->4, output is 1->2->3->4->5.

INPUTS: Two sorted linked lists.

OUTPUT: Return merged sorted linked list.

ERROR CASES: Return NULL for error cases.

NOTES:
*/

#include <malloc.h>
#include <stdio.h>

struct node {
	int num;
	struct node *next;
};

int length(struct node* head)
{
	int i = 0;
	while (head != NULL)
	{
		i++;
		head = head->next;
	}
	return i;
}
void insert(node **head, int ele)
{
	node *p, *temp;
	temp = (node*)malloc(sizeof(node*));
	temp->num = ele;
	temp->next = NULL;
	if (head == NULL)
		*head = temp;
	else
	{
		p = *head;
		p->next = temp;
	}
}
struct node * merge2LinkedLists(struct node *head1, struct node *head2) {
	if ((head1 == NULL) && (head2 == NULL))
		return NULL;
	if ((head1 == NULL) && (head2 != NULL))
		return head2;
	else if ((head1 != NULL) && (head2 == NULL))
		return head1;
	struct node *head, *p, *q, *r;
	int i, j = 0, k = 0, m, n;
	head = (node*)malloc(sizeof(node*));
	p = head1;
	q = head2;
	r = head;
	m = length(p);
	n = length(q);
	for (i = 0; i < m + n;)
	{
		if ((j < m) && (k < n))
		{
			if (p->num <= q->num)
			{
				insert(&r, p->num);
				r = r->next;
				p = p->next;
				i++; j++;
			}
			else
			{
				insert(&r, q->num);
				r = r->next;
				q = q->next;
				i++; k++;
			}
		}
		else if (j == m)
		{
			for (; i < m + n;)
			{
				insert(&r, q->num);
				r = r->next;
				i++;
				q = q->next;
			}
		}
		else
		{
			for (; i < m + n;)
			{
				insert(&r, p->num);
				r = r->next;
				p = p->next;
				i++;
			}
		}
	}
	head = head->next;
	return head;
}