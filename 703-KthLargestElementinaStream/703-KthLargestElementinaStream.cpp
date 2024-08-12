class KthLargest {
    priority_queue<int,vector<int>,greater<int>> minheap;
    int idx;
public:
    KthLargest(int k, vector<int>& nums) {
        for(int i:nums){
            minheap.push(i);
            if(minheap.size()>k)
            minheap.pop();
        }
        idx=k;
    }
    
    int add(int val) {
        minheap.push(val);
        while(minheap.size()>idx)
        minheap.pop();

        return minheap.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */