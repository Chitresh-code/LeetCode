class Solution {
public:
    long long minEnd(int n, int x) {
        long long result = x;
        n--;
        for (int bit = 0; n > 0; bit++) {
            if ((x & (1LL << bit)) == 0) {
                result |= (n & 1LL) << bit;
                n >>= 1;
            }
        }
        return result;
    }
};