class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>>& logs, int x, vector<int>& queries) {
        vector<pair<int, int>> sortedQueries;
        for (int i = 0; i<queries.size(); i++) {
            sortedQueries.push_back({queries[i], i});
        }
        sort(sortedQueries.begin(), sortedQueries.end()); //[[10,0], [11,1]]
        sort(logs.begin(), logs.end(), [](const auto &a, const auto &b) {
            return a[1] < b[1];
        }); // logs = [[1,3], [1,5], [2,6]]

        vector<int> answer(queries.size(), 0);
        vector<int> mp (n+1, 0);
        int left = 0, right = 0;
        int uniqueServerAccessed = 0;
        for (auto &it : sortedQueries) {
            int index = it.second;
            int time = it.first;
            while (right < logs.size() && logs[right][1] <= time) {
                if (mp[logs[right][0]] == 0) {
                    uniqueServerAccessed++;
                }
                mp[logs[right][0]]++;
                right++;
            }
            while (left < logs.size() && logs[left][1] < time - x){
                if (mp[logs[left][0]] == 1) {
                    uniqueServerAccessed--;
                }
                mp[logs[left][0]]--;
                left++;
            }
            answer[index] = n - uniqueServerAccessed;
        }

        return answer;
    }
};