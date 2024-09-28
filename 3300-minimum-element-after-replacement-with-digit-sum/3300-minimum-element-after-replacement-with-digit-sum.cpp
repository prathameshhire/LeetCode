class Solution {
public:
    int minElement(vector<int>& nums) {
        vector <int> ans;
        for (int i=0; i<nums.size(); i++) {
            int sum=0;
            int n=nums[i];
            while(n!=0) {
                sum += n%10;
                n/=10;
            }
            ans.push_back(sum);
        }
        int min = INT_MAX;
        for(auto it:ans) {
            if (min>it) {
                min = it;
            }
        }
        return min;
    }
};