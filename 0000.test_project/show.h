#ifndef SHOW
#define SHOW

#include <string>
#include <vector>
#include <list>
#include <unordered_map>
#include <map>
#include <unordered_set>
#include <set>
#include <iostream>
using namespace std;

struct ListNode
{
	int val;
	ListNode *next;
	ListNode(int _val) : val(_val) { next = NULL; }
};

void show(vector<vector<bool>> answer)
{
	cout << boolalpha;
	for (vector<bool> &i : answer)
	{
		for (bool j : i)
			cout << j << " ";
		cout << endl;
	}
	cout << "---------------------------" << endl;
	cout << noboolalpha;
}
template <typename T>
void show(vector<vector<T>> answer)
{
	int answer_size = answer.size();
	int single_answer_size;
	cout << "-------" << endl;
	cout << "size=" << answer.size() << endl
		 << "~~~~" << endl;
	for (int i = 0; i < answer_size; ++i)
	{
		single_answer_size = answer.at(i).size();
		for (int j = 0; j < single_answer_size; ++j)
			cout << answer.at(i).at(j) << " ";
		cout << endl;
	}
	cout << "-------" << endl;
}
template <typename T>
void show(vector<T> answer)
{
	cout << "----" << endl;
	int answer_size = answer.size();
	cout << "size=" << answer.size() << endl
		 << "~~~~" << endl;
	for (int i = 0; i < answer_size; ++i)
		cout << answer.at(i) << endl;
	cout << "----" << endl;
}
void show(vector<pair<int,int>> answer)
{
	cout << "----" << endl;
	int answer_size = answer.size();
	cout << "size=" << answer.size() << endl
		 << "~~~~" << endl;
	for (int i = 0; i < answer_size; ++i)
		cout << answer.at(i).first << ' ' << answer.at(i).second << endl;
	cout << "----" << endl;
}
template <typename T>
void show(list<T> answer)
{
	cout << "----" << endl;
	cout << "size=" << answer.size() << endl
		 << "~~~~" << endl;
	for (auto p=answer.begin();p!=answer.end();++p)
		cout << *p << endl;
	cout << "----" << endl;
}
void show(ListNode * p)
{
	cout << "----" << endl;
	while (p!=NULL)
	{
		cout << p->val << endl;
		p=p->next;
	}
	cout << "----" << endl;
}
template <typename K,typename V>
void show(unordered_map<K,V> answer)
{
	cout << "----" << endl;
	cout << "size=" << answer.size() << endl
		 << "~~~~" << endl;
	for (auto p=answer.begin();p!=answer.end();++p)
		cout << p->first << ' ' << p->second << endl;
	cout << "----" << endl;
}
template <typename K,typename V>
void show(map<K,V> answer)
{
	cout << "----" << endl;
	cout << "size=" << answer.size() << endl
		 << "~~~~" << endl;
	for (auto p=answer.begin();p!=answer.end();++p)
		cout << p->first << ' ' << p->second << endl;
	cout << "----" << endl;
}
template <typename T>
void show(unordered_set<T> answer)
{
	cout << "----" << endl;
	cout << "size=" << answer.size() << endl
		 << "~~~~" << endl;
	for (auto p=answer.begin();p!=answer.end();++p)
		cout << *p << endl;
	cout << "----" << endl;
}
template <typename T>
void show(set<T> answer)
{
	cout << "----" << endl;
	cout << "size=" << answer.size() << endl
		 << "~~~~" << endl;
	for (auto p=answer.begin();p!=answer.end();++p)
		cout << *p << endl;
	cout << "----" << endl;
}
template <typename K,typename V>
void show(multimap<K,V> answer)
{
	cout << "----" << endl;
	cout << "size=" << answer.size() << endl
		 << "~~~~" << endl;
	for (auto p=answer.begin();p!=answer.end();++p)
		cout << p->first << ' ' << p->second << endl;
	cout << "----" << endl;
}


int base=1e9+7;
int quick_pow(int a,int n)
{
    //a^n
    if (a==0)
        return 0;
    if (n==0)
        return 1;
    a%=base;
    if ((n&1)==1)
        return a*quick_pow(a,n-1)%base;
    else
    {
        int half=quick_pow(a,n/2);
        return (long long)half*half%base;
    }
}

#endif
