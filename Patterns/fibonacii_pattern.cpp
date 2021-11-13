#include<iostream>
using namespace std;
int main() {
	long long int num,a=0,b=1,c;
	cin>>num;
	
	for(int i=1;i<=num;i++){

     for(int j=1;j<=i;j++){
cout<<a<<"\t";
c=a+b;
a=b;
b=c;

}
cout<<endl;


	}
	return 0;
}