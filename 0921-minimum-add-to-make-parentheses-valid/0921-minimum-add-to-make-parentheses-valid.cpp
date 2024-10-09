class Solution {
public:
    int minAddToMakeValid(string s) {
        stack <char> st;
        st.push('z');
        for (char ch: s) {
            if (ch == ')') {
                char top = st.top();
                if (top == '(') {
                    st.pop();
                    continue;
                }
                st.push(ch);
            }
            if (ch == '(') {
                st.push(ch);
            }
        }
        return st.size()-1;
    }
};