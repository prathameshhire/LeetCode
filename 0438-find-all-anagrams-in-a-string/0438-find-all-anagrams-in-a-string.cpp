class Solution {
public:
    bool allZeros(vector<int> &freq) {
        for(int i : freq) {
            if(i != 0) return false;
        }
        return true;
    }
    vector<int> findAnagrams(string s, string p) {
        vector<int> freq(26, 0);
        for(char ch:p) freq[ch-'a']++;
        vector<int> result;        
        int i = 0, j = 0;
        while(j < s.length()) {
            freq[s[j] - 'a']--;
            if(j-i+1 == p.length()) {
                if(allZeros(freq)) result.push_back(i);                
                freq[s[i] - 'a']++;
                i++;
            }
            j++;
        }
        return result;
    }
};