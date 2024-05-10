
#include <bits/stdc++.h>

#define rep(i,a,b)      for(int i = a; i < b; i ++)

using namespace std;


int mindist(vector<int> distance, vector<bool> visited)
{
    int min = INT_MAX;int ind = -1;
    rep(i,0,distance.size())
    {
        if(distance[i]!=INT_MAX && distance[i] < min && visited[i] == false)
        {
            ind = i;
            min = distance[i];
        }
    }
    return ind;
}

void printSolution(vector<int> dist)
{
    cout << "Vertex \t Distance from Source" << endl;
    for (int i = 0; i < dist.size(); i++)
        cout << i << " \t\t" << dist[i] << endl;
}


void djikstras(vector<vector<int>> graph, int src)
{
    vector<int> distance(graph.size(), INT_MAX);
    vector<bool> visited(graph.size(), false);

    distance[src] = 0;

    rep(i,1,graph.size()-1)
    {
        int u = mindist(distance, visited);
        visited[u] = true;

        rep(v,0,graph.size())
        {
            if(graph[u][v] && !visited[v] && distance[u]!=INT_MAX && graph[u][v] + distance[u] < distance[v])
            {
                distance[v] = graph[u][v] + distance[u] ;
            }

        }
    }
    printSolution(distance);

}


int main()
{
    int v; 
    cout << "enter the number of vertices: "; cin >> v;


    vector<vector<int>> graph(v);

    rep(i,0,v)
    {
        graph[i].resize(v);
    }
    cout << "enter the number of edges present inside the graph: "; int n; cin >> n;
    rep(i,0,n)
    {
        int x,y,wt;
        cin >> x >>y >> wt;
        graph[x][y] = wt;
    }

    djikstras(graph,0);

}
