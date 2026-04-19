class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> st;
        for(int i : nums1) st.insert(i);
        unordered_set<int> result;
        for(int j : nums2) {
            if(st.find(j) != st.end()) result.insert(j);
        }
        vector<int> res (result.begin(), result.end());
        return res;
    }
};