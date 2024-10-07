class Solution {
public:
    int minLength(string s) {
        stack <char> st;
        st.push('Z');
        for (char ch:s) {
            if (ch=='B') {
                char top = st.top();
                if (top=='A') {
                    st.pop();
                    continue;
                }
            }
            if (ch=='D') {
                char top = st.top();
                if (top=='C') {
                    st.pop();
                    continue;
                }
            }
            st.push(ch);
        }
        return st.size()-1;
    }
};