#include<iostream>
using namespace std;

int call(int n,int j){
    
    if(n==0){
        return j;
    }
   if(n%10==0){
      int ans= call(n/10,j+1);
      return ans;
   }
   else{
int ans = call(n/10,j);
return ans;
   }
  
}
int main(){
    int n;
    cin>>n;
    cout<<call(n,0);
}