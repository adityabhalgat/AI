#include<iostream>
#include<queue>
#include<vector>
using namespace std;

class FlightGraph{
    int cities;
    vector<vector<int>>adjList;

public:
    FlightGraph(int n){
        cities = n;
        adjList.resize(n);
    }

    void makeConnection(int u , int v){
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    void dfsHelper(int city , vector<bool>& Visited){
        Visited[city] = true;
        cout << city << " ";
        for(auto neighbour : adjList[city]){
            if(!Visited[neighbour]){
                dfsHelper(neighbour , Visited);
            }
        }
    }

    void traverseDFS(){
        vector<bool>Visited(cities,false);
        for(int i = 0 ; i < cities ; i++){
            if(!Visited[i])
                dfsHelper(i , Visited);
        }
    }


    void bfs(int startCity){
        queue<int>q;
        vector<bool>visited(cities , false);

        q.push(startCity);
        visited[startCity] = true;
        while(!q.empty()){
            int curCity = q.front();
            q.pop();
            
            for(auto it : adjList[curCity]){
                if(!visited[it]){
                    visited[it] = true;
                    q.push(it);
                }
            }
        }

    }
};