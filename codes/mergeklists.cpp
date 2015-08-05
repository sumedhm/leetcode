#include <iostream>
#include <vector>
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

ListNode* mergeKLists(vector<ListNode*>& lists) {
	if(lists.size()==0) return NULL;
	ListNode* head;
	ListNode* temp;
	int size = lists.size(), n = 0, min, index = -1;
	for(int i=0;i<size;i++){		
		if(lists[i]!=NULL){
			if(index==-1){
				min = lists[i]->val;
				index = i;
			}
			if(lists[i]->val < min){
				min = lists[i]->val;
				index = i;
			}
		} else {
			n++;
		}
	}
	if(n==size) return NULL;
	head = lists[index];
	lists[index] = lists[index]->next;
	head->next = NULL;
	temp = head;
	index = -1;
	while(true){
		n = 0;
		index = -1;
		for(int i=0;i<size;i++){
			if(lists[i]!=NULL){
				if(index==-1){
					min = lists[i]->val;
					index = i;
				}
				if(lists[i]->val < min){
					min = lists[i]->val;
					index = i;
				}
			} else {
				n++;
			}
		}
		if(n<size){
			temp->next = lists[index];
			temp = temp->next;
			lists[index] = lists[index]->next;
			temp->next = NULL;
			index=-1;
		} else break;
	}
	return head;
}

int main(){
	ListNode* head1;
	ListNode* head2;
	int arr1[] = {1,3,4,6};
	int arr2[] = {2,5,7,8};
	head1 = createList(arr1, 4);
	head2 = createList(arr2, 4);
	vector<ListNode*> lists;
	lists.push_back(head1);
	lists.push_back(head2);
	ListNode *head = mergeKLists(lists);
	ListNode* temp = head;
	while(temp!=NULL){
		cout << temp->val << "->";
		temp = temp->next;
	}
	cout << "NULL" << endl;
	return 0;
}