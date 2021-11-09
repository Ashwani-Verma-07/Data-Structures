#include<iostream>
using namespace std;
int main() {
long long int n,sum,a[1000];
cin>>n;
for(int i=0;i<n;i++){
	cin>>a[i];
}
cin>>sum;
for(int i=0;i<n-1;i++){
	for(int j=i+1;j<n;j++){
		if(sum==a[i]+a[j]){
			if(a[i]<a[j]){
			cout<<a[i]<<" and "<<a[j]<<endl;
			}
			if(a[i]>a[j]){
				cout<<a[j]<<" and "<<a[i]<<endl;
			}
		}
	}
}

	return 0;
}