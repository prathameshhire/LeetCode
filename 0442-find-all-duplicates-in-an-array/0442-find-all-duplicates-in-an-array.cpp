class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        unordered_map <int,int> m;
        vector <int> v;
        for (int i=0; i<nums.size(); i++){
            int k= nums[i];
            m[k]++; // error likely to occur at this point
            if (m[k]>1) {
                v.push_back(k);
            }
        }
        return v;
    }
};