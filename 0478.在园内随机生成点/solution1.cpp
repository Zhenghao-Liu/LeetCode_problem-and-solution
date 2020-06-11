/**
* 拒绝采样
* 在圆的外接正方形范围上生成随机数，如果是在园内则返回，则不再园内则重新生成
* 采用std::mt19937生成0~1的double随机数
  通过记录内接正方形的左下角坐标作为起点基准
  即内接正方形的左下角坐标(left_down_x,left_down_y)
  右上角坐标(left_down_x+2*r,left_down_y+2*r)
*/
class Solution {
    mt19937 rng{random_device{}()};
    uniform_real_distribution<double> uni{0,1};
    double r,x,y;
public:
    Solution(double radius, double x_center, double y_center) {
        r=radius;
        x=x_center;
        y=y_center;
    }
    
    vector<double> randPoint() {
        double left_down_x=x-r;
        double left_down_y=y-r;
        while (true)
        {
            double xx=left_down_x+2*r*uni(rng);
            double yy=left_down_y+2*r*uni(rng);
            if ((xx-x)*(xx-x)+(yy-y)*(yy-y)<=r*r)
                return {xx,yy};
        }
        return {};
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(radius, x_center, y_center);
 * vector<double> param_1 = obj->randPoint();
 */
