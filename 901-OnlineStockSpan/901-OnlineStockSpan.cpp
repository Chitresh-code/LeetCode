class StockSpanner {
public:
    int curr;
    stack<pair<int,int>> st;
    StockSpanner() {
        curr=0;
        st.push({INT_MAX,0});
    }
    
    int next(int price) {
        while(price>=st.top().first){
            st.pop();
        }
        int val=++curr-st.top().second;
        st.push({price,curr});
        return val;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */