#include<iostream>
using namespace std;
int main() {
	int r,c;
	cin>>r>>c;
	long long int a[1000][1000];
	for(int i=0;i<r;i++){
		for(int j=0;j<c;j++){
			cin>>a[i][j];
		}
	}
	//waveprint
	for(int j=0;j<c;j++){
		if(j%2==0){
			for(int i=0;i<r;i++){
			cout<<a[i][j]<<", ";
			}
		}
		else{
			for(int i=r-1;i>=0;i--){
				cout<<a[i][j]<<", ";
			}
		}
	}
	cout<<"END"<<endl;
	return 0;
}