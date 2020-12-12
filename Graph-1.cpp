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


void Graph::displayVerticesNearMe(string name, int miles){
    vertex *finder = findVertex(name);

    for(int i=0; i < finder->adj.size(); i++){
        if(finder->adj[i].weight <= miles){
            adjVertex tmp = finder->adj[i];
            cout << tmp.v->name << " is " << tmp.weight << " miles away from you!" << endl;
        }
    }
    
};


void Graph::displayVertices(){
    for(int i = 0; i < vertices.size(); i++){
        cout<<vertices[i].name<<endl;
    }
}


void Graph::isAdjacent(std::string v1, std::string v2){
    vertex *finder = findVertex(v1);

    for(int i=0; i < finder->adj.size(); i++){
        if(finder->adj[i].v->name == v2){
            cout << finder->adj[i].weight << " miles apart!" << endl;
        }
    }
};


vertex *Graph::findVertex(std::string name){
    for(int i=0; i<vertices.size(); i++){
        if(vertices[i].name == name){
            return &vertices[i];
        }
    }
    return NULL;
};


void Graph::dijkstra(std::string start){
    vertex* temp = findVertex(start);
    temp->distance = 0;
    while(!allVisitedCheck())
    {
    	vertex *minNode = getMinNode();
    	minNode->visited = true;

    	for(edge *e: minNode->links)
    	{
    		if(e->neighbor->distance >minNode->distance + e->weight)
    		{
    			e->neighbor->distance = minNode->distance + e->weight;
    		}
    	}
    }
    for(vertex *v : vertices1)
    {
    	cout << "enter loop" << endl;
        cout<<v->name<<" is "<<v->distance<<" away from the source "<<start<<endl;
    }
    for(vertex *v: vertices1)
    {
    	v->visited = false;
    	v->distance = INT_MAX;
    }
}


bool Graph::allVisitedCheck(){
    for(vertex *v: vertices1)
        {
            if(!v->visited)
            {
                return false;
            }
        }
        return true;
    
}


vertex* Graph::getMinNode(){
    int min = INT_MAX;
	vertex *result;

	for(vertex *v: vertices1)
	{
		if(!v->visited)
		{
			if(v->distance <min)
			{
				min = v->distance;
				result = v;
			}
		}
	}
	return result;

} 


bool Graph::enqueueIndividuals(vertex *vertToAdd, person individual){
    bool success = vertToAdd->graphQueue->enqueue(individual);
    return success;
};


void Graph::printQueueFromGraph(vertex *vert){
    vert->graphQueue->printQueue();
};

bool Graph::vertexExists(string address){
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



