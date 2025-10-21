#include <iostream>
#include <queue>
using namespace std;

void addegde(vector<int> adj[], int v, int u)
{
  adj[v].push_back(u);
}

void printt(vector<int> adj[], int v)
{
    for (int i = 0; i <= v; i++)
    {
      cout << i;
      for (int x : adj[i])
      {
        cout << "->" << x;
      }
      cout << endl;
    }
  }
  
  vector<int> bfs(vector<int> adj[], int v, int src)
  {
    vector<int> ve;
    bool visited[v] = {0};
    queue<int> q;
    visited[src] = true;
    // ve.push_back(src);
    q.push(src);
    while (!q.empty())
    {
      int f = q.front();
      ve.push_back(f);
      q.pop();
      for (int x : adj[f])
      {
        if (visited[x] == false)
        {
          visited[x] = true;
          q.push(x);
        }
      }
    }
    return ve;
  }

  int main()
  {
    int v;
    v = 4;
    // directed graph
    vector<int> adj[v + 1];
    addegde(adj, 0, 1);
    addegde(adj, 0, 2);
    addegde(adj, 0, 4);
    addegde(adj, 4, 3);

    int src = 0;
    printt(adj, v);
    vector<int> ve = bfs(adj, v, src);
    for (int x : ve)
    {
      cout << x << " ";
    }
    return 0;
  }
