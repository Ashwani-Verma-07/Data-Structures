#include<iostream>
#include<cstring>
using namespace std;
string a[9]={"", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
void call(string input,string output[]){
if(input.length()==0){
    string *p=output;
    cout<<*p<<endl;
    return;
}
char ch=input[0];
string del=input.substr(1);

 string codeforch=a[ch-'0'];
for(int i=0;i<codeforch.length();i++){
   char cho=codeforch[i];
   call(del,output+cho);
}


}
int main(){
    string input,output[1000];
cin>>input;
call(input,output);


}