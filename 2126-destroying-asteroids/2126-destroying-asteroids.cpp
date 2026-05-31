class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        sort(asteroids.begin(), asteroids.end());
        long long m = mass;
        for(int asteroid: asteroids) {
            if(asteroid <= m) m += asteroid;
            else return false;
        }
        return true;
    }
};