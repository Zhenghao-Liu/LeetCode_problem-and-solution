class Solution {
public:
    int largestMagicSquare(vector<vector<int>>& grid) {
        int ans=1;
        int row=grid.size(),col=grid.at(0).size();
        for (int i=0;i<row;i++) {
            for (int j=0;j<col;j++) {
                for (int k=2;i+k<=row && j+k<=col;k++) {
                    int sum=0;
                    for (int b=j;b<j+k;b++) {
                        sum+=grid.at(i).at(b);
                    }
                    bool can=true;
                    for (int a=i;a<i+k;a++) {
                        int cur=0;
                        for (int b=j;b<j+k;b++) {
                            cur+=grid.at(a).at(b);
                        }
                        if (cur!=sum) {
                            can=false;
                            break;
                        }
                    }
                    if (!can) {
                        continue;
                    }
                    for (int b=j;b<j+k;b++) {
                        int cur=0;
                        for (int a=i;a<i+k;a++) {
                            cur+=grid.at(a).at(b);
                        }
                        if (cur!=sum) {
                            can=false;
                            break;
                        }
                    }
                    if (!can) {
                        continue;
                    }
                    int cur=0;
                    for (int a=i,b=j;a<i+k && b<j+k;a++,b++) {
                        cur+=grid.at(a).at(b);
                    }
                    if (cur!=sum) {
                        continue;
                    }
                    cur=0;
                    for (int a=i,b=j+k-1;a<i+k && b>=j;a++,b--) {
                        cur+=grid.at(a).at(b);
                    }
                    if (cur!=sum) {
                        continue;
                    }
                    ans=max(ans,k);
                    if (ans==row || ans==col) {
                        return ans;
                    } 
                }
            }
        }
        return ans;
    }
};