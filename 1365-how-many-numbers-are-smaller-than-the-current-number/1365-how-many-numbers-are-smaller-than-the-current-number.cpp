class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int> freq(101,0);
        for(int t : nums) freq[t]++;
        for(int i = 1; i<101; i++) {
            freq[i] += freq[i-1];
        } 
        vector<int> result(nums.size());
        for(int i = 0; i<nums.size(); i++) {
            int number = nums[i];
            if(number == 0) result[i] = 0;
            else result[i] = freq[number-1];
        }
        return result;
    }
};