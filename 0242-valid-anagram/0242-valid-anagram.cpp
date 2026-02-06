class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char,int> mp;
        for (char c:s) {
            mp[c]++;
        }
        for (char d:t) {
            mp[d]--;
        }
        for (auto &p : mp){
            if (p.second != 0) return false;
        }
        return true;
    }
};