class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int> m;
        int n=nums.size();
        for (auto a:nums){
            m[a]++;
            if (m[a]>(n/2)){
                return a;
            }
        }
        return -1;
    }
};