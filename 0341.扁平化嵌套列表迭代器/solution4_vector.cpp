//采用vector来存，也是在存储时就检查是否是数组
/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

class NestedIterator {
    vector<int> v;
    int v_size;
    int index;
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        build_v(nestedList);
        v_size=v.size();
        index=0;
    }

    void build_v(vector<NestedInteger> & nestedList)
    {
        for (auto &i:nestedList)
            if (i.isInteger())
                v.push_back(i.getInteger());
            else
                build_v(i.getList());
    }
    
    int next() {
        int ans=v.at(index);
        ++index;
        return ans;
    }
    
    bool hasNext() {
        return index<v_size;
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */
