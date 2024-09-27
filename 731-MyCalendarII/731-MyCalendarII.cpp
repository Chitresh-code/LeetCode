class MyCalendarTwo {
public:
    multiset<pair<int,int>> st;
    MyCalendarTwo() {
        
    }
    
    bool book(int start, int end) {
        int ps = -1,pe = -1;
        int ch = 1;
        for(auto it:st)
        {
            if(ps != -1 && pe != -1)
            {
                if(pe > it.first)
                {
                    int is = it.first;
                    int ie = min(pe,it.second);
                    if(start <= is && end > is)
                    {
                        ch = 0;
                        break;
                    }
                    else if(ie > start && ie <= end)
                    {
                        ch = 0;
                        break;
                    }
                    else if(start >= is && end <= ie)
                    {
                        ch = 0;
                        break;
                    }
                }
            }
            if(it.second > pe)
            {
                ps = it.first;
                pe = it.second;
            }
        }

        if(ch)
        {
            //cout<<start<<" "<<end<<endl;
            st.insert({start,end});
        }
        return ch;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */