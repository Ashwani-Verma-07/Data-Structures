#include <iostream>
using namespace std;

int main() {
    int range,temp;
    cin>>range;

    for(int i=0;i<range;i++){
		cout<<"\t";
        for(int spc=(range-i-1);spc>=1;spc--){
            cout<<" "<<" ";
        }

        for(int j=0;j<=i;j++){
            if(i==0 || j==0){
                temp = 1;
            }else{
                temp = temp*(i-j+1)/j;
            }
            cout<<temp<<"   ";
        }
        cout<<endl;
    }

    return 0;
}