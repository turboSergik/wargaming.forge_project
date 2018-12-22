#include <bits/stdc++.h>

#define ll long long

#define fi first
#define se second

using namespace std;

int m = 1e6;
ll mod = 1000165987;

ll p = 205, hs;
pair<string,string> ans[5000000];
int h1 = 0;
ll step[5000000];

string way_to_resp = "C:\\DISK D\\response2.txt";

int kol_rep = 0, rep_now;

//map<string, int> name_rep;
//map<string, vector<string> > map_key[3000000];

unordered_map<string, int> name_rep;
unordered_map<string, vector<string> > map_key[3000000];

set<string> st_ans;
map<string, int> map_ans;
map<string, int> map_ans_max;

int get(string s1, string s2) {

//    cout << "s1=" << s1 << " s2=" << s2 << endl;

    for (int i = 0; i < s2.size(); i++) {
        if (i == s1.size()) return 0;
        if (s1[i] != s2[i]) return 0;
    }

    return 1;
}

string get_json(string s1) {

    s1.erase(s1.size() - 3, 3);
    s1 = s1 + "json";
    return s1;
}

string del_json(string s1) {

    int pos = 0;
    for (int i = s1.size() - 1; i >= 0; i--) if (s1[i] == '\\') {
        pos = i;
        break;
    }

    s1.erase(pos - 1, s1.size() - pos + 1);
    return s1;
}

int main()
{
	 ifstream root(way_to_resp);
	//ifstream root("/home/user/Work/response1.txt");
	string s_root, s_way, s2;
	string key, value;


	while (getline(root, s_root)) {

		int n = s_root.size();
		int now = 0;

		s_root.erase(n - 4, 4);
		s_root = s_root + "txt";



		ifstream way(s_root);
		cout << s_root << endl;


        string rep = s_root;
        int kol = 0;
        for (int i = rep.size() - 1; i >= 0; i--) {
            if (rep[i] == '\\') break;
            kol++;
        }

        rep.erase(rep.size() - kol - 2, kol + 2);
        cout << rep << endl;

        rep_now = name_rep[rep];

        if (!rep_now) {
            kol_rep++;
            name_rep[rep] = kol_rep;
            rep_now = kol_rep;
        }


        while(way >> key) {
            getline(way, value);
//            cout << key << " " << value << endl;
//            ans[++h1] = {key, value};
            map_key[rep_now][key].push_back(value);
            h1++;

        }
        way.close();

//        cout << h1 << endl;
//        cout << rep_now << endl;
//        cin >> h1;



	}

	string q_path;
	string q_val;
	int mode;

    vector<string> response;
    vector<pair<string, string> > full_ans;
    vector<pair<string,string> > out;
//    vector<pair<string, string> > out;

    vector<string> all_val;

	string way_in_deep;

    cout << "TREE DONE." << endl;
    while(1) {

        cout << "Enter values: " << endl;

        getline(cin, q_path);
        cin >> mode;
        getline(cin, q_val);
        getline(cin, q_val);

//        while(cin >> q_val) {
//            all_val.push_back(q_val);
//        }




        for (int i = 0; i < q_path.size(); i++) if (q_path[i] == '\\') {
            q_path.insert(i, "\\");
            i+=1;
        }

//        cout << "way=: " << q_path << " mode=" << mode << " val=" << q_val << endl;


        int resp_int = 0;
        int count = 0;

        if (mode == 1) map_ans.clear(), map_ans_max.clear();

        response.clear();
        full_ans.clear();
        out.clear();

        ///
        ifstream all_files("C:\\DISK D\\response2.txt");

        while(getline(all_files, way_in_deep)) {

//            cout << "way in deep = " << way_in_deep << " all path=" << q_path << endl;

            if (!get(way_in_deep, q_path)) continue;

//                cout << "q_val=" << q_val << endl;

                count++;
                map_ans.clear();

    //            cout << "IN WHILE" << endl;

                rep_now = name_rep[del_json(way_in_deep)];
    //            cout << way_in_deep << " " << del_json(way_in_deep) << endl;
//                cout << "rep=" << rep_now << endl;

                if (rep_now) {
                    response = map_key[rep_now][q_val];



                    for (int i = 0; i < response.size(); i++) {
                        resp_int = 1;

                        full_ans.push_back({response[i], way_in_deep});



                        if (mode == 1) {
                            map_ans[response[i]]++;
                            map_ans_max[response[i]] = max(map_ans_max[response[i]], map_ans[response[i]]);
                        }

//                        cout << response[i] << "    path:=" << q_path << endl;
                    }
                }
//            }
        }

        if (mode == 0) {
            cout << full_ans.size() << endl;
            for (int i = 0; i < full_ans.size(); i++) {
                cout << full_ans[i].fi << endl;
                cout << full_ans[i].se << endl;
                cout << endl;
            }

            if (!full_ans.size()) cout << -1 << endl;
            continue;
        }

        sort(full_ans.begin(), full_ans.end());


        if (mode == 0) {
            out = full_ans;
        }
        else if (mode == 2) {

            if (resp_int) out.push_back(full_ans[0]);
            for (int i = 1; i < full_ans.size(); i++) if (full_ans[i].fi != full_ans[i - 1].fi) out.push_back(full_ans[i]);

        }
        else {

            int kol = 1;
            for (int i = 1; i < full_ans.size(); i++) if (full_ans[i].fi != full_ans[i - 1].fi) {

                int mx = map_ans_max[full_ans[i - 1].fi];
                if (mx * count == kol) out.push_back(full_ans[i - 1]);
                kol = 1;

            }
            else kol++;

            int mx = map_ans_max[full_ans[full_ans.size() - 1].fi];
            if (mx * count == kol) out.push_back(full_ans[full_ans.size() - 1]);


        }

        if (!out.size()) cout << -1 << endl;
        else {

            cout << out.size() << endl;
            for (int i = 0; i < out.size(); i++) {
                cout << out[i].fi << endl;
                cout << out[i].se << endl;
                cout << endl;
            }

        }

        all_files.close();
    }

	return 0;
}

/*
C:\\DISK D\\Kill_me\\foolishness

C:\\DISK D\\Kill_me\\Aachen
C:\DISK D\Kill_me\Aachen

C:\DISK D\Kill_me\ab

c\Aachen
1

C:\DISK D\Kill_me
0
hopped
*/
