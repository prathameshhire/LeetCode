class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;
        for (string s: strs) {
            string sortedS = s;
            sort(sortedS.begin(), sortedS.end());
            mp[sortedS].push_back(s);
        }
        vector<vector<string>> result;
        for (auto &p : mp) {
            result.push_back(p.second);
        }
        return result;
    }
};