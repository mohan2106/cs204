#include<bits/stdc++.h>
using namespace std;
typedef long long lli;
typedef long li;
#define forz(n) for (long i = 0; i < n; i++)
#define rforz(a,n) for (long i = a; i < n; i++)
#define forlz(n) for (long int i = 0; i < n; i++)
// #define modulo 1e9+7

struct node  
{ 
  int data; 
  struct node *left; 
  struct node *right; 
};

struct node* newNode(int data) 
{ 
  struct node* node = (struct node*)malloc(sizeof(struct node)); 
  
  node->data = data; 
  
  node->left = NULL; 
  node->right = NULL; 
  return(node); 
} 

struct node* search(struct node* root, int key) 
{ 
    
    if (root == NULL || root->data == key) 
       return root; 
    
    if (root->data < key) 
       return search(root->right, key); 
  
    return search(root->left, key); 
} 

void inorder(struct node *root) 
{ 
    if (root != NULL) 
    { 
        inorder(root->left); 
        printf("%d \n", root->data); 
        inorder(root->right); 
    } 
} 
   

struct node* insert(struct node* node, int key) 
{ 
    
    if (node == NULL) return newNode(key); 
    if (key < node->data) 
        node->left  = insert(node->left, key); 
    else if (key > node->data) 
        node->right = insert(node->right, key);    
  
    return node; 
} 
struct node * minValueNode(struct node* node) 
{ 
    struct node* current = node; 
  
    while (current && current->left != NULL) 
        current = current->left; 
  
    return current;     
}  

struct node* deleteNode(struct node* root, int key) 
{ 
    if (root == NULL) return root; 
  
    if (key < root->data) 
        root->left = deleteNode(root->left, key); 
  
    else if (key > root->data) 
        root->right = deleteNode(root->right, key); 
  
    else
    { 
        // node with only one child or no child 
        if (root->left == NULL) 
        { 
            struct node *temp = root->right; 
            free(root); 
            return temp; 
        } 
        else if (root->right == NULL) 
        { 
            struct node *temp = root->left; 
            free(root); 
            return temp; 
        } 
  
        struct node* temp = minValueNode(root->right); 
  
        root->data = temp->data; 
  
        root->right = deleteNode(root->right, temp->data); 
    } 
    return root; 
} 

int main(){

    struct node *root = NULL; 
    root = insert(root, 50); 
    root = insert(root, 30); 
    root = insert(root, 20); 
    root = insert(root, 40); 
    root = insert(root, 70); 
    root = insert(root, 60); 
    root = insert(root, 80); 
  
    printf("Inorder traversal of the given tree \n"); 
    inorder(root); 
  
    printf("\nDelete 20\n"); 
    root = deleteNode(root, 20); 
    printf("Inorder traversal of the modified tree \n"); 
    inorder(root); 
  
    printf("\nDelete 30\n"); 
    root = deleteNode(root, 30); 
    printf("Inorder traversal of the modified tree \n"); 
    inorder(root); 
  
    printf("\nDelete 50\n"); 
    root = deleteNode(root, 50); 
    printf("Inorder traversal of the modified tree \n"); 
    inorder(root); 
    
    return 0;
}