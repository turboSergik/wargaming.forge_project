//#include <bits/stdc++.h>

#include "pch.h"
#include <cstring>
#include <iomanip>
#include <sstream>
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <fstream>


#define ll long long

using namespace std;

int m = 1e6;
ll mod = 1000165987;

ll p = 205, hs;
ll ans[5000000];
ll step[5000000];

string way_to_resp = "C:\\DISK D\\anime\\response1.txt"

ll get_hs(string &s1) {

	ll ans = 0;
	for (int i = 0; i < s1.size(); i++) {
		ans = ans + (s1[i] + 100) * step[i];
		ans %= mod;
	}
	return ans;
}

int main()
{
	//    ifstream root("C:\\DISK D\\anime\\response1.txt");
	ifstream root("/home/user/Work/response1.txt");
	string s_root, s_way, s2;

	step[0] = 1;
	for (int i = 1; i <= m; i++) {
		step[i] = step[i - 1] * p;
		step[i] %= mod;
	}

	while (getline(root, s_root)) {

		int n = s_root.size();
		int now = 0;

		s_root.erase(n - 4, 4);
		s_root = s_root + "txt";

		ifstream way(s_root);
		cout << s_root << endl;

		while (getline(way, s_way)) {
			//            cout << s_way << endl;

			hs = get_hs(s_way);
			ans[++now] = hs;

		}

		sort(ans + 1, ans + 1 + now);

		s2 = s_root;
		s2 = s2 + "t";

		ofstream out(s2);
		for (int i = 1; i <= now; i++) out << ans[i] << '\n';

		out.close();
		way.close();


		//        break;

	}


	return 0;
}
