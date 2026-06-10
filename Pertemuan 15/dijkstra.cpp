#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

const int INF = 1000000000;
int n = 7;

vector<pair<int, int>> graph[7];
vector<string> lokasi = {"Restoran", "A", "B", "C", "D", "E", "Pelanggan"};
vector<int> dist_node;
vector<int> parent;

void addEdge(int u, int v, int w) {
    graph[u].push_back({v, w});
    graph[v].push_back({u, w});
}

int main() {
    addEdge(0, 1, 4);
    addEdge(0, 2, 2);
    addEdge(0, 3, 7);
    addEdge(1, 2, 3);
    addEdge(1, 5, 6);
    addEdge(2, 3, 3);
    addEdge(2, 4, 2);
    addEdge(2, 5, 3);
    addEdge(3, 4, 4);
    addEdge(4, 6, 3);
    addEdge(5, 6, 4);

    dist_node.assign(n, INF);
    parent.assign(n, -1);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    int start = 0;
    int goal = 6;
    dist_node[start] = 0;
    pq.push({0, start});

    while (!pq.empty()) {
        int d = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        if (d > dist_node[u]) continue;

        for (auto edge : graph[u]) {
            int v = edge.first;
            int w = edge.second;

            if (dist_node[u] + w < dist_node[v]) {
                dist_node[v] = dist_node[u] + w;
                parent[v] = u;
                pq.push({dist_node[v], v});
            }
        }
    }

    vector<int> path;
    for (int v = goal; v != -1; v = parent[v]) {
        path.push_back(v);
    }
    reverse(path.begin(), path.end());

    cout << "===== FOOD DELIVERY =====" << endl << endl;
    cout << "Rute Tercepat : " << endl;

    for (int i = 0; i < path.size(); i++) {
        cout << lokasi[path[i]];
        if (i < path.size() - 1) cout << " -> ";
    }

    cout << "\n\nTotal Waktu Tempuh : " << dist_node[goal] << " menit\n";

    return 0;
}
