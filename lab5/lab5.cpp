#include<bits/stdc++.h>
#include<cctype>
using namespace std;

const int ALPHABET_SIZE = 62; 
struct data
{
    string info;
    struct data *left;
    struct data *right;
};

struct TrieNode 
{ 
    struct TrieNode *children[ALPHABET_SIZE]; 
    string data; 
    bool isEndOfWord; 
}; 
typedef struct TrieNode trie;

trie *getNode(void) 
{ 
    trie *pNode =  new TrieNode; 
  
    pNode->isEndOfWord = false; 
    pNode->data = "";
    for (int i = 0; i < ALPHABET_SIZE; i++) 
        pNode->children[i] = NULL; 
  
    return pNode; 
} 

void insert(trie *root, string key,string data) 
{ 
    trie *pCrawl = root; 
  
    for (int i = 0; i < key.length(); i++) 
    { 
        int index ;
        if(isupper(key[i])){
            index = key[i]-'A'+26;
        }else if(isdigit(key[i])){
            index = key[i]-'0'+52;
        }
        else{
            index = key[i] - 'a';
        }
        
        if (!pCrawl->children[index]) 
            pCrawl->children[index] = getNode(); 
  
        pCrawl = pCrawl->children[index]; 
    } 
  
    // mark last node as leaf 
    pCrawl->isEndOfWord = true;
    pCrawl->data = data; 
} 

bool search(struct TrieNode *root, string key) 
{ 
    struct TrieNode *pCrawl = root; 
  
    for (int i = 0; i < key.length(); i++) 
    { 
        int index ;
        if(isupper(key[i])){
            index = key[i]-'A'+26;
        }else if(isdigit(key[i])){
            index = key[i]-'0'+52;
        }
        else{
            index = key[i] - 'a';
        }
        if (!pCrawl->children[index]) 
            return false; 
  
        pCrawl = pCrawl->children[index]; 
    } 
  
    return (pCrawl != NULL && pCrawl->isEndOfWord); 
} 

string searchget(struct TrieNode *root, string key) 
{ 
    struct TrieNode *pCrawl = root; 
  
    for (int i = 0; i < key.length(); i++) 
    { 
        int index ;
        if(isupper(key[i])){
            index = key[i]-'A'+26;
        }else if(isdigit(key[i])){
            index = key[i]-'0'+52;
        }
        else{
            index = key[i] - 'a';
        }
        
        pCrawl = pCrawl->children[index]; 
    } 
  
    return pCrawl->data; 
} 

typedef struct data node;

int pres(char ch){
    switch(ch){
        case '^':
            return 4;
        case '*':
            return 2;
        case '/':
            return 3;
        case '+':
            return 1;
        case '-':
            return 1;
        default:
            return 0;
    }
}
bool isOperator(char ch){
    switch(ch){
        case '^':
        case '*':
        case '/':
        case '+':
        case '-':
        case '(':
        case ')':
            return true;
        default:
            return false;
    }
}
bool isOperator2(char ch){
    switch(ch){
        case '^':
        case '*':
        case '/':
        case '+':
        case '-':
            return true;
        default:
            return false;
    }
}

vector<string> postfix(vector<string> str){
    vector<string> pf,resu;
    stack<char> st;
    st.push('M');
    int len = str.size();
    // cout<<len;
    for(int i=0;i<len;i++){
        // cout<<str[i]<<"\t";
        if(!isOperator(str[i][0])){
            pf.push_back(str[i]);
        }
        else if(str[i][0] == '('){
            st.push('(');
        }else if(str[i][0] == ')'){
            while(st.top() != '(' && st.top() != 'M'){
                // cout<<st.top();
                char d=st.top();
                string x="";
                x.push_back(d);
                pf.push_back(x);
                st.pop();
            }
            if(st.top() == '('){
                st.pop();
            }
       } else{
            // cout<<"got "<<str[i][0]<<endl;
            if(st.top() != '(' && str[i][0]!='^'){
                while(st.top() != 'M' && pres(str[i][0])<=pres(st.top())){
                    char d=st.top();
                    string x="";
                    x.push_back(d);
                    pf.push_back(x);
                    st.pop();
                }
            }else if(st.top() != '(' && str[i][0]=='^'){
                while(st.top() != 'M' && pres(str[i][0])<pres(st.top())){
                    char d=st.top();
                    string x="";
                    x.push_back(d);
                    pf.push_back(x);
                    st.pop();
                }
            }
            st.push(str[i][0]);
        }
    }
    while(st.top()!='M'){
        char d=st.top();
        string x="";
        x.push_back(d);
        pf.push_back(x);
        st.pop();
    }
    for(auto at=pf.begin();at!=pf.end();at++){
        string s=*at;
        if(s[0] != '\0'){
            resu.push_back(s);
            // cout<<*at<<'\t';
        }
    }
    return resu;
    // cout<<pf.size()<<'\n';

}
node *createNode(string v){
    node *n=(node *)malloc(sizeof(node));
    n->left = NULL;
    n->right = NULL;
    n->info = v;
    return n;
}

