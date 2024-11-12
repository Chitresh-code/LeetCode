class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        
        std::sort(items.begin(), items.end());

        for(int i = 1; i < items.size(); i++)
        {
            items[i].back() = std::max(items[i - 1].back(), items[i].back());
        }

        std::vector<int> returnVal;

        for(const int& query : queries)
        {
            int bestBeautyIdx = std::upper_bound(items.begin(), items.end(), query,
            [](const int a, const std::vector<int>& b){return a < b.front();}) - items.begin();

            // Since upper bound should've placed us at the first element with a price > query OR
            // one past the last element of the array if query is greater than all the prices in items
            --bestBeautyIdx;

            int beauty = bestBeautyIdx == -1 ? 0 : items[bestBeautyIdx].back();
            returnVal.push_back(beauty);
        }


        return returnVal;
    }
};