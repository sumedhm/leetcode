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

void insert(vector<ListNode*> lists, vector<int>& heap, int index){
	int i = heap.size();
	if(lists[index]==NULL) return;
	heap.push_back(index);
	while(i>0){
		if(lists[heap[(i-1)/2]]->val > lists[heap[i]]->val){
			int temp = heap[i];
			heap[i] = heap[(i-1)/2];
			heap[(i-1)/2] = temp;
			i = (i-1)/2;
		} else {
			break;
		}
	}
	return;
}

/*Return index of node*/
int extract_min(vector<ListNode*> lists, vector<int>& heap){
	if(heap.size()==0) return -1;
	int temp;
	if(heap.size()==1){
		temp = heap[0];
		heap.clear();
	} else {
		int i = heap.size()-1;
		temp = heap[0];
		heap[0] = heap[i];
		heap.erase(heap.begin()+i);
		int j = 0, temp2;
		while(2*j+1<i){
			if(2*j+2<i){
				if(lists[heap[j]]->val > lists[heap[2*j+1]]->val && lists[heap[j]]->val > lists[heap[2*j+2]]->val){
					int index;
					if(lists[heap[2*j+1]]->val < lists[heap[2*j+2]]->val){
						index = 2*j+1;
					} else {
						index = 2*j+2;
					}
					temp2 = heap[index];
					heap[index] = heap[j];
					heap[j] = temp2;
					j = index;
				} else if(lists[heap[j]]->val > lists[heap[2*j+1]]->val){
					temp2 = heap[2*j+1];
					heap[2*j+1] = heap[j];
					heap[j] = temp2;
					j = 2*j+1;
				} else if(lists[heap[j]]->val > lists[heap[2*j+2]]->val){
					temp2 = heap[2*j+2];
					heap[2*j+2] = heap[j];
					heap[j] = temp2;
					j = 2*j+2;
				} else {
					break;
				}
			} else {
				if(lists[heap[j]]->val > lists[heap[2*j+1]]->val){
					temp2 = heap[2*j+1];
					heap[2*j+1] = heap[j];
					heap[j] = temp2;
				}
				break;
			}
		}
	}
	return temp;
}

ListNode* mergeKLists(vector<ListNode*>& lists) {
	if(lists.size()==0) return NULL;
	vector<int> heap;
	ListNode* head;
	ListNode* temp;
	int size = lists.size(), n = 0, index;
	for(int i=0;i<size;i++){		
		if(lists[i]!=NULL){
			insert(lists, heap, i);
		} else {
			n++;
		}
	}
	if(n==size) return NULL;
	index = extract_min(lists, heap);
	head = lists[index];
	lists[index] = lists[index]->next;
	insert(lists, heap, index);
	head->next = NULL;
	temp = head;
	while(heap.size()>0){
		index = extract_min(lists, heap);
		temp->next = lists[index];
		temp = temp->next;
		lists[index] = lists[index]->next;
		temp->next = NULL;
		insert(lists, heap, index);
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