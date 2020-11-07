//因为每个数都一定不一样，存每个数组的开头元素在pieces的下标，然后暴力匹配
class Solution {
public:
    bool canFormArray(vector<int>& arr, vector<vector<int>>& pieces) {
        int arr_size=arr.size();
        int p_size=pieces.size();
        unordered_map<int,int> um;
        for (int i=0;i<p_size;++i)
            um[pieces.at(i).at(0)]=i;
        for (int i=0;i<arr_size;)
        {
            int ii=arr.at(i);
            if (um.find(ii)==um.end())
                return false;
            int val=um.at(ii);
            int siz=pieces.at(val).size();
            for (int j=0;j<siz;++j,++i)
                if (arr.at(i)!=pieces.at(val).at(j))
                    return false;
        }
        return true;
    }
};
