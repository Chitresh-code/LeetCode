class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        unordered_map<string, int> countMap;

        for (const auto& str : arr) {
            countMap[str]++;
        }

        for (const auto& str : arr) {
            if (countMap[str] == 1) {
                k--;
                if (k == 0) {
                    return str;
                }
            }
        }

        return "";
    }
};
