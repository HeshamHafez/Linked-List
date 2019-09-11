/*
 ============================================================================
 Name        : linked.h
 Author      : Hesham Hafez
 Date        : 11/9/2019
 Description : Linked List Exercises
 ============================================================================
 */

#ifndef LINKED_H_
#define LINKED_H_

/*******************************************************************************
 *                       	Included Libraries                                 *
 *******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include "std_types.h"

/*******************************************************************************
 *                         Linked List Structures                              *
 *******************************************************************************/
typedef struct ST_Node
{
	uint32 data;
	struct ST_Node * next;
}node;

/*******************************************************************************
 *                         Enum Declaration                                   *
 *******************************************************************************/
typedef enum
{
	DONE,
	NOT_FOUND
}EnmListStatus_t;

/*******************************************************************************
 *                      Functions Prototypes                                   *
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
node** Create_List(void);

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
EnmListStatus_t InsertToList(node** list, uint32 data, uint8 position);


/*******************************************************************************
 * Function Name:	PrintList
 *
 * Description: 	Print List
 *
 * Inputs:			pointer to pointer to struct "Head of Linked List"
 *
 * Return:		    NULL
 *******************************************************************************/
void PrintList(node ** list);

/*******************************************************************************
 * Function Name:	DeleteList
 *
 * Description: 	Delete List
 *
 * Inputs:			pointer to pointer to struct "Head of Linked List"
 *
 * Return:		    NULL
 *******************************************************************************/
void DeleteList(node ** list);

/*******************************************************************************
 * Function Name:	DeleteNode
 *
 * Description: 	Delete Node from list
 *
 * Inputs:			*pointer to pointer to struct "Head of Linked List"
 * 					*position of the nodes
 *
 * Return:		    NULL
 *******************************************************************************/
void DeleteNode(node ** list,uint8 position);

/*******************************************************************************
 * Function Name:	SearchNode
 *
 * Description: 	Search for a Node in list
 *
 * Inputs:			*pointer to pointer to struct "Head of Linked List"
 * 					*Data of nodes
 *
 * Return:		    NULL
 *******************************************************************************/
void SearchNode(node** list, uint32 data);

/*******************************************************************************
 * Function Name:	ListSize
 *
 * Description: 	Print the Size of the Linked List
 *
 * Inputs:			*pointer to pointer to struct "Head of Linked List"
 * 					*Data of nodes
 *
 * Return:		    NULL
 *******************************************************************************/
void ListSize(node** list);


#endif /* LINKED_H_ */
