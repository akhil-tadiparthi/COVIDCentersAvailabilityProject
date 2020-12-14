#include "Graph.h"
#include "Queue.h"
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include <queue>

using namespace std;


void Graph::addEdge(string v1, string v2, int weight){
    //adds edge between v1 and v2. The distance between the two centers is passed in through weight
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
    //checks if vertex already exists
    for(int i = 0; i < vertices.size(); i++){
        if(vertices[i].name == n){
            found = true;
            cout<<vertices[i].name<<" found."<<endl;
        }
    }

    //adds if the vertex doesn't exist
    if(found == false){
        vertex v;
        v.name = n;
        vertices.push_back(v);

    }
}


void Graph::displayEdges()
{
    //loops through the vertices and prints all of its edges
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


void Graph::displayVerticesNearMe(string name, int miles){
    vertex *finder = findVertex(name);
    //loops through the verticies
    for(int i=0; i < finder->adj.size(); i++){
        //if the distance is less than what was passed in, it prints the vertices
        if(finder->adj[i].weight <= miles){
            adjVertex tmp = finder->adj[i];
            cout << tmp.v->name << " is " << tmp.weight << " miles away from you!" << endl;
        }
    }
    
};


void Graph::displayVertices(){
    //loops through and displays vertices
    for(int i = 0; i < vertices.size(); i++){
        cout<<vertices[i].name<<endl;
    }
}


void Graph::isAdjacent(std::string v1, std::string v2){
    vertex *finder = findVertex(v1);

    //loops through the vertices and prints the distance between the two centers
    for(int i=0; i < finder->adj.size(); i++){
        if(finder->adj[i].v->name == v2){
            cout << finder->adj[i].weight << " miles apart!" << endl;
            break;
        }
    }
};


vertex *Graph::findVertex(std::string name){

    //loops through the vertices to find a specific vertex
    for(int i=0; i<vertices.size(); i++){
        if(vertices[i].name == name){
            return &vertices[i];
        }
    }
    return NULL;
};


bool Graph::enqueueIndividuals(vertex *vertToAdd, person individual){
    //calls the queue function to enqueue the patient at the vertToAdd
    bool success = vertToAdd->graphQueue->enqueue(individual);
    return success;
};


void Graph::printQueueFromGraph(vertex *vert){
    //prints the queue at vert
    vert->graphQueue->printQueue();
};

bool Graph::vertexExists(string address){
    //checks if the vertex exists by looping through all of them
    bool found = false;
    for(int i = 0; i < vertices.size(); i++){
        if(vertices[i].name == address){
            found = true;
            return true;
        } 
    }
    if(found == false){
        return false;
    }
    
};


void Graph::printShortestPath(string start1, string end1) {
    vertex* startVertex;
    startVertex = findVertex(start1);
    vertex* endVertex;
    endVertex = findVertex(end1);
    //initialize starter
    startVertex->distance = 0;
    startVertex->visited = true;
    startVertex->parent = nullptr;
    vector<vertex*> beenthrough;
    beenthrough.push_back(startVertex);
    while (!allVerticesVisited()) {
        for (int i = 0; i < beenthrough.size(); i++) {
            for (int j = 0; j < beenthrough[i]->adj.size(); j++) {
                //Sets the parents and distance if there is a shorter distance
                if (!beenthrough[i]->adj[j].v->visited && beenthrough[i]->distance + beenthrough[i]->adj[j].weight < beenthrough[i]->adj[j].v->distance) {
                    beenthrough[i]->adj[j].v->distance = beenthrough[i]->distance + beenthrough[i]->adj[j].weight;
                    beenthrough[i]->adj[j].v->parent = beenthrough[i];
                }
            }
        }
        //assigns minNode using the minNode function
        vertex* minNode = getMinNode();
        if (minNode == endVertex) {
            break;
        }
        minNode->visited = true;
        beenthrough.push_back(minNode);
    }
    //creates a vector for which centers to go through for teh shortest distance
    vector<string> steps;
    vertex* tmpVertex;
    tmpVertex = endVertex;
    while (tmpVertex != nullptr){
        steps.push_back(tmpVertex->name);
        tmpVertex = tmpVertex->parent;
    }
    for (int i = steps.size() - 1; i >= 0; i--) {
        if (i== 0) cout << steps[i] << endl;
        else cout << steps[i] << "-->";
    }

    //prints toatl distance between edges
    cout << endVertex->distance << " miles in total" << endl;

    //resets to default
    for (int i = 0; i < vertices.size(); i++) {
        vertices[i].distance = INT_MAX;
        vertices[i].parent = nullptr;
        vertices[i].visited = false;
    }
}

vertex* Graph::getMinNode(){
    int minNum = INT_MAX;
    vertex* minNode;
    //loops through and returns the min distance vertex
    for (int i = 0; i < vertices.size(); i++) {
        if (!vertices[i].visited) {
            if (vertices[i].distance < minNum) {
                minNum = vertices[i].distance;
                minNode = &vertices[i];
            }
        }
    }
    return minNode;
} 

bool Graph::allVerticesVisited() {
    //checks if all the vertices have been visited
    bool visited = true;
    for (int i = 0; i < vertices.size(); i++) {
        if (!vertices[i].visited) visited = false;
    }
    return visited;
}