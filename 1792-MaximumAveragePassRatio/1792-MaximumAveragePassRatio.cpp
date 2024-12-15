class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        priority_queue<pair<double, int>> q;
        for (int i = 0; i < classes.size(); i++) {
            long long denominator = (long long)classes[i][1] * (classes[i][1] + 1);
            double ratio = (double)(classes[i][1] - classes[i][0]) / denominator;
            q.push({ratio, i});
        }
        while (extraStudents > 0) {
            auto [r, idx] = q.top();
            q.pop();
            int a = classes[idx][0] + 1;
            int b = classes[idx][1] + 1;
            classes[idx][0] = a;
            classes[idx][1] = b;
            long long denominator = (long long)b * (b + 1);
            double new_r = (double)(b - a) / denominator;
            q.push({new_r, idx});
            extraStudents--;
        }
        double ratio = 0;
        for (int i = 0; i < classes.size(); i++) {
            ratio += (double)classes[i][0] / classes[i][1];
        }
        return ratio / classes.size();
    }
};