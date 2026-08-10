class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        unordered_set<int> good;

        for (vector<int> triple : triplets) {
            if (triple[0] <= target[0] && triple[1] <= target[1] && triple[2] <= target[2]) {
                if (triple[0] == target[0]) {
                    good.insert(0);
                }

                if (triple[1] == target[1]) {
                    good.insert(1);
                }

                if (triple[2] == target[2]) {
                    good.insert(2);
                }
            }
        }

        return good.size()==3;
    }
};
