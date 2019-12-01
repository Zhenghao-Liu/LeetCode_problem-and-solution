class Solution {
public:
    int compareVersion(string version1, string version2) {
        int v1_left,v1_right,v2_left,v2_right;
        v1_left=v1_right=v2_left=v2_right=0;
        int version1_size=version1.size(),version2_size=version2.size();
        int a,b;
        while (v1_left<version1_size || v2_left<version2_size)
        {
            a=b=0;
            for (v1_right=v1_left;v1_right<version1_size && version1.at(v1_right)!='.';++v1_right);
            for (v2_right=v2_left;v2_right<version2_size && version2.at(v2_right)!='.';++v2_right);
            if (v1_right!=v1_left)
                a=stoi(string(version1.begin()+v1_left,version1.begin()+v1_right));
            if (v2_right!=v2_left)
                b=stoi(string(version2.begin()+v2_left,version2.begin()+v2_right));
            if (a>b)
                return 1;
            else if (a<b)
                return -1;
            v1_left=v1_right+1;
            v2_left=v2_right+1;
        }
        return 0;
    }
};
