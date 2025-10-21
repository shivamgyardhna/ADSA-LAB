#include <iostream>
#include <vector>
using namespace std;

void addegde(vector<int> adj[], int v, int u)
{
  adj[v].push_back(u);
  adj[u].push_back(v);
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
  void dfsrec(vector<int> adj[], int v, bool visited[], int src, vector<int> &ve)
  {
    visited[src] = true;
    ve.push_back(src);
    for (int x : adj[src])
    {
      if (visited[x] == false)
      {
        dfsrec(adj, v, visited, x, ve);
      }
    }
  }

  vector<int> dfs(vector<int> adj[], int v, int src)
  {
    vector<int> ve;
    bool visited[v] = {0};
    dfsrec(adj, v, visited, src, ve);
    return ve;
  }

  int main()
  {
    int v;
    v = 5;
    // directed graph
    vector<int> adj[v + 1];
    addegde(adj, 0, 1);
    addegde(adj, 0, 2);
    addegde(adj, 0, 4);
    addegde(adj, 4, 3);

    int src = 0;
    printt(adj, v);
    vector<int> ve = dfs(adj, v, src);
    for (int x : ve)
    {
      cout << x << " ";
    }
    return 0;
  }

  /*

  Output: 0 1 2 4 3
  Explanation:
  0 is connected to 1, 2, 4.
  1 is connected to 0.
  2 is connected to 0.
  3 is connected to 0.
  4 is connected to 0, 3.

  */