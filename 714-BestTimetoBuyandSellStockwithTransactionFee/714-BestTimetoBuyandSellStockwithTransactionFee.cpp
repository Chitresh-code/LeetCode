class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<int> curr(2, 0), next(2, 0);

        for(int idx=n-1;idx>=0;idx--){
            curr[1] = max(-prices[idx] + next[0], next[1]);
            curr[0] = max(prices[idx] - fee + next[1], next[0]);
            next = curr;
        }
        return next[1];
    }
};