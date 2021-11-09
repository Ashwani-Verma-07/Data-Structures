#include<iostream>
#include<cstring>
using namespace std;
bool call(char a[],int i,int j){
    int flag=0;
if(j==0 or j==1){
    return true;
}
if(a[i]==a[j]){
    flag=1;
}
else{
    return false;
}
if(flag==1){
    bool is_re = call(a,i+1,j-1);
    return is_re;
}

 
}
int main(){

    char a[100];
    cin>>a;
    int n=strlen(a);
   int i=call(a,0,n-1);
   cout<<call(a,0,n-1);
   if(i==1){
       cout<<"true"<<endl;
   }
   else{
       cout<<"false"<<endl;
   }
}