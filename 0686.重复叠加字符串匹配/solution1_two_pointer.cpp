//首先枚举出可能对应B头字母的指针，然后暴力循环遍历A
class Solution {
public:
    int repeatedStringMatch(string A, string B) {
        int A_size=A.size();
        int B_size=B.size();
        vector<int> pos;
        for (int i=0;i<A_size;++i)
            if (A.at(i)==B.at(0))
                pos.push_back(i);
        for (int i:pos)
        {
            int p_A=i;
            int p_B;
            int ans=1;
            for (p_B=0;p_B<B_size;)
            {
                if (A.at(p_A)==B.at(p_B))
                {
                    ++p_A;
                    ++p_B;
                }
                else
                    break;
                if (p_A==A_size && p_B!=B_size)
                {
                    ++ans;
                    p_A=0;
                } 
            }
            if (p_B==B_size)
                return ans;
        }
        return -1;
    }
};
