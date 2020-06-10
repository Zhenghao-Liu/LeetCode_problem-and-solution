/**
* 对于每个供暖器都要以最小距离到达房子
* 那换个思路来：反向思路，每个房子要到达供暖器的距离要最小
* 那自然离一个房子最近的供暖器，要么是离该房子左边的第一个供暖器，要么是离该房子右边的第一个供暖器，两者之中的最小值
* 要让所有供暖器都能到达房子，即所有房子都能通过最小距离到达供暖器，所以在所有房子中选取最大的上述距离
* 那只需要找离房子最近的右边第一个供暖器right，因为right-1就一定是离房子最近左边的第一个供暖器
* 那对于下一个房子i+1，他左边距离最小的供暖器必然不在 当前房子i的左边的供暖器范围之内
  因此只需要从right开始匹配
*/
class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        if (houses.empty())
            return 0;
        if (heaters.empty())
            return -1;
        sort(houses.begin(),houses.end());
        sort(heaters.begin(),heaters.end());
        int ans=0;
        int right=0;
        int heaters_size=heaters.size();
        for (int &i:houses)
        {
            while (right+1<heaters_size && heaters.at(right)<i)
                ++right;
            if (right==0)
                ans=max(ans,distance(i,heaters.at(right)));
            else
                ans=max(ans,min(distance(i,heaters.at(right)),distance(i,heaters.at(right-1))));
        }
        return ans;
    }
    int distance(int a,int b)
    {
        return abs(a-b);
    }
};
