#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <climits>
#include <algorithm>
using namespace std;

const int INF = INT_MAX;
int V = 8;
vector<string> names = {"Andi","Budi","Citra","Dina","Eko","Fara","Gilang","Hana"};
vector<vector<int>> adj(8);
vector<vector<pair<int,int>>> wadj(8);

void addEdge(int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void addWeightedEdge(int u, int v, int w) {
    wadj[u].push_back({v,w});
    wadj[v].push_back({u,w});
}

void dfsHelper(int v, vector<bool>& visited) {
    visited[v] = true;
    cout << "  -> " << names[v] << "\n";
    for (int u : adj[v])
        if (!visited[u])
            dfsHelper(u, visited);
}

void runDFS(int start) {
    vector<bool> visited(V, false);
    cout << "\n[DFS] Telusuri semua teman yang terhubung dari " << names[start] << ":\n";
    dfsHelper(start, visited);
}

void runBFS(int start) {
    vector<bool> visited(V, false);
    vector<int> level(V, -1);
    queue<int> q;
    visited[start] = true;
    level[start] = 0;
    q.push(start);
    
    cout << "\n[BFS] Tingkat pertemanan dari " << names[start] << ":\n";
    while (!q.empty()) {
        int v = q.front(); q.pop();
        cout << "  Level " << level[v] << " : " << names[v];
        if (level[v] == 0) cout << " (kamu sendiri)";
        else if (level[v] == 1) cout << " (teman langsung)";
        else cout << " (teman dari teman, " << level[v] << " langkah)";
        cout << "\n";
        
        for (int u : adj[v]) {
            if (!visited[u]) {
                visited[u] = true;
                level[u] = level[v] + 1;
                q.push(u);
            }
        }
    }
}

void displayWeightedGraph() {
    cout << "\n[WEIGHTED GRAPH] Representasi jaringan sosial berbobot:\n";
    for (int i = 0; i < V; i++) {
        cout << "  " << names[i] << " -> ";
        for (auto edge : wadj[i])
            cout << names[edge.first] << "(jarak:" << edge.second << ") ";
        cout << "\n";
    }
}

void runDijkstra(int start) {
    vector<int> dist(V, INF);
    vector<int> prev_node(V, -1);
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    
    dist[start] = 0;
    pq.push({0, start});
    
    while (!pq.empty()) {
        int d = pq.top().first, u = pq.top().second; pq.pop();
        if (d > dist[u]) continue;
        
        for (auto edge : wadj[u]) {
            int v = edge.first, w = edge.second;
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                prev_node[v] = u;
                pq.push({dist[v], v});
            }
        }
    }
    
    cout << "\n[DIJKSTRA] Jalur hubungan terpendek dari " << names[start] << ":\n";
    for (int i = 0; i < V; i++) {
        if (i == start) continue;
        cout << "  " << names[start] << " -> " << names[i] << " : ";
        if (dist[i] == INF) { cout << "tidak terhubung\n"; continue; }
        
        cout << "total jarak = " << dist[i] << " | jalur: ";
        vector<int> path;
        for (int cur = i; cur != -1; cur = prev_node[cur]) path.push_back(cur);
        reverse(path.begin(), path.end());
        
        for (int j = 0; j < (int)path.size(); j++) {
            cout << names[path[j]];
            if (j < (int)path.size() - 1) cout << " -> ";
        }
        cout << "\n";
    }
}

int main() {
    cout << "============================================================\n";
    cout << "     SIMULASI JARINGAN SOSIAL - STRUKTUR DATA GRAF\n";
    cout << "============================================================\n";

    cout << "\n[USERS] Daftar pengguna:\n";
    for (int i = 0; i < V; i++) cout << "  ID " << i << " : " << names[i] << "\n";

    addEdge(0,1); addEdge(0,2); addEdge(1,3); addEdge(1,4);
    addEdge(2,4); addEdge(2,5); addEdge(3,6); addEdge(4,7);
    addEdge(5,6); addEdge(6,7);

    cout << "\n[ADJACENCY LIST] Jaringan pertemanan:\n";
    for (int i = 0; i < V; i++) {
        cout << "  " << names[i] << " -> ";
        for (int u : adj[i]) cout << names[u] << " ";
        cout << "\n";
    }

    runDFS(0);
    runBFS(0);

    addWeightedEdge(0,1,1); addWeightedEdge(0,2,2); addWeightedEdge(1,3,3); addWeightedEdge(1,4,4);
    addWeightedEdge(2,4,2); addWeightedEdge(2,5,5); addWeightedEdge(3,6,2); addWeightedEdge(4,7,3);
    addWeightedEdge(5,6,1); addWeightedEdge(6,7,4);

    displayWeightedGraph();
    runDijkstra(0);

    cout << "\n============================================================\n";
    cout << "                   SIMULASI SELESAI\n";
    cout << "============================================================\n";

    return 0;
}
