/*
 * 允许mi多一个元素于mx
 * 暂缓删除
 */
class Solution {
    int _k;
    priority_queue<int,vector<int>,less<int>> mi;
    priority_queue<int,vector<int>,greater<int>> mx;
    int miSz,mxSz;
    unordered_map<int,int> ump;
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        _k=k;
        init();
        int sz=nums.size();
        vector<double> ans;
        ans.reserve(sz-k+1);
        for (int i=0;i<k-1;i++) {
            add(nums.at(i));
        }
        for (int i=k-1;i<sz;i++) {
            if (i!=k-1) {
                rem(nums.at(i-k));
            }
            add(nums.at(i));
            ans.push_back(sol());
        }
        return ans;
    }
    void init() {
        while (!mi.empty()) {
            mi.pop();
        }
        while (!mx.empty()) {
            mx.pop();
        }
        miSz=mxSz=0;
        ump.clear();
    }
    void balance() {
        if (miSz>mxSz+1) {
            mx.push(mi.top());
            mi.pop();
            miSz--;
            mxSz++;
            while (!mi.empty()) {
                int n=mi.top();
                auto p=ump.find(n);
                if (p==ump.end() || (*p).second==0) {
                    break;
                }
                (*p).second--;
                mi.pop();
            }
        } else if (miSz<mxSz) {
            mi.push(mx.top());
            mx.pop();
            miSz++;
            mxSz--;
            while (!mx.empty()) {
                int n=mx.top();
                auto p=ump.find(n);
                if (p==ump.end() || (*p).second==0) {
                    break;
                }
                (*p).second--;
                mx.pop();
            }
        }
    }
    void rem(int n) {
        ump[n]++;
        if (n<=mi.top()) {
            --miSz;
            if (n==mi.top()) {
                while (!mi.empty()) {
                    int n=mi.top();
                    auto p=ump.find(n);
                    if (p==ump.end() || (*p).second==0) {
                        break;
                    }
                    (*p).second--;
                    mi.pop();
                }
            }
        } else {
            --mxSz;
            if (n==mx.top()) {
                while (!mx.empty()) {
                    int n=mx.top();
                    auto p=ump.find(n);
                    if (p==ump.end() || (*p).second==0) {
                        break;
                    }
                    (*p).second--;
                    mx.pop();
                }
            }
        }
        balance();
    }
    void add(int n) {
        if (mi.empty() || n<=mi.top()) {
            mi.push(n);
            miSz++;
        } else {
            mx.push(n);
            mxSz++;
        }
        balance();
    }
    double sol() {
        if (_k%2==0) {
            return ((double)mi.top()+(double)mx.top())/2;
        }
        return (double)mi.top();
    }
};
