#include<iostream>
#include<algorithm>
using namespace std;
int quick_sort(int arr[],int sp,int ep){
            
            int pivot = arr[ep]; // pivot 
    int i = sp - 1; // Index of smaller element and indicates the right position of pivot found so far
  
    for (int j = sp; j <= ep - 1; j++) 
    { 
        // If current element is smaller than the pivot 
        if (arr[j] < pivot) 
        { 
            i++; // increment index of smaller element 
            swap(arr[i], arr[j]); 
        } 
    } 
    swap(arr[i + 1],arr[ep]); 
    return i + 1; 
} 
void call(int arr[],int sp,int ep){

    if(sp>=ep){
        return;
    }
  int ans = quick_sort(arr,sp,ep);
    call(arr,sp,ans-1);
    call(arr,ans+1,ep);
}

int main(){
    int n,arr[1000];
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    call(arr,0,n-1);

        for(int i=0;i<n;i++){
            cout<<arr[i]<<" ";
        }
}
