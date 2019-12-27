//数学题，记住在坐标系中，在右边的在上边的就是大的，就好理解了
class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        int s1=(C-A)*(D-B),s2=(G-E)*(H-F);
        if (E>=C || H<=B || G<=A || F>=D)
            return s1+s2;
        int left_bottom_x=max(A,E);
        int left_bottom_y=max(B,F);
        int right_up_x=min(G,C);
        int right_up_y=min(H,D);
        int overlap=(right_up_x-left_bottom_x)*(right_up_y-left_bottom_y);
        return s1-overlap+s2;
    }
};
