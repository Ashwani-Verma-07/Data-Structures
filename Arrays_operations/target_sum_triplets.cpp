#include<iostream>
#include<algorithm>
using namespace std;

int main() {
	long long int a[1000];
	long long int n;
    long long int k;

	cin>>n;

	
	for (int i=0;i<n;i++)
	   	cin>>a[i];
    
	sort(a,a+n);

	cin>>k;
	for(int i=0;i<n-2;i++){
		int j=i+1,l=n-1;
		while(j<l){
			if(a[i]+a[j]+a[l]==k){
				cout<<a[i]<<", "<<a[j]<<" and "<<a[l]<<endl;
				l--;j++;
			}
			else if(a[i]+a[j]+a[l]<k){
				j++;
			}
			else{
				l--;
			}
		}
	}
	return 0;
}