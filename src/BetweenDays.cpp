/*
Q4: Two dates are given in a 8 node single linked list form,where each node
has one digit only, dates 01-31, months 01-12, year 0000-9999.

Find the number of days in between those two dates .[Exclusive]

Ex : Date1:  0->1->0->1->2->0->0->4 .
     Date2 : 0->5->0->1->2->0->0->4 should return 3 .
As there are 3 days between Jan1st 2004 and Jan 5th 2004.

Ex 2 : Date1 : 3->1->1->2->2->0->1->2.
       Date2 : 0->2->0->1->2->0->1->3 should return 1 .
(There is only one day between 31st Dec 2012 and 2nd  Jan 2013 .)

Note : Consecutive Days and Same Days should return 0;
->Return -1 for NULL Inputs .
->Between Days have to be calculated by not including start and end date .
->The SLL will have 8 Nodes in all cases . Month 9 will be represented as 09.

Difficulty : Hard 
*/
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

struct node{
	int data;
	struct node *next;
};

int count_leap(int m, int y){
	if (m <= 2)
		y--;
	return y / 4 - y / 100 + y / 400;
}

int between_days(struct node *date1head, struct node *date2head){
	if (date1head == NULL || date2head == NULL)
		return -1;
	struct node *temp1, *temp2;
	int months[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	int dd1, dd2, mm1, mm2, yy1, yy2,i;
	long int days1, days2;
	temp1 = date1head;
	temp2 = date2head;
	dd1 = (temp1->data * 10) + (temp1->next->data * 1);
	dd2 = (temp2->data * 10) + (temp2->next->data * 1);
	mm1 = (temp1->next->next->data * 10) + (temp1->next->next->next->data * 1);
	mm2 = (temp2->next->next->data * 10) + (temp2->next->next->next->data * 1);
	yy1 = (temp1->next->next->next->next->data * 1000) + (temp1->next->next->next->next->next->data * 100) + (temp1->next->next->next->next->next->next->data * 10) + (temp1->next->next->next->next->next->next->next->data * 1);
	yy2 = (temp2->next->next->next->next->data * 1000) + (temp2->next->next->next->next->next->data * 100) + (temp2->next->next->next->next->next->next->data * 10) + (temp2->next->next->next->next->next->next->next->data * 1);
	days1 = yy1 * 365 + dd1;
	days2 = yy2 * 365 + dd2;
	for (i = 0; i < mm1; i++)
		days1 += months[i];
	for (i = 0; i < mm2; i++)
		days2 += months[i];
	days1 += count_leap(mm1, yy1);
	days2 += count_leap(mm2, yy2);
	if (days1>days2)
		return days1 - days2 - 1;
	else
		return days2 - days1 - 1;
}