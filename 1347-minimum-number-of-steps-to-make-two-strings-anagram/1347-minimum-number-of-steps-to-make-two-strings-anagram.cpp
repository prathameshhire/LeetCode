class Solution {
public:
    int minSteps(string s, string t) {
        unordered_map <char, int> hashmap;
        for (char c:s) {
            hashmap[c]++;
        }
        for (char ch:t) {
            hashmap[ch]--;
        }

        int count=0;
        for (auto it:hashmap) {
            count+=abs(it.second);
        }
        return count/2;
    }
};