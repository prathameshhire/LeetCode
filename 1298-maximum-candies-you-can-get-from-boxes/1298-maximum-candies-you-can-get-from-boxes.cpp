class Solution {
public:
    int dfs(int box, vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes, unordered_set<int> &visited, unordered_set<int> &foundBoxes) {
        if (visited.count(box)) return 0;

        if (status[box] == 0){
            foundBoxes.insert(box);
            return 0;
        }
        
        visited.insert(box);
        int candiesCollected = candies[box];
        
        for (int &newBox : containedBoxes[box]) {
            candiesCollected += dfs(newBox, status, candies, keys, containedBoxes, visited, foundBoxes);
        }
        for (int &newKey : keys[box]) {
            status[newKey] = 1;
            if (foundBoxes.count(newKey)) {
                candiesCollected += dfs(newKey, status, candies, keys, containedBoxes, visited, foundBoxes);
            }
        }

        
        
        return candiesCollected;

    }
    int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes, vector<int>& initialBoxes) {
        int candiesCollected = 0;
        unordered_set<int> visited;
        unordered_set<int> foundBoxes;

        for (int &box : initialBoxes) {
            candiesCollected += dfs(box, status, candies, keys, containedBoxes, visited, foundBoxes);
        }

        return candiesCollected;
    }
};