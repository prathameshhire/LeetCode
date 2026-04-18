class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size()-k+1;
        vector<int> list(n);
        deque<int> dq;
        for (int i = 0; i<nums.size(); i++) {
            if(!dq.empty() && dq.front() < i-k+1) {
                dq.pop_front();
            }
            while(!dq.empty() && nums[dq.back()] <= nums[i]) {
                dq.pop_back();
            }
            dq.push_back(i);
            if(i >= k-1) list[i-k+1] = nums[dq.front()];
        }
        return list;
    }
};