#include<iostream>
#include<algorithm>
using namespace std;
int main() {
	int n,arr[1000],srr[1000],drr[1000],no;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	cin>>no;
	for(int i=0;i<no;i++){
		cin>>srr[i];
	}
	int j=n-1,carry=0;
	int k=no-1;
	int f=max(n,no)-1;
	int num=f;
	while(f!=-1){
		int sum=carry;
		if(j>=0){
			sum+=arr[j];
		}
		if(k>=0){
			sum+=srr[k];
		}
		carry=sum/10;
		sum=sum%10;
		drr[f]=sum;
		j--,k--,f--;
	}
	if(carry!=0){
		cout<<carry<<", ";
	}
	for(int i=0;i<num+1;i++){
		cout<<drr[i]<<", ";
	}
cout<<"END"<<endl;

	return 0;
}