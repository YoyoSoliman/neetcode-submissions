class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> res;
        for (int a : asteroids) {
            if (res.empty()) {
                res.push_back(a);
                continue;
            }

            bool a_destroyed = false;

            while (!res.empty() and a < 0 and res.back() > 0) {
                if (abs(a) == abs(res.back())) {
                    a_destroyed = true;
                    res.pop_back();
                    break;
                }

                if (abs(a) < abs(res.back())) {
                    a_destroyed = true;
                    break;
                } else {
                    res.pop_back();
                }
            }

            if (!a_destroyed) {
                res.push_back(a);
            }
        }

        return res;
    }
};