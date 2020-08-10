//方法同solution1，改成静态数组提速明显
const int maxn=1024;
int pos[maxn];
class Solution {
public:
    int longestAwesome(string s) {
        int s_size=s.size();
        memset(pos,0x3f,sizeof(pos));
        pos[0]=-1;
        int sum=0;
        int ans=0;
        for (int i=0;i<s_size;++i)
        {
            int a=1<<(s.at(i)-'0');
            sum^=a;
            if (pos[sum]!=0x3f3f3f3f)
                ans=max(ans,i-pos[sum]);
            for (int ii=0;ii<10;++ii)
            {
                int j=sum^(1<<ii);
                if (pos[j]!=0x3f3f3f3f)
                    ans=max(ans,i-pos[j]);
            }
            if (pos[sum]==0x3f3f3f3f)
                pos[sum]=i;
        }
        return ans;
    }
};
