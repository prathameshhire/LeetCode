class Solution {
public:
    vector<int> buildArray(vector<int>& nums) {
        int n = nums.size();
        vector <int> ans (n);
        for (int i=0; i <n; i++){
            int k=nums[i];
            ans[i]= nums[k];
        }
        return ans;
    }
};