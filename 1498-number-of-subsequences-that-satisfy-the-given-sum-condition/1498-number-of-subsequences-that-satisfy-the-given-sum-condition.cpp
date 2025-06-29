class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int left=0;
        int right=n-1;
        vector<int>power(n,1);
        int mod=1e9+7;
        for(int i=1;i<n;i++){
            power[i]=(power[i-1]*2)%mod;
        }
        int result=0;
        while(left<=right){
            if(nums[left]+nums[right]<=target){
result=(result+power[right-left])%mod;
left++;
            }
            else{
                right--;
            }
        }
        return result;
    }
};