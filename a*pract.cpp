#include<iostream>
#include<vector>
#include<queue>
using namespace std;

struct Node
{
    int x,y,g,h;

    int f(){
        return g + h;
    }
};

struct Compare
{
    bool operator()(Node a , Node b){
        return a.f() > b.f();
    }
};


class GameMap{
    int n , m;
    vector<vector<int>>grid;

    GameMap(int N , int M){
        n = N;
        m = M;
        grid.assign(n,vector<int>(m,0));
    }

    void addObstacle(int x , int y){
        grid[x][y] = 1;
    }
    
    void printGrid(){
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < 0 ; j++){
                cout << grid[i][j] << " ";
            }
            cout << endl;
        }
    }

    int heuristic(int x , int y, int gx , int gy){
        return abs(x - gx) + abs(y - gy);
    }

    void AStar(int sx , int sy , int gx, int gy){
        priority_queue<Node , vector<Node> , Compare>pq;
        vector<vector<bool>> visited(n, vector<bool>(m, false));

        pq.push({sx,sy,0,heuristic(sx,sy,gx,gy)});

        while (!pq.empty())
        {
            Node curr = pq.top();
            pq.pop();

            int currX = curr.x;

        }
        

    }
};

int main(){
    return 0;
}