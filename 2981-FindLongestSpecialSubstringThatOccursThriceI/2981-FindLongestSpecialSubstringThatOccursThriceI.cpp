class Solution {
public:
    int maximumLength(string s) {
        int count[26][51];
        memset(count, 0, sizeof(count));

        int last = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] != s[last]) {
                count[s[last] - 'a'][i - last] += 1;
                last = i;
            }
        }
        count[s[last] - 'a'][s.size() - last] += 1;

        int ans = -1;
        for (int i = 0; i < 26; i++) {
            for (int j = 1; j < 51; j++) {
                if (count[i][j] >= 3) {
                    ans = max(ans, j);
                } else if (j >= 2 && count[i][j] >= 1 && count[i][j] + count[i][j-1] >= 2) {
                    ans = max(ans, j-1);
                } else if (j >= 3 && count[i][j] >= 1) {
                    ans = max(ans, j-2);
                }
            }
        }

        return ans;
    }
};