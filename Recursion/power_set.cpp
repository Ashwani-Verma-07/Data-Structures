#include<iostream>
#include<cmath>
#include<string>
using namespace std;
int call(string input,string output[]){
    if(input.empty()){
      output[0]="";
        return 1;
    }
    string small_string=input.substr(1);
    int small_output=call(small_string,output);
    for(int i=0;i<small_output;i++){ 
        output[i+small_output]=input[0]+output[i];
    }
    return 2*small_output;
}
int main(){
    string input;
    cin>>input;
    int n=input.size();
    int num=pow(2,n);
    string *output=new string[num];
    int size=call(input,output);
    for(int i=0;i<size;i++){
        cout<<output[i]<<endl;
    }
}