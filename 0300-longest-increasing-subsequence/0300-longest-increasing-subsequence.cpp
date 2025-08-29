class Solution {
public:
    int n;
    vector<vector<int>> t;
    int solve(vector<int> &nums, int i, int P) {
        if (i == n) return 0;
        if (P != -1 && t[i][P] != -1) return t[i][P];
        int take = 0;
        if (P == -1 || nums[i] > nums[P]) {
            take = 1 + solve(nums, i+1, i);
        }
        int skip = solve(nums, i+1, P);
        if (P != -1) t[i][P] = max(skip, take);
        return max(skip, take);
    }

    int lengthOfLIS(vector<int>& nums) {
        n = nums.size();
        t = vector<vector<int>> (n, vector<int> (n,-1));
        return solve(nums,0,-1);    
    }
};