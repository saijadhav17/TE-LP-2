#include<bits/stdc++.h>
#define rep(i,a,b)  for(int i = a; i < b ; i++)

using namespace std;


int minindex(vector<int> key, vector<bool> visited)
{
    int min = INT_MAX;
    int ind = -1;

    rep(i,0,key.size())
    {
        if(key[i]<min && !visited[i])
        {
            min = key[i];
            ind = i;
        }
    }
    return ind;
}

void printMST(vector<int> parent, vector<vector<int>> graph,int n)
{
	cout << "Edge \tWeight\n";
	for (int i = 1; i < n; i++)
		cout << parent[i] << " - " << i << " \t"<< graph[i][parent[i]] << " \n";

    
}


void minimumSpanningTree(vector<vector<int>> graph, int n)
{
    vector<int> parent(n,-1);
    vector<int> key(n, INT_MAX);
    vector<bool> visited(n,false);

    key[0] = 0;
    
    rep(i,0,n-1)
    {
        int u = minindex(key, visited);
        visited[u] = true;
        rep(v,0,n)
        {
            if(graph[u][v] && !visited[v] && graph[u][v] < key[v] )
            {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }
    printMST(parent, graph, n);
}
    

int main()
{
    int v;
    cout << "enter the number of vertices: ";
    cin >> v;

    vector<vector<int>> graph(v);
    
    rep(i, 0, v)
    {
       
        graph[i].resize(v);
    }

    int n; 
    cout << "enter the number of edges: ";
    cin >> n;

    rep(i, 0, n)
    {
        int u, v, wt;
        cin >> u >> v >> wt;

        graph[u][v] = graph[v][u]=wt;
        
    }

    minimumSpanningTree(graph, v);

    return 0;
}