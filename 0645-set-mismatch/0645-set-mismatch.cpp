class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        vector<int> array(nums.size()+1);
        for(int i = 0; i<nums.size(); i++) {
            array[nums[i]]++;
        }
        vector<int> result(2,-1);
        for(int i = 1; i<array.size(); i++) {
            if(array[i] == 2) result[0] = i;
            if(array[i] == 0) result[1] = i;
        }
        return result;
    }
};