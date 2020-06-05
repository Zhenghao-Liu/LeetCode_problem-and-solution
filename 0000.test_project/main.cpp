//#include "pch.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <chrono>
#include "Tree_to_String.h"
#include "show.h"
#include <bits/stdc++.h>
//#include <stdexcept>
//#include <list>
//#include <iomanip>
//#include <ratio>
//#include <ctime>
//#include <cstdio>
//#include <set>
//#include <bitset>
//#include <map>
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
	cout << endl
		 << "---------------------------------------" << endl;
	cout << "It takes " << time_span.count() * 1000 << " ms.";
	return 0;
}
/*---------------------------------------*/

/*---------------------------------------*/
