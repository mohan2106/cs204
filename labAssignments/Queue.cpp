#include<bits/stdc++.h>
using namespace std;
typedef long long lli;
typedef long li;
#define forz(n) for (long i = 0; i < n; i++)
#define rforz(a,n) for (long i = a; i < n; i++)
#define forlz(n) for (long int i = 0; i < n; i++)
// #define modulo 1e9+7

struct QueueData { 
    int key; 
    struct QueueData* next; 
}; 
  
struct Queue { 
    struct QueueData *front, *rear; 
}; 
  
 
struct QueueData* newNode(int k) 
{ 
    struct QueueData* temp = (struct QueueData*)malloc(sizeof(struct QueueData)); 
    temp->key = k; 
    temp->next = NULL; 
    return temp; 
} 
  
struct Queue* createQueue() 
{ 
    struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue)); 
    q->front = q->rear = NULL; 
    return q; 
} 

void enQueue(struct Queue** q, int k) 
{ 
    struct QueueData* temp = newNode(k); 
    if ((*q)->rear == NULL) { 
        (*q)->front = temp;
         (*q)->rear = temp;
        return; 
    } 
    (*q)->rear->next = temp; 
    (*q)->rear = temp; 
} 
  
int deQueue(struct Queue** q) 
{  
    if ((*q)->front == NULL) 
        return 0; 

    struct QueueData* temp = (*q)->front; 
    int res = temp->key;
    (*q)->front = (*q)->front->next; 
    free(temp); 
  
    if ((*q)->front == NULL) 
        (*q)->rear = NULL; 
    return res; 
} 
void prnt(Queue* q){
    while(q->front != q->rear){
        cout<<q->front->key<<" ";
        q->front = q->front->next;
    }
    cout<<q->front->key;
}

int main(){
	struct Queue* q = createQueue(); 
    enQueue(&q, 10); 
    cout<<q->front->key<<" "<<q->rear->key<<'\n';
    enQueue(&q, 20); 
    cout<<q->front->key<<" "<<q->rear->key<<'\n';

    int a = deQueue(&q); 
    cout<<q->front->key<<" "<<q->rear->key<<'\n';

    int b = deQueue(&q); 
    cout<<"dequeued item is: "<<a<<'\n';
    enQueue(&q, 30); 
    cout<<q->front->key<<" "<<q->rear->key<<'\n';
    enQueue(&q, 40); 
    cout<<q->front->key<<" "<<q->rear->key<<'\n';
    enQueue(&q, 50); 
    cout<<q->front->key<<'\n';
    int n = deQueue(&q); 
    prnt(q);
    cout<<'\n';
    printf("Dequeued item is %d", n); 
        

    return 0;
}