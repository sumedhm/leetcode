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

ListNode* reverseKGroup(ListNode* head, int k) {
	if(head==NULL) return NULL;
	if(k==1) return head;
	ListNode *temp1, *temp2, *temp3, *_head, *_tail, *next;
	bool head_set = false, finished = false;
	_head = _tail = head;
	while(!finished){
		for(int i=1;i<k;i++){
			if(_tail==NULL){
				finished = true;
				break;
			}
			_tail = _tail->next;
		}
		if(_tail){			
			if(!head_set){
				head = _tail;
				temp1 = NULL;
				head_set = true;
			} else 
				temp1->next = _tail;
			next = _tail->next;
			temp2 = _head;
			while(temp1!=_tail){
				temp3 = temp2->next;
				temp2->next = temp1;
				temp1 = temp2;
				temp2 = temp3;
			}
			_head->next = next;
			temp1 = _head;
			_head = _tail = next;
		}
	}
	return head;
}

int main(){
	ListNode* head;
	int arr[] = {1};
	head = createList(arr, 1);
	head = reverseKGroup(head, 1);
	ListNode* temp = head;
	while(temp!=NULL){
		cout << temp->val << "->";
		temp = temp->next;
	}
	cout << "NULL" << endl;
	return 0;
}