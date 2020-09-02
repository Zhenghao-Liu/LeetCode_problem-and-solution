class Solution {
public:
    bool containsPattern(vector<int>& arr, int m, int k) {
        int size=arr.size();
        if (m*k>size)
            return false;
        vector<int> key,t;
        key.reserve(m);
        t.reserve(m);
        int count=0;
        for (int i=0;i+m-1<size;++i)
        {
            key.clear();
            count=1;
            for (int j=i;j<i+m;++j)
                key.push_back(arr.at(j));
            for (int j=i+m;j+m-1<size;)
            {
                t.clear();
                int k;
                for (k=j;k<j+m;++k)
                    t.push_back(arr.at(k));
                if (t==key)
                    ++count;
                else
                    break;
                j+=m;
            }
            if (count>=k)
                return true;
        }
        return false;
    }
};
