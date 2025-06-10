class Solution {
public:
    int maxDifference(string s) {
        if (s.length() == 0) return 0;
        vector<int> mp (26,0);
        for (char c:s) {
            mp[c-'a']++;
        }
        int oddMax = 0, evenMin = INT_MAX;
        for (int i = 0; i<mp.size(); i++) {
            if (mp[i]%2 == 1 && mp[i] > oddMax) {
                oddMax = mp[i];
            }
            if (mp[i]%2 == 0 && mp[i] < evenMin && mp[i] != 0) {
                evenMin = mp[i];
            }
        }
        return oddMax-evenMin;
    }
};