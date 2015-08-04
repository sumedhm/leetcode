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

ListNode* removeNthFromEnd(ListNode* head, int n) {
		ListNode* cur=head;
		ListNode* ref=head;
		for(int i=0;i<n;i++){
			ref=ref->next;
		}
		ListNode *prev = NULL;
		while(ref!=NULL){
			ref = ref->next;
			prev = cur;
			cur = cur->next;
		}
		//cout << cur->val << endl;
		if(prev==NULL){
			cur = head;
			head = head->next;
			free(cur);
		} else if(cur!=NULL){
			prev->next = cur->next;
			free(cur);
		}
        return head;
}

int main(){
	ListNode* head;
	int arr[] = {1,1};
	head = createList(arr,1);
	head = removeNthFromEnd(head, 1);
	ListNode* temp = head;
	while(temp!=NULL){
		cout << temp->val << "->";
		temp = temp->next;
	}
	cout << "NULL" << endl;
	return 0;
}