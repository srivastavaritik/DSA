class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> res;
        for (int i = 0; i < asteroids.size(); ++i) {
            if (asteroids[i] > 0) res.push_back(asteroids[i]);
            else {
                while (!res.empty() && res.back() > 0 && res.back() < -asteroids[i]) res.pop_back();
                if (res.empty() || res.back() < 0) res.push_back(asteroids[i]);
                else if (res.back() == -asteroids[i]) res.pop_back();
            }
        }
        return res;
    }
};