class MyCircularDeque {
    vector<int> v;
    int front;
    int rear;
    int maxsize;
public:
    /** Initialize your data structure here. Set the size of the deque to be k. */
    MyCircularDeque(int k) {
        maxsize=k+1;
        front=0;
        rear=0;
        v=vector<int>(maxsize);
    }
    
    /** Adds an item at the front of Deque. Return true if the operation is successful. */
    bool insertFront(int value) {
        if (isFull())
            return false;
        front=(front-1+maxsize)%maxsize;
        v.at(front)=value;
        return true;
    }
    
    /** Adds an item at the rear of Deque. Return true if the operation is successful. */
    bool insertLast(int value) {
        if (isFull())
            return false;
        v.at(rear)=value;
        rear=(rear+1)%maxsize;
        return true;
    }
    
    /** Deletes an item from the front of Deque. Return true if the operation is successful. */
    bool deleteFront() {
        if (isEmpty())
            return false;
        front=(front+1)%maxsize;
        return true;
    }
    
    /** Deletes an item from the rear of Deque. Return true if the operation is successful. */
    bool deleteLast() {
        if (isEmpty())
            return false;
        rear=(rear-1+maxsize)%maxsize;
        return true;
    }
    
    /** Get the front item from the deque. */
    int getFront() {
        if (isEmpty())
            return -1;
        return v.at(front);
    }
    
    /** Get the last item from the deque. */
    int getRear() {
        if (isEmpty())
            return -1;
        return v.at((rear-1+maxsize)%maxsize);
    }
    
    /** Checks whether the circular deque is empty or not. */
    bool isEmpty() {
        return rear==front;
    }
    
    /** Checks whether the circular deque is full or not. */
    bool isFull() {
        return (rear+1)%maxsize==front;
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
