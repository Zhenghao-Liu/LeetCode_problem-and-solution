/*
* 用unorder_set会有浪费，即肯定不是最终结果的但是还是要insert
* 采用字典树，把所有的数按照二进制下存入
* 对每个数在字典树中求异或最大可能，求完所有数后即答案
*/
class Trie {  
public:
    //数组初始化只有全为0才能这样写
    Trie* arc[2]={NULL};
    int max_length=1;

    /** Initialize your data structure here. */
    Trie(int _max_length=1) {
        max_length=_max_length;
    }
    
    /** Inserts a word into the trie. */
    void insert(int num) {
        Trie* p=this;
        int mask=1<<(max_length-1);
        for (int i=0;i<max_length;++i)
        {
            int cur_bit=(num & mask) == mask ? 1 : 0;
            mask>>=1;
            if (p->arc[cur_bit]==NULL)
                p->arc[cur_bit]=new Trie();
            p=p->arc[cur_bit];
        }
    }
};
class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        int max_num=INT_MIN;
        int nums_size=nums.size();
        for (int &i:nums)
            if (i>max_num)
                max_num=i;
        int max_num_length=max_num!=0 ? 32-__builtin_clz(max_num) : 1;
        Trie *root=new Trie(max_num_length);
        for (int &i:nums)
            root->insert(i);
        int ans=INT_MIN;
        for (int &i:nums)
        {
            Trie *p=root;
            int mask=1<<(max_num_length-1);
            int try_ans=0;
            for (int j=0;j<max_num_length;++j)
            {
                int cur_bit=(i & mask) == mask ? 1 : 0;
                int wanted_bit=cur_bit^1;
                mask>>=1;
                try_ans<<=1;
                if (p->arc[wanted_bit]!=NULL)
                {
                    try_ans|=1;
                    p=p->arc[wanted_bit];
                }
                else
                {
                    p=p->arc[wanted_bit^1];
                }
            }
            if (try_ans>ans)
                ans=try_ans;
        }
        return ans;
    }
};
