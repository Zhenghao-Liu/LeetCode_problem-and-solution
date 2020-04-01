/*
* 采取逆序的方式存进栈中，这样取出来时候就是正序
* 当发现栈顶不是一个数而是一个数组时，则像初次初始化一样，把栈顶元素当做新的初始化参数放新值进栈中
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
    stack<NestedInteger> s;
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        for (int i=nestedList.size()-1;i>=0;--i)
            s.push(nestedList.at(i));
    }
    
    int next() {
        NestedInteger ans=s.top();
        s.pop();
        return ans.getInteger();
    }
    
    bool hasNext() {
        if (s.empty())
            return false;
        if (!s.top().isInteger())
        {
            vector<NestedInteger> temp=s.top().getList();
            s.pop();
            for (int i=temp.size()-1;i>=0;--i)
                s.push(temp.at(i));
            return this->hasNext();
        }
        return true;
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */
