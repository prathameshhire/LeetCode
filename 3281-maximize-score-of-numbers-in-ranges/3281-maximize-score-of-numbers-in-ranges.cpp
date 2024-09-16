class Solution {
private:
    bool check(vector<int> arr, int d, int mid) {
        for (int i=1; i<arr.size(); i++) {
            if (arr[i]-arr[i-1]>=mid) continue;
            else {
                if (arr[i]+d-arr[i-1]<mid) return false;
                arr[i]=arr[i-1]+mid;
            }
        }
        return true;
    }
public:
    int maxPossibleScore(vector<int>& start, int d) {
        long long l=0, r=INT_MAX;
        long long ans;
        sort(start.begin(), start.end());
        while(l<=r) {
            int mid=(l+r)/2;
            if(check(start,d,mid)) {
                ans=mid;
                l=mid+1;
            }
            else r=mid-1;
        }
        return ans;
    }
};