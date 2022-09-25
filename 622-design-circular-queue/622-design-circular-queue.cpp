class MyCircularQueue {
public:
    vector<int> q;
    int sz, qsize = 0;
    int head = 0;
    
    MyCircularQueue(int k) {
        q.resize(k);    
        sz = k;
    }
    
    bool enQueue(int value) {
        if (isFull()) return false;
        q[addV(head, qsize)] = value;
        qsize++;
        return true;
    }
    
    bool deQueue() {
        if (isEmpty()) return false;
        addW(head, 1);
        qsize--;
        return true;
    }
    
    int Front() {
        if (isEmpty()) return -1;
        return q[head];
    }
    
    int Rear() {
        if (isEmpty()) return -1;
        return q[addV(head, qsize - 1)];
    }
    
    bool isEmpty() {
        return !qsize; 
    }
    
    bool isFull() {
        return qsize == sz;
    }
    
    void addW(int &x, int addon) {
        x = (x + addon) % sz;
    }
    
    int addV(int x, int addon) {
        return (x + addon) % sz;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 * w = last write pointer
 * r = pointer to be read
 */