class Solution {
public:
    string minWindow(string s, string t) {
        if(t.empty()) return "";
        unordered_map<char, int> window, freq;
        for(char c : t) {
            freq[c]++;
        }
        int need = freq.size();
        int i = 0, j = 0;
        pair<int, int> res = {-1,-1};
        int result = INT_MAX;
        int have = 0;
        while(j<s.length()) {
            char c = s[j];
            window[c]++;
            if(freq.count(c) && window[c] == freq[c]) {
                have++;
            }
            while(have == need) {
                if(j-i+1 < result) {
                    result = j-i+1;
                    res = {i,j};
                }
                window[s[i]]--;
                if(freq.count(s[i]) && window[s[i]] < freq[s[i]]) {
                    have--;
                }
                i++;
            }
            j++;
        }
        return result == INT_MAX ? "": s.substr(res.first, result);
    }
};