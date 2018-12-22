#include <bits/stdc++.h>
#include <stdio.h>
#include <dirent.h>
#include <sys/types.h>

#define ll long long

using namespace std;

ll mod = 1000165987;
ll step[5000000];
ll p = 205, hs;

ll get_hs(string &s1) {

    ll ans = 0;
    for (int i = 0; i < s1.size(); i++) {
        ans = ans + (s1[i] + 100) * step[i];
        ans %= mod;
    }
    return ans;
}

static void list_dir(const char *path, ll val)
{

//    cout << "in list dir" << endl;
//    cout << path << " val=" << val << endl;

    struct dirent *entry;
    DIR *dir = opendir(path);
    if (dir == NULL) {
        return;
    }

    while ((entry = readdir(dir)) != NULL) {
        string s1 = entry -> d_name, s2;
        int n = s1.size();

//        cout << "s1=" << s1 << endl;

        if (s1.size() > 4 && s1.substr(n - 4, 4) == "json") {

//            cout << "+" << endl;

            s2 = path;
            s2 += "\\";
            //s2 += "";
            s2 += s1;

            n = s2.size();

            s2.erase(n - 4, 4);
            s2 = s2 + "txtt";

//            cout << "S2====" << s2 << endl;

            ifstream in(s2);

            ll a;
            while(in >> a) {
//                cout << a << endl;
                if (a == val) {
                    cout << "FIND MATCH; WAY: " << s2 << endl;
                }
            }

            in.close();
        }
    }

    closedir(dir);
}

int main() {

//    setlocale(LC_ALL, "Rus");

    int m = 1e5;

    step[0] = 1;
    for (int i = 1; i <= m; i++) {
        step[i] = step[i - 1] * p;
        step[i] %= mod;
    }


    char way[200];
    char key[200];
    char val[200];



    while(1) {

        cout << "           Enter way, key, val:" << endl;

        gets(way);
        gets(key);
        gets(val);

        clock_t startTime = clock();




        string s1, s2;
        s1 = way;
//        cout << s1 << endl;

//        s1 = key + "$$$" + val;
        s1 = key;
        s1 += "$$$";
        s1 += val;
        hs = get_hs(s1);

        list_dir(way, hs);

        cout << double( clock() - startTime ) / (double)CLOCKS_PER_SEC<< " seconds." << endl;

//        cout << "s1=" << s1 << " hs=" << hs << endl;



    }


}

/*
C:\DISK D\Kill_me\Aachen
monolatry
False

C:\DISK D\Kill_me\roentgenoscope
petrel
False

C:\DISK D\Kill_me\roentgenoscope
sigma
cw

C:\DISK D\Kill_me\roentgenoscope
Sigma
cw

/home/user/Work/control
*/
