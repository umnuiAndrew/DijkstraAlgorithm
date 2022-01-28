# include <iostream>
# include <algorithm>
# include <vector>
# include <list>
using namespace std;

class Graph
{
    vector< vector<int> > Edge;
    vector<unsigned char> visited; //We can use vector<bool>, but it's slow and broken :( , CPP's byte array http://stackoverflow.com/questions/10077771/what-is-the-correct-way-to-deal-with-medium-sized-byte-arrays-in-modern-c
public:

    Graph(int V)
    {
        Edge.resize(V);
        visited.resize(V);
    }

    void add_edge(int v,int w)
    {
        Edge[v].push_back(w);
    }

    void resetVisited()
    {
        for(auto i : visited) i = false;
    }

    void DFS(int s)
    {
        if (visited[s])
        {
            return;
        }
        visited[s] = true;
        cout << s << " ";
        for (auto x = Edge[s].begin(); x != Edge[s].end(); ++x)
        {
            if (!visited[*x])
            {
                DFS(*x);
            }
        }
    }
};

int main()
{
    Graph g(6);
    g.add_edge(0,1);
    g.add_edge(0,2);
    g.add_edge(1,2);
    g.add_edge(2,0);
    g.add_edge(2,3);
    g.add_edge(3,3);
    int v;
    cout<<"Enter vertex from where to perform BFS"<<endl;
    cin>>v;
    g.DFS(v);
}