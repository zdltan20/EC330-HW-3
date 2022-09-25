#include "ListNode.h"
#include <iostream>
#include <algorithm>

using namespace std;
//Leanorine Lorenzana-Garcia BU-ID: U70358223
//Zachary Tan BU-ID: U71790150

DListNode* twowayBubble(DListNode* head) {
	
	//Variable Declaration
	bool direction = false, isSorted = false;
	//direction sets whether it is iterating through the left or right
	//false = to the right, true = to the left
	//isSorted checks whether the linked list is sorted
	
	struct DListNode* ptr1;
	ptr1 = head; //set ptr1 to head
	
	do {
		isSorted = true; //set isSorted to true in case while loop did not sort
		if(!direction) { //if going to the right
			while(ptr1->next != NULL) { //while not at the end
				if(ptr1->val > ptr1->next->val) { //if left node is greater than right node
					ptr1->val = ptr1->val + ptr1->next->val;
					ptr1->next->val = ptr1->val - ptr1->next->val;
					ptr1->val = ptr1->val - ptr1->next->val;
					isSorted = false; //Linked list was sorted to set to false
				}
				ptr1 = ptr1->next; //go to next node
			}
			direction = true; //change direction
		} else {
			while(ptr1->prev != NULL) {
				if(ptr1->val < ptr1->prev->val) { //if right node is less than left node
					ptr1->val = ptr1->val + ptr1->prev->val;
					ptr1->prev->val = ptr1->val - ptr1->prev->val;
					ptr1->val = ptr1->val - ptr1->prev->val;
					isSorted = false; 
				}
				ptr1 = ptr1->prev; //go to previous node
			}
			direction = false;
		}
	} while (!isSorted); //do while loop to check at least once

	return head; // don't forget to change this
}