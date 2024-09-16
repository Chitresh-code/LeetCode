class Solution {
public:
    static bool comp(pair<int, int>&a, pair<int, int>&b){
        if(a.first==b.first)
            return a.second<b.second;
        return a.first<b.first;
    }

    int findMinDifference(vector<string>& timePoints) {
        int n = timePoints.size();
        vector<pair<int, int>> v;
        for(auto time: timePoints){
            int hr=(time[0]-'0')*10 + (time[1]-'0');
            int min=(time[3]-'0')*10 + (time[4]-'0');
            v.push_back({hr, min});
        }
        sort(v.begin(), v.end(), comp);

        int hrDiff=24+v[0].first-v[n-1].first;
        int minuteDiff=v[0].second-v[n-1].second;
        if(minuteDiff<0)
            hrDiff--;
        int actualDiff=hrDiff*60+(60+minuteDiff)%60;
        int minDiff=actualDiff;
        for(int i=0;i<n-1;i++){
            hrDiff=v[i+1].first-v[i].first;
            minuteDiff=v[i+1].second-v[i].second;
            if(minuteDiff<0)
                hrDiff--;

            actualDiff=hrDiff*60+(60+minuteDiff)%60;
            minDiff=min(minDiff, actualDiff);
        }
        

        return minDiff;
    }
};

auto init = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();