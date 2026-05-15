#include<iostream>
#include<vector>
#include<queue>
#include<cmath>
using namespace std;
/*
1. Create a strut node with x,y,g,h make a function f in it which gives g+h to us
2. Create a strut Compare with a operater overloading a.f > b.f
3. Create a gamemap class with n , m and vector of vector grid
4. make a default constructor which makes a m*n vector and initializes it to 0 
5. make a add obastacle method to checnge it to 1 if there is a obstacle
6. display function to show the gird made
7. heuristic function which will give me the manhatten distance between the curr x and y and final goal
8. A* function : 
    a. priority queue <Node, vector<Node> , Compare>
    b.  visited array with all false
    c.  push start in queue {x,y,0,heuristic(x,y,fx,fy)}
    d.  while not empty pop the top if visited then continue else go to adjacent 
    e.  callcualte the new g and h 
    f.  push them to tehe queue
    g.


*/
struct Node {
    int x, y;
    int g, h;

    int f() const {
        return g + h;
    }
};

// Comparator for priority queue
struct Compare {
    bool operator()(Node a, Node b) {
        return a.f() > b.f();
    }
};

class GameMap {
private:
    int n, m;
    vector<vector<int>> grid;

public:
    GameMap(int rows, int cols) {
        n = rows;
        m = cols;
        grid.assign(n, vector<int>(m, 0));
    }

    void addObstacle(int x, int y) {
        grid[x][y] = 1;
    }

    void display() {
        cout << "\nGame Map (0=Free, 1=Obstacle):\n";
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cout << grid[i][j] << " ";
            }
            cout << endl;
        }
    }

    int heuristic(int x1, int y1, int x2, int y2) {
        return abs(x1 - x2) + abs(y1 - y2); // Manhattan
    }

    void aStar(int sx, int sy, int gx, int gy) {
        priority_queue<Node, vector<Node>, Compare> pq;
        vector<vector<bool>> visited(n, vector<bool>(m, false));

        pq.push({sx, sy, 0, heuristic(sx, sy, gx, gy)});

        cout << "\nPath Traversal (A*): ";

        while (!pq.empty()) {
            Node curr = pq.top();
            pq.pop();

            int x = curr.x;
            int y = curr.y;

            if (visited[x][y]) continue;
            visited[x][y] = true;

            cout << "(" << x << "," << y << ") ";

            if (x == gx && y == gy) {
                cout << "\nGoal Reached!\n";
                return;
            }

            // 4 directions
            int dx[] = {-1, 1, 0, 0};
            int dy[] = {0, 0, -1, 1};

            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];

                if (nx >= 0 && ny >= 0 && nx < n && ny < m &&
                    grid[nx][ny] == 0 && !visited[nx][ny]) {

                    int newG = curr.g + 1;
                    int newH = heuristic(nx, ny, gx, gy);

                    pq.push({nx, ny, newG, newH});
                }
            }
        }

        cout << "\nNo Path Found!\n";
    }
};

// ================= MAIN =================
int main() {
    int n, m;
    cout << "Enter grid size (rows cols): ";
    cin >> n >> m;

    GameMap game(n, m);

    int choice;

    do {
        cout << "\n===== GAME PATH MENU =====\n";
        cout << "1. Add Obstacle\n";
        cout << "2. Display Map\n";
        cout << "3. Find Path (A*)\n";
        cout << "4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                int x, y;
                cout << "Enter obstacle position: ";
                cin >> x >> y;
                game.addObstacle(x, y);
                break;
            }

            case 2:
                game.display();
                break;

            case 3: {
                int sx, sy, gx, gy;
                cout << "Enter start (x y): ";
                cin >> sx >> sy;
                cout << "Enter goal (x y): ";
                cin >> gx >> gy;
                game.aStar(sx, sy, gx, gy);
                break;
            }

            case 4:
                cout << "Exiting...\n";
                break;

            default:
                cout << "Invalid choice!\n";
        }

    } while (choice != 4);

    return 0;
}