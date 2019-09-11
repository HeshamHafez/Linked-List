/*
 ============================================================================
 Name        : linked.c
 Author      : Hesham Hafez
 Date        : 11/9/2019
 Description : Linked List Exercises
 ============================================================================
 */

/*******************************************************************************
 *                       	Included Libraries                                 *
 *******************************************************************************/
#include "linked.h"


static volatile uint8 Max_position = 0;

/*******************************************************************************
 *                      Functions Definitions                                   *
 *******************************************************************************/

/*******************************************************************************
 * Function Name:	Create_List
 *
 * Description: 	Create Linked List
 *
 * Inputs:			NULL
 *
 * Return:			pointer to pointer to struct
 *******************************************************************************/
node** Create_List(void)
{
	node** head;
	head = (node**)malloc(sizeof(node*));
	if(head != NULL)
	{
		*head = NULL;
		return head;
	}
	else
	{
		printf("No allocation \n");
		exit(1);
	}
	/*
	node ** head = (node **) malloc(sizeof(node*));
	(*head)->next = NULL;
	return head;
	 */
}

/*******************************************************************************
 * Function Name:	InsertToList
 *
 * Description: 	Insert Node to list
 *
 * Inputs:			*pointer to pointer to struct "Head of Linked List"
 * 					*Data of node
 * 					*position of the nodes
 *
 * Return:		    Status
 *******************************************************************************/
EnmListStatus_t InsertToList(node** list, uint32 data, uint8 position)
{
	EnmListStatus_t status;
	node *current = NULL;
	sint8 i;
	node * link = (node*) malloc(sizeof(node));
	if(*list==NULL)
	{
		if((position == 0))
		{
			link->data = data;
			link->next = NULL;
			*list = link;
			Max_position++;
			status = DONE;
		}
		else
		{
			status = NOT_FOUND;
		}
	}
	else
	{
		if(Max_position >= position)
		{
			current = *list;
			for(i = 1; i != position;i++)
			{

				// loop until reach the last node in the old list
				if(current->next != NULL)
				{
					current = current->next;
				}
			}
			// insert the data to the new node and make the next point to null
			link->data = data;
			link->next =current->next;
			current->next = link;
			Max_position++;
			status = DONE;
		}
		else
		{
			status = NOT_FOUND;
		}
	}
	return status;
}


void PrintList(node ** list)
{
	node *ptr = *list;
	printf("[head] =>");

	/*start looping from the head until the last node*/
	while(ptr != NULL)
	{
		printf(" %d =>",ptr->data);
		ptr = ptr->next;
	}

	printf(" [null]\n");
}

void DeleteList(node ** list)
{
	node *Delete_Node = NULL;
	node *current = *list;

	/*start looping from the head until the last node*/
	while(current != NULL)
	{
		Delete_Node = current;
		current = current->next;
		free(Delete_Node);
	}
	printf("Linked List is deleted\n");
}

void DeleteNode(node ** list,uint8 position)
{
	node* current = *list;
	node* DeleteNode = NULL;
	int i,flag = 1;

	if(position == 0)
	{
		*list = current->next;
		free(current);
	}
	/* Searching for index node */
	for(i=0;i<position-1;i++){
		if(current->next == NULL)
		{
			printf("5\n");
			flag = -1;
			return;
		}
		else
		{
			printf("2\n");
			current = current->next;
		}
	}

	if(flag == 1)
	{
		printf("1\n");
		/* saving pointer to free it */
		DeleteNode = current->next;

		/* Pre-deleted node point to the post_deleted node */
		current->next = current->next->next;

		/* free deleted node */
		free(DeleteNode);
	}
}
//	node *DeleteNode;
//	node *PreNode=*list;
//	if(Max_position>=position)
//	{
//		for(uint8 i=;i<(position-1);i++)
//		{
//
//			PreNode->next=PreNode->next->next;
//		}
//		DeleteNode=PreNode->next;
//		PreNode->next=PreNode->next->next;
//		free(DeleteNode);
//		printf("Node is Deleted\n");
//	}
//	else
//	{
//		printf("Node is not Found\n");
//	}
//}
//	node *Delete_Node = NULL;
//	node *prev = *list;
//	node *current = prev->next;
//	/*Delete Nodes from the head until the last node*/
//	if(Max_position>=position)
//	{
//		for(uint8 i=1;i!=position;i++)
//		{
//			prev = prev->next;
//			current = current->next;
//		}
//		Delete_Node = prev;
//		current = current->next;
//		prev = prev->next;
//		free(Delete_Node);


void SearchNode(node** list, uint32 data)
{
	uint8 pos = 0;
	node *current = NULL;
	if(*list==NULL)
	{
		printf("Linked List is empty");
		return;
	}

	// start checking from the first node
	current = *list;
	while(current != NULL)
	{
		if(current->data == data)
		{
			printf("%d found at position %d\n", data, pos);
			return;
		}
		current = current->next;
		pos++;
	}
	// item not found in the list
	printf("%d does not exist in the list\n", data);
}

void ListSize(node** list)
{
	uint8 size = 0;
	node *current = NULL;
	// check if the linked list is empty
	if(*list==NULL)
	{
		printf("List size : %d\n", size);
		return;
	}
	// list is not empty contains one node at least
	current = *list;
	size = 1;
	while(current->next != NULL)
	{
		current = current->next;
		size++;
	}
	printf("List size : %d\n", size);
}


