class Solution {
public:

    int rec(int index, int currOr, vector<int>&nums, int maxOr) {
        if(index==nums.size()) {
            if (currOr == maxOr) {
                return 1;
            }
            else return 0;
        }

        int taken = rec(index+1, currOr|nums[index], nums, maxOr);
        int notTaken = rec(index+1, currOr, nums, maxOr);

        return taken+notTaken;
    }


    int countMaxOrSubsets(vector<int>& nums) {
        int maxOr = 0;
        for (auto num:nums) {
            maxOr|=num;
        }

        int currOr=0;
        return rec(0,currOr,nums,maxOr);
    }
};