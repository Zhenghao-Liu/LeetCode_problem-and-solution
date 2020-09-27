class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        int size=asteroids.size();
        int ans_length=0;
        vector<int> ans(size);
        for (int i=0;i<size;++i)
        {
            int ii=asteroids.at(i);
            if (ii>0)
            {
                ans.at(ans_length)=ii;
                ++ans_length;
            }
            else
            {
                int abs_ii=-ii;
                while (ans_length>0 && ans.at(ans_length-1)>0 && ans.at(ans_length-1)<abs_ii)
                    --ans_length;
                if (ans_length>0 && ans.at(ans_length-1)>0 && ans.at(ans_length-1)>=abs_ii)
                {
                    if (ans.at(ans_length-1)==abs_ii)
                        --ans_length;
                }
                else
                {
                    ans.at(ans_length)=ii;
                    ++ans_length;
                }
            }
        }
        ans.resize(ans_length);
        return ans;
    }
};
