class SummaryRanges {
private:
    vector<vector<int>> ans;
public:
    /** Initialize your data structure here. */
    SummaryRanges() {
        ans.clear();
    }
    
    void addNum(int val) {
        //如果为空，那直接插入
        if (ans.empty())
        {
            ans.push_back({val,val});
            return;
        }
        //如果val-1比最右边的边界还大，那直接插入
        if (val-1>ans.back().at(1))
        {
            ans.push_back({val,val});
            return;
        }
        //如果val刚好能和右边的边界扩大一位，则更新最后一位
        if (val-1==ans.back().at(1))
        {
            ans.back().at(1)=val;
            return;
        }
        //二分查找数组中[0]最右边的比val小的位置
        int ans_size=ans.size();
        int left=0,right=ans_size-1;
        while (left<right)
        {
            int mid=(left+right+1)>>1;
            if (ans.at(mid).at(0)>val)
                right=mid-1;
            else
                left=mid;
        }
        //如果left为0有两种可能：第0个数组[0]比val小，或者所有数组[0]都比val大
        //情况二，刚好可以构成最左边[0]边界往左一位，则更新
        if (left==0 && val+1==ans.at(0).at(0))
        {
            ans.at(0).at(0)=val;
            return;
        }
        //这里是第二种情况，且val比[0][0]还要小，则直接添加在最左边
        if (left==0 && val<ans.at(0).at(0) && val+1!=ans.at(0).at(0))
        {
            ans.insert(ans.begin(),{val,val});
            return;
        }
        //通用情况：第left个数组的[0]比val小
        //即ans.at(left).at(0)<=val && val<ans.at(left+1).at(0)
        //可以写成草稿 [a , b]   [c,d] 可以插入的地方有5个
        //插在a与b之间
        if (val<=ans.at(left).at(1))
            return;
        //连接b与c使结果为[a,d]
        else if (val-1==ans.at(left).at(1) && left+1<ans_size && val+1==ans.at(left+1).at(0))
        {
            ans.at(left).at(1)=ans.at(left+1).at(1);
            ans.erase(ans.begin()+left+1);
            return;
        }
        //拓展b
        else if (val-1==ans.at(left).at(1))
        {
            ans.at(left).at(1)=val;
            return;
        }
        //拓展c
        else if (left+1<ans_size && val+1==ans.at(left+1).at(0))
        {
            ans.at(left+1).at(0)=val;
            return;
        }
        //插在b与c之间新的数组
        else
        {
            ans.insert(ans.begin()+left+1,{val,val});
            return;
        }
    }
    
    vector<vector<int>> getIntervals() {
        return ans;
    }
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(val);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */
