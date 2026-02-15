class Solution {
public:
    bool isSubstringPresent(string s) {
        unordered_set<string> st;
        for (int i = 0; i<s.length()-1; i++) {
            string subS = s.substr(i, 2);
            st.insert(subS);
        }

        reverse(s.begin(), s.end());

        for (int i = 0; i<s.length()-1; i++) {
            string subS = s.substr(i,2);
            if (st.find(subS) != st.end()){
                return true;
            }
        }

        return false;
    }
};