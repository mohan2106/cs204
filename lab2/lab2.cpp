#include<bits/stdc++.h>
using namespace std;

struct node{
	int x;
	int y;
	struct node *prev;
	struct node *next;
};
typedef struct node nd;

void addFirst(int x,int y,nd **root){
	nd *nextNode = (nd*)malloc(sizeof(nd));
	if(nextNode == NULL){
		cout<<"No space for new Node";
		return;
	}
	nextNode->x = x;
	nextNode->y = y;
	nextNode->prev= NULL;
	nextNode->next = *root;
	if(*root != NULL){
		(*root)->prev = nextNode;
	}
	
	*root = nextNode;
	//cout<<nextNode->x;
	return;
}
void delFirst(nd **root){
	if(*root == NULL){
		cout<<"Empty Linked List"<<endl;
	}else{
		nd *temp=*root;
		*root = temp->next;
		if(*root != NULL){
			(*root) ->prev = NULL;
		}
		free(temp);
	}
}
void del(int x,int y,nd **root){
	nd *temp=*root;
	if(temp == NULL){
		cout<<"-1"<<endl;
		return;
	}else{
		while(temp!=NULL){
			if((temp->x == x) && (temp->y == y)){
				break;
			}else{
				temp=temp->next;
			}
		}
		if(temp == NULL){
			cout<<"-1"<<endl;
			return;
		}else{
			if(temp->prev != NULL && temp->next != NULL){
				temp->prev->next = temp->next;
				temp->next->prev = temp->prev;
				free(temp);
			}
			else if(temp->prev != NULL && temp->next == NULL){
				temp->prev->next = NULL;
				free(temp);
			}else if(temp->prev == NULL && temp->next != NULL){
				*root = temp->next;
				(*root)->prev = NULL;
			}else if(temp->prev == NULL && temp->next == NULL){
				*root = NULL;
				free(temp);
			}
			cout<<"0"<<endl;
			return;
		}
	}

}
double dist(int a,int b){
	return sqrt(a*a + b*b);
}
void searchAtDistance(double b,nd **root){
	nd *temp = *root;
	int z=0;
	while(temp != NULL){
		double x=dist(temp->x,temp->y);
		if(x<=b){
			cout<<"("<<temp->x<<","<<temp->y<<") ";
			z++;
		}
		temp= temp->next;
	}
	if(z>0){
		cout<<endl;
	}
	return;
}
void search(int a,int b,nd **root){
	if(*root == NULL){
		cout<<-1<<endl;
		return ;
	}else{
		nd *temp = *root;
		while(temp != NULL){
			if(temp->x == a && temp->y ==b){
				cout<<0<<endl;
				return;
			}
			temp=temp->next;
		}
		cout<<-1<<endl;
		return ;
	}
}
void Length(nd *node) 
{ 
	int i=0;
    while (node != NULL) 
    { 
        i++;
        node = node->next; 
    } 
    cout<<i<<endl;
    return ;
} 

void printList(nd *node) 
{ 
    while (node != NULL) 
    { 
        printf(" %d %d\n", node->x, node->y); 
        node = node->next; 
    } 
} 


int main(){
	nd *root = NULL;
	long int t;
	cin>>t;
	long int i=0;
	int array[t][3];
	while(i<t){
		cin>>array[i][0];
		switch(array[i][0]){
			case 1:
				cin>>array[i][1]>>array[i][2];
				//addFirst(b,c,&root);
				break;
			case 2:
				//delFirst(&root);
				break;
			case 3:
				cin>>array[i][1]>>array[i][2];
				//del(b,c,&root);
				break;
			case 4:
				cin>>array[i][1];
				//searchAtDistance(b,&root);
				break;
			case 5:
				cin>>array[i][1]>>array[i][2];
				//search(b,c,&root);
				break;
			case 6:
				//Length(root);
				break;
			case 10:
				//printList(root);
				break;
			default:
				break;
		}
		i++;
	}
	i=0;
	while(i<t){
		switch(array[i][0]){
			case 1:
				//cin>>array[i][1]>>array[i][2];
				addFirst(array[i][1],array[i][2],&root);
				break;
			case 2:
				delFirst(&root);
				break;
			case 3:
				//cin>>array[i][1]>>array[i][2];
				del(array[i][1],array[i][2],&root);
				break;
			case 4:
				//cin>>array[i][1];
				searchAtDistance(array[i][1],&root);
				break;
			case 5:
				//cin>>array[i][1]>>array[i][2];
				search(array[i][1],array[i][2],&root);
				break;
			case 6:
				Length(root);
				break;
			case 10:
				printList(root);
				break;
			default:
				break;
		}
		i++;
	}
	return 0;
}