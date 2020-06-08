class BrowserHistory {
    deque<string> d;
    int index;
public:
    BrowserHistory(string homepage) {
        d.push_back(homepage);
        index=0;
    }
    
    void visit(string url) {
        while (d.size()>index+1)
            d.pop_back();
        ++index;
        d.push_back(url);
    }
    
    string back(int steps) {
        while (steps>0 && index>0)
        {
            --index;
            --steps;
        }
        return d.at(index);
    }
    
    string forward(int steps) {
        int cur=index;
        while (steps>0 && index<d.size()-1)
        {
            --steps;
            ++index;
        }
        return d.at(index);
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */
