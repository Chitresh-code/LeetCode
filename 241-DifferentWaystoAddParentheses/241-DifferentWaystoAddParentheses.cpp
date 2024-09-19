class Solution {
public:


void calc(vector<int> &a,vector<int>& b, vector<int>& c, char op) {

    for(int i = 0; i < a.size(); i++) {
        for(int j = 0; j < b.size(); j++) {

            if(op == '+') {
                c.push_back(a[i] + b[j]);
            } else if(op == '-') {
                c.push_back(a[i] - b[j]);
            } else {
                c.push_back(a[i] * b[j]);
            }
        }
    }
}



vector<int> diffWaysToCompute(string expression) {

    vector<int> intValue;
    vector<int> opValue;
    int curval = -1;

    for(int i = 0; i < expression.size(); i++) {

        if(expression[i] == '+'||expression[i] == '-'||expression[i] == '*') {
            intValue.push_back(curval);
            opValue.push_back(expression[i]);
            curval = -1;
            continue;
        }

        if(curval != -1) {
            curval = curval*10 + (expression[i] - '0');
        } else {
            curval = expression[i] - '0';
        }

    }

    intValue.push_back(curval);

    int n = intValue.size();
    vector<vector<vector<int>>> dp(n,vector<vector<int>>(n,vector<int>()));

    for(int width = 0; width < n; width++) {

        for(int i = 0; i < n - width; i++) {

            int j = i+width;

            if(i == j) {
                dp[i][j].push_back(intValue[i]);
                continue;
            }


            for(int k = i; k+1 <= j;k++) {
                char op = opValue[k];
                calc(dp[i][k],dp[k+1][j],dp[i][j],op);
            }
        }

    }

    return dp[0][n-1];

}
};