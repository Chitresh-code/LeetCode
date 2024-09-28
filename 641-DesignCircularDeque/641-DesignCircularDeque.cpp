class MyCircularDeque {
    int r;
    int f;
    int count;
    vector<int> deque;
public:
    MyCircularDeque(int k) {
        r=f=-1;
        count=0;
        deque.resize(k);
    }
    bool insertFront(int value) {
        if(isFull()) return false;
        if(isEmpty()){
            r=0;
            f=0;
        }
        else{
            f--;
            if(f<0) f=deque.size()-1;
        }
        deque[f]=value;
        count++;
        return true;
    }
    
    bool insertLast(int value) {
        if(isFull()) return false;
        if(isEmpty()){
            f=0;
            r=0;
        }
        else
            r=(r+1)%deque.size();
        deque[r]=value;
        count++;
        return true;
    }
    
    bool deleteFront() {
        if(isEmpty()) return false;
        f=(f+1)%deque.size();
        count--;
        if(count==0){
            f=-1; r=-1;
        }
        return true;
    }
    
    bool deleteLast() {
        if(isEmpty()) return false;
        r--;
        if(r<0) r=deque.size()-1;
        count--;
        if(count==0){
            f=-1; r=-1;
        }
        return true;
    }
    
    int getFront() {
        if(isEmpty()) return -1;
        return deque[f];
    }
    
    int getRear() {
        if(isEmpty()) return -1;
        return deque[r];
    }
    
    bool isEmpty() {
        return (count==0);
    }
    
    bool isFull() {
        return (count==deque.size());
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */