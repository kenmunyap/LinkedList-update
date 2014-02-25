#include "LinkedList.h"
#include <stdio.h>
#include <malloc.h>


LinkedList *createLinkedList(){
	LinkedList *list = malloc(sizeof(LinkedList));
	list->head = NULL;
	list->tail = NULL;
	list->length = 0;

	return list;
}

void list_Add(LinkedList *list,Element *element){

	if(list->head ==NULL){
		list->head = list->tail = &element[0];
	
	}
	
	else{
		list->head = &element[0];
		list->tail = &element[(list->length)];
		element[(list->length)-1].next = &element[list->length];
	}
	list->tail->next=NULL;
	
	if(&element[0] == NULL){
		list->length = 0;
	}
	else{
		list->length++;
	}
}

