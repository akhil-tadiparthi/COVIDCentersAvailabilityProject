#ifndef GRAPH_H
#define GRAPH_H
#include<vector>
#include<iostream>
#include "Queue.h"

struct vertex;

struct adjVertex{
    vertex *v;
    int weight;
};

struct vertex{
    std::string name;
    vertex *parent;
    bool visited;
    int distance;
    std::vector<adjVertex> adj;
    Queue *graphQueue = new Queue(100);

};

struct edge {
    vertex *neighbor;
    int weight;

};

class Graph
{
    public:
        Graph(){};
        ~Graph(){};  
        void addEdge(std::string v1, std::string v2, int weight);
        void addVertex(std::string name);
        int isAdjacent(std::string v1, std::string v2);
        void displayEdges();
        void displayVerticesNearMe(std::string name);
        void displayVertices();
        void dijkstra(std::string start, std::string end);
        vertex *findVertex(std::string name);
        bool enqueueIndividuals(vertex *vertToAdd,person individual);
        bool dequeueIndividuals();
        void PrintPrimaryQueue();

    protected:
    private:
        Queue *graphQueue;
        std::vector<vertex> vertices;

        
};

#endif // GRAPH_H
