class Solution {
public:
    bool solve(string s1, string s2) {
        if (s1 == s2) return true;
        int n = s1.length();
        bool result = false;

        for (int i = 1; i<n; i++) {

            bool not_swapped = solve(s1.substr(0,i), s2.substr(0,i)) && solve(s1.substr(i, n-i), s2.substr(i,n-i));
            if (not_swapped) {
                result = true;
                break;
            }
            bool swapped = solve(s1.substr(0,i), s2.substr(n-i, i)) && solve(s1.substr(i, n-i), s2.substr(0, n-i));
            if (swapped) {
                result = true;
                break;
            } 
        
        }

        return result;
    }
    
    bool isScramble(string s1, string s2) {
        return solve(s1, s2);
    }
};