//建立字典树然后dfs
class WordDictionary {
public:
    bool is_leaf=false;
    //数组初始化只有全为0才能这样写
    WordDictionary* next[10]={NULL};
    /** Initialize your data structure here. */
    WordDictionary() {
        
    }
    
    /** Adds a word into the data structure. */
    void addnum(int num) {
        WordDictionary* p=this;
        stack<int> helper;
        while (num!=0)
        {
            helper.push(num%10);
            num/=10;
        }
        int temp;
        while(!helper.empty())
        {
            temp=helper.top();
            helper.pop();
            if (p->next[temp]==NULL)
                p->next[temp]=new WordDictionary;
            p=p->next[temp];
        }
        p->is_leaf=true;
    }
};
class Solution {
public:
    vector<int> lexicalOrder(int n) {
        WordDictionary all_nums;
        for (int i=1;i<=n;++i)
            all_nums.addnum(i);
        vector<int> ans;
        dfs(&all_nums,ans,0);
        return ans;
    }
    void dfs(WordDictionary *p,vector<int> &ans,int num)
    {
        if (p->is_leaf)
            ans.push_back(num);
        for (int i=0;i<10;++i)
            if (p->next[i]!=NULL)
                dfs(p->next[i],ans,num*10+i);
    }
};
