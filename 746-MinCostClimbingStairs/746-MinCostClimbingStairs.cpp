class Solution {
public:
    int totalCost(int n,vector<int>&cost,vector<int>&dp){
        if(dp[n]!=-1) return dp[n];
        dp[n] = cost[n] + min(totalCost(n+1,cost,dp),totalCost(n+2,cost,dp));
        return dp[n];
    }
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> dp(cost.size()+2,-1);
        dp[cost.size()]=0;
        dp[cost.size()+1]=INT_MAX;
        
        return min(totalCost(0,cost,dp),totalCost(1,cost,dp));
    }
};