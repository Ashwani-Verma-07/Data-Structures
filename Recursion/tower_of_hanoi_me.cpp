#include<iostream>
using namespace std;
int call(int n,string source,string des,string aux){
if(n==1){
    cout<<source<<" --> "<<des<<endl;
    return 0;
}
call(n-1,source,aux,des);
cout<<source<<" --> "<<des<<endl;
call(n-1,aux,des,source);

return 0;
}



int main(){
    int n;
    string source="A",des="B",aux="C";
    cin>>n;
    call(n,source,des,aux);
}
