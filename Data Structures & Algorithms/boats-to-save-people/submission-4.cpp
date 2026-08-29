class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        std::sort(people.begin(),people.end());

        int l = 0;
        int r = people.size() - 1;
        int count = 0;

        while (l < r) {
            if (people[r] == limit) {
                count++;
                r--;
                continue;
            }

            if (people[l] + people[r] <= limit) {
                count++;
                l++;
                r--;
            } else {
                count++;
                r--;
            }
        }
        if (l == r) {
            count++;
        }

        return count;
    }
};