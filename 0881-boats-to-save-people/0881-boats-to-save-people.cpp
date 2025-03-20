class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());
        int l = 0, r = people.size()-1;
        int res = 0;
        while (l<=r) {
            int remain = limit - people[r];
            res++;
            r--;
            if (l<=r && remain >=people[l]) {
                l++;
            } 
        }
        return res;
    }
};