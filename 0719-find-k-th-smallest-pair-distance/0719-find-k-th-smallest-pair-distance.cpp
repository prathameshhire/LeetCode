class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        int n = nums.size();
        int maxSize = *max_element(nums.begin(), nums.end());
        vector<int> vec (maxSize+1,0);
        for (int i = 0; i<n; i++) {
            for (int j = i+1; j<n; j++) {
                int val = abs(nums[i] - nums[j]);
                vec[val]++;
            }
        }
        for (int i = 0; i<vec.size(); i++) {
            k -= vec[i];
            if (k <= 0) return i;
        }
        return -1;
    }
};