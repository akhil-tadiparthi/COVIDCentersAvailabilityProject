#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include "Graph.h"
#include "Queue.h"

using namespace std;

void die(string message) {
    cout << message << endl;
    exit(0);
}

void generate_graph(Graph* g, std::string filename) {
    ifstream file(filename);

    if(file.fail()) {
        die("Check if file exists!");
    }
    
    int weight;
    string title, word, line, cur_person;

    vector<string> people;

    std::getline(file, line);
    stringstream lineStream(line);

    // read in vertices
    while(std::getline(lineStream, word, ',')) {
        if(word != "centers"){
            g->addVertex(word);
            people.push_back(word);
        }    
    }

    // read in edges
    while(std::getline(file, line)) {
        stringstream lineStream(line);
        // get the name of the person
        std::getline(lineStream, word, ',');
        cur_person = word;

        // cycle through potential edges
        for(int i=0; i<people.size();i++) {
            std::getline(lineStream, word, ',');
            weight = atoi(word.c_str());

            // add edge to graph if not -1
            if(weight != -1 && weight != 0)
                g->addEdge(cur_person, people[i], weight);
        }
    }
}

int main(int argc, const char * argv[]) {
    Graph g;
    string dmenu =  "\n======Main Menu======\n"
                    "1. Display Test Centers\n"
                    "2. Display Entire Map\n"
                    "3. Add a New Center\n"
                    "4. Register a Patient\n"
                    "5. List of registered patients at a center\n"
                    "6. Find the Testing Centers Near Me\n"
                    "7. Distance Between Any Two Centers\n"
                    "8. Quit\n";

    if (argc < 2) {
        die("Missing people file!");
    }
    
    int choice = 0;
    int choice2 = 0;
    bool done = false;
    
    std::string filename(argv[1]);
    generate_graph(&g, filename);

    
    do {
        cout << dmenu;
        cin >> choice;
        
        // flush the newlines and other characters
        cin.clear();
        cin.ignore();
        
        switch (choice) {
            case 1:
            {
                g.displayVertices();
                break;
            }
            case 2:
            {
                g.displayEdges();
                break;
            }
            case 3:
            {
                cout << "From which of the following centers should the connection start?" << endl;
                cout << "\nRockyMountainUrgentCare-Boulder\nNextCareUrgentCare-Longmont\nAdvancedUrgentCare-Lafayette\nAFCUrgentCare-Louisville\nAdvancedUrgentCare-Westminister\nZipClinicUrgentCare-Westminister\nClinica-Lafayette\nLittleClinic-Broomfield\nNextCareUrgentCare-Broomfield\nRockyMountainUrgentCare-Westminister\nLittleClinic-Erie\nAdvancedUrgentCare-Broomfield\nLittleClinic2-Broomfield\nNextCareUrgentCare-Thornton\nCommunityTest-Thornton\nLittleClinic-Thornton\nAFCUrgentCare-Thornton\nCommunityTest2-Thornton\nThorntonFire-Thornton\nAdvancedUrgentCare-Brighton" << endl << endl;
                cout << "Type here: " << endl;
                string name1;
                getline(cin,name1);

                cout << "\nWhat is the name of your center?" << endl;
                string name2;
                getline(cin,name2);

                g.addVertex(name2);

                cout << "\nWhat is the distance between the two centers?" << endl;
                int distance;
                cin >> distance;

                g.addEdge(name1,name2,distance);

                break;
            } 
            case 4:
            {
                cout << "\nWhat is your name?" << endl;
                string name;
                getline(cin,name);

                cout << "\nWhat is your age?" << endl;
                string age;
                getline(cin,age);
                int age2 = stoi(age);

                cout << "\nWhat is your address?" << endl;
                string address;
                getline(cin,address);

                cout << "\nWhich center of the following do you want to register at?" << endl;
                cout << "\nRockyMountainUrgentCare-Boulder\nNextCareUrgentCare-Longmont\nAdvancedUrgentCare-Lafayette\nAFCUrgentCare-Louisville\nAdvancedUrgentCare-Westminister\nZipClinicUrgentCare-Westminister\nClinica-Lafayette\nLittleClinic-Broomfield\nNextCareUrgentCare-Broomfield\nRockyMountainUrgentCare-Westminister\nLittleClinic-Erie\nAdvancedUrgentCare-Broomfield\nLittleClinic2-Broomfield\nNextCareUrgentCare-Thornton\nCommunityTest-Thornton\nLittleClinic-Thornton\nAFCUrgentCare-Thornton\nCommunityTest2-Thornton\nThorntonFire-Thornton\nAdvancedUrgentCare-Brighton" << endl << endl;
                cout << "Type here: " << endl;
                string center; 
                getline(cin,center);
                
                vertex *vert = g.findVertex(center);
                person individual = {name, age2, address};
                bool success = g.enqueueIndividuals(vert,individual);

                cout << "\nYou are successfully registered!" <<endl;

                break;
            }
            case 5:
            {
                cout << "\nWhich center's Queue would you like to look at?" << endl;
                cout << "\nRockyMountainUrgentCare-Boulder\nNextCareUrgentCare-Longmont\nAdvancedUrgentCare-Lafayette\nAFCUrgentCare-Louisville\nAdvancedUrgentCare-Westminister\nZipClinicUrgentCare-Westminister\nClinica-Lafayette\nLittleClinic-Broomfield\nNextCareUrgentCare-Broomfield\nRockyMountainUrgentCare-Westminister\nLittleClinic-Erie\nAdvancedUrgentCare-Broomfield\nLittleClinic2-Broomfield\nNextCareUrgentCare-Thornton\nCommunityTest-Thornton\nLittleClinic-Thornton\nAFCUrgentCare-Thornton\nCommunityTest2-Thornton\nThorntonFire-Thornton\nAdvancedUrgentCare-Brighton" << endl << endl;
                cout << "Type here: " << endl;
                string center;
                cin >> center;
                
                vertex *vert = g.findVertex(center);
                g.printQueueFromGraph(vert);

                break;
            }
            case 6:
            {
                cout << "\nWhich center are you at right now?" << endl;
                cout << "\nRockyMountainUrgentCare-Boulder\nNextCareUrgentCare-Longmont\nAdvancedUrgentCare-Lafayette\nAFCUrgentCare-Louisville\nAdvancedUrgentCare-Westminister\nZipClinicUrgentCare-Westminister\nClinica-Lafayette\nLittleClinic-Broomfield\nNextCareUrgentCare-Broomfield\nRockyMountainUrgentCare-Westminister\nLittleClinic-Erie\nAdvancedUrgentCare-Broomfield\nLittleClinic2-Broomfield\nNextCareUrgentCare-Thornton\nCommunityTest-Thornton\nLittleClinic-Thornton\nAFCUrgentCare-Thornton\nCommunityTest2-Thornton\nThorntonFire-Thornton\nAdvancedUrgentCare-Brighton" << endl << endl;
                cout << "Type here: " << endl;
                string name;
                getline(cin,name);

                cout << "\nWhat mile radius would you like to search under?" << endl;
                int miles;
                cin >> miles;
                cout << "\n";

                g.displayVerticesNearMe(name,miles);
                break;
            }
            case 7:
            {
                cout << "\nWhat is the name of the first center of the following?" << endl;
                cout << "\nRockyMountainUrgentCare-Boulder\nNextCareUrgentCare-Longmont\nAdvancedUrgentCare-Lafayette\nAFCUrgentCare-Louisville\nAdvancedUrgentCare-Westminister\nZipClinicUrgentCare-Westminister\nClinica-Lafayette\nLittleClinic-Broomfield\nNextCareUrgentCare-Broomfield\nRockyMountainUrgentCare-Westminister\nLittleClinic-Erie\nAdvancedUrgentCare-Broomfield\nLittleClinic2-Broomfield\nNextCareUrgentCare-Thornton\nCommunityTest-Thornton\nLittleClinic-Thornton\nAFCUrgentCare-Thornton\nCommunityTest2-Thornton\nThorntonFire-Thornton\nAdvancedUrgentCare-Brighton" << endl << endl;
                cout << "Type here: " << endl;
                string name1;
                getline(cin,name1);
                cout << "\nWhat is the name of the second center of the following?" << endl;
                cout << "\nRockyMountainUrgentCare-Boulder\nNextCareUrgentCare-Longmont\nAdvancedUrgentCare-Lafayette\nAFCUrgentCare-Louisville\nAdvancedUrgentCare-Westminister\nZipClinicUrgentCare-Westminister\nClinica-Lafayette\nLittleClinic-Broomfield\nNextCareUrgentCare-Broomfield\nRockyMountainUrgentCare-Westminister\nLittleClinic-Erie\nAdvancedUrgentCare-Broomfield\nLittleClinic2-Broomfield\nNextCareUrgentCare-Thornton\nCommunityTest-Thornton\nLittleClinic-Thornton\nAFCUrgentCare-Thornton\nCommunityTest2-Thornton\nThorntonFire-Thornton\nAdvancedUrgentCare-Brighton" << endl << endl;
                cout << "Type here: " << endl;
                string name2;
                getline(cin,name2);

                g.isAdjacent(name1,name2);

                break;
            }
            case 8:
            default:
            {
                done = true;
                break;
            }
        }
        
    } while(!done);
    
    cout << "Goodbye!" << endl;
    return 0;
}
