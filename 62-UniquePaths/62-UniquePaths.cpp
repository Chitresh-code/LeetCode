class Solution {
public:
    int possibleWays(int i , int j , int m , int n ,vector< vector<int>> & prev){
        if(i >= m || j>= n) return 0;
        if(i == m-1 || j == n-1) return 1;
        if(prev[i][j] == -1){
            int right = possibleWays(i , j+1 , m , n , prev);
            int down = possibleWays(i+1 , j , m , n , prev);
            prev[i][j] = right + down;
        }
        return prev[i][j];
    }
    int uniquePaths(int m, int n) {
        vector< vector<int>> prev( m , vector<int>( n , -1));
        return possibleWays(0 , 0 , m , n ,prev);
    }
};