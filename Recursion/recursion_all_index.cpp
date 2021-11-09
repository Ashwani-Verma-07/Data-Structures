#include<iostream>
using namespace std;
 int call(int input[], int size, int x, int output[]){

 if(size==0)
      return 0;
    int ans=call(input, size-1, x , output );
    if(input[size-1]==x)
    { cout<<"size is:"<<size;
        output[ans]=size-1;
       return ans+1; 
    }
    else{
    return ans;
    }

}





int main(){
       int n,arr[1000],srr[100];
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int key,i=0;
    cin>>key;
int size = call(arr,n,key,srr);
for(int i=0;i<size;i++){
    cout<<srr[i]<<" ";
}

     
    return 0; 
}