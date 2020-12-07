#include "Graph.h"
#include "Queue.h"
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include <queue>

using namespace std;


void Graph::addEdge(string v1, string v2, int weight){

    for(int i = 0; i < vertices.size(); i++){
        if(vertices[i].name == v1){
            for(int j = 0; j < vertices.size(); j++){
                if(vertices[j].name == v2 && i != j){
                    adjVertex av;
                    av.v = &vertices[j];
                    av.weight = weight;
                    vertices[i].adj.push_back(av);
                    //another vertex for edge in other direction
                    adjVertex av2;
                    av2.v = &vertices[i];
                    av2.weight = weight;
                    vertices[j].adj.push_back(av2);
                }
            }
        }
    }
}


void Graph::addVertex(string n){
    bool found = false;
    for(int i = 0; i < vertices.size(); i++){
        if(vertices[i].name == n){
            found = true;
            cout<<vertices[i].name<<" found."<<endl;
        }
    }
    if(found == false){
        vertex v;
        v.name = n;
        vertices.push_back(v);

    }
}


void Graph::displayEdges()
{
    for(int i = 0; i < vertices.size(); i++){
        cout<<vertices[i].name<<"-->";
        for(int j = 0; j < vertices[i].adj.size(); j++){
            cout<<vertices[i].adj[j].v->name;
            if (j != vertices[i].adj.size()-1)
                cout<<"***";
        }
        cout<<endl<<endl;
    }
}


void Graph::displayVerticesNearMe(string name){
    for(int i = 0; i < vertices.size(); i++){
        if(vertices[i].name == name){
            
        }

    }
};


void Graph::displayVertices(){
    for(int i = 0; i < vertices.size(); i++){
        cout<<vertices[i].name<<endl;
    }
}


int Graph::isAdjacent(std::string v1, std::string v2){
    vertex *finder = findVertex(v1);

    for(int i=0; i < finder->adj.size(); i++){
        if(finder->adj[i].v->name == v2){
            return finder->adj[i].weight;
        }
    }
    return -1;
};


vertex *Graph::findVertex(std::string name){
    for(int i=0; i<vertices.size(); i++){
        if(vertices[i].name == name){
            return &vertices[i];
        }
    }
    return NULL;
};


void Graph::dijkstra(std::string start, std::string end){
    vertex *startV = findVertex(start);
    vertex *endV = findVertex(end);
    startV->visited = true;
    startV->distance= 0;
    visited = {startV}; //list of solved vertiices
    while(!endV->visited){
        int minDistance = INT_MAX;
        visitedV = NULL;
        for(int x=0; x < visited.end; x++){
            s=visited[x];
            for(int y=0; y<s.adjacent.end; y++){

            }

        }



    }

}


//add paramenter for vertex
bool Graph::enqueueIndividuals(vertex *vertToAdd, person individual){
    bool success = vertToAdd->graphQueue->enqueue(individual);
    return success;
};

bool Graph::dequeueIndividuals(){
    person tmpCar = graphQueue->dequeue();
    return true;
};
