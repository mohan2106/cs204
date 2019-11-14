#include <bits/stdc++.h> 
using namespace std; 
  
const int ALPHABET_SIZE = 26; 

struct TrieNode 
{ 
    struct TrieNode *children[ALPHABET_SIZE]; 
    bool isEndOfWord; 
}; 
struct TrieNode *getNode(void) 
{ 
    struct TrieNode *pNode =  new TrieNode; 
    pNode->isEndOfWord = false; 
    for (int i = 0; i < ALPHABET_SIZE; i++) 
        pNode->children[i] = NULL; 
    return pNode; 
} 
void insert(struct TrieNode *root, string key) 
{ 
    struct TrieNode *pCrawl = root; 
    for (int i = 0; i < key.length(); i++) 
    { 
        int index = key[i] - 'a'; 
        if (!pCrawl->children[index]) 
            pCrawl->children[index] = getNode(); 
        pCrawl = pCrawl->children[index]; 
    } 
    pCrawl->isEndOfWord = true; 
} 
bool search(struct TrieNode *root, string key) 
{ 
    struct TrieNode *pCrawl = root; 
    for (int i = 0; i < key.length(); i++) 
    { 
        int index = key[i] - 'a'; 
        if (!pCrawl->children[index]) 
            return false; 
        pCrawl = pCrawl->children[index]; 
    } 
    return (pCrawl != NULL && pCrawl->isEndOfWord); 
} 
  
int main() 
{ 
    struct TrieNode *root = getNode(); 
    while(1)
    {
        int x;cin>>x;
        if(x==1)
        {
            string s;cin>>s;
            insert(root,s);
        }
        else if(x==2)
        {
            string s;cin>>s;
            if(search(root,s)) cout<<"String is present\n";
            else cout<<"String is not present\n";
        }
        else break;
    }
} 
