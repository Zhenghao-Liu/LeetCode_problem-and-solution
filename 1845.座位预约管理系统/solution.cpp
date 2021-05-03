class SeatManager {
    priority_queue<int,vector<int>,greater<int>> pq;
public:
    SeatManager(int n) {
        while (!pq.empty()) {
            pq.pop();
        }
        for (int i=1;i<=n;i++) {
            pq.push(i);
        }
    }
    
    int reserve() {
        int ans=pq.top();
        pq.pop();
        return ans;
    }
    
    void unreserve(int seatNumber) {
        pq.push(seatNumber);
    }
};

/**
 * Your SeatManager object will be instantiated and called as such:
 * SeatManager* obj = new SeatManager(n);
 * int param_1 = obj->reserve();
 * obj->unreserve(seatNumber);
 */