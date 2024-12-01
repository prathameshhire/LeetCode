class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        if (nums.size() == 0) return 0;
        if (nums.size() == 1 && nums[0] != val) return 1;
        if (nums.size() == 1 && nums[0] == val) return 0;
        

        int i = 0;
        int j = nums.size()-1;
        while (i<j) {
            if (nums[i] == val && nums[j] != val) {
                swap (nums[i], nums[j]);
                i++;
                j--;
                continue;
            }
            if (nums[i] == val && nums[j] == val) {
                j--;
                continue;
            }
            if (nums[j] == val) {
                i++;
                j--;
                continue;
            }
            else {
                i++;
            }
        }
        int k = 0;
        i = 0;
        while (i<nums.size() && nums[i] != val) {
            i++;
            k++;
        } 
        return k;
    }
};