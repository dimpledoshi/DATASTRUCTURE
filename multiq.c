/*Write a C program to implement multiple linked queues (at least 5) and perform the following operations on them-
(i) Add an item in ith queue (ii) Delete an item from ith queue (iii) Display ith queue*/

#include<stdio.h>
#include<stdlib.h>
#define MAX_QUE 5
int n=1;
#define MALLOC(temp,n,NODE) temp=((NODE)malloc(n* sizeof(NODE)))
struct node
 {
  int info;
  struct node *link;
 };
typedef struct node* NODE;
void display(NODE first)
 {
  NODE temp;
  if(first==NULL)
   {
   printf("LIST IS EMPTY \n"); return;
   }
  printf("The contents of the linked list \n");
  temp=first;
  while(temp!=NULL)
  {
    printf("%d",temp->info);
    temp=temp->link;
  }
  printf("\n");
 }
NODE deletefront(NODE first)
 {
  NODE temp;
  if(first==NULL)
   { printf("List is empty , cannot delete"); return first;}
  temp=first;
  temp=temp->link;
  printf("Item deleted %d",first->info);
  free(first);
  return temp;
 }
NODE insertrear(int item,NODE first)
 {
  NODE temp,cur;
  MALLOC(temp,1,NODE);
  temp->info=item;
  temp->link=NULL;
  if(first==NULL)
  return temp;
  cur=first;
  while(cur->link!=NULL)
    cur=cur->link;
  cur->link=temp;
  return first;
 }
int main()
 {
  NODE a[MAX_QUE];
  int choice,item,i;
  for(i=0;i<MAX_QUE;i++)
  { a[i]=NULL;}
  for(;;)
   {
    printf("Enter queue number: 0,1,2,3,4:\n");
    scanf("%d",&i);
    printf("1. Push an item in ith  queue\n 2. Pop an item from ith queue\n 3. Display ith  queue\n 4.Exit\n");
    printf("Enter your choice\n");
    scanf("%d",&choice);
    switch(choice)
    {
     case 1: printf("\nEnter item to be inserted\n");
             scanf("%d",&item);
             a[i]=insertrear(item,a[i]);
             break;
     case 2: a[i]=deletefront(a[i]);
             break;
     case 3: display(a[i]);
             break;
     default: exit(0);
    }
  }
  return 0;
 }
