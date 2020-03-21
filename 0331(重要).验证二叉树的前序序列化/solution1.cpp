/*
* 设所有节点都占有一个槽位，包括空节点'#'
* 初始化只有1个槽位，如果节点是空节点'#'则消耗一个槽位，如果不是空节点，那么就要为他左右孩子增加两个槽位
*/
class Solution {
public:
    bool isValidSerialization(string preorder) {
        stringstream ss;
        ss << preorder;
        int slot=1;
        string temp;
        while (getline(ss,temp,','))
        {
            --slot;
            if (slot<0)
                return false;
            if (temp!="#")
                slot+=2;
        }
        return slot==0;
    }
};
