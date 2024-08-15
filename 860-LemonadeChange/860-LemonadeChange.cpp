class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int count_5 = 0, count_10 = 0,count_20 = 0;
        for(auto note : bills) {
            if (note == 5) {
                count_5++;
            }
            if (note == 10) {
                count_10++;
                if (count_5 != 0) {
                    count_5--;
                }
                else return false;
            }
            if (note == 20) {
                count_20++;
                if ((count_10 != 0) && (count_5 != 0)) {
                    count_10--;
                    count_5--;
                }
                else if (count_5 >= 3) {
                    count_5 -= 3;
                }
                else return false;
            }
        }
        return true;
    }
};