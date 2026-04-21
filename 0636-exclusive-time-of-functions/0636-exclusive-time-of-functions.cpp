class Solution {
public:
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        vector<int> ans(n);
        stack<pair<int, int>> st;
        int prevTime = 0;
        for(string &s : logs) {
            int num = stoi(s.substr(0, s.find(':')));
            int time = stoi(s.substr(s.rfind(':')+1));
            if(s.find('e') != -1) {
                ans[num] += time-prevTime+1;
                prevTime = time+1;
                st.pop();
            }
            else {
                if(!st.empty()) ans[st.top().first] += time-prevTime;
                st.push({num, time});
                prevTime = time;
            }
        }
        return ans;
    }
};