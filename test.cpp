//#include "pch.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <chrono>
//#include <iomanip>
//#include <ratio>
//#include <ctime>
//#include <cstdio>
//#include <set>
//#include <bitset>
//#include <map>
//#include <bits/stdc++.h>
//#include <typeinfo>
//#include <deque>
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
	using namespace std::chrono;
	steady_clock::time_point t_begin = steady_clock::now();
	/*---------------------------------------*/
	


	/*---------------------------------------*/
	steady_clock::time_point t_end = steady_clock::now();
	duration<double> time_span = duration_cast<duration<double>>(t_end - t_begin);
	cout << endl << "---------------------------------------" << endl;
	cout << "It takes " << time_span.count()*1000 << " ms.";
	return 0;
}
/*---------------------------------------*/

/*---------------------------------------*/
void show(vector<vector<bool>> answer)
{
	cout << boolalpha;
	for (vector<bool> &i:answer)
	{
		for (bool j:i)
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
