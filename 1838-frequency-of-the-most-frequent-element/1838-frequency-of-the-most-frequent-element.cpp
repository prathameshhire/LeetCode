class Solution {
public:
    int bsearch(int target_idx, int k, vector<int> &nums, vector<long> &prefixSum) {
        int l = 0;
        int r = target_idx;
        int ans = 0;
        while(l<=r) {
            int mid = l+(r-l)/2;
            long count = target_idx - mid + 1;
            long cumSum = prefixSum[target_idx] - prefixSum[mid] + nums[mid];
            long targetSum = count * nums[target_idx];
            if(targetSum - cumSum <= k) {
                ans = mid;
                r = mid-1;
            }
            else {
                l = mid+1;
            }
        }
        return target_idx - ans +1;
    }
    int maxFrequency(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<long> prefixSum(n);
        prefixSum[0] = nums[0];
        for(int i = 1; i<n; i++) {
            prefixSum[i] = prefixSum[i-1] + nums[i];
        }
        int result = 0;
        for(int i = 0; i<n; i++) {
            result = max(result, bsearch(i, k, nums, prefixSum));
        }
        return result;
    }
};