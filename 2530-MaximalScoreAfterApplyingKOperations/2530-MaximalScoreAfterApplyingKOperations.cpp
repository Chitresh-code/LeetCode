class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        priority_queue<int> pq(nums.begin(), nums.end());
        long long res = 0;
        while (k--) {
            int maxElement = pq.top();
            res += maxElement;
            if (maxElement == 1) return res + k;
            pq.pop();
            pq.push((maxElement+2)/3);
        }
        return res;
    }
};