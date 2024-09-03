class Solution {
public:
    int getLucky(string s, int k) {
        int word = 0;
        for (int ch : s) {
            int temp = ch - 'a' + 1;
            while(temp != 0) {
                word += temp % 10;
                temp /= 10;
            }
        }

        while(k-- > 1) {
            int temp = 0;
            while (word != 0) {
                temp += word % 10;
                word /= 10;
            }
            word = temp;
        }
        return word;   
    }
};