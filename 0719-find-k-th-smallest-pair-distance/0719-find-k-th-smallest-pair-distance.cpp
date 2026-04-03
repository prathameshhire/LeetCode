class Solution {
public:
    int possible(vector<int> &nums, int mid) {
        int i = 0;
        int j = 1;
        int n = nums.size();
        int count = 0;
        while (j<n) {
            while(nums[j] - nums[i] > mid){
                i++;
            }
            count += (j-i);
            j++;
        }
        return count;
    }
    int smallestDistancePair(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int l = 0;
        int r = nums[n-1] - nums[0];
        int result = 0;
        while (l<=r) {
            int mid = l+(r-l)/2;
            int countPair = possible(nums, mid);
            if (countPair >= k) {
                r = mid-1;
                result = mid;
            } 
            else l = mid+1;
        }        
        return result;
    }
};