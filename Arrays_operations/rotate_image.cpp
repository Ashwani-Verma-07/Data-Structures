<<<<<<< HEAD
#include<iostream>
using namespace std;
int main() {
	int n,arr[100][100];
	cin>>n;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin>>arr[i][j];
		}
	}
	for(int i=0;i<n;i++){
		int u=n-1;
		int col=0;
		while(col<u){
			swap(arr[i][col],arr[i][u]);
			col++;
			u--;
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(i<=j){
			swap(arr[j][i],arr[i][j]);
			}
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cout<<arr[i][j]<<" ";
		}
		cout<<endl;
	}
	return 0;
}
||||||| 9b54bd4
=======
#include<iostream>
using namespace std;
int main() {
	int n,arr[100][100];
	cin>>n;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin>>arr[i][j];
		}
	}
	for(int i=0;i<n;i++){
		int u=n-1;
		int col=0;
		while(col<u){
			swap(arr[i][col],arr[i][u]);
			col++;
			u--;
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(i<=j){
			swap(arr[j][i],arr[i][j]);
			}
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cout<<arr[i][j]<<" ";
		}
		cout<<endl;
	}
	return 0;
}
>>>>>>> 2f14c0984f8b217ed6ae9035f84e70026d5dd6f9
