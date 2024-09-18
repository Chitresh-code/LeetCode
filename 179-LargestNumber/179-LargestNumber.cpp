class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> numbers;

        for (int num : nums) {
            numbers.push_back(to_string(num));
        }

        sort(numbers.begin(), numbers.end(), [](const string& s1, const string& s2) {
            return s1 + s2 > s2 + s1;
        });     
        //This means for two strings s1 and s2, we will check which of the two      possible concatenations (s1 + s2 or s2 + s1) is larger.

        string result;
        for (const string& num : numbers) {
            result += num;
        }

        return result.empty() || result[0] == '0' ? "0" : result;
    }
};