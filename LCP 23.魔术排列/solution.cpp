//可以根据tar判断k是多少，之后按这个k模拟下去，判断最终结果与tar是否相同
class Solution {
public:
    bool isMagic(vector<int>& tar) {
        int N=tar.size();
        vector<int> vec(N);
        int ii=0;
        int jj=2;
        while (jj<=N)
        {
            vec.at(ii)=jj;
            ++ii;
            jj+=2;
        }
        jj=1;
        while (ii<N)
        {
            vec.at(ii)=jj;
            jj+=2;
            ++ii;
        }
        // for (int i=0;i<N;++i)
        //     cout <<vec.at(i) << ' ' ;
        int k=0;
        for (int i=0;i<N;++i)
            if (tar.at(i)==vec.at(i))
                ++k;
            else
                break;
        if (k==0)
            return false;
        if (k==N)
            return true;
        vector<int> ans(N);
        for (int i=0;i<k;++i)
            ans.at(i)=vec.at(i);
        for (int i=0;i+k<N;++i)
            vec.at(i)=vec.at(i+k);
        vec.resize(N-k);
        vector<int> t;
        t.reserve(vec.size());
        int index=k;
        while (index<N)
        {
            t.clear();
            for (int i=1;i<vec.size();i+=2)
                t.push_back(vec.at(i));
            for (int i=0;i<vec.size();i+=2)
                t.push_back(vec.at(i));
            for (int i=0;i<t.size() && i<k;++i)
                ans.at(index++)=t.at(i);
            vec.clear();
            for (int i=k;i<t.size();++i)
                vec.push_back(t.at(i));
        }
        return ans==tar;
        
    }
};
