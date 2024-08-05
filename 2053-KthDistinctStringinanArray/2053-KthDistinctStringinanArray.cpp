class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        vector<string> sol;

        for (auto i = arr.begin(); i < arr.end(); ++i) {
            int check = 0;
            for (auto j = arr.begin(); j < arr.end(); ++j) {
                if (i != j && *i == *j) {
                    check++;
                    break;
                }
            }

            if (check == 0) {
                sol.push_back(*i);
            }
        }

        if (k > sol.size()) {
            return "";
        }

        return sol[k-1];
    }
};
