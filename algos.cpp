#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

// ================= GRAPH CLASS =================
class Graph {
private:
    int V;
    vector<vector<pair<int, int>>> adj; // (node, weight)
    vector<vector<int>> edges; // for Kruskal

public:
    Graph(int v) {
        V = v;
        adj.resize(V);
    }

    void addEdge(int u, int v, int w) {
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
        edges.push_back({w, u, v});
    }

    // ========== DIJKSTRA ==========
    void dijkstra(int src) {
        vector<int> dist(V, 1e9);
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

        dist[src] = 0;
        pq.push({0, src});

        while (!pq.empty()) {
            int d = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            for (auto it : adj[node]) {
                int v = it.first;
                int w = it.second;

                if (dist[v] > d + w) {
                    dist[v] = d + w;
                    pq.push({dist[v], v});
                }
            }
        }

        cout << "\nShortest distances from node " << src << ":\n";
        for (int i = 0; i < V; i++) {
            cout << "To " << i << " = " << dist[i] << endl;
        }
    }

    // ========== PRIM'S ==========
    void prims() {
        vector<int> key(V, 1e9);
        vector<bool> mst(V, false);

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

        key[0] = 0;
        pq.push({0, 0});

        int total = 0;

        while (!pq.empty()) {
            int u = pq.top().second;
            pq.pop();

            if (mst[u]) continue;
            mst[u] = true;
            total += key[u];

            for (auto it : adj[u]) {
                int v = it.first;
                int w = it.second;

                if (!mst[v] && w < key[v]) {
                    key[v] = w;
                    pq.push({key[v], v});
                }
            }
        }

        cout << "\nTotal cost of MST (Prim's): " << total << endl;
    }

    // ========== KRUSKAL ==========
    int findParent(int node, vector<int>& parent) {
        if (parent[node] == node) return node;
        return parent[node] = findParent(parent[node], parent);
    }

    void kruskal() {
        sort(edges.begin(), edges.end());

        vector<int> parent(V);
        for (int i = 0; i < V; i++) parent[i] = i;

        int total = 0;

        for (auto e : edges) {
            int w = e[0], u = e[1], v = e[2];

            int pu = findParent(u, parent);
            int pv = findParent(v, parent);

            if (pu != pv) {
                total += w;
                parent[pu] = pv;
            }
        }

        cout << "\nTotal cost of MST (Kruskal): " << total << endl;
    }
};

// ================= SELECTION SORT =================
void selectionSort(vector<int>& arr) {
    int n = arr.size();

    for (int i = 0; i < n - 1; i++) {
        int minIdx = i;

        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIdx]) {
                minIdx = j;
            }
        }

        swap(arr[i], arr[minIdx]);
    }

    cout << "\nSorted Array:\n";
    for (int x : arr) cout << x << " ";
    cout << endl;
}

// ================= MAIN =================
int main() {
    int V, E;

    cout << "Enter number of vertices: ";
    cin >> V;

    Graph g(V);

    cout << "Enter number of edges: ";
    cin >> E;

    cout << "Enter edges (u v weight):\n";
    for (int i = 0; i < E; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        g.addEdge(u, v, w);
    }

    int choice;

    do {
        cout << "\n===== MENU =====\n";
        cout << "1. Dijkstra\n";
        cout << "2. Prim's MST\n";
        cout << "3. Kruskal MST\n";
        cout << "4. Selection Sort\n";
        cout << "5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                int src;
                cout << "Enter source node: ";
                cin >> src;
                g.dijkstra(src);
                break;
            }

            case 2:
                g.prims();
                break;

            case 3:
                g.kruskal();
                break;

            case 4: {
                int n;
                cout << "Enter size of array: ";
                cin >> n;

                vector<int> arr(n);
                cout << "Enter elements:\n";
                for (int i = 0; i < n; i++) cin >> arr[i];

                selectionSort(arr);
                break;
            }

            case 5:
                cout << "Exiting...\n";
                break;

            default:
                cout << "Invalid choice!\n";
        }

    } while (choice != 5);

    return 0;
}