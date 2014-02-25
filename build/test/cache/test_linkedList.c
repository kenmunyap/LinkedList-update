#include "unity.h"
#include "LinkedList.h"




void setUp(){}

void tearDown(){}



void test_createLinkedList_should_return_initialized_LinkedList_object(){

 LinkedList *list;



 list = createLinkedList();

 if ((((list)) != ((void *)0))) {} else {UnityFail( (" Expected Non-NULL"), (_U_UINT)(_U_UINT)(_U_UINT)13);;};

 if ((((list->head)) == ((void *)0))) {} else {UnityFail( (" Expected NULL"), (_U_UINT)(_U_UINT)(_U_UINT)14);;};

 if ((((list->tail)) == ((void *)0))) {} else {UnityFail( (" Expected NULL"), (_U_UINT)(_U_UINT)(_U_UINT)15);;};

 UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((list->length)), (((void *)0)), (_U_UINT)16, UNITY_DISPLAY_STYLE_INT);

}









void test_list_Add_should_add_first_new_element_properly(){





 LinkedList *list;

 list = createLinkedList();



 Element arrayElement[] = {{.next = ((void *)0), .data = 1}};





 list->length = 0;

 list_Add(list, arrayElement);

 UnityAssertEqualNumber((_U_SINT)((list->head)), (_U_SINT)((list->tail)), (((void *)0)), (_U_UINT)33, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((list->head->data)), (((void *)0)), (_U_UINT)34, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((list->tail->data)), (((void *)0)), (_U_UINT)35, UNITY_DISPLAY_STYLE_INT);

 if ((((arrayElement[0].next)) == ((void *)0))) {} else {UnityFail( (" Expected NULL"), (_U_UINT)(_U_UINT)(_U_UINT)36);;};

 UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((list->length)), (((void *)0)), (_U_UINT)37, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)(_UP)((&arrayElement[0])), (_U_SINT)(_UP)((&arrayElement[0])), (((void *)0)), (_U_UINT)38, UNITY_DISPLAY_STYLE_HEX32);

}



void test_list_Add_should_add_second_new_element_properly(){





 LinkedList *list;

 list = createLinkedList();



 Element arrayElement[] = {{.next = &arrayElement[0] , .data = 3},

         {arrayElement[1].next = ((void *)0), arrayElement[1].data = 2}

         };





 list->length = 1;

 list->head = &arrayElement[0];

 list->tail = &arrayElement[(list->length)-1];



 list_Add(list, arrayElement);

 if (((list->head) != (list->tail))) {} else {UnityFail( (" Expected Not-Equal"), (_U_UINT)(_U_UINT)57);;};

 UnityAssertEqualNumber((_U_SINT)((3)), (_U_SINT)((list->head->data)), (((void *)0)), (_U_UINT)58, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((2)), (_U_SINT)((list->tail->data)), (((void *)0)), (_U_UINT)59, UNITY_DISPLAY_STYLE_INT);

 if ((((arrayElement[1].next)) == ((void *)0))) {} else {UnityFail( (" Expected NULL"), (_U_UINT)(_U_UINT)(_U_UINT)60);;};

 UnityAssertEqualNumber((_U_SINT)((2)), (_U_SINT)((list->length)), (((void *)0)), (_U_UINT)61, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)(_UP)((&arrayElement[1])), (_U_SINT)(_UP)((arrayElement[0].next)), (((void *)0)), (_U_UINT)62, UNITY_DISPLAY_STYLE_HEX32);

}



void test_list_Add_should_add_third_new_element_properly(){





 LinkedList *list;

 list = createLinkedList();



 Element arrayElement[] = {{.next = &arrayElement[0] , .data = 3},

         {arrayElement[1].next = &arrayElement[2], arrayElement[1].data = 2},

         {arrayElement[2].next = ((void *)0), arrayElement[2].data = 1}

         };





 list->length = 2;

 list->head = &arrayElement[0];

 list->tail = &arrayElement[(list->length)-1];



 list_Add(list, arrayElement);

 if (((list->head) != (list->tail))) {} else {UnityFail( (" Expected Not-Equal"), (_U_UINT)(_U_UINT)82);;};

 UnityAssertEqualNumber((_U_SINT)((3)), (_U_SINT)((list->head->data)), (((void *)0)), (_U_UINT)83, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((list->tail->data)), (((void *)0)), (_U_UINT)84, UNITY_DISPLAY_STYLE_INT);

 if ((((arrayElement[2].next)) == ((void *)0))) {} else {UnityFail( (" Expected NULL"), (_U_UINT)(_U_UINT)(_U_UINT)85);;};

 UnityAssertEqualNumber((_U_SINT)((3)), (_U_SINT)((list->length)), (((void *)0)), (_U_UINT)86, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)(_UP)((&arrayElement[2])), (_U_SINT)(_UP)((arrayElement[1].next)), (((void *)0)), (_U_UINT)87, UNITY_DISPLAY_STYLE_HEX32);

}
