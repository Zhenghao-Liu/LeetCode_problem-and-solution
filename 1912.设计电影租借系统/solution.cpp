typedef pair<int,int> pii;
map<pii,int> price;
struct out {
    int shop,mov,pri;
    out(int a,int b,int c):shop(a),mov(b),pri(c){}
    bool operator <(const out &s) const {
        return (pri<s.pri) ||
            (pri==s.pri && shop<s.shop) ||
            (pri==s.pri && shop==s.shop && mov<s.mov);
    }
};
class MovieRentingSystem {
    set<out> outSt;
    map<int,set<out>> inUmp;
public:
    MovieRentingSystem(int n, vector<vector<int>>& entries) {
        price.clear();
        outSt.clear();
        inUmp.clear();
        for (vector<int> &i:entries) {
            price[{i.at(0),i.at(1)}]=i.at(2);
            inUmp[i.at(1)].emplace(i.at(0),i.at(1),i.at(2));
        }
    }
    
    vector<int> search(int movie) {
        vector<int> ans;
        ans.reserve(5);
        int sz=inUmp[movie].size();
        auto p=inUmp[movie].begin();
        for (int i=0;i<5 && i<sz;i++) {
            ans.push_back(p->shop);
            p++;
        }
        return ans;
    }
    
    void rent(int shop, int movie) {
        out instance=out(shop,movie,price[{shop,movie}]);
        auto p=inUmp[movie].find(instance);
        inUmp[movie].erase(p);
        outSt.insert(instance);
    }
    
    void drop(int shop, int movie) {
        out instance=out(shop,movie,price[{shop,movie}]);
        auto p=outSt.find(instance);
        outSt.erase(p);
        inUmp[movie].insert(instance);
    }
    
    vector<vector<int>> report() {
        vector<vector<int>> ans;
        ans.reserve(5);
        int sz=outSt.size();
        auto p=outSt.begin();
        for (int i=0;i<5 && i<sz;i++) {
            ans.push_back({p->shop,p->mov});
            p++;
        }
        return ans;
    }
};

/**
 * Your MovieRentingSystem object will be instantiated and called as such:
 * MovieRentingSystem* obj = new MovieRentingSystem(n, entries);
 * vector<int> param_1 = obj->search(movie);
 * obj->rent(shop,movie);
 * obj->drop(shop,movie);
 * vector<vector<int>> param_4 = obj->report();
 */