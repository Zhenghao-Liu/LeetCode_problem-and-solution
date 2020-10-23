class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        int name_size=name.size();
        int typed_size=typed.size();
        int i=0,j=0;
        while (i<name_size && j<typed_size)
        {
            char cur_nam=name.at(i);
            int ori_i=i;;
            while (i<name_size && cur_nam==name.at(i))
                ++i;
            char cur_typ=typed.at(j);
            int ori_j=j;
            while (j<typed_size && cur_typ==typed.at(j))
                ++j;
            if (!(cur_nam==cur_typ && j-ori_j>=i-ori_i))
                return false;
        }
        return i==name_size && j==typed_size;
    }
};
