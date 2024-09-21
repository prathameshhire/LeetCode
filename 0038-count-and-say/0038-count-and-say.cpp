class Solution {
public:
    string countAndSay(int n) {
        if (n == 1) return "1";
        string s = countAndSay(n-1);
        int count=1;
        string ans ="";
        for (int i=0; i<s.size(); i++) {
            while (s[i]==s[i+1] && i<s.size()) {
                count++;
                i++;
            }
            string temp = to_string(count) + s[i];
            ans += temp;
            count =1;
        }
        return ans; 
    }
};