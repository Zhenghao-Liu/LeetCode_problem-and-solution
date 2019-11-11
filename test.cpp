//#include "pch.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
//#include <map>
//#include <bits/stdc++.h>
//#include <typeinfo>
//#include <stack>
//#include <queue>
//#include <sstream>
//#include <fstream>
//#include <cmath>
//#include <unordered_map>
//#include <unordered_set>
//#include <cstdlib>
//#include <numeric>
/*---------------------------------------*/
using namespace std;
template <typename T>
void show(vector<T> answer);
template <typename T>
void show(vector<vector<T>> answer);
void show(vector<vector<bool>> answer);
/*---------------------------------------*/


/*---------------------------------------*/
int main()
{


	return 0;
}
/*---------------------------------------*/


/*---------------------------------------*/
void show(vector<vector<bool>> answer)
{
	int answer_size = answer.size();
	for (int i = 0; i < answer_size; ++i)
	{
		for (unsigned int j = 0; j < answer.at(i).size(); ++j)
			if (answer.at(i).at(j) == 0)
				cout << "false ";
			else
				cout << "true ";
		cout << endl;
	}
	cout << "---------------------------" << endl;
}
template <typename T>
void show(vector<vector<T>> answer)
{
	int answer_size = answer.size();
	int single_answer_size;
	cout << "-------" << endl;
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
