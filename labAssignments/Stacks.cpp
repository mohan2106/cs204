#include<bits/stdc++.h>
using namespace std;
typedef long long lli;
typedef long li;
#define forz(n) for (long i = 0; i < n; i++)
#define rforz(a,n) for (long i = a; i < n; i++)
#define forlz(n) for (long int i = 0; i < n; i++)
// #define modulo 1e9+7

struct StackData{
    int data;
    struct StackData* next;
};

int isEmpty(struct StackData* root) 
{ 
    return !root; 
} 

void pushStack(StackData** root,int d){
    StackData* n = (struct StackData*)malloc(sizeof(StackData));
    n->data = d;
    n->next = *root;
    *root = n;
}

int pop(struct StackData** root) 
{ 
    if (isEmpty(*root)) 
        return INT_MIN; 
    struct StackData* temp = *root; 
    *root = (*root)->next; 
    int popped = temp->data; 
    free(temp); 
  
    return popped; 
} 

int top(struct StackData* root){
    if(root != NULL){
        return root->data;
    }
}

int main(){
	StackData* root = NULL;
    pushStack(&root, 10); 
    pushStack(&root, 20); 
    pushStack(&root, 30); 
  
    printf("%d popped from stack\n", pop(&root)); 
  
    printf("Top element is %d\n", top(root)); 

    return 0;
}