/*
Given two SORTED Circular Linked Lists ,
Write a function to merge those two linked lists .
The First Linked List head should point to the final merged linked list .
The Final merged linked list should also be in SORTED order and a Circular Linked List.
You need to return the Length of Final SLL.

*********
The First linked list head should now point to the Final sorted(Ascending) Linked list First Node
*********
Ex : A: 0->3->5->10->20 (and 20 now pointing back to 0,instead of Null )
B: 1->2->6->11->21->50->70 (70 Pointing back to 1).

The Final Linked List is A:0->1->2->3->5->6->10->11->20->21->50->70 .

Note : Dont use Malloc or create any new nodes ,Only pointers need to be interchanged,
You can use temp pointers although.
Note : The Final Linked List should be  also be a circular Linked List where Last node is
pointing towards the first node.
Note : Return -1 for Invalid Inputs like NULL;

Input : head1 and head2 are Addresses of Two Circular Linked Lists heads .
Output :Return Length of New SLL .Modify the head1 value, such that it now points to 
Merged Sorted Circular SLL .

Difficulty : Medium
*/
#include <stdlib.h>
#include <stdio.h>

struct node{
	int data;
	struct node *next;
};

int len_ll(struct node *head){
	struct node *temp;
	int count = 0, strt;
	temp = head;
	strt = temp->data;
	temp = temp->next;
	count++;
	while (temp->data != strt){
		count++;
		temp = temp->next;
	}
	return count;
}


int merge_circularlists(struct node **head1, struct node **head2){
	//Returns Length of merged Sorted circular SLL and also points *head1 to final SLL .
	int strt1, strt2, flag1 = 1, flag2 = 1;
	int count = 0;
	struct node *temp1, *temp2, *res, *tempres;
	if ((head1 == NULL && head2 == NULL) || (*head1 == NULL && *head2 == NULL))
		return -1;
	if (*head2 == NULL)
		return len_ll(*head1);
	if (*head1 == NULL){
		head1 = head2;
		return len_ll(*head1);
	}
	temp1 = *head1;
	temp2 = *head2;
	strt1 = temp1->data;
	strt2 = temp2->data;
	if (strt1 < strt2){
		res = temp1;
		temp1 = temp1->next;
		flag1 = 0;
	}
	else{
		res = temp2;
		temp2 = temp2->next;
		flag2 = 0;
	}
	count++;
	tempres = res;
	do{
		if (temp1->data < temp2->data){
			res->next = temp1;
			res = res->next;
			temp1 = temp1->next;
			flag1 = 0;
		}
		else{
			res->next = temp2;
			temp2 = temp2->next;
			res = res->next;
			flag2 = 0;
		}
		count++;
	} while (temp1->data <temp1->next->data &&temp2->data <temp2->next->data);
	if (temp1->data < temp2->data){
		res->next = temp1;
		temp1 = temp1->next;
		res = res->next;
		count++;
		flag1 = 0;
	}
	else{
		res->next = temp2;
		temp2 = temp2->next;
		res = res->next;
		count++;
		flag2 = 0;
	}
	if (temp1->data != strt1 || flag1){
		while (temp1->data != strt1||flag1){
			res->next = temp1;
			temp1 = temp1->next;
			res = res->next;
			count++;
			flag1 = 0;
		}
	}
	if (temp2->data != strt2 || flag2){
		while (temp2->data != strt2 || flag2){
			res->next = temp2;
			temp2 = temp2->next;
			res = res->next;
			count++;
			flag2 = 0;
		}
	}
	res->next = *head1;
	*head1 = tempres;
	return count;
}