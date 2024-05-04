class Solution {
private:
    void sorta (vector<int>&nums){
        int j=1;
        for (int i=1; i<nums.size(); i++){
            if (nums[i]!=nums[i-1]){
                nums[j]=nums[i];
                j++;
            }
        }  
    }
public:
    int removeDuplicates(vector<int>& nums) {
        set <int>s;
        for (int i=0; i<nums.size(); i++){
            s.insert(nums[i]);
        }
        int k= s.size();
        sorta(nums);
        return k;

    }
};