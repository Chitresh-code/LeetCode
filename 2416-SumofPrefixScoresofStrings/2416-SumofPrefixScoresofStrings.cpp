class Solution {
public:
    vector<int> sumPrefixScores(vector<string>& words) {
        int n = words.size();
        vector<int> indexes(n);
        iota(indexes.begin(), indexes.end(), 0);
        sort(indexes.begin(), indexes.end(), [&](const int& i, const int& j) {
            return words[i] < words[j];
        });

        vector<int> delta(n);
        auto check = [&](int j, int cur, int pos) -> bool {
            if (words[indexes[cur]].size() - 1 < pos) return 0;
            else return words[indexes[cur]][pos] == words[indexes[j]][pos];
        };
        vector<int> last(1001, n);
        for (int i = 0; i < n; ++i) {
            int lcp = 0;
            if (i != 0) {
                while(lcp < min(words[indexes[i]].size(), words[indexes[i - 1]].size())) {
                    if (words[indexes[i]][lcp] == words[indexes[i - 1]][lcp]) ++lcp;
                    else break;
                }
            }
            for (int j = lcp; j < words[indexes[i]].size(); ++j) {
                int lo = i;
                int hi = last[j];
                while (hi - lo > 1) {
                    int mid = (lo + hi)/2;
                    if (check(i, mid, j)) {
                        lo = mid;
                    } else {
                        hi = mid;
                    }
                }
                last[j + 1] = lo +  1;
                delta[i] += lo - i  +1;
                if (lo + 1 < n) delta[lo + 1] -= lo - i + 1;
            }
        }
        for (int i = 1; i < n; ++i) delta[i] += delta[i-1];
        vector<int> ans(n);
        for (int i = 0; i < n; ++i) ans[indexes[i]] = delta[i];
        return ans;
    }
};