//完全按照h指数的定义来做
class Solution {
public:
    int hIndex(vector<int>& citations) {
        int citations_size=citations.size();
        for (int i=citations_size;i>0;--i)
        {
            int temp=0;
            for (int& j:citations)
                if (j>=i)
                    ++temp;
            if (temp>=i)
                return i;
        }
        return 0;
    }
};
