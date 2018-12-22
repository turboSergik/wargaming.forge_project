#include <bits/stdc++.h>
#include <stdio.h>
#include <dirent.h>
#include <sys/types.h>
#include <ctime>

#define ll long long
using namespace std;

char path[300];
vector<string> v;


static void list_dir(const char *path)
{

    struct dirent *entry;
    DIR *dir = opendir(path);
    if (dir == NULL) {
        return;
    }

    while ((entry = readdir(dir)) != NULL) {
        string s1 = entry -> d_name;
//        cout << "push " << s1 << endl;

        int n = s1.size();
        if (n > 3 && s1[n - 3] == 't' && s1[n - 2] == 'x' && s1[n - 1] == 't') v.push_back(s1);

    }
}

int main()
{
//	 ifstream root(way_to_resp);
	//ifstream root("/home/user/Work/response1.txt");

	string s_root, s_way, s2;
	string key, value, q_key;
	string root;
    string kek;


	root = "C:\\DISK D\\228322\\get.txt";

	string path_string;

    ifstream read_root(root);
//    gets(path);
//    read_root >> path;
//    getline(read_root, q_key);


    getline(read_root, kek);
    while(kek[kek.size() - 1] == ' ') kek.erase(kek.size() - 1, 1);

//    path = c_str(kek);
    for (int i = 0; i < kek.size(); i++) path[i] = kek[i];

    getline(read_root, q_key);


//    gets(path);
//    getline(cin, q_key);

//    cout << path << " ------- " << q_key << endl;


    unsigned int start_time =  clock(); // начальное время
    // здесь должен быть фрагмент кода, время выполнения которого нужно измерить

    vector<string> resp;
    v.clear();

    list_dir(path);


    for (int i = 0; i < v.size(); i++){


        path_string = "";
        for (int i = 0; i < strlen(path); i++) path_string = path_string + path[i];

        s_way = v[i];
        path_string += "\\\\";
        path_string += s_way;
        s_way = path_string;

            cout << s_way << endl;



        ifstream in(s_way);
        while(in >> key) {

            getline(in, value);

//                cout << key << " " << q_key << endl;

            if (key == q_key) resp.push_back(value);

        }
    }

        ofstream put_root("C:\\DISK D\\228322\\put.txt");
        put_root << 1 << "|";
        for (auto i : resp) {
            put_root << i << " ";
//            cout << i << endl;
        }
        put_root << "|";
        put_root << s_way;
        cout << endl;

//
//    cout << path << endl;
//    cout << q_key << endl;
//    cout << endl;

    unsigned int end_time = clock(); // конечное время
    unsigned int search_time = end_time - start_time; // искомое время
//    cout << "TIME: " << search_time << endl;





	return 0;
}

/*
C:\\DISK D\\Kill_me\\foolishness
False


C:\\DISK D
lol
*/