long long int convertInt(string str){
    if(str[0]!='-'){
        long long int res=0;
        for(int i=0;i<str.length();i++){
            res = res*10 + (str[i]-'0');
        }
        return res;
    }else{
        long long int res=0;
        for(int i=1;i<str.length();i++){
            res = res*10 + (str[i]-'0');
        }
        return res*(-1);
    }
    
}

node *generateTree(vector<string> v){
    stack<node *> st;
    node *t,*t1,*t2;
    for(int i=0;i<v.size();i++){
        if(!isOperator(v[i][0])){
            t= createNode(v[i]);
            st.push(t);
        }
        else{
            // int da = convertInt(v[i]);
            t = createNode(v[i]); 
            t1 = st.top(); 
            st.pop();   
            t2 = st.top(); 
            st.pop(); 
            t->right = t1; 
            t->left = t2; 
            st.push(t); 
        }
    }
    t=st.top();
    st.pop();
    return t;
}
string eval(string str1,string str2,char ch){
    long long int a = convertInt(str1);
    long long int b = convertInt(str2);
    long long int t;
    if(ch == '^'){
        t = floor(pow(a,b));
    }
    switch(ch){
        case '^':
            return to_string(t);
        case '*':
            return to_string(a*b);
        case '/':
            return to_string(a/b);
        case '+':
            return to_string(a+b);
        case '-':
            return to_string(a-b);
        default:
            cout<<"Cant be evaluated";
            return "-1";
    }
}

string inorder(node *t) 
{ 

    if(t) 
    { 
        string c = t->info;
        if(!isOperator(c[0])){
            return c;
        }else{
            string str1 = inorder(t->left);
            string str2 = inorder(t->right);
            return eval(str1,str2,c[0]);
        }
    }else{
        return "0";
    } 
} 

bool valid(vector<string> v){
    int flag = 0;
    int len = v.size();
    for(int i=1;i<len;i++){
        if(isOperator2(v[i][0]) && isOperator2(v[i-1][0])){
            return false;
        }
    }
    return true;
}

