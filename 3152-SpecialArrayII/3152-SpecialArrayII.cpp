vector<int> prefixSum; vector<bool> ans; prefixSum.push_back(0);
for (int i = 1; i < nums.size(); i++) prefixSum.push_back((nums[i] % 2 == nums[i - 1] % 2) ? prefixSum[i - 1] + 1 : prefixSum[i - 1]);
for (vector<int>& query : queries) ans.push_back(prefixSum[query[0]] == prefixSum[query[1]]);
return ans;