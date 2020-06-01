class Solution {
    int base=1e9+7;
public:
    int maxArea(int h, int w, vector<int>& hcuts, vector<int>& vcuts) {
        hcuts.push_back(0);
        hcuts.push_back(h);
        sort(hcuts.begin(),hcuts.end());
        vcuts.push_back(0);
        vcuts.push_back(w);
        sort(vcuts.begin(),vcuts.end());
        int max_h=0;
        for (int i=1;i<hcuts.size();++i)
            max_h=max(max_h,hcuts.at(i)-hcuts.at(i-1));
        int max_w=0;
        for (int i=1;i<vcuts.size();++i)
            max_w=max(max_w,vcuts.at(i)-vcuts.at(i-1));
        //cout << max_h << ' ' << max_w << endl;
        long long a=max_h%base;
        long long b=max_w%base;
        return (a*b)%base;
    }
};
