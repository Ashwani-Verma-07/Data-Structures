#include<iostream>
using namespace std;
int call(int arr[],int n,int key,int i){
if(n==0){
    return -1;
}
int ans=call(arr+1,n-1,key,i+1);
if(ans==-1){
    if(arr[0]==key){
        return i;
    }
    else{
        return -1;
    }
}
else{
return ans;
}
}
int main(){
 int n,arr[1000];
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int key,i=0;
    cin>>key;
    cout<<call(arr,n,key,i);
    return 0; 
}












































/*int call(int arr[],int n,int key,int i){
    if(n==0){
        return -1;
    }
    if(arr[0]==key){
        return i;
    }
    else{
        int fact=call(arr-1,n-1,key,i-1);
        return fact;
    }
}


int main(){
      int n,arr[1000];
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int key,i=n-1;
    cin>>key;
    cout<<call(arr+n-1,n,key,i);
    return 0; 
}
*/