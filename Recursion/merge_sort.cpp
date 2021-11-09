#include<iostream>
using namespace std;
int merge(int arr[],int sp,int mid,int ep){
    int srr[1000],drr[1000],frr[1000];
    int m=mid-sp+1;
    int o=ep-mid;
    for(int i=0;i<m;i++){
        srr[i]=arr[sp+i];
    }
   
    for(int i=0;i<o;i++){
        drr[i]=arr[mid+i+1];
    }
    int i=0,j=0;
    int y=sp;
    while(i<m and j<o){
           if(srr[i]<drr[j]){
arr[y]=srr[i];
i++;
           }
           else{
               arr[y]=drr[j];
               j++;
              
           }
           y++;
           
    }
    while(i<m){
        arr[y]=srr[i];
        i++;
        y++;
    }
    while(j<o){
        arr[y]=drr[j];
        j++;
        y++;
    }
    
return 0;
}



void call(int arr[],int sp,int ep){
    if(sp>=ep){
        return;
    }
   
    int mid=(sp+ep)/2;
    
    call(arr,sp,mid);
    call(arr,mid+1,ep);
    //call
    merge(arr,sp,mid,ep);
    

}
int main(){
    int arr[100],n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    call(arr,0,n-1);
   for(int i=0;i<n;i++){
       cout<<arr[i]<<" ";
   }
    
}