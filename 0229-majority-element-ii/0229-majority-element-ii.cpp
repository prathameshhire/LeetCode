class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map <int,int> count;
        for (auto it: nums) {
            count[it]++;
            if (count.size() > 2) {
                unordered_map <int,int> newcount;                
                for (auto entry: count) {
                    newcount[entry.first] = entry.second-1; 
                }
                count = newcount;

            }
        }

        vector <int> ans;
        for (auto entry:count) {
            int frequency = 0;
            for (auto num:nums) {
                if (num == entry.first) {
                    frequency++;
                }
            }
            if (frequency > nums.size() /3) ans.push_back(entry.first);
        }
        return ans;
    }
};