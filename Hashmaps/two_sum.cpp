class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> index;
      unordered_map<int,int> map;
     
   for(int i=0;i<nums.size();i++){
     int k=nums[i];
     int m=target-k;
     if(map.count(m)){
       index.push_back(i);
       index.push_back(map[m]);
       return index;
     }
     else{
       map[nums[i]]=i;
     }
   }
      return index;
      }
};

