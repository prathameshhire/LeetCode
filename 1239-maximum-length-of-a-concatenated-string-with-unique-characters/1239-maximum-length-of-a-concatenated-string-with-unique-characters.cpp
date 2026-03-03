class Solution {
public:
    
    bool hasDuplicate(string &s1, string &s2) {
        vector<int> vec(26,0);

        for (char &ch : s1) {
            if (vec[ch-'a'] > 0) return true;
            vec[ch - 'a']++;
        }

        for (char &ch : s2) {
            if (vec[ch-'a'] > 0) return true;
        }

        return false;
    }

    int solve(string temp, int i, vector<string> & arr, int &n) {
        if (i == n) return temp.length();

        int include = 0;
        int exclude = 0;

        if (hasDuplicate(arr[i], temp)) {
            exclude = solve(temp, i+1, arr, n);
        }
        else {
            include = solve(temp + arr[i], i+1, arr, n);
            exclude = solve(temp, i+1, arr, n);
        }

        return max(include, exclude);
    }

    int maxLength(vector<string>& arr) {
        string temp = "";
        int n = arr.size();
        return solve(temp, 0, arr, n);
    }

};