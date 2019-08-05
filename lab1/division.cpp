#include<bits/stdc++.h>
using namespace std;

string sum(string str1, string str2) 
{ 
    if (str1.length() > str2.length()) 
        swap(str1, str2); 
 
    string str = ""; 
    int n1 = str1.length(), n2 = str2.length(); 
    reverse(str1.begin(), str1.end()); 
    reverse(str2.begin(), str2.end()); 
  
    int carry = 0; 
    for (int i=0; i<n1; i++) 
    { 
        int sum = ((str1[i]-'0')+(str2[i]-'0')+carry); 
        str.push_back(sum%10 + '0'); 
        carry = sum/10; 
    } 
    for (int i=n1; i<n2; i++) 
    { 
        int sum = ((str2[i]-'0')+carry); 
        str.push_back(sum%10 + '0'); 
        carry = sum/10; 
    } 
    if (carry) 
        str.push_back(carry+'0'); 
    reverse(str.begin(), str.end()); 
  
    return str; 
} 

string singleMultiply(string str,char ch,int l2){
	int x= ch-'0';
	int carry=0;
	for(int i=l2-1;i>=0;i--){
		int temp=(str[i]-'0')*x + carry;
		str[i]=temp%10 + '0';
		carry=temp/10;
	}
	string zero="0";
	zero[0] = carry+'0';

	if(carry==0){
		return str;
	}else{
		return zero.append(str);
	}
}

string multiply(string str1,string str2){
	long int l1=str1.length();
	long int l2=str2.length();
	string result="";
	long int k=0;
	string zero="0";
	for(long int i=l1-1;i>=0;i--){
		string str=singleMultiply(str2,str1[i],l2);
		for(long int z=0;z<k;z++){
			str.append(zero);
		}
		k++;
		result=sum(str,result);
	}
	return result;
}

int lenZero(string s){
	int i=0;
	while(s[i]-'0' == 0){
		i++;
	}
	return i;
}

string modify(string str){
	int l2=lenZero(str);
	int l1=str.length();
	string stt="";
	for(int i=l2;i<l1;i++){
		stt.push_back(str[i]);
	}
	return stt;
}


bool isSmaller(string str1, string str2) 
{ 
    // Calculate lengths of both string 
    int flag1=0;
    int flag2=0;
    int x1=lenZero(str1);
    int x2=lenZero(str2);
    int n1 = str1.length()-x1, n2 = str2.length()-x2; 
    
    if (n1 < n2) 
    return true; 
    if (n2 < n1) 
    return false; 
	
    for (int i=0; i<n1-x1; i++){
    	if(str1[i+x1]-'0'!=0){
    		flag1=1;
    	}
    	if(str2[i+x2]-'0'!=0){
    		flag2=1;
    	}
    	if(flag1>flag2){
    		return false;
    	}else if(flag2>flag1){
    		return true;
    	}

		if (str1[i+x1] < str2[i+x2] && flag1 && flag2) 
        	return true; 
    	else if (str1[i+x1] > str2[i+x2] &&flag2 &&flag1) 
        	return false; 
    	
    } 
    return false; 
} 
bool isEqualSmaller(string str1, string str2) 
{ 
    // Calculate lengths of both string 
    int flag1=0;
    int flag2=0;
    int x1=lenZero(str1);
    int x2=lenZero(str2);
    int n1 = str1.length()-x1, n2 = str2.length()-x2; 
    
    if (n1 < n2) 
    return true; 
    if (n2 < n1) 
    return false; 
	
    for (int i=0; i<n1-x1; i++){
    	if(str1[i+x1]-'0'!=0){
    		flag1=1;
    	}
    	if(str2[i+x2]-'0'!=0){
    		flag2=1;
    	}
    	if(flag1>flag2){
    		return false;
    	}else if(flag2>flag1){
    		return true;
    	}

		if (str1[i+x1] < str2[i+x2] && flag1 && flag2) 
        	return true; 
    	else if (str1[i+x1] > str2[i+x2] &&flag2 &&flag1) 
        	return false; 
    	
    } 
    return true; 
} 

string findDiff(string str1, string str2) 
{ 
    if (isSmaller(str1, str2)) 
        swap(str1, str2); 
    string str = ""; 
    int n1 = str1.length(), n2 = str2.length();     
    reverse(str1.begin(), str1.end()); 
    reverse(str2.begin(), str2.end()); 
      
    int carry = 0;  
    for (int i=0; i<n2; i++) 
    { 
        int sub = ((str1[i]-'0')-(str2[i]-'0')-carry); 
        if (sub < 0) 
        { 
            sub = sub + 10; 
            carry = 1; 
        } 
        else
            carry = 0; 
  
        str.push_back(sub + '0'); 
    } 
    for (int i=n2; i<n1; i++) 
    { 
        int sub = ((str1[i]-'0') - carry); 
        if (sub < 0) 
        { 
            sub = sub + 10; 
            carry = 1; 
        } 
        else
            carry = 0; 
              
        str.push_back(sub + '0'); 
    } 
    reverse(str.begin(), str.end()); 
  
    return str; 
} 

string getQuotent(string str1,string str2){
	// cout<<"inside getQuotent  "<<str1<<" "<<str2<<endl;
	int x=0;
	while(isSmaller(str2,str1)){
		//cout<<str1<<" "<<str2<<endl;
		str1=findDiff(str1,str2);
		x++;
	}
	return to_string(x);
}

string devide(string str1,string str2,string q){
	long int l1=str1.length()-lenZero(str1);
	long int l2=str2.length()-lenZero(str2);
	string s="1";
	long int x=l1-l2-1;
	while(x>0){
		s.push_back('0');
		x--;
	}
	if(l1-l2-1 > 0){
		string temp1=str1;
		string dat=str1;
		string temp2=str2;
		string tt=getQuotent(temp1,multiply(temp2,s));
		q=multiply(s,tt);
		temp2=findDiff(dat,multiply(temp2,q));
		temp2=modify(temp2);
		 return devide(temp2,str2,q);
	}else{
		return q;
	}
}

int main(){
	int t;
	cin>>t;
	while(t--){
		string str1,str2;
		cin>>str1>>str2;
		string stri=str2;
		if(str2.length()>str1.length()){
			cout<<"0"<<'\n'<<str1<<endl;
		}else{
			long int l1=str1.length();
			long int l2=str2.length();
			string q="0";
			// cout<<q<<endl;
			q=devide(str1,str2,q);
			str2=multiply(str2,q);
			int x=0;
			if(isSmaller(str2,str1)){
				str1=findDiff(str1,str2);
				str1=modify(str1);
				
			}
			while(isEqualSmaller(stri,str1)){
				str1=findDiff(str1,stri);
				str1=modify(str1);
				x++;
			}
			if(str1.length()==0){
				str1="0";
			}
			q=sum(q,to_string(x));
			cout<<'\n'<<q<<'\n'<<str1<<endl;
		}
	}
	return 0;
}