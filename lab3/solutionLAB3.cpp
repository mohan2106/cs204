#include<iostream>
#include<stack>
#include<string>
#include<map>
using namespace std;



int manage(stack<char> &v,char ch){
	int flag;
	switch(ch){
		case '(':
			flag=0;
			break;
		case '{':
			flag=1;
			break;
		case '[':
			flag=2;
			break;
		case '<':
			flag=3;
			break;
		case '|':
			flag=4;
			break;
		case ')':
			flag=5;
			break;
		case '}':
			flag=6;
			break;
		case ']':
			flag=7;
			break;
		case '>':
			flag=8;
			break;
		default:
			return 0;
	}
	if(v.empty()){
		if(flag<=4){
			v.push(ch);
			return 1;
		}else{
			return 0;
		}
	}else{
		if(flag<=3){
			v.push(ch);
			return 1;
		}else if(flag==4){
			if(v.top() == '|'){
				v.pop();
				return 1;
			}else{
				v.push(ch);
				return 1;
			}
		}else{
			if(ch == '}'){
				if(v.top() == '{'){
					v.pop();
					return 1;
				}else{
					return 0;
				}
			}
			else if(ch == ']'){
				if(v.top() == '['){
					v.pop();
					return 1;
				}else{
					return 0;
				}
			}else if(ch == '>'){
				if(v.top() == '<'){
					v.pop();
					return 1;
				}else{
					return 0;
				}
			}else if(ch == ')'){
				if(v.top() == '('){
					v.pop();
					return 1;
				}else{
					return 0;
				}
			}
		}
	}
	return 0;
}

int main(){
	int t;
	cin>>t;
	while(t--){
		string str;
		cin>>str;
		int len=str.length();
		stack<char> arr;
		int result;
		for(int i=0;i<len;i++){
			// cout<<i<<'\t';
			result = manage(arr,str[i]);
			if(result == 0){
				cout<<"NO"<<'\n';
				break;
			}
		}
		
		if(arr.empty() && result==1){
			cout<<"YES"<<'\n';
		}else if(result==1){
			cout<<"NO"<<'\n';
		}
	}
	return 0;
}