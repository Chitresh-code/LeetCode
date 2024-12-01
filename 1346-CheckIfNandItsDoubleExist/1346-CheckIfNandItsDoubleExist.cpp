class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        int size_nums = arr.size();
        for(int i=0;i<size_nums;i++)
        {
            for(int j=0;j<size_nums;j++)
            {
                if(i != j)
                {
                    if(arr[i] == 2 *arr[j])
                    {
                        return true;
                    }
                }
            }
        }

        return false;
    }
};