/*
 ============================================================================
 Name        : main.c
 Author      : Hesham Hafez
 Date        : 11/9/2019
 Description : Linked List Exercises
 ============================================================================
 */


#include "linked.h"


int main(void)
{
	setvbuf(stdout, NULL, _IONBF,0);
	setvbuf(stderr, NULL, _IONBF, 0);
	 node** ptr;
	uint32 uservalue=30;
	uint8 NodePos=0;
	ptr = Create_List();

	InsertToList(ptr,uservalue,NodePos);
	InsertToList(ptr,35,1);
	InsertToList(ptr,40,2);
	InsertToList(ptr,45,2);

	PrintList(ptr);
	ReverseList(ptr);
	PrintList(ptr);
	DeleteNode(ptr,3);
	PrintList(ptr);
	SearchNode(ptr,35);
	SearchNode(ptr,40);
	ListSize(ptr);
	DeleteNode(ptr,2);
	ListSize(ptr);
	PrintList(ptr);
	DeleteList(ptr);


	return 0;
}
