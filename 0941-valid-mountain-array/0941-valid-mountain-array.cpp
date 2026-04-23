class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        if (arr.size() < 3) return false;
        int n = arr.size();
        int i;
        if(arr[1] < arr[0]) return false;
        for(i = 1; i<n; i++) {
            if(arr[i] == arr[i-1]) return false;
            else if(i != 1 && arr[i] < arr[i-1]) break;
        }
        if(i == n && arr[n-1] >= arr[n-2]) return false;
        for(;i<n; i++) {
            if(arr[i] >= arr[i-1]) return false;
        }
        return true;
    }
};