#include<iostream>
using namespace std;
int call(int arr[],int n){
    
 if(n==1){
     return arr[0];
 }
 
 return arr[0] +call(arr+1,n-1);

}
int main(){
    int n,arr[1000];
    cin>>n;
   for(int i=0;i<n;i++){
       cin>>arr[i];
   }
    
    cout<<call(arr,n);
}