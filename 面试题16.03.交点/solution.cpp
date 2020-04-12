class Solution {
public:
    vector<double> intersection(vector<int>& start1, vector<int>& end1, vector<int>& start2, vector<int>& end2) {
        double x1=start1.at(0),y1=start1.at(1),x2=end1.at(0),y2=end1.at(1);
        double A1=y1-y2,B1=x2-x1,C1=y2*x1-y1*x2;
        x1=start2.at(0),y1=start2.at(1),x2=end2.at(0),y2=end2.at(1);
        double A2=y1-y2,B2=x2-x1,C2=y2*x1-y1*x2;
        //直线平行
        if (A1*B2==A2*B1)
        {
            //重合
            if (A1*C2==A2*C1)
            {
                double x1_left=min(start1.at(0),end1.at(0));
                double x1_right=max(start1.at(0),end1.at(0));
                double y1_down=min(start1.at(1),end1.at(1));
                double y1_up=max(start1.at(1),end1.at(1));
                double x2_left=min(start2.at(0),end2.at(0));
                double x2_right=max(start2.at(0),end2.at(0));
                double y2_down=min(start2.at(1),end2.at(1));
                double y2_up=max(start2.at(1),end2.at(1));
                //B包含A
                if (x1_right<=x2_right && x1_left<=x2_left && y1_down>=y2_down && y1_up<=y2_up)
                {
                    if (A1*B1<0 || A1==0 || B1==0)
                        return {x1_left,y1_down};
                    if (A1*B1>0)
                        return {x1_left,y1_up};
                }
                //A包含B
                if (x1_left>=x2_left && x1_right>=x2_right && y1_up>=y2_up && y1_down<=y2_down)
                {
                    if (A1*B1<0 || A1==0 || B1==0)
                        return {x2_left,y2_down};
                    if (A1*B1>0)
                        return {x2_left,y2_up};
                }
                //特殊垂直于x轴情况
                if (B1==0)
                {
                    //A在上B在下
                    if (y1_down<=y2_up && y1_up>=y2_down)
                        return {x1_left,y1_down};
                    //A在下B在上
                    if (y1_up>=y2_down && y1_down<=y2_up)
                        return {x1_left,y2_down};
                    return {};
                }
                //A右接于B
                if (x1_right>=x2_left && x1_left<x2_right)
                {
                    if (A1*B1<0 || A1==0)
                        return {x2_left,y2_down};
                    if (A1*B1>0)
                        return {x2_left,y2_up};
                }
                //A左接于B
                if (x1_left<=x2_right && x1_right>x2_left)
                {
                    if (A1*B1<0 || A1==0)
                        return {x1_left,y1_down};
                    if (A1*B1>0)
                        return {x1_left,y1_up};
                }
            }
            else
                return {};
        }
        //直线相交
        else
        {
            double denominator=A2*B1-A1*B2;
            double x=(B2*C1-B1*C2)/denominator;
            double y=(A1*C2-A2*C1)/denominator;
            double x_boundary_left=min(start1.at(0),end1.at(0));
            double x_boundary_right=max(start1.at(0),end1.at(0));
            double y_boundary_down=min(start1.at(1),end1.at(1));
            double y_boundary_up=max(start1.at(1),end1.at(1));
            if (x>=x_boundary_left && x<=x_boundary_right && y>=y_boundary_down && y<=y_boundary_up);
            else
                return {};
            x_boundary_left=min(start2.at(0),end2.at(0));
            x_boundary_right=max(start2.at(0),end2.at(0));
            y_boundary_down=min(start2.at(1),end2.at(1));
            y_boundary_up=max(start2.at(1),end2.at(1));
            if (x>=x_boundary_left && x<=x_boundary_right && y>=y_boundary_down && y<=y_boundary_up)
                return {x,y};
            else
                return {};
        }
        return {};
    }
};
