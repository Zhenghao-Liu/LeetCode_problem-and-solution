class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int,vector<int>,less<int>> pq;
        for (int i:piles) {
            pq.push(i);
        }
        for (int i=0;i<k;i++) {
            int cur=pq.top();
            pq.pop();
            cur-=cur/2;
            pq.push(cur);
        }
        int ans=0;
        while (!pq.empty()) {
            ans+=pq.top();
            pq.pop();
        }
        return ans;
    }
};