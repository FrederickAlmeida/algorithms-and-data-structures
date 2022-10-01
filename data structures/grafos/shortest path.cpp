#include <iostream>
// #include <bits/stdc++.h>
#include <vector>
#include <queue>
#include <map>

using namespace::std;

void BFS(map<string, vector<string>> &adjlist, map<string, bool> &vis, map<string, int> &d, string start) {
    queue<string> q;
    q.push(start);
    vis[start] = true;

    while(q.size() > 0) {
        string v = q.front(); q.pop();

        for (auto adjecent: adjlist[v]) {
            if (vis[adjecent] == false) {
                vis[adjecent] = true;
                d[adjecent] = d[v] + 1;
                q.push(adjecent);
            }
        }
    }
}


int main() {
    map<string, bool> vis;
    map<string, int>d;
    map<string, vector<string>> adjlist;

    int cases, teams;
    string name1, name2, name3;

    cin >> cases;

    while (cases--) {
        cin >> teams;

        while (teams--) {
            cin >> name1 >> name2 >> name3;
            d[name1] = 305; d[name2] = 305; d[name3] = 305;

            adjlist[name1].push_back(name2);
            adjlist[name1].push_back(name3);

            adjlist[name2].push_back(name1);
            adjlist[name2].push_back(name3);

            adjlist[name3].push_back(name1);
            adjlist[name3].push_back(name2);
        }

        for(auto it: adjlist) {
            vis[it.first] = false;
        }

        d["Ahmad"] = 0;
        BFS(adjlist, vis, d, "Ahmad");

        vector<pair<int, string>> ans;
        for(auto kv: d) {
            ans.push_back({kv.second, kv.first});
        }

        sort(ans.begin(), ans.end());

        cout << adjlist.size() << "\n";
        for(auto it: ans) {
            cout << it.second << " ";
            if (it.first == 305)    cout << "undefined\n";
            else    cout << it.first << '\n';
        }

        vis.clear();
        d.clear();
        adjlist.clear();
    }
}