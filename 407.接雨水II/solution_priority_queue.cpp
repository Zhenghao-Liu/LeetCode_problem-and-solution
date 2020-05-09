/**
* 把每一个元素称作块。因为那个图片给的好像瓷砖啊。
* 其实做这题一开始都是想的是对于每一个块，去找它四个方向最高的高度中的最小值(二维下则是左右最高的高度取较小的那一个)作为上界，当前块作为下界
  但是这4个方向每次遍历复杂度过高，且不能像二维那样去提前预存每个方向的最大值
* 那可以反过来我不以每个块为处理单元，而是以块的四周作为处理单元
* 那如何保证所有四周的可能性都考虑到呢？
  我们从矩阵的最外围往里面遍历，像一个圈不断缩小的过程
* 为了防止重复遍历用visited记录
* 其次要用小顶堆(以高度为判断基准)来存入所有快的四周(即圈是不断缩小的，小顶堆存的就是这个圈)
* 为什么要用小顶堆？
  这样可以保证高度较小的块先出队
** 为什么要让高度较小的块先出队？(关键点)
  1. 一开始时候就讲了基础做法是：对于每一个块，去找它四个方向最高的高度中的最小值(二维下则是左右最高的高度取较小的那一个)作为上界，当前块作为下界
  2. 而我们现在反过来不是以中心块为处理单元，而是以四周作为处理单元
  3. 我们如果能确保当前出队的元素对于该中心块来说是它周围四个高度中的最小值那么就能确定接雨水的大小
  4. 为什么队头元素的高度比中心块要高它就一定是中心块周围四个高度中的最小值呢？
     因为我们的前提就是小顶堆：高度小的块先出队，所以对于中心块来说，先出队的必然是中心块四周高度最小的那一个
* 步骤：
  1. 构建小顶堆，初始化为矩阵的最外围(边界所有元素)
  2. 不断出队，倘若队头元素的四周(队头元素的四周其实就是上面说的中心块，队头元素是中心块的四周高度中最矮的一个)
     即代表能够接雨水：队头元素减去该中心块即当前中心块能接雨水的值
  3. 但是接完雨水之后中心块还要存进队列中，但这时要存入的中心块是接完雨水后的中心块
*/
class Solution {
    vector<pair<int,int>> dir{{-1,0},{1,0},{0,-1},{0}};
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        int row=heightMap.size();
        if (row==0)
            return 0;
        int column=heightMap.at(0).size();
        //小顶堆，要让高度小的先出队
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> helper;
        vector<vector<bool>> visited(row,vector<bool>(column,false));
        for (int i=0;i<row;++i)
            for (int j=0;j<column;++j)
                if (i==0 || i==row-1 || j==0 || j==column-1)
                {
                    helper.push({heightMap.at(i).at(j),i,j});
                    visited.at(i).at(j)=true;
                }
        int ans=0;
        while (!helper.empty())
        {
            int cur_height=helper.top().at(0);
            int x=helper.top().at(1);
            int y=helper.top().at(2);
            helper.pop();
            for (pair<int,int> &i:dir)
            {
                int surr_x=x+i.first;
                int surr_y=y+i.second;
                if (surr_x>=0 && surr_x<row && surr_y>=0 && surr_y<column && !visited.at(surr_x).at(surr_y))
                {
                    if (heightMap.at(surr_x).at(surr_y)<cur_height)
                        ans+=cur_height-heightMap.at(surr_x).at(surr_y);
                    helper.push({max(cur_height,heightMap.at(surr_x).at(surr_y)),surr_x,surr_y});
                    visited.at(surr_x).at(surr_y)=true;
                }
            }
        }
        return ans;
    }
};
