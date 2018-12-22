#include <bits/stdc++.h>

#define ll long long

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

    cout << "TREE DONE." << endl;
    while(1) {

        cout << "Enter values: " << endl;

        getline(cin, q_path);
        getline(cin, q_val);

        for (int i = 0; i < q_path.size(); i++) if (q_path[i] == '\\') {
            q_path.insert(i, "\\");
            i+=1;
        }
        cout << q_path << endl;

        vector<string> response;

        int resp_int = 0;

        rep_now = name_rep[q_path];
        if (rep_now) {
            response = map_key[rep_now][q_val];
//            cout << map_key[rep_now][q_val] << " path: " << q_path << endl;

            for (int i = 0; i < response.size(); i++) {
                resp_int = 1;
                cout << response[i] << "    path:=" << q_path << endl;
            }
        }

//        if (!resp)

    }

	return 0;
}

/*
C:\\DISK D\\Kill_me\\foolishness

C:\\DISK D\\Kill_me\\Aachen
C:\DISK D\Kill_me\Aachen

C:\DISK D\Kill_me\ab
*/
