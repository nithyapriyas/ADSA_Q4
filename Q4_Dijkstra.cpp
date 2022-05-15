#include <bits/stdc++.h>
using namespace std;

#define inf INT_MAX

//find the vertex with min distance
int GetVertexWithMinDistance(int distance[], bool visited[], int numVertices)
{
    int min = inf;
    int minVertex;
 
    for (int i = 0; i < numVertices; i++)
    {
        // If the node is not visited already and the distance is min 
        if (visited[i] == false && distance[i] < min)
        {
            min = distance[i];
            minVertex = i;
        }
    }
 
    return minVertex;
}


//Find Shortest path using Dijkstras
void FindShortestPathUsingDijkstra(std::vector<std::vector<int>> graph, int sourceVertex)
{
    int numVertices = graph.size();
    int distance[numVertices];
    bool visited[numVertices];
 
    //Set distance to inf and set visited as false
    for (int i = 0; i < numVertices; i++)
    {
        distance[i] = inf;
        visited[i] = false;
    }

    //Assign distance as 0 to sourceVertex
    distance[sourceVertex] = 0;

    for (int i = 0; i < numVertices - 1; i++)
    {
        //Get Vertix with minimum distance which is not visited
        int u = GetVertexWithMinDistance(distance, visited, numVertices);
 
        //Set it to visited
        visited[u] = true;
 
        //Go over the adjacency matrix
        for (int v = 0; v < numVertices; v++)
        {
            //Check if the node v is adjacent to u and if its not visited
            if (graph[u][v] && visited[v] == false)
            {
                //Update the distance list if the weight of the edge is lesser than the distance list
                if(graph[u][v] + distance[u] < distance[v])
                {
                    distance[v] = graph[u][v] + distance[u];
                }
            }
        }
    }
 
    // Print the shortest path from the source to each vertex
    printf("\n\nShortest Path using Dijsktra's");
    for (int i = 0; i < numVertices; i++)
    {
        printf("\n\t%d --> %d = %d",sourceVertex, i, distance[i]);
    }
}

int main()
{
    std::vector<std::vector<int>> graph;
    int numVertices;

    printf("\nEnter the number of vertex\n");
    scanf("%d", &numVertices);

    for(int i = 0; i < numVertices; i++)
    {
        graph.push_back(std::vector<int> (numVertices, 0));
    }

    printf("\nEnter the weight of i, j. Enter 0 if they are not connected");
	for(int i = 0; i < numVertices; i++)
	{
		for(int j = 0; j < numVertices; j++)
		{
			if ( i != j)
            {
                if(graph[i][j] == 0)
                {
                    printf("\nEnter the weight of edge %d to %d is \t", i, j);
                    int x;
                    scanf("%d", &x);
                    graph[j][i] = graph[i][j] = x;
                }
            }
		}
	}

    printf("\nThe input graph is \n");
    for(int i=0;i<numVertices;i++)
    {
        printf("\n\t");
        for(int j=0;j<numVertices;j++)
        {
            printf("%d  ", graph[i][j]);
        }
    }
    FindShortestPathUsingDijkstra(graph, 0);
    return 0;
}