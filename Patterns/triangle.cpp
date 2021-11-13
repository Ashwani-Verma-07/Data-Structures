#include<iostream>
using namespace std;
int main() {
	
	int n;
	cin>>n;
	int p;
	for(int i=1;i<=n;i++){

for(int j=1;j<=n-i;j++){
cout<<"\t";
}
p=i;
for(int j=1;j<=i;j++){
	if(j==i){
		cout<<p++;
	}

else 
cout<<p++<<"\t";
}
p=p-2;
for(int j=1;j<=i-1;j++)
cout<<"\t"<<p--;
cout<<endl;
	}
	return 0;
}