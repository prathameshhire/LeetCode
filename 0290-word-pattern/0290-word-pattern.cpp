class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<string, char> mp;
        string word  = "";
        vector<string> words;
        for (int j = 0; j<s.length(); j++) {
            if (s[j] == ' ') {
                words.push_back(word);
                word = "";
                continue;
            }
            word += s[j];
        }
        words.push_back(word);
        unordered_set<char> used;
        if (pattern.length() != words.size()) return false;
        for (int i = 0; i<pattern.length(); i++) {
            string key = words[i];
            if (mp.find(key) == mp.end()) {
                if (used.find(pattern[i]) == used.end()) {
                    mp[key] = pattern[i];
                    used.insert(pattern[i]);
                }
                else return false;
            } 
            if (mp.find(key) != mp.end()) {
                if (mp[key] != pattern[i]) return false;
            }
        }
        return true;
    }
};