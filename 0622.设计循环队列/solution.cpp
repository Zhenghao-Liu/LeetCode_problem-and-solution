//front指向队头，rear指向队尾的下一个，即队列是[front,rear)左闭右开，注意是入队是队尾向后移，出队是队头向后移
class MyCircularQueue {
    vector<int> circle_queue;
    int MAXQSIZE;
    int front,rear;
public:
    /** Initialize your data structure here. Set the size of the queue to be k. */
    MyCircularQueue(int k) {
        MAXQSIZE=k+1;
        circle_queue=vector<int>(MAXQSIZE);
        front=rear=0;
    }
    
    /** Insert an element into the circular queue. Return true if the operation is successful. */
    bool enQueue(int value) {
        if (isFull())
            return false;
        circle_queue.at(rear)=value;
        rear=(rear+1)%MAXQSIZE;
        return true;
    }
    
    /** Delete an element from the circular queue. Return true if the operation is successful. */
    bool deQueue() {
        if (isEmpty())
            return false;
        front=(front+1)%MAXQSIZE;
        return true;
    }
    
    /** Get the front item from the queue. */
    int Front() {
        if (isEmpty())
            return -1;
        return circle_queue.at(front);
    }
    
    /** Get the last item from the queue. */
    int Rear() {
        if (isEmpty())
            return -1;
        return circle_queue.at((rear-1+MAXQSIZE)%MAXQSIZE);
    }
    
    /** Checks whether the circular queue is empty or not. */
    bool isEmpty() {
        return front==rear;
    }
    
    /** Checks whether the circular queue is full or not. */
    bool isFull() {
        return (rear+1)%MAXQSIZE==front;
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
 */
