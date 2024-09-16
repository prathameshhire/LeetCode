class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> ans(nums.size(),1);
        int prefix=1;
        for (int i=0;i<ans.size();i++){
            ans[i]*=prefix;
            prefix*=nums[i];
        }
        int suffix=1;
        for (int i=ans.size()-1;i>=0;i--){
            ans[i]*=suffix;
            suffix*=nums[i];
        }
        return ans;
    }
};