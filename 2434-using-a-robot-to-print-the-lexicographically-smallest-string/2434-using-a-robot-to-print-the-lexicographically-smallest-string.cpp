class Solution {
public:
    string robotWithString(string s) {
        unordered_map<char,int> mp;
        stack<char> st;
        char minChar = 'a';
        for (char c : s) {
            mp[c]++;
        }
        string res="";
        for (char c : s) {
            st.push(c);
            mp[c]--;
            while(minChar != 'z' && mp[minChar] == 0) {
                minChar++;
            }
            while(!st.empty() && st.top() <= minChar) {
                res.push_back(st.top());
                st.pop();
            }
        }
        return res;
    }
};