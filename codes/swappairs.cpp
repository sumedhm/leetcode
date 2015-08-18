#include <iostream>
#include <stdlib.h>

using namespace std;

struct ListNode {
 	int val;
	ListNode *next;
};

ListNode* createList(int vals[], int n){
	int i=0;
	ListNode* head;
	ListNode* temp;
	head = (ListNode*) malloc(sizeof(ListNode));
	head->val = vals[i];
	head->next = NULL;
	temp = head;
	i++;
	while(i<n){
		temp->next = (ListNode*) malloc(sizeof(ListNode));
		temp = temp->next;
		temp->val = vals[i];
		temp->next = NULL;
		i++;
	}
	return head;
}

ListNode* swapPairs(ListNode* head) {
	if(head==NULL) return NULL;
	ListNode *temp1, *temp2, *temp3;
	temp1 = head;
	temp2 = head->next;
	if(temp2!=NULL) head = temp2;
	else return head;
	temp1->next = temp2->next;
	temp2->next = temp1;
	temp2 = temp1->next;
	if(temp2==NULL) temp3 = NULL;
	else temp3 = temp2->next;
	while(temp3!=NULL){
		temp1->next = temp3;
		temp2->next = temp3->next;
		temp3->next = temp2;
		temp1 = temp2;
		temp2 = temp2->next;
		if(temp2==NULL) temp3 = NULL;
		else temp3 = temp2->next;
	}
	return head;        
}

int main(){

	ListNode* head;
	int arr[] = {1,2,3,4};
	head = createList(arr, 4);
	head = swapPairs(head);
	ListNode* temp = head;
	while(temp!=NULL){
		cout << temp->val << "->";
		temp = temp->next;
	}
	cout << "NULL" << endl;
	return 0;
}