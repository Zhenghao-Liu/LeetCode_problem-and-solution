class Solution {
    public int maxPoints(int[][] points) {
        int n = points.length;
        if (n == 0) return 0;
        if (n == 1) return 1;
        int res = 0;
        //对于第i个点只需考虑它和后面点的组合即可，因为和前面的组合已经在更小的i时候讨论了 
        for (int i = 0; i < n - 1; i++) {
            Map<String, Integer> slope = new HashMap<>();
            //repeat记录和第i个点重复点的个数 
            int repeat = 0;
            int tmp_max = 0;
            for (int j = i + 1; j < n; j++) {
            	//dy为第j个点和第i个点之间y的距离 
                int dy = points[i][1] - points[j][1];
                //dx为第j个点和第i个点之间x的距离 
                int dx = points[i][0] - points[j][0];
                //dy=0=dx表明第j个点和第i个点重合了 
                if (dy == 0 && dx == 0) {
                    repeat++;
                    continue;
                }
                //求公约数，因为如果采用dy/dx的方式求斜率，如果是一条平行于y轴的线会造成除法错误 
                int g = gcd(dy, dx);
                //这一步不仅是进行简单的约分
				//对于特殊例子[0,0]的两个点[1,-1]、[-1,1]两者公约数分别为-1、1，但除去公约数后则为[-1,1]、[-1,1]则相同了
                if (g != 0) {
                    dy /= g;
                    dx /= g;
                }
                //String.valueOf(int)是将int数据类型直接转为stirng，eg:int为10则结果为"10",C++用to_string() 
                String tmp = String.valueOf(dy) + "/" + String.valueOf(dx);
                //put为insert意思
				//HashMap.getOrDefault(a,b)为如果在哈希表中找到key为a的则返回a的映射value，如果没找到a则返回b 
				//slope中更新斜率一样的点的个数 
                slope.put(tmp, slope.getOrDefault(tmp, 0) + 1);
                tmp_max = Math.max(tmp_max, slope.get(tmp));
            }
            //重合的点也算在一条直线上，且重合的点可以说在任意一条直线上 
            res = Math.max(res, repeat + tmp_max + 1);
        }
        return res;
    }
    private int gcd(int dy, int dx) {
        if (dx == 0) return dy;
        else return gcd(dx, dy % dx);
    }
}
