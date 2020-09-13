//克鲁斯卡尔，会卡常所以静态数组，且因为最多1000个点，所以边的两端u,v可以用u*1000+v一个数字来表示，进而可以直接pair存边的两端以及曼哈顿距离
typedef pair<int,int> pii;
const int MAXN=1000;
int parent[MAXN];
const int MAXM=1000005;
pii e[MAXM];
class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int size=points.size();
        if (size==1)
            return 0;
        union_find(size);
        memset(e,0x3f,sizeof(e));
        int index=0;
        for (int i=0;i<size;++i)
            for (int j=i+1;j<size;++j)
            {
                int d=abs(points.at(i).at(0)-points.at(j).at(0))+abs(points.at(i).at(1)-points.at(j).at(1));
                e[index]={i*1000+j,d};
                ++index;
            }
        sort(e,e+index,[](const pii &A,const pii &B){
            return A.second<B.second;
        });
        int ans=0;
        int cnt=0;
        for (pii & i:e)
        {
            int x=i.first/1000;
            int y=i.first%1000;
            if (!union_v(x,y))
                continue;
            ans+=i.second;
            ++cnt;
            if (cnt==size-1)
                return ans;
        }
        return ans;
        
    }
    void union_find(int n)
    {
        memset(parent,0,sizeof(parent));
        init(n);
    }

    void init(int n)
    {
        for (int i=0;i<n;++i)
            parent[i]=i;
    }

    int find_root(int i)
    {
        if (parent[i]!=i)
        {
            int root=find_root(parent[i]);
            parent[i]=root;
            return root;
        }
        return i;
    }

    bool union_v(int a,int b)
    {
        int a_root=find_root(a);
        int b_root=find_root(b);
        if (a_root==b_root)
            return false;
        parent[a_root]=b_root;
        return true;
    }
};
