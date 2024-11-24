class Solution {
public:
    #define ll long long
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        ll ans = 0, m = matrix.size(), n = matrix[0].size();
        ll smallest_abs = INT_MAX;
        ll cnt = 0; 

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                int curr = matrix[i][j];
                if(curr < 0) {
                    cnt++;
                    curr = -curr;
                }
                ans += curr;
                smallest_abs = min(smallest_abs, (ll)curr);
            }
        }
        return (cnt % 2) ? ans - 2 * smallest_abs : ans;
    }
};
