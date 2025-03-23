class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n = s1.size();
        int m = s2.size();

        vector<int> s1freq (26,0);
        vector<int> s2freq (26,0);
        int i = 0, j = 0;

        for (char ch: s1) {
            s1freq[ch - 'a']++;
        }

        while (j<m) {
            s2freq[s2[j]-'a']++;
            if (j-i+1 > n) {
                s2freq[s2[i]-'a']--;
                i++;
            }

            if (s1freq == s2freq) return true;

            j++;
        }
        return false;
    }
};