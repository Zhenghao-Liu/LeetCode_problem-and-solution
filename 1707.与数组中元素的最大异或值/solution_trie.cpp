/*
 * 2^30=1'073'741'824 > 1e9
 * 因此最多需要30位的二进制存储就可以表示所有元素，采用字典树
   存储时候按照从高位到低位的方向去存，即10，先存1再存0
   这样子保证异或结果能尽可能的大
 * 且是离线算法：根据mi进行升序排序
 * 在字典树上贪心的进行dfs，即尽可能往异或1的结果方向去走
 */
const int UP=30;
class Trie {
private:
    //数组初始化只有全为0才能这样写
    Trie* arc[2]={NULL};
public:

    Trie() {}
    
    void insert(int word) {
        Trie *p=this;
        int mask=1<<(UP-1);
        while (mask!=0) {
            int nxt= (mask&word)==0 ? 0 : 1;
            if (p->arc[nxt]==NULL) {
                p->arc[nxt]=new Trie;
            }
            p=p->arc[nxt];
            mask>>=1;
        }
    }
    
    int dfs(int word) {
        Trie *p=this;
        int ans=0;
        int mask=1<<(UP-1);
        while (mask!=0) {
            int nxt= (mask&word)==0 ? 1 : 0;
            if (p->arc[nxt]!=NULL) {
                ans|=mask;
                p=p->arc[nxt];
            } else if (p->arc[(nxt^1)]!=NULL) {
                p=p->arc[(nxt^1)];
            } else {
                return -1;
            }
            mask>>=1;
        }
        return ans;
    }
};
class Solution {
public:
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        int nums_size=nums.size();
        sort(nums.begin(),nums.end());
        int queries_size=queries.size();
        vector<int> idx(queries_size);
        for (int i=0;i<queries_size;i++) {
            idx.at(i)=i;
        }
        sort(idx.begin(),idx.end(),[&queries](const int &A,const int &B){
            return queries.at(A).at(1)<queries.at(B).at(1);
        });
        vector<int> ans(queries_size);
        int idx_nums=0;
        Trie trie;
        for (int i=0;i<queries_size;++i) {
            int ii=idx.at(i);
            int xi=queries.at(ii).at(0),mi=queries.at(ii).at(1);
            while (idx_nums<nums_size && nums.at(idx_nums)<=mi) {
                trie.insert(nums.at(idx_nums));
                idx_nums++;
            }
            ans.at(ii)=trie.dfs(xi);
        }
        return ans;
    }
};
