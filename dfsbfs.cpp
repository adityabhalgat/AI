#include<iostream>
#include<vector>
#include<queue>
using namespace std;


class FlightGraph {
private:
    int cities;
    vector<vector<int>> adjList;

public:
    FlightGraph(int n) {
        cities = n;
        adjList.resize(n);
    }

    // Add flight route (undirected)
    void addRoute(int u, int v) {
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    // Display routes
    void displayRoutes() {
        cout << "\nFlight Routes:\n";
        for (int i = 0; i < cities; i++) {
            cout << "City " << i << " -> ";
            for (int dest : adjList[i]) {
                cout << dest << " ";
            }
            cout << endl;
        }
    }

    // ========== DFS ==========
    void dfsHelper(int city, vector<bool> &visited) {
        visited[city] = true;
        cout << city << " ";

        for (int next : adjList[city]) {
            if (!visited[next]) {
                dfsHelper(next, visited);
            }
        }
    }

    void exploreAllCities() {
        vector<bool> visited(cities, false);

        cout << "\nDFS (Exploring all reachable cities): ";
        for (int i = 0; i < cities; i++) {
            if (!visited[i]) {
                dfsHelper(i, visited);
            }
        }
        cout << endl;
    }

    // ========== BFS ==========
    void shortestRoute(int start) {
        vector<bool> visited(cities, false);
        queue<int> q;

        q.push(start);
        visited[start] = true;

        cout << "\nBFS (Minimum stops from city " << start << "): ";

        while (!q.empty()) {
            int city = q.front();
            q.pop();

            cout << city << " ";

            for (int next : adjList[city]) {
                if (!visited[next]) {
                    visited[next] = true;
                    q.push(next);
                }
            }
        }
        cout << endl;
    }
};

// ================= MAIN =================
int main() {
    int n, e;

    cout << "Enter number of cities: ";
    cin >> n;

    FlightGraph fg(n);

    cout << "Enter number of routes: ";
    cin >> e;

    cout << "Enter routes (city1 city2):\n";
    for (int i = 0; i < e; i++) {
        int u, v;
        cin >> u >> v;
        fg.addRoute(u, v);
    }

    int choice;

    do {
        cout << "\n===== Flight Management Menu =====\n";
        cout << "1. Add Route\n";
        cout << "2. Display Routes\n";
        cout << "3. Explore All Cities (DFS)\n";
        cout << "4. Find Routes from City (BFS)\n";
        cout << "5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                int u, v;
                cout << "Enter cities to connect: ";
                cin >> u >> v;
                fg.addRoute(u, v);
                break;
            }
            case 2:
                fg.displayRoutes();
                break;

            case 3:
                fg.exploreAllCities();
                break;

            case 4: {
                int start;
                cout << "Enter starting city: ";
                cin >> start;
                fg.shortestRoute(start);
                break;
            }

            case 5:
                cout << "Exiting system...\n";
                break;

            default:
                cout << "Invalid choice!\n";
        }

    } while (choice != 5);

    return 0;
}