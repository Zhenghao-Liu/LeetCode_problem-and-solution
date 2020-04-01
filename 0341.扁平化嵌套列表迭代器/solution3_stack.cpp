/*
* solution1是先全部存好，再通过hasNext()检查
* solution3则是在存的时候就检查好每个元素，省去了出栈的时间
* 初始化时间较长，但next和hasNext较快
*/
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
    stack<NestedInteger*> s;
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        for (int i=nestedList.size()-1;i>=0;--i)
            build_s(&nestedList.at(i));
    }
    
    void build_s(NestedInteger * p)
    {
        if (p->isInteger())
            s.push(p);
        else
        {
            vector<NestedInteger>& temp=p->getList();
            for (int i=temp.size()-1;i>=0;--i)
                build_s(&temp.at(i));
        }
    }

    int next() {
        NestedInteger* ans=s.top();
        s.pop();
        return ans->getInteger();
    }
    
    bool hasNext() {
        return !s.empty();
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */
