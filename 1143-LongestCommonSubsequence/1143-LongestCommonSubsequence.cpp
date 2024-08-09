// Memoization
//  class Solution {
//  public:
//      int calculate_longest_Common_Subsequence(string& text1, string& text2,
//      int ind1, int ind2,vector<vector<int>>& dp){
//          if(ind1<0 || ind2<0) return 0;
//          if(dp[ind1][ind2]!=-1) return dp[ind1][ind2];
//          if(text1[ind1]==text2[ind2]){
//              return dp[ind1][ind2]=1 +
//              calculate_longest_Common_Subsequence(text1, text2, ind1-1,
//              ind2-1, dp);
//          }else{
//              return
//              dp[ind1][ind2]=max(calculate_longest_Common_Subsequence(text1,
//              text2, ind1-1, ind2, dp),
//              calculate_longest_Common_Subsequence(text1, text2, ind1, ind2-1,
//              dp));
//          }
//      }
//      int longestCommonSubsequence(string text1, string text2) {
//          int n=text1.length(), m=text2.length();
//          vector<vector<int>> dp(n, vector<int>(m,-1));
//          return calculate_longest_Common_Subsequence(text1, text2, n-1, m-1,
//          dp);
//      }
//  };

/**************************************************************************************************************************************************************************************************************************************************************/

// Memoization:Better
//  class Solution {
//  public:
//     int calculate_longest_Common_Subsequence(string& text1, string& text2,
//     int ind1, int ind2,vector<vector<int>>& dp){
//          if(ind1==0 || ind2==0) return 0;
//          if(dp[ind1][ind2]!=-1) return dp[ind1][ind2];
//          if(text1[ind1-1]==text2[ind2-1]){
//              return dp[ind1][ind2]=1 +
//              calculate_longest_Common_Subsequence(text1, text2, ind1-1,
//              ind2-1, dp);
//          }else{
//              return
//              dp[ind1][ind2]=max(calculate_longest_Common_Subsequence(text1,
//              text2, ind1-1, ind2, dp),
//              calculate_longest_Common_Subsequence(text1, text2, ind1, ind2-1,
//              dp));
//          }
//      }
//     int longestCommonSubsequence(string text1, string text2) {
//          int n=text1.length(), m=text2.length();
//           vector<vector<int>> dp(n+1, vector<int>(m+1,-1));
//           return calculate_longest_Common_Subsequence(text1, text2, n, m,
//           dp);
//       }
//  };

/*************************************************************************************************************************************************************************************************************************************************************/

// Tabulation

// class Solution {
// public:
//     int longestCommonSubsequence(string text1, string text2) {
//         int n = text1.length(), m = text2.length();
//         // vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
//         vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
//         // Initialize the base cases
//         for (int i = 0; i <= n; i++) {
//             dp[i][0] = 0;
//         }
//         for (int i = 0; i <= m; i++) {
//             dp[0][i] = 0;
//         }
//         for (int i = 1; i <= n; i++) {
//             for (int j = 1; j <= m; j++) {
//                 if (text1[i - 1] == text2[j - 1]) {
//                     dp[i][j] = 1 + dp[i - 1][j - 1];
//                 } else {
//                     dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
//                 }
//             }
//         }
//         return dp[n][m];
//     }
// };


/******************************************************************************************************************************************************************************/


//Space Optimization

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.length(), m = text2.length();
        vector<int> prev(m + 1, 0), curr(m + 1, 0);

        // Initialize the base cases
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (text1[i - 1] == text2[j - 1]) {
                    curr[j] = 1 + prev[j - 1];
                } else {
                    curr[j] = max(prev[j], curr[j - 1]);
                }
            }
            // Correctly copy values from curr to prev for the next iteration
            swap(prev, curr);
        }
        return prev[m];
    }
};

