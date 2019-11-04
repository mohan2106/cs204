#include<bits/stdc++.h>
using namespace std;
typedef long long lli;
typedef long li;
#define forz(n) for (long i = 0; i < n; i++)
#define rforz(a,n) for (long i = a; i < n; i++)
#define forlz(n) for (long int i = 0; i < n; i++)
// #define modulo 1e9+7

struct LinkedList{
    int data;
    struct LinkedList *next;
 };

 typedef struct LinkedList *node; 

node createNode(){
    node temp;
    temp = (node)malloc(sizeof(struct LinkedList)); 
    temp->next = NULL;
    return temp;
}

node addNode(node &head, int value){
    node temp,p;
    temp = createNode();
    temp->data = value; 
    if(head == NULL){
        head = temp; 
    }
    else{
        p  = head;
        while(p->next != NULL){
            p = p->next;
        }
        p->next = temp;
    }
    return head;
}

void deleteNode(struct LinkedList **head_ref, int key) 
{ 
    struct LinkedList* temp = *head_ref, *prev; 
    if (temp != NULL && temp->data == key) 
    { 
        *head_ref = temp->next;    
        free(temp);               
        return; 
    } 
    while (temp != NULL && temp->data != key) 
    { 
        prev = temp; 
        temp = temp->next; 
    } 
  
    if (temp == NULL) return; 
  
    prev->next = temp->next; 
  
    free(temp);  
} 


void printList(struct LinkedList *node) 
{ 
    while (node != NULL) 
    { 
        printf(" %d ", node->data); 
        node = node->next; 
    } 
} 
  


int main(){
    struct LinkedList* head = NULL;
    addNode(head,20);
	addNode(head,30);
    addNode(head,40);
    addNode(head,50);
    addNode(head,60);
    deleteNode(&head,40);
    printList(head);
    return 0;
}