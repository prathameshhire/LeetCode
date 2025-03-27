class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> ans(temperatures.size(), 0);
        stack<pair<int,int>> st;
        for (int i = 0; i<temperatures.size(); i++) {
            while (!st.empty() && temperatures[i]>st.top().second) {
                int index = st.top().first;
                ans[index] = i-index;
                st.pop();
            }
            st.push({i,temperatures[i]});
        }
        return ans;
    }
};