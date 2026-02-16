class Solution {
public:
    long long maximumPoints(vector<int>& enemyEnergies, int currentEnergy) {
        sort(enemyEnergies.begin(), enemyEnergies.end());
        if (currentEnergy < enemyEnergies[0]) return 0;
        long long point = 1;
        currentEnergy -= enemyEnergies[0];
        long long sum = accumulate(enemyEnergies.begin(), enemyEnergies.end(), 0LL) - enemyEnergies[0];
        sum += currentEnergy;
        point += (sum/enemyEnergies[0]);
        return point;
    }
};