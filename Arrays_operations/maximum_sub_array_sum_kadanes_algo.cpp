#include<iostream>
using namespace std;
int main() {
	long long int n,a[1000000];
	int cs=0,ms=0,num;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>num;
		int a[num];
	for(int i=0;i<num;i++){
               cin>>a[i];
		}
		int cs=a[0];
		int ms=a[0];
		for(int i=1;i<num;i++){
			cs=cs+a[i];
			if(cs<0){
				cs=0;
			}
			ms=max(cs,ms);
		}
		cout<<ms<<endl;
	} 
	
	return 0;
}