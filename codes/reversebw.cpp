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

ListNode* reverseBetween(ListNode* head, int m, int n){
	int i=1;
	bool fin = false;
	ListNode *tmp = head;
	ListNode *prev, *prev1, *next, *head1=tmp;
	while(i<m){
		if(tmp==NULL){
			fin = true;
			break;
		}
		head1 = tmp;
		tmp = tmp->next;
		i++;
	}
	if(fin || tmp->next==NULL) return head;
	if(m==1){
		head1 = head;
	} else {		
		prev1 = head1;
		head1 = head1->next;
	}
	prev = head1;
	tmp = tmp->next;
	i++;
	next = tmp->next;
	while(i<=n){
		tmp->next = prev;
		prev = tmp;
		tmp = next;
		if(next==NULL) break;
		next = next->next;
		i++;
	}
	if(m==1){
		head = prev;
	} else {		
		prev1->next = prev;
	}
	head1->next = tmp;
	return head;
}

int main(){	
	ListNode *head, *temp;
	int arr[] = {1,2,3,4,6};
	head = createList(arr, 5);
	head = reverseBetween(head,1,5);
	while(head!=NULL){
		temp = head;
		cout << head->val << "->";
		head = head->next;
		free(temp);
	}
	cout << "NULL" << endl;
	return 0;
}