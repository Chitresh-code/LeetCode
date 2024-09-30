class CustomStack {
public:
    vector<pair<long long,long long>> vp;
    int mx = 0;
    CustomStack(int sz) {
        mx = sz;
        vp.clear();
    }
    
    void push(int x) {
        if(vp.size() >= mx)
        return;
        vp.push_back({x,0});
        return;
    }
    
    int pop() {
        if(vp.size()==0)
        {
            return -1;
        }
        long long int extra = vp.back().second;
        long long int ans = vp.back().first;
        vp.pop_back();
        ans += extra;
        if(vp.size() > 0)
        {
            long long int prev_ele = vp.back().first;
            long long int prev_extra = vp.back().second;
            vp.pop_back();
            vp.push_back({prev_ele,prev_extra + extra});
        }

        return ans;
    }
    
    void increment(int k, int val) {
        if(vp.size()==0)
        return;
        long long int in = min(k-1,(int)vp.size() - 1);
        vp[in].second += val;
        return;
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */