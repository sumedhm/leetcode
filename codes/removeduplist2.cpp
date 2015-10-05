#include <iostream>
#include <vector>
#include <stdlib.h>
using namespace std;

struct ListNode {
    int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
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

ListNode* deleteDuplicates(ListNode* head) {
	if(head==NULL) return head;
	ListNode* cur = head;
	ListNode* prev = NULL;
	int del = -400;
	while(cur!=NULL){
		if(cur->next==NULL){
			if(cur->val==del){
				if(cur==head) head = NULL;
				else prev->next = cur->next;
				free(cur);
			}
			cur = NULL;
		} else {
			if(cur->val == cur->next->val || cur->val == del){
				del = cur->val;
				if(cur==head) {
					head = head->next;
					free(cur);
					cur = head;
				} else {
					prev->next = cur->next;
					free(cur);
					cur = prev->next;
				}
			} else {
				prev = cur;
				cur = cur->next;
			}
		}
	}
	return head;
}

int main(){
	int n, i=0;
	while(true){
		cin >> n;
		i = 0;
		int arr[n];
		while(i<n) cin >> arr[i++];
		ListNode *head;
		head = createList(arr, n);
		head = deleteDuplicates(head);
		ListNode* temp = head;
		while(temp!=NULL){
			cout << temp->val << "->";
			temp = temp->next;
		}
		cout << "NULL" << endl;
	}
	return 0;
}