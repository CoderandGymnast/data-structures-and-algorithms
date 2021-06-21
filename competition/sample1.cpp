#include <iostream>
#include <vector>

using namespace std;

void dfs(vector<int> *adjs, bool *visited, int v, int *count)
{
    visited[v] = true;
    (*count)++;
    for (int i = 0; i < adjs[v].size(); i++)
    {
        if (!visited[adjs[v][i]])
        {
            dfs(adjs, visited, adjs[v][i], count);
        }
    }
}

void init(bool *visited, int numNodes)
{

    for (int i = 0; i < numNodes; i++)
    {
        visited[i] = false;
    }
}

int main()
{
    int numNodes, numEdges, a, b, s;
    int count = 0;
    cin >> numNodes;
    vector<int> *adjs = new vector<int>[numNodes];
    bool *visited = new bool[numNodes];
    init(visited, numNodes);
    cin >> numEdges;
    for (int i = 0; i < numEdges; i++)
    {
        cin >> a >> b;
        adjs[a].push_back(b);
        adjs[b].push_back(a);
    }
    cin >> s;
    dfs(adjs, visited, s, &count);
    cout << numNodes - count;
    return 0;
}