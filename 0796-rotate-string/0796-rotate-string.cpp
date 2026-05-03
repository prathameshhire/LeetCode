class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.length() != goal.length()) return false;
        int n = s.length();
        for(int i = 0; i<n; i++) {
            int j = 0;
            bool equal = true;
            while(j < n) {
                if(!(s[j] == goal[(i+j) % n])) {
                    equal = false;
                    break;
                }
                j++;
            }
            if(equal) return true;  
        }
        return false;
    }
};