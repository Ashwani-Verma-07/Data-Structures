#include <iostream>

using namespace std;
Binary_search(int arr[],int n,int key){
int sp=0;
int ep=n-1;

while(sp<=ep){
        int mid=(sp+ep)/2;
    if(arr[mid]==key){
        return mid;
    }
    else if(arr[mid]>key){
        ep=mid-1;
    }
    else{
        sp=mid+1;
    }

}

return -1;

}
int main()
{
   int n,arr[100],key;
   cin>>n;
   for(int i=0;i<n;i++){
    cin>>arr[i];
   }
   cin>>key;
   cout<<Binary_search(arr,n,key)<<endl;


    return 0;
}
