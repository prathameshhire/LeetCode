class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n,-1);
        stack<int> st;
        for (int i = 2*n-1; i>=0; i--) {
            int index = i%n;
            if (st.empty()) {
                st.push(nums[index]);
                continue;
            }
            if (i<n) {
                if (st.top()<=nums[index]){
                    while(!st.empty() && st.top()<=nums[index]) {
                        st.pop();
                    }
                    if (!st.empty()) ans[i] = st.top();
                }
                else{
                    ans[index] = st.top(); 
                }
            }
            else{
                if (st.top()<=nums[index] && !st.empty()){
                    while(!st.empty() && st.top()<=nums[index]){
                        st.pop();
                    }
                }
            }
            st.push(nums[index]);
        }
        return ans;
    }
};