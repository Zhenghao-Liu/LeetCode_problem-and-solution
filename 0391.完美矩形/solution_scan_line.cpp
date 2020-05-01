class Solution {
public:
    bool isRectangleCover(vector<vector<int>>& rectangles) {
        //扫描方向从左往右，从下向上
        int left_down_x=INT_MAX;
        int left_down_y=INT_MAX;
        int right_top_x=INT_MIN;
        int right_top_y=INT_MIN;
        //遍历一次找出当前可能完美矩形的左下角和右上角
        for (vector<int> &i:rectangles)
        {
            left_down_x=min(left_down_x,i[0]);
            left_down_y=min(left_down_y,i[1]);
            right_top_x=max(right_top_x,i[2]);
            right_top_y=max(right_top_y,i[3]);
        }
        //按从左往右，扫描线要走的长度，即可能最大完美矩形的宽度
        int width=right_top_x-left_down_x;
        //扫描线当前所在处的水平高度
        //初始化为最低的高度
        vector<int> height(width,left_down_y);
        //按照每个小矩形的下边的高度来进行排序
        //这样是为了在扫描过程中由高度低的点来得到其小矩形的高度
        //再处理同一条扫描线更高处的矩形时，新矩形的最低高度应该和旧矩形的最高高度一致
        sort(rectangles.begin(),rectangles.end(),[](const vector<int>& A,const vector<int>& B){
            return A[1]<B[1];
        });
        for (vector<int> &i:rectangles)
        {
            //倘若高度不一致，则代表出现空缺或重合
            //不能简单只改变一个点的高度，因为不能保证每个矩形都是等宽的
            for (int j=i[0];j<i[2];++j)
            {
                if (height[j-left_down_x]!=i[1])
                    return false;
                //更新高度
                height[j-left_down_x]=i[3];
            }
        }
        //哪怕完美契合了还要检查最高的高度是否和最大完美可能矩形是否一样
        //因为前面扫描都是通过一个矩形上界和上面矩形的下界来判断，对于最高矩形的上界没有判断到
        for (int &i:height)
            if (i!=right_top_y)
                return false;
        return true;
    }
};
