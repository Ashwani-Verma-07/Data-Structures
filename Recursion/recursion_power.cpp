#include <iostream>
int power(int x,int n);
using namespace std;
int power(int x,int n){
  if(n==1){
    return x;
  }


    return x*power(x,n-1);

}
int main()
{cout<<"Enter number"<<endl;
 int x,n;
 cin>>x;
 cout<<"Enter how many times"<<endl;
 cin>>n;
int mul=power(x,n);
cout<<mul<<endl;
    return 0;
}
