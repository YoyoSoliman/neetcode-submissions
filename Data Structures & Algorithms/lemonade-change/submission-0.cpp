class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int number_of_10 = 0;
        int number_of_5 = 0;
        int number_of_20 = 0;
        for (int b : bills) {
            if (b == 5) {
                number_of_5++;
            }
            if (b==10) {
                number_of_10++;
            }
            if (b==20) {
                number_of_20++;
            }

            int change = b - 5;

            while (change > 0) {
                if (number_of_20 > 0 and change >= 20) {
                    number_of_20--;
                    change-=20;
                    continue;
                }

                if (number_of_10 > 0 and change >= 10) {
                    number_of_10--;
                    change-=10;
                    continue;
                }

                if (number_of_5 > 0 and change >= 5) {
                    number_of_5--;
                    change-=5;
                    continue;
                }

                return false;
            }
        }
        return true;
    }
};