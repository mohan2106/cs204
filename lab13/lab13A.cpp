#include<bits/stdc++.h>
#include<iostream> 

#include <list> 
using namespace std; 

int getAscii(char a){
    if(a-'a' < 0){
        return a-'A' +1;
    }else{
        return a-'a' +1;
    }
}
  

class Hash 
{ 
    int BUCKET;    
    list<string> *table; 
public: 
    Hash(int V);  // Constructor 
  
    // inserts a key into hash table 
    void insertItem(string x); 
  
    // deletes a key from hash table 
    void deleteItem(string key); 
  
    // hash function to map values to key 
    int hashFunction(string x);

    bool searchString(string s);
  
    void displayHash(); 
}; 
  
Hash::Hash(int b) 
{ 
    this->BUCKET = b; 
    table = new list<string>[BUCKET]; 
} 
bool Hash::searchString(string s){
  int t = hashFunction(s);
  for (auto x : table[t]) {
      if(x.compare(s) == 0){
        return true;
      }
  }
  return false;

}

int Hash::hashFunction(string s){
    const int p = 31;
    const int m = BUCKET;
    int hash_value = 0;
    int p_pow = 1;
    for (char c : s) {
        hash_value = (hash_value + (getAscii(c)) * p_pow) % m;
        p_pow = (p_pow * p) % m;
    }
    return hash_value;
}
  
void Hash::insertItem(string key) 
{ 
    int index = hashFunction(key)%BUCKET; 
    table[index].push_back(key);  
} 
  
// function to display hash table 
void Hash::displayHash() { 
  for (int i = 0; i < BUCKET; i++) { 
    cout << i; 
    for (auto x : table[i]) 
      cout << " --> " << x; 
    cout << endl; 
  } 
} 
  
// Driver program  
int main() 
{ 
  
  
  int n;
  cin>>n;
  string temp;
  Hash h(n); 
  vector<string> arr;
  for(int i=0;i<n;i++){
    cin>>temp;
    arr.push_back(temp);
    h.insertItem(temp);
  }
  for(string s:arr){
    string x = s;
    reverse(x.begin(),x.end());
    if(h.searchString(x)){
      cout<<"YES\n";
    }else{
      cout<<"NO\n";
    }
  }


  // h.displayHash(); 
  
  return 0; 
} 
