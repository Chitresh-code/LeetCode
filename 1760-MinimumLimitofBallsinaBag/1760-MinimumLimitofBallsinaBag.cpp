#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minimumSize(vector<int>& nums, int maxOperations) {
        int left = 1, right = *max_element(nums.begin(), nums.end());

        while (left < right) {
            int mid = left + (right - left) / 2;

            if (countOperations(nums, mid) <= maxOperations) {
                right = mid;  // Try to lower the maximum bag size
            } else {
                left = mid + 1;  // Increase the allowed maximum size
            }
        }

        return left;
    }

private:
    int countOperations(const vector<int>& nums, int maxSize) {
        int operations = 0;
        for (int n : nums) {
            operations += (n - 1) / maxSize;  // Number of splits required for current bag
        }
        return operations;
    }
};
```javascript []
console.log('Hello world!')