/*
* 状压dp，为了分析方便把原题改成0可以选择，1不可以选择
* 思路在状压笔记上的第三题
*/
#include <bits/stdc++.h>
#include <iostream>
#include <cstdio>
using namespace std;
int mod = 1e9;
int main()
{
    int r, c;
    cin >> r >> c;
    int ALL = (1 << c) - 1;
    int temp;
    vector<vector<int>> matrix(r, vector<int>(c));
    vector<int> g(r);
    for (int i = 0; i < r; ++i)
        for (int j = 0; j < c; ++j)
        {
            cin >> temp;
            matrix.at(i).at(j) = (temp ^ 1);
            if (temp == 0)
                g.at(i) |= 1 << j;
        }
    vector<vector<int>> dp(r, vector<int>(ALL + 1, 0));
    for (int s = 0; s <= ALL; ++s)
        if ((s & g.at(0)) == 0 && (s & (s >> 1)) == 0)
            dp.at(0).at(s) = 1;
    for (int i = 1; i < r; ++i)
        for (int s = 0; s <= ALL; ++s)
            for (int k = 0; k <= ALL; ++k)
                if ((s & k) == 0 && (s & g.at(i)) == 0 && (s & (s >> 1)) == 0)
                {
                    dp.at(i).at(s) += dp.at(i - 1).at(k);
                    dp.at(i).at(s) %= mod;
                }
    int ans = 0;
    for (int s = 0; s <= ALL; ++s)
        if ((s & g.at(r - 1)) == 0 && (s & (s >> 1)) == 0)
        {
            ans += dp.at(r - 1).at(s);
            ans %= mod;
        }
    cout << ans;
    return 0;
}
