#include <iostream>
#include <vector>
#include <queue>

#define INF 999999

void addEdge(std::vector<std::pair<int, int>> Graph[], int u, int v, int w)
{
    Graph[u].push_back({v, w});
    Graph[v].push_back({u, w});
}

void Dijkstra(std::vector<std::pair<int, int>> graph[], int src, int V)
{
    //Min Priority Queue to always store min on top 
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> pq;
    std::vector<int> dist(V, INF);

    dist[src] = 0;
    pq.push(std::make_pair(0, src));

    while (!pq.empty())
    {
        int u = pq.top().second;
        pq.pop();

        for (auto x : graph[u])
        {
            int v = x.first;
            int w = x.second; // distance u -> v
            if (dist[u] + w < dist[v]) // (src -> u) + (u -> v) < (src -> v)
            {
                dist[v] = dist[u] + w;
                pq.push(std::make_pair(dist[v], v));
            }
        }
    }

    for(int i=1;i<V;++i)
    {
        std::cout<<"U->V: "<< 0 <<"->"<<i<<"  weight = "<<dist[i]<<"\n";
    }
}

int main()
{
    int V = 9;
    std::vector<std::pair<int, int>> graph[V];
    addEdge(graph, 0, 1, 4);
    addEdge(graph, 0, 7, 8);
    addEdge(graph, 1, 2, 8);
    addEdge(graph, 1, 7, 11);
    addEdge(graph, 2, 3, 7);
    addEdge(graph, 2, 8, 2);
    addEdge(graph, 2, 5, 4);
    addEdge(graph, 3, 4, 9);
    addEdge(graph, 3, 5, 14);
    addEdge(graph, 4, 5, 10);
    addEdge(graph, 5, 6, 2);
    addEdge(graph, 6, 7, 1);
    addEdge(graph, 6, 8, 6);
    addEdge(graph, 7, 8, 7);

    Dijkstra(graph, 0, 9);
}
