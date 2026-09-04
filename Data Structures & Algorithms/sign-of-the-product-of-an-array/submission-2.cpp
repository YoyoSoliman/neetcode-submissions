class Solution {
public:
    int arraySign(vector<int>& nums) {

        int numberofN = 0;

        for (int num : nums) {
            if (num == 0) {
                return 0;
            }
            if (num < 0) {
                numberofN++;
            }
        }

        if (numberofN % 2 == 1) {
            return -1;
        }

        return 1;
    }
};