class Solution {
public:
    int numberOfSpecialChars(string word) {
        unordered_set<char> st;

        for(char c : word) {
            st.insert(c);
        }

        int count = 0;

        for(char ch = 'a'; ch <= 'z'; ch++) {
            if(st.count(ch) && st.count(toupper(ch))) {
                count++;
            }
        }

        return count;
    }
};