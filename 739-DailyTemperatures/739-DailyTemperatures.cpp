class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int size = temperatures.size();
        stack<int> indicesStack;
        vector<int> result(size, 0);

        for (int i = size - 1; i >= 0; i--) {

            while (!indicesStack.empty() &&
                   temperatures[indicesStack.top()] <= temperatures[i]) {
                indicesStack.pop();
            }

            if (!indicesStack.empty()) {
                result[i] = indicesStack.top() - i;
            }

            indicesStack.push(i);
        }

        return result;
    }
};
