/*
* 注释说了不能保存vector的copy
* 不然的话1.直接用复制构造函数，然后返回复制的新类的next
         2.记录下vector，然后设一个index，peek则返回vector.at(index)，next返回vector.at(index++)
* 既然不能保存副本，接口又只有这几个，必然peek()函数体里面一定是调用到next()的
* 可以假设peek()调用后1.再调用peek()，那两次调用peek()值应该一样
                     2.再调用next()，peek()、next()的返回值应该一样，但下一次调用peek()值返回就不一样
* 所以应缓存peek()的值，并在peek()调用后设置一个标识值execute_peek
* 总结：调用了peek会导致指针后移，但是peek后面紧接着的next应返回peek的结果，所以应该把peek的结果缓存起来
*/
// Below is the interface for Iterator, which is already defined for you.
// **DO NOT** modify the interface for Iterator.

class Iterator {
    struct Data;
	Data* data;
public:
	Iterator(const vector<int>& nums);
	Iterator(const Iterator& iter);
	virtual ~Iterator();
	// Returns the next element in the iteration.
	int next();
	// Returns true if the iteration has more elements.
	bool hasNext() const;
};


class PeekingIterator : public Iterator {
private:
    int num;
    bool execute_peek;
public:
	PeekingIterator(const vector<int>& nums) : Iterator(nums) {
	    // Initialize any member here.
	    // **DO NOT** save a copy of nums and manipulate it directly.
	    // You should only use the Iterator interface methods.
	    execute_peek=false;
	}

    // Returns the next element in the iteration without advancing the iterator.
	int peek() {
        if (!execute_peek)
        {
            execute_peek=true;
            num=this->Iterator::next();
        }
        return num;
	}

	// hasNext() and next() should behave the same as in the Iterator interface.
	// Override them if needed.
	int next() {
	    if (execute_peek)
        {
            execute_peek=false;
            return num;
        }
        return this->Iterator::next();
	}

	bool hasNext() const {
	    return execute_peek || this->Iterator::hasNext();
	}
};
