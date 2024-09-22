class Solution {
public:
    bool reportSpam(vector<string>& message, vector<string>& bannedWords) {
        unordered_map<string,int> hashmap;
        for (auto it: bannedWords) {
            hashmap[it]++;
        }
        int count = 0;
        for (auto it: message) {
            if (hashmap.find(it)!=hashmap.end()) {
                count++;
                if (count>=2) return true;
            }
        }
        return false;
    }
};