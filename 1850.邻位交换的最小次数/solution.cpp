class Solution {
public:
    int getMinSwaps(string num, int k) {
        string s=num;
        while (k>0) {
            k--;
            next_permutation(s.begin(),s.end());
        }
        int ans=0;
        int sz=num.size();
        for (int i=0;i<sz;i++) {
            if (num.at(i)!=s.at(i)) {
                int j=i+1;
                for (;j<sz && s.at(j)!=num.at(i);j++);
                for (;j>i;j--) {
                    swap(s.at(j),s.at(j-1));
                    ans++;
                }
            }
        }
        return ans;
    }
};