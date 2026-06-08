class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> less;
        vector<int> equal;
        vector<int> more;
        for(int i = 0; i<nums.size(); i++) {
            if(nums[i] > pivot) more.push_back(nums[i]);
            if(nums[i] == pivot) equal.push_back(nums[i]);
            if(nums[i] < pivot) less.push_back(nums[i]);
        }
        for(int num : equal) less.push_back(num);
        for(int num : more) less.push_back(num);
        return less;
    }
};