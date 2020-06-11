/**
* 采用极坐标表示
  x=x0+r*cosθ y=y0+r*cosθ
* 采用std::mt19937生成[0,1)的double随机数
* 注意cos、sin操作的都是弧度制
* θ取0~2pi
  通过极坐标就保证一点在圆内
  但是对于半径不能单纯的通过随机数直接乘r，因为这样不符合均匀随机
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
        double angle=uni(rng)*2*M_PI;
        double rr=sqrt(uni(rng))*r;
        return {x+rr*cos(angle),y+rr*sin(angle)};
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(radius, x_center, y_center);
 * vector<double> param_1 = obj->randPoint();
 */