string convertPos(string str){
    string res="";
    auto it = str.begin();
    it++;
    for(it;it!=str.end();it++){
        res.push_back(*it);
    }
    return res;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        // map<char,string> var;
        struct TrieNode *rootTrie = getNode(); 
        while(n--){
            node *root = NULL;
            string str;
            cin>>str;
            string temp="";
            // string tempstr="";
            string variable="";
            vector<string> ne;
            int k=0;
            if(str.find('=') != std::string::npos){
                int i=0;
                while(str[i]!='='){
                    variable.push_back(str[i]);
                    i++;
                }
                i++;
                for(i;i<str.length();i++){
                    if(!isOperator(str[i])){
                        if(isalpha(str[i])){
                            temp.push_back(str[i]);
                            // auto it = var.find(str[i]);
                            // if(it!=var.end()){
                            //     temp = var[str[i]];
                            // }else{
                            //     cout<<"CANT BE EVALUATED"<<'\n';
                            //     goto terminate;
                            // }
                        }else{
                            temp.push_back(str[i]);
                        }
                    }
                    else{
                        if(isalpha(temp[0])){
                            if(search(rootTrie,temp)){
                                temp = searchget(rootTrie,temp);
                                if(temp[0]=='-'){
                                    temp = convertPos(temp);
                                    string d= "";
                                    d.push_back('(');
                                    ne.push_back(d);
                                    d="";
                                    d.push_back('0');
                                    ne.push_back(d);
                                    d= "";
                                    d.push_back('-');
                                    ne.push_back(d);
                                    ne.push_back(temp);
                                    d="";
                                    d.push_back(')');
                                    ne.push_back(d);
                                }else{
                                    ne.push_back(temp);
                                    string d= "";
                                    d.push_back(str[i]);
                                    ne.push_back(d);
                                }
                                string d= "";
                                d.push_back(str[i]);
                                ne.push_back(d);
                                temp="";
                            }else{
                                cout<<"CANT BE EVALUATED"<<'\n';
                                goto terminate;
                            }
                        }else{
                            if((ne.size() == 0 || temp.length() == 0) && str[i]=='-' && str[i-1]!=')'){
                                string d= "";
                                d.push_back('0');
                                ne.push_back(d);
                            }
                            if(temp.length()!=0){
                                ne.push_back(temp);
                            }
                            string d= "";
                            d.push_back(str[i]);
                            ne.push_back(d);
                            temp="";
                        }
                        
                    }
                }
                if(temp.size()>0){
                    if(isalpha(temp[0])){
                        if(search(rootTrie,temp)){
                            temp = searchget(rootTrie,temp);
                            if(temp[0]=='-'){
                                temp = convertPos(temp);
                                string d= "";
                                d.push_back('(');
                                ne.push_back(d);
                                d="";
                                d.push_back('0');
                                ne.push_back(d);
                                d= "";
                                d.push_back('-');
                                ne.push_back(d);
                                ne.push_back(temp);
                                d="";
                                d.push_back(')');
                                ne.push_back(d);
                            }else{
                                ne.push_back(temp);
                            }
                            // ne.push_back(temp);
                        }else{
                            cout<<"CANT BE EVALUATED"<<'\n';
                            goto terminate;
                        }
                        temp="";
                    }else{
                        ne.push_back(temp);
                    }
                }
                if(valid(ne)){
                    ne= postfix(ne);
                    // for(auto it= ne.begin();it!=ne.end();it++){
                    //     cout<<*it<<"\t";
                    // }
                    // cout<<'\n';
                    root = generateTree(ne);
                    string result = inorder(root); 
                    insert(rootTrie,variable,result);
                    // cout<<result<<'\n';
                }else{
                    cout<<"CANT BE EVALUATED"<<"\n";
                }
            }else{
                int i=0;
                for(i;i<str.length();i++){
                    if(!isOperator(str[i])){
                        if(isalpha(str[i])){
                            temp.push_back(str[i]);
                        }else{
                            temp.push_back(str[i]);
                        }
                    }
                    else{
                        if(isalpha(temp[0])){
                            if(search(rootTrie,temp)){
                                temp = searchget(rootTrie,temp);
                                if(temp[0]=='-'){
                                    temp = convertPos(temp);
                                    string d= "";
                                    d.push_back('(');
                                    ne.push_back(d);
                                    d="";
                                    d.push_back('0');
                                    ne.push_back(d);
                                    d= "";
                                    d.push_back('-');
                                    ne.push_back(d);
                                    ne.push_back(temp);
                                    d="";
                                    d.push_back(')');
                                    ne.push_back(d);
                                }else{
                                    ne.push_back(temp);
                                }
                                string d= "";
                                d.push_back(str[i]);
                                ne.push_back(d);
                                temp="";
                            }else{
                                cout<<"CANT BE EVALUATED"<<'\n';
                                goto terminate;
                            }
                            
                        }else{
                            if((ne.size() == 0 || temp.length() == 0) && str[i]=='-' && str[i-1]!=')'){
                                string d= "";
                                d.push_back('0');
                                ne.push_back(d);
                            }
                            if(temp.length()!=0){
                                ne.push_back(temp);
                            }
                            string d= "";
                            d.push_back(str[i]);
                            ne.push_back(d);
                            temp="";
                        }
                        
                    }
                }
                if(temp.size()>0){
                    if(isalpha(temp[0])){
                        if(search(rootTrie,temp)){
                            temp = searchget(rootTrie,temp);
                            if(temp[0]=='-'){
                                temp = convertPos(temp);
                                string d= "";
                                d.push_back('(');
                                ne.push_back(d);
                                d="";
                                d.push_back('0');
                                ne.push_back(d);
                                d= "";
                                d.push_back('-');
                                ne.push_back(d);
                                ne.push_back(temp);
                                d="";
                                d.push_back(')');
                                ne.push_back(d);
                            }else{
                                ne.push_back(temp);
                            }
                            // ne.push_back(temp);
                        }else{
                            cout<<"CANT BE EVALUATED"<<'\n';
                            goto terminate;
                        }
                        temp="";
                    }else{
                        ne.push_back(temp);
                    }
                }
                if(valid(ne)){
                    ne= postfix(ne);
                    // for(auto it= ne.begin();it!=ne.end();it++){
                    //     cout<<*it<<"\t";
                    // }
                    // cout<<'\n';
                    root = generateTree(ne);
                    string result = inorder(root); 
                    // insert(rootTrie,variable,result);
                    cout<<result<<'\n';
                }else{
                    cout<<"CANT BE EVALUATED"<<"\n";
                }
            }
                    
            terminate:
                int mohan=4;
        }
    }
}