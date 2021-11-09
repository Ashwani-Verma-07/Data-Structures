#include<iostream>
#include<cstring>
using namespace std;
char call(char a[],int n){
    if(n==0 or n==1){
        return 0;
    }
    string s=call(a+1,n-1);
    return s;
    if(char[0]=='p' and char[1]=='i'){
        cout<<"3.14";

    }
}


int main(){
    char a[100];
    cin>>a;
    int n=strlen(a);
   cout<< call(a,n);
}