class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        int n = deck.size();
        vector <int> ans(n);
        queue <int> q;
        
        for (int i=0; i< n; i++) {
            q.push(i);
        }
        
        sort (deck.begin(), deck.end());
        
        for (int i=0; i< n; i++) {
            int index = q.front();
            ans[index] = deck[i];
            q.pop();
            
            if (!q.empty()) {
                int back = q.front();
                q.pop();
                q.push(back);
            }
        }
        return ans;
    }
};