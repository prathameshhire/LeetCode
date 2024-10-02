class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int> ans = arr;
        sort(ans.begin(), ans.end());
        unordered_map<int, int> mp;  
        int rank = 1;
        
        for (int i = 0; i < ans.size(); i++) {
            if (mp.find(ans[i]) == mp.end()) {
                mp[ans[i]] = rank++;
            }
        }
        
        for (int i = 0; i < arr.size(); i++) {
            ans[i] = mp[arr[i]];
        }
        
        return ans;
    }
};