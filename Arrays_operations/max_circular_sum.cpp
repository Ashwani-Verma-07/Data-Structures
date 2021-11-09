#include <iostream>

using namespace std;
int kadane_algo(int a[],int n){

    int cs=0,ms=0;
    for(int i=0;i<n;i++){
            cs+=a[i];
        if(cs<0){
            cs=0;}
    ms=max(cs,ms);

    }
              return ms;
}
int main()
{int num,q=0;
cin>>num;
	while(q<num){
int n,sum=0,arr[10000];
cin>>n;
for(int i=0;i<n;i++){
    cin>>arr[i];
}
int kadane_sum=kadane_algo(arr,n);
for(int i=0;i<n;i++){
    sum+=arr[i];
    arr[i]=-arr[i];
}
sum=sum+kadane_algo(arr,n);
if(sum>kadane_sum){
    cout<<sum<<endl;
}
else{
    cout<<kadane_sum<<endl;
}
	q++;
	}
    return 0;
}