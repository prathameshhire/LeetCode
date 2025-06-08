class Solution {
public:
    int operation (int type, int n, vector<int> &nums ) {
        int ops = 0, prev = 0;
        for (int i = 0; i<n-1; i++) {
            int val = prev ? -nums[i] : nums[i];
            if (val != type) {
                ops++;
                prev=1;
            }
            else {
                prev=0;
            }
        }
        int lastnumber = prev ? -nums.back() : nums.back();
        return (lastnumber == type) ? ops : INT_MAX;
    }
    
    bool canMakeEqual(vector<int>& nums, int k) {
        int negatives = 0;
        int n = nums.size();
        for (auto num:nums) {
            if (num == -1) {
                negatives++;
            } 
        }
        
        if((n%2 == 0) && negatives % 2 == 1) {
            return false;
        }
        int ans = min(operation (-1,n,nums), operation(1,n,nums));
        return (ans<=k);
    }
};