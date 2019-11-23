//具体方法参照powacai大佬代码java里面加的注释笔记
class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int points_size=points.size();
        if (points_size<=1)
            return points_size;
        int answer=1,repeat_points,dx,dy,gcd,temporary_max;
        string temporary;
        for (int i=0;i<points_size-1;++i)
        {
            unordered_map<string,int> points_map;
            repeat_points=0;
            temporary_max=0;
            for (int j=i+1;j<points_size;++j)
            {
                dx=points.at(j).at(0)-points.at(i).at(0);
                dy=points.at(j).at(1)-points.at(i).at(1);
                if (dx==0 && dy==0)
                {
                    ++repeat_points;
                    continue;
                }
                gcd=get_gcd(dx,dy);
                dx=dx/gcd;
                dy=dy/gcd;
                temporary=to_string(dy)+"/"+to_string(dx);
                if (points_map.find(temporary)==points_map.end())
                    points_map.insert({temporary,1});
                else
                    ++points_map.at(temporary);
                temporary_max=max(temporary_max,points_map.at(temporary));
            }
            answer=max(answer,1+temporary_max+repeat_points);
        }
        return answer;
    }
int get_gcd(int a, int b) 
{
    if (b == 0) 
        return a;
    else 
        return get_gcd(b,a%b);
}
};
