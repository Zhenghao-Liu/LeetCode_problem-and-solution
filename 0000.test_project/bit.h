#ifndef BIT
#define BIT

#include<vector>
using namespace std;

class bit {
private:
    vector<int> t;
    int n;
public:
    bit() {
        t.clear();
        n=0;
    }

    bit(int n) {
        t=vector<int>(n+1);
        this->n=n;
    }

    int lowbit(int x)
    {
        return x&(-x);
    }

    void add(int x,int k)
    {
        for (;x<=n;x+=lowbit(x))
            t.at(x)+=k;
    }

    int ask(int x)
    {
        int ans=0;
        for (;x>0;x-=lowbit(x))
            ans+=t.at(x);
        return ans;
    }

    int interval_sum(int x,int y)
    {
        return ask(y)-ask(x-1);
    }
};

#endif