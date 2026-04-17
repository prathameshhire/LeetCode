# C++ solution using sliding window

# Code
```cpp []
class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        long long result = 0;
        int minkposition = -1;
        int maxkposition = -1;
        int cultidx = -1;
        for(int i = 0; i<nums.size(); i++) {
            if (nums[i] > maxK || nums[i] < minK) cultidx = i;
            if(nums[i] == minK) minkposition = i;
            if(nums[i] == maxK) maxkposition = i;
            int smaller = min(minkposition, maxkposition);
            long long temp = smaller - cultidx;
            result += temp <= 0 ? 0 : temp;
        }
        return result;
    }
};
```