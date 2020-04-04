//对于每一个柱子的接水高度，取决于左右两边最高的柱子的，两个中较矮的一根减去当前柱子高度
class Solution {
public:
    int trap(vector<int>& height) {
        int height_size=height.size();
        if (height_size<=2)
            return 0;
        int left,right,answer=0,ans;
        for (int i=1;i<height_size-1;++i)
        {	
            left=right=height.at(i);
            ans=i-1;
            while (ans>=0)
            {
                if (left<height.at(ans))
                    left=height.at(ans);
                --ans;
            }	
            ans=i+1;
            while (ans<height_size)
            {
                if (right<height.at(ans))
                    right=height.at(ans);
                ++ans;
            }
            if (left>right)
                left=right;
            if (left>height.at(i))
                answer=answer+left-height.at(i);	
        }
        return answer;
    }
};
