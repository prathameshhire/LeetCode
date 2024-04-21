class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
    int n= nums.size();
    int k =0;
    for (int i=0; i < n; i++){
          for (int j=0; j<i; j++){
              if (nums[i]==nums[j]){
                  k+=1;
              }
          }
     }
     return k;   
    }
};