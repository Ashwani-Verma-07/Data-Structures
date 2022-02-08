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
//Output : 
5
                1   
              1   1   
            1   2   1   
          1   3   3   1   
        1   4   6   4   1 
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
      int i=0,j=0,temp;
      vector<int> num1;
      vector<vector<int>>vec;
    for(i=0;i<numRows;i++){
	        for(j=0;j<=i;j++){
        
            if(i==0 || j==0){
                temp = 1;
            }else{
              //counting the desired value
                temp = temp*(i-j+1)/j;
                 }
              num1.push_back(temp); 
            }
   //deleting previously inserted values of num1  
      for(int k=0;k<j-1;k++){
        num1.erase(num1.begin());
      }
      //push num1 into vec
      vec.push_back(num1);
    }
      
      return vec;
    }
};
//Input: numRows = 5
//Output: [[1],[1,1],[1,2,1],[1,3,3,1],[1,4,6,4,1]]
