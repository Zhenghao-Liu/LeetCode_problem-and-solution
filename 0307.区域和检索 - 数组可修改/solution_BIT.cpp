class NumArray {
    vector<int> BIT;
    vector<int> _nums;
    int n;
public:
    NumArray(vector<int>& nums) {
        int nums_size=nums.size();
        n=nums_size;
        BIT=vector<int>(nums_size+1,0);
        _nums=vector<int>(nums_size+1,0);
        BIT.at(0)=0;
        for (int i=1;i<=n;++i)
        {
            add(i,nums.at(i-1));
            _nums.at(i)=nums.at(i-1);
        }
    }
    
    void update(int i, int val) {
        ++i;
        int k=val-_nums.at(i);
        _nums.at(i)=val;
        add(i,k);
    }
    
    int sumRange(int i, int j) {
        ++i;
        ++j;
        return prefix(i,j);
    }
    
    int lowbit(int x)
    {
        return x&(-x);
    }

    //让a[x]+=k，x从下标1开始
    void add(int x,int k)
    {
        for (;x<=n;x+=lowbit(x))
            BIT.at(x)+=k;
    }
    //计算a[1]~a[x]的部分和，x从下标1开始
    int ask(int x)
    {
        int ans=0;
        for (;x>0;x-=lowbit(x))
            ans+=BIT.at(x);
        return ans;
    }
    //计算a[x]~a[y]的部分和，x从下标1开始
    int prefix(int x,int y)
    {
        return ask(y)-ask(x-1);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(i,val);
 * int param_2 = obj->sumRange(i,j);
 */
