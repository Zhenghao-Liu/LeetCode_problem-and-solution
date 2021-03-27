typedef pair<int,int> pii;
typedef long long ll;
ll mod=1e9+7;
class Solution {
public:
    int getNumberOfBacklogOrders(vector<vector<int>>& orders) {
        priority_queue<pii,vector<pii>,less<pii>> buy;
        priority_queue<pii,vector<pii>,greater<pii>> sell;
        for (vector<int> &i:orders) {
            if (i.at(2)==0) {
                // buy
                int pri=i.at(0),amo=i.at(1);
                while (amo>0 && !sell.empty() && sell.top().first<=pri) {
                    auto [p,a]=sell.top();
                    sell.pop();
                    if (a<=amo) {
                        amo-=a;
                    } else {
                        a-=amo;
                        amo=0;
                        sell.push({p,a});
                    }
                }
                if (amo>0) {
                    buy.push({pri,amo});
                }
            } else {
                // sell
                int pri=i.at(0),amo=i.at(1);
                while (amo>0 && !buy.empty() && buy.top().first>=pri) {
                    auto [p,a]=buy.top();
                    buy.pop();
                    if (a<=amo) {
                        amo-=a;
                    } else {
                        a-=amo;
                        amo=0;
                        buy.push({p,a});
                    }
                }
                if (amo>0) {
                    sell.push({pri,amo});
                }
            }
        }
        ll ans=0;
        while (!sell.empty()) {
            ans+=sell.top().second;
            sell.pop();
            ans%=mod;
        }
        while (!buy.empty()) {
            ans+=buy.top().second;
            buy.pop();
            ans%=mod;
        }
        return ans;
    }
};