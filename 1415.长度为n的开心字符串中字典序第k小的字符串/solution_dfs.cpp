class Solution {
    vector<char> mask_a{'b','c'};
    vector<char> mask_b{'a','c'};
    vector<char> mask_c{'a','b'};
    int count;
public:
    string getHappyString(int n, int k) {
        vector<char> mask{'a','b','c'};
        count=0;
        string ans;
        dfs("a",mask_a,n,k,ans);
        dfs("b",mask_b,n,k,ans);
        dfs("c",mask_c,n,k,ans);
        return ans;
    }
    void dfs(string s,vector<char> & mask,int n,int k,string &ans)
    {
        if (count==k)
            return;
        if (s.size()==n)
        {
            ++count;
            if (count==k)
                ans=s;
            return;
        }
        for (char &i:mask)
            if (i=='a')
                dfs(s+'a',mask_a,n,k,ans);
            else if (i=='b')
                dfs(s+'b',mask_b,n,k,ans);
            else
                dfs(s+'c',mask_c,n,k,ans);
    }
};
