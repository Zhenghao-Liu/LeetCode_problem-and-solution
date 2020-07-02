//把可能的点进行1开始编号，那么随机点直接随机编号就好了，这样保证了概率均匀。因为要通过编号获得坐标，必然要知道在哪个矩形里面，那么就用前缀和方式存取矩形里面节点个数，这样可以通过二分直接查得在编号是在哪个矩形里面，之后就可以用类似二维矩阵的编码方式，[i][j]=row*i+j，我这里是把矩形左下角当成了[0][0]点，最后注意一下这种方式，i是第几行即应该对应的是纵坐标，j是第几列那么对应的是横坐标
//rand() % (b-a+1)+ a 就表示 a~b 之间的一个随机整数
class Solution {
    vector<int> prefix;
    vector<vector<int>> rects;
public:
    Solution(vector<vector<int>>& _rects) {
        rects=_rects;
        prefix.reserve(rects.size());
        for (vector<int> &i:rects)
        {
            int cur=(i.at(2)-i.at(0)+1)*(i.at(3)-i.at(1)+1);
            if (!prefix.empty())
                prefix.push_back(cur+prefix.back());
            else
                prefix.push_back(cur);
        }
    }
    
    vector<int> pick() {
        int point_index=rand()%prefix.back()+1;
        int pos=lower_bound(prefix.begin(),prefix.end(),point_index)-prefix.begin();
        int start_point_index;
        if (pos==0)
            start_point_index=1;
        else
            start_point_index=prefix.at(pos-1)+1;
        int row=rects.at(pos).at(2)-rects.at(pos).at(0)+1;
        int column=rects.at(pos).at(3)-rects.at(pos).at(1)+1;
        int i=(point_index-start_point_index)/row;
        int j=point_index-start_point_index-i*row;
        return {rects.at(pos).at(0)+j,rects.at(pos).at(1)+i};
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(rects);
 * vector<int> param_1 = obj->pick();
 */
