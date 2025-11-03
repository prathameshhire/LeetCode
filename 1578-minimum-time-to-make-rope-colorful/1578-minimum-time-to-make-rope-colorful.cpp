class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int ans = 0;
        int i=0;
        int n = colors.size();
        while(i<n)
        {
            int sum = neededTime[i];
            int maxi = neededTime[i];
            while( (i+1 < n) && colors[i]==colors[i+1])
            {
                sum += neededTime[i+1];
                maxi = max(maxi,neededTime[i+1]); 
                i++;
            }
            i++;
            ans += sum-maxi;
        }
        return ans ;
    }
};