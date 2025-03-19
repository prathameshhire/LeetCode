class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k = k % (nums.size());
        int l = 0, r = nums.size()-1;
        while (l<r) {
            swap(nums[l], nums[r]);
            l++;
            r--;
        }
        l = 0; r = k-1;
        while (l<r) {
            swap(nums[l], nums[r]);
            l++;
            r--;
        }
        l = k; r = nums.size()-1;
        while (l<r) {
            swap(nums[l], nums[r]);
            l++;
            r--;
        }    
    }
};