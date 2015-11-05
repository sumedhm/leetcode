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

ListNode* partition(ListNode* head, int x) {
		if(head==NULL) return head;
        ListNode *s=NULL,*s_t=NULL,*g=NULL,*g_t=NULL,*tmp; //heads for lists with smaller, equal and greater elements;
        while(head!=NULL){
        	tmp = head->next;
        	if(head->val >= x){
        		if(g==NULL){
        			g = g_t = head;
        			g->next = NULL;
        		} else {
        			g_t->next = head;
        			g_t = g_t->next;
        			g_t->next = NULL;
        		}
        	} else{
        		if(s==NULL){
        			s = s_t = head;
        			s->next = NULL;
        		} else {
        			s_t->next = head;
        			s_t = s_t->next;
        			s_t->next = NULL;
        		}
        	}
        	head = tmp;
        }
        if(s!=NULL){
        	s_t->next = g;
        	head = s;
        } else head = g;
        return head;
}

int main(){
	int arr[] = {1,4,3,2,5,2};
	ListNode *head = createList(arr,6);
	head = partition(head,3);
	while(head!=NULL){
		cout << head->val << " ";
		head = head->next;
	}
	cout << endl;
	return 0;
}

