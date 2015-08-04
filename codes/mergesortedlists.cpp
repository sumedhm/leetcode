#include <iostream>
#include <stdlib.h>

using namespace std;

struct ListNode{
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

ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
	ListNode* head;
	ListNode* temp;
	if(l1==NULL && l2==NULL) return NULL;
	if(l1!=NULL && l2!=NULL){
		if(l1->val < l2->val){
			head = l1;
			l1 = l1->next;
			head->next = NULL;
		} else {
			head = l2;
			l2 = l2->next;
			head->next = NULL;
		}
	} else if(l2==NULL){
		head = l1;
		l1 = l1->next;
		head->next = NULL;
	} else {
		head = l2;
		l2 = l2->next;
		head->next = NULL;
	}
	temp = head;
	while(l1!=NULL && l2!=NULL){
		if(l1->val < l2->val){
			temp->next = l1;
			l1 = l1->next;
			temp = temp->next;
			temp->next = NULL;
		} else {
			temp->next = l2;
			l2 = l2->next;
			temp = temp->next;
			temp->next = NULL;
		}
	}
	while(l1!=NULL){
		temp->next = l1;
		l1 = l1->next;
		temp = temp->next;
		temp->next = NULL;
	}
	while(l2!=NULL){
		temp->next = l2;
		l2 = l2->next;
		temp = temp->next;
		temp->next = NULL;
	}
	temp->next = NULL;
	return head;        
}

int main(){

	ListNode* head1;
	ListNode* head2;
	int arr1[] = {1,3,4,6};
	int arr2[] = {2,5,7,8};
	head1 = createList(arr1, 4);
	head2 = createList(arr2, 4);
	ListNode *head = mergeTwoLists(head1, head2);
	ListNode* temp = head;
	while(temp!=NULL){
		cout << temp->val << "->";
		temp = temp->next;
	}
	cout << "NULL" << endl;
	return 0;

}