/*
 * 异或结果在[a,b]范围内
 * 可以转化成是 <=b的范围 减去 <=a-1 的范围
 * 采用twosum加字典树
 * 采用字典树去看有多少个是<=tar的，然后twosum往字典树加数字
 * 设计到个数，所以字典树要存当前分支下的个属于
 * 如果当前异或结果是小于目标值，那么可以直接结算
   如果当期异或结果是等于目标值，那么需要到下一位进行考虑
 */
const int UP=15;
class Trie {
private:
    int sz=0;
    //数组初始化只有全为0才能这样写
    Trie* arc[2]={NULL};
public:
    /** Initialize your data structure here. */
    Trie() {
        sz=0;
        arc[0]=arc[1]=NULL;
    }
    
    /** Inserts a word into the trie. */
    void insert(int num) {
        Trie* p=this;
        for (int i=UP;i>=0;i--)
        {
            int nxt= ((1<<i)&num)==0 ? 0 : 1;
            if (p->arc[nxt]==NULL)
                p->arc[nxt]=new Trie();
            p=p->arc[nxt];
            p->sz++;
        }
    }
    
    /** Returns if the word is in the trie. */
    int search(int num,int tar) {
        Trie* p=this;
        int ans=0;
        for (int i=UP;i>=0 && p!=NULL;i--) {
            int n= ((1<<i)&num)==0 ? 0 : 1;
            int t= ((1<<i)&tar)==0 ? 0 : 1;
            if (n==0 && t==0) {
                p=p->arc[0];
            } else if (n==0 && t==1) {
                ans+= p->arc[0]==NULL ? 0 : p->arc[0]->sz;
                p=p->arc[1];
            } else if (n==1 && t==0) {
                p=p->arc[1];
            } else if (n==1 && t==1) {
                ans+= p->arc[1]==NULL ? 0 :p->arc[1]->sz;
                p=p->arc[0];
            }
        }
        if (p!=NULL) {
            ans+=p->sz;
        }
        return ans;
    }
};

class Solution {
public:
    int countPairs(vector<int>& nums, int low, int high) {
        Trie trie;
        int ans=0;
        for (int i:nums) {
            ans+=trie.search(i,high)-trie.search(i,low-1);
            trie.insert(i);
        }
        return ans;
    }
};