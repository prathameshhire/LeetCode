class Solution {
public:
    bool isGood(vector<int>& nums) {
        unordered_set<int> st;
        int n = nums.size()-1;
        bool flag = 0;
        for(int &num : nums) {
            if(num > n) return false;
            if(st.find(num) != st.end()) {
                if(num != n || flag) return false;
                flag = 1;
            }
            st.insert(num);
        }
        return true;
    }
};