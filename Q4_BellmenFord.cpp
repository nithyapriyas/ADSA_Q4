#include <bits/stdc++.h>
using namespace std;

#define inf INT_MAX
struct Edge
{
    int source;
    int destination;
    int weight;
};

struct Graph
{
    int numVertices = -1;
    std::vector<Edge> edgeVector = {};
};

void FindShortestPathUsingBellmanFord(Graph g, int sourceVertex)
{
    int distance[g.numVertices];
 
    //Set distance to inf and set visited as false
    for (int i = 0; i < g.numVertices; i++)
    {
        distance[i] = inf;
    }

    //Assign distance as 0 to sourceVertex
    distance[sourceVertex] = 0;

    for (int i = 0; i < g.numVertices - 1; i++)
    {
        for(auto e: g.edgeVector)
        {
            //Check if the node e.destination is adjacent to e.source and if its not visited
            if (distance[e.source] != inf)
            {
                //Update the distance list if the weight of the edge is lesser than the distance list
                if(e.weight + distance[e.source] < distance[e.destination])
                {
                    distance[e.destination] = e.weight + distance[e.source];
                }
            }
        }
    }
 
    // Print the shortest path
    printf("\n\nShortest Path using BellmenFord's Algo");
    for (int i = 0; i < g.numVertices; i++)
    {
        printf("\n\t%d --> %d = %d",sourceVertex, i, distance[i]);
    }
}

int main()
{
    Graph g;
    //No of vertex, edge
    int numEdge;
    printf("\nEnter the number of vertex\n");
    scanf("%d", &g.numVertices);
    printf("\nEnter the number of edge\n");
    scanf("%d", &numEdge);

    printf("\nEnter the Edge and weight in space seperated way. Example for 0 -> 1 with weight 5, the input should be \"0 1 5\"\n");
    for (int i = 0; i < numEdge; i++)
    {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        g.edgeVector.push_back({u, v, w});
    }


    FindShortestPathUsingBellmanFord(g,0);
    return 0;
}