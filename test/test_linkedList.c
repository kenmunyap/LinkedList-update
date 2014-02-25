#include "unity.h"
#include "LinkedList.h"
#include <malloc.h>


void setUp(){}
void tearDown(){}

void test_createLinkedList_should_return_initialized_LinkedList_object(){
	LinkedList *list;

	list = createLinkedList();
	TEST_ASSERT_NOT_NULL(list);
	TEST_ASSERT_NULL(list->head);
	TEST_ASSERT_NULL(list->tail);
	TEST_ASSERT_EQUAL(0,list->length);
}




void test_list_Add_should_add_first_new_element_properly(){


	LinkedList *list;
	list = createLinkedList();
	
	Element arrayElement[] = {{.next = NULL, .data = 1}};
	
	
	list->length = 0;
	list_Add(list, arrayElement);
	TEST_ASSERT_EQUAL(list->head,list->tail);
	TEST_ASSERT_EQUAL(1,list->head->data);
	TEST_ASSERT_EQUAL(1,list->tail->data);
	TEST_ASSERT_NULL(arrayElement[0].next);
	TEST_ASSERT_EQUAL(1,list->length);
	TEST_ASSERT_EQUAL_PTR(&arrayElement[0],&arrayElement[0]);
}

void test_list_Add_should_add_second_new_element_properly(){


	LinkedList *list;
	list = createLinkedList();
	
	Element arrayElement[] = {{.next = &arrayElement[0] , .data = 3},
							  {arrayElement[1].next = NULL, arrayElement[1].data = 2}
							  };
	
	
	list->length = 1;
	list->head = &arrayElement[0];
	list->tail = &arrayElement[(list->length)-1];
	
	list_Add(list, arrayElement);
	TEST_ASSERT_NOT_EQUAL(list->head,list->tail);
	TEST_ASSERT_EQUAL(3,list->head->data);
	TEST_ASSERT_EQUAL(2,list->tail->data);
	TEST_ASSERT_NULL(arrayElement[1].next);
	TEST_ASSERT_EQUAL(2,list->length);
	TEST_ASSERT_EQUAL_PTR(&arrayElement[1],arrayElement[0].next);
}

void test_list_Add_should_add_third_new_element_properly(){


	LinkedList *list;
	list = createLinkedList();
	
	Element arrayElement[] = {{.next = &arrayElement[0] , .data = 3},
							  {arrayElement[1].next = &arrayElement[2], arrayElement[1].data = 2},
							  {arrayElement[2].next = NULL, arrayElement[2].data = 1}
							  };
	
	
	list->length = 2;
	list->head = &arrayElement[0];
	list->tail = &arrayElement[(list->length)-1];
	
	list_Add(list, arrayElement);
	TEST_ASSERT_NOT_EQUAL(list->head,list->tail);
	TEST_ASSERT_EQUAL(3,list->head->data);
	TEST_ASSERT_EQUAL(1,list->tail->data);
	TEST_ASSERT_NULL(arrayElement[2].next);
	TEST_ASSERT_EQUAL(3,list->length);
	TEST_ASSERT_EQUAL_PTR(&arrayElement[2],arrayElement[1].next);
}