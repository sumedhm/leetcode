#include <iostream>
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

ListNode* rotateRight(ListNode* head, int k) {
		if(k==0) return head;
		if(head==NULL) return head;
        ListNode *temp1, *temp2, *temp;
        temp1 = temp2 = temp = head;
        int i = 0, len = 0;
        while(temp!=NULL){
        	temp = temp->next;
        	len++;
        }
        if(k>=len) k = k % len;
        while(temp1->next!=NULL && i<k){
        	temp1 = temp1->next;
        	i++;
        }
        if(temp1==temp2) return head;
        while(temp1->next!=NULL){
        	temp1 = temp1->next;
        	temp2 = temp2->next;
        }
        temp = temp2->next;
        temp1->next = head;
        temp2->next = NULL;
        return temp;
}

int main(){
	int arr[] = {1,2};
	ListNode *head;
	head = createList(arr, 2);
	head = rotateRight(head, 1);
	ListNode* temp = head;
	while(temp!=NULL){
		cout << temp->val << "->";
		temp = temp->next;
	}
	cout << "NULL" << endl;
	return 0;
}