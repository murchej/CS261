#include <stdlib.h>

#include "ll.h"

// struct node
 //{
 //	int val;
 //	struct node *next;
 //};


struct node* add_two_num (struct node* l1, struct node* l2)
{
		struct node* sum = malloc(sizeof(struct node));
		struct node* cur = sum;

		cur->val = 0;
		

		while(l1 || l2){
			cur->val += l1->val + l2-> val;
			cur->next = malloc(sizeof(struct node));
			cur->next->val = 0;

			if(cur->val >= 10){
				cur->next->val = cur->val / 10;
				cur->val = cur->val % 10;
			}

			if(l1->next && !l2->next){
				l2->next = malloc(sizeof(struct node));
				l2->next->val = 0;
			}
			else if(!l1->next && l2->next){
				l1->next = malloc(sizeof(struct node));
				l1->next->val = 0;
			}

			l1 = l1->next;
			l2 = l2->next;
			cur = cur->next;
		}

		cur->next = NULL;

		return sum;
}


