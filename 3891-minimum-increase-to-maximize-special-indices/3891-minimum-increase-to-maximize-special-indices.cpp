class Solution {
public:
    typedef long long ll;
    long long minIncrease(vector<int>& nums) {
        int n = nums.size();
        if(n <= 2) return 0;
        vector<ll> cost(n,0);
        for(int i = 1; i<n-1; i++){
            ll need = max(nums[i-1], nums[i+1])+1;
            cost[i] = max(0LL, need-nums[i]);
        }
        ll result = 0;
        if(n%2 == 0) {
            int k = n/2-1;
            vector<ll>pref(k+1,0);
            for(int i = 1; i<=k; i++) {
                pref[i] = pref[i-1] + cost[2*i-1];
            }
            vector<ll>suff(k+1, 0);
            for(int i = k-1; i>=0; i--){
                suff[i] = suff[i+1] + cost[2*i+2];
            }
            result = LLONG_MAX;
            for(int i = 0; i<=k; i++) {
                result = min(result, pref[i] + suff[i]);
            }
            return result;
        }
        else {
            for (int i = 1; i < n-1; i+=2) {
                result += cost[i];
            } 
            return result;
        }
    }
};