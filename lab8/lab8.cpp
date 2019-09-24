#include<bits/stdc++.h>

using namespace std;

void swap(vector<float> &arr, int a, int b){
    float temp = arr[a];
    arr[a] = arr[b];
    arr[b] = temp ; 
}

float insertionSort(vector<float> arr,int t, int n)  
{  
    int i, j;  
    float key;
    for (i = 1; i < n; i++) 
    {  
        key = arr[i+t];  
        j = i - 1;
        while (j >= 0 && arr[j+t] > key) 
        {  
            arr[j + 1 + t] = arr[j +t];  
            j = j - 1;  
        }  
        arr[j + t + 1] = key;  
    } 
    return arr[t + n/2]; 
}  

int partition(vector<float> &arr, int l, int r, float x) 
{ 
    int i; 
    for (i=l; i<r; i++) 
        if (arr[i] == x) 
           break; 
    swap(arr, i, r); 
     i = l; 
    for (int j = l; j <= r - 1; j++) 
    { 
        if (arr[j] <= x) 
        { 
            swap(arr,i,j);
            i++; 
        } 
    } 
    swap(arr,i,r); 
    return i; 
} 


float blumSort(vector<float> &array, int l,int r,int k){
    if(k >= 0 && k<= r-l+1){
        int n = r-l + 1;
        vector<float> median((n+4)/5,0);
        int i;
        for(i = 0; i < n/5; i++){
            median[i] = insertionSort(array, l+ i*5,5);
        }
        if(i*5 < n){
            median[i] = insertionSort(array, l + i*5, n%5);
            i++;
        }
        float medOfmed = (i==1)?median[i-1]:blumSort(median, 0,i-1,(i+1)/2);

        int pos = partition(array,l,r,medOfmed);
        if (pos-l == k-1) 
            return array[pos]; 
        if (pos-l > k-1) 
            return blumSort(array, l, pos-1, k); 
  
        // Else recur for right subarray q

        return blumSort(array, pos+1, r, k-pos+l-1);
    }
    return 0.00;
}

int main(){
    long t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<float> array(n,0);
        long x,y;
        float temp;
        for(int i=0; i<n; i++){
            cin>>x>>y;
            array[i] = sqrt(x*x + y*y);
        }
        int t;
        if(n%2 == 0){
            t= n/2;
        }else{
            t = (n+1)/2;
        }
        float ans = blumSort(array,0,n-1,t);
        cout<<ans<<'\n';
        
    }
    return 0;
}
