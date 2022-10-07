#ifndef UNION_FIND
#define UNION_FIND

#include <vector>

using namespace std;

class union_find {
private:
    vector<int> parent;
    vector<int> rank;
    vector<int> cnt;
public:
    union_find() {
        parent.clear();
        rank.clear();
        cnt.clear();
    }

    explicit union_find(int n) {
        parent = vector<int>(n);
        rank = vector<int>(n, 0);
        cnt = vector<int>(n, 0);
        init(n);
    }

    void init(int n) {
        for (int i = 0; i < n; ++i) {
            parent.at(i) = i;
            rank.at(i) = 0;
            cnt.at(i) = 1;
        }
    }

    int find_root(int i) {
        if (parent.at(i) != i) {
            int root = find_root(parent.at(i));
            cnt.at(i) = cnt.at(root);
            parent.at(i) = root;
            return root;
        }
        return i;
    }

    int union_vertices(int a, int b) {
        int a_root = find_root(a);
        int b_root = find_root(b);
        if (a_root == b_root)
            return cnt.at(a_root);
        if (rank.at(a_root) < rank.at(b_root)) {
            parent.at(a_root) = b_root;
            cnt.at(b_root) += cnt.at(a_root);
            return cnt.at(b_root);
        } else {
            parent.at(b_root) = a_root;
            cnt.at(a_root) += cnt.at(b_root);
            if (rank.at(a_root) == rank.at(b_root))
                ++rank.at(a_root);
            return cnt.at(a_root);
        }
        return -1;
    }

    bool is_connected(int a, int b) {
        return find_root(a) == find_root(b);
    }

    int get_cnt(int i) {
        int root = find_root(i);
        return cnt.at(root);
    }
};

#endif
