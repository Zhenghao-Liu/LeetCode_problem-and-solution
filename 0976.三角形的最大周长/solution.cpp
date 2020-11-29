class Solution {
public:
    int largestPerimeter(vector<int>& A) {
        int ans=0;
        sort(A.rbegin(),A.rend());
        int size=A.size();
        for (int i=0;i+2<size;++i)
        {
            int a=A.at(i);
            int b=A.at(i+1);
            int c=A.at(i+2);
            if (b+c>a)
            {
                ans=a+b+c;
                break;
            }
        }
        return ans;
    }
};
