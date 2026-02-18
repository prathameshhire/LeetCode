class Solution {
public:
    int t [10001];
    bool solve(vector<int> &nums, int n, int index) {    
        if (index == n-1) return true;
        if (t[index] != -1) return t[index]; 
        for (int i = 1; i<=nums[index]; i++) {
            if (solve(nums, n, index+i)) return t[index] = true;
        }
        return t[index] = false;
    }
    bool canJump(vector<int>& nums) {
        memset(t, -1, sizeof(t));
        int n = nums.size();
        return solve(nums, n, 0);
    }
};