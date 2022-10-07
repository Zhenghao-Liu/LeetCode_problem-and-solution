#ifndef SHOW
#define SHOW

#include <string>
#include <vector>
#include <list>
#include <unordered_map>
#include <map>
#include <unordered_set>
#include <set>
#include <bitset>
#include <iostream>
#include <queue>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int _val) : val(_val) { next = NULL; }
};

template<typename T>
void show(T answer) {
    cout << "-------" << endl;
    cout << answer << endl;
    cout << "-------" << endl;
}

void show(vector<vector<bool>> answer) {
    cout << boolalpha;
    for (vector<bool> &i: answer) {
        for (bool j: i)
            cout << j << " ";
        cout << endl;
    }
    cout << "---------------------------" << endl;
    cout << noboolalpha;
}

template<typename T>
void show(vector<vector<T>> answer) {
    int answer_size = answer.size();
    int single_answer_size;
    cout << "-------" << endl;
    cout << "size=" << answer.size() << endl
         << "~~~~" << endl;
    for (int i = 0; i < answer_size; ++i) {
        single_answer_size = answer.at(i).size();
        for (int j = 0; j < single_answer_size; ++j)
            cout << answer.at(i).at(j) << " ";
        cout << endl;
    }
    cout << "-------" << endl;
}

void show(vector<pair<int, int>> answer) {
    cout << "----" << endl;
    int answer_size = answer.size();
    cout << "size=" << answer.size() << endl
         << "~~~~" << endl;
    for (int i = 0; i < answer_size; ++i)
        cout << answer.at(i).first << ' ' << answer.at(i).second << endl;
    cout << "----" << endl;
}

template<typename T>
void show(vector<T> answer) {
    cout << "----" << endl;
    int answer_size = answer.size();
    cout << "size=" << answer.size() << endl
         << "~~~~" << endl;
    for (int i = 0; i < answer_size; ++i)
        cout << answer.at(i) << endl;
    cout << "----" << endl;
}

template<typename T>
void show(list<T> answer) {
    cout << "----" << endl;
    cout << "size=" << answer.size() << endl
         << "~~~~" << endl;
    for (auto p = answer.begin(); p != answer.end(); ++p)
        cout << *p << endl;
    cout << "----" << endl;
}

void show(ListNode *p) {
    cout << "----" << endl;
    while (p != NULL) {
        cout << p->val << endl;
        p = p->next;
    }
    cout << "----" << endl;
}

template<typename K, typename V>
void show(unordered_map<K, V> answer) {
    cout << "----" << endl;
    cout << "size=" << answer.size() << endl
         << "~~~~" << endl;
    for (auto p = answer.begin(); p != answer.end(); ++p)
        cout << p->first << ' ' << p->second << endl;
    cout << "----" << endl;
}

template<typename K, typename V>
void show(map<K, V> answer) {
    cout << "----" << endl;
    cout << "size=" << answer.size() << endl
         << "~~~~" << endl;
    for (auto p = answer.begin(); p != answer.end(); ++p)
        cout << p->first << ' ' << p->second << endl;
    cout << "----" << endl;
}

template<typename T>
void show(unordered_set<T> answer) {
    cout << "----" << endl;
    cout << "size=" << answer.size() << endl
         << "~~~~" << endl;
    for (auto p = answer.begin(); p != answer.end(); ++p)
        cout << *p << endl;
    cout << "----" << endl;
}

template<typename T>
void show(set<T> answer) {
    cout << "----" << endl;
    cout << "size=" << answer.size() << endl
         << "~~~~" << endl;
    for (auto p = answer.begin(); p != answer.end(); ++p)
        cout << *p << endl;
    cout << "----" << endl;
}

template<typename K, typename V>
void show(multimap<K, V> answer) {
    cout << "----" << endl;
    cout << "size=" << answer.size() << endl
         << "~~~~" << endl;
    for (auto p = answer.begin(); p != answer.end(); ++p)
        cout << p->first << ' ' << p->second << endl;
    cout << "----" << endl;
}

void show_in_binary(int x) {
    cout << "----" << endl;
    cout << bitset<32>(x).to_string() << endl;
    cout << "----" << endl;
}

template<typename T>
void show(priority_queue<T> answer) {
    cout << "----" << endl;
    cout << "size=" << answer.size() << endl
         << "~~~~" << endl;
    while (!answer.empty()) {
        cout << answer.top() << endl;
        answer.pop();
    }
    cout << "----" << endl;
}

template<typename A, typename B>
void show(priority_queue<pair<A, B>> answer) {
    cout << "----" << endl;
    cout << "size=" << answer.size() << endl
         << "~~~~" << endl;
    while (!answer.empty()) {
        cout << answer.top().first << ' ' << answer.top().second << endl;
        answer.pop();
    }
    cout << "----" << endl;
}

#endif
