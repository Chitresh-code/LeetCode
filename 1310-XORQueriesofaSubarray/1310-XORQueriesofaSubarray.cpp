class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        vector<int> pre(arr.size());

        pre[0] = arr[0];
        for(int i = 1; i < arr.size(); i++) {
            pre[i] = pre[i - 1]^arr[i];
        }

        vector<int> result(queries.size());
        for(int i = 0; i < queries.size(); i++) {
            int first = queries[i][0];
            int second = queries[i][1];

            if(first == 0) result[i] = pre[second];
            else result[i] = pre[first - 1]^pre[second];
        }
    return result;
    }
};