class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(false);
    }
    int countConsistentStrings(string allowed, vector<string>& words) {
        uint8_t invalid[128];
        memset(&invalid['a'], 1, 26);
        for (auto c: allowed) invalid[c] = 0;
        int consistent{0};
        for (auto const& word: words) {
            int all_valid{1};
            for (auto c: word) {
                if (invalid[c]) {
                    all_valid = 0;
                    break;
                }
            }
            consistent += all_valid;
        }
        return consistent;
    }
};