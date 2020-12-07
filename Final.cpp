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
    string dmenu =  "======Main Menu======\n"
                    "1. Display Test Centers\n"
                    "2. Display Entire Map\n"
                    "3. Add a New Center\n"
                    "4. Register a Patient\n"
                    "5. Find the Closest Testing Center\n"
                    "6. Find the Shortest Path Between Two Centers\n"
                    "7. Quit\n";

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
                cout << "RockyMountainUrgentCare-Boulder\nNextCareUrgentCare-Longmont\nAdvancedUrgentCare-Lafayette\nAFCUrgentCare-Louisville\nAdvancedUrgentCare-Westminister\nZipClinicUrgentCare-Westminister\nClinica-Lafayette\nLittleClinic-Broomfield\nNextCareUrgentCare-Broomfield\nRockyMountainUrgentCare-Westminister\nLittleClinic-Erie\nAdvancedUrgentCare-Broomfield\nLittleClinic2-Broomfield\nNextCareUrgentCare-Thornton\nCommunityTest-Thornton\nLittleClinic-Thornton\nAFCUrgentCare-Thornton\nCommunityTest2-Thornton\nThorntonFire-Thornton\nAdvancedUrgentCare-Brighton" << endl << endl;
                string name1;
                getline(cin,name1);

                cout << "What is the name of your center?" << endl;
                string name2;
                getline(cin,name2);

                g.addVertex(name2);

                cout << "What is the distance between the two centers?" << endl;
                int distance;
                cin >> distance;

                g.addEdge(name1,name2,distance);

                break;
            } 
            case 4:
            {
                cout << "What is your name?" << endl;
                string name;
                getline(cin,name);

                cout << "What is your age?" << endl;
                int age;
                cin >> age;

                cout << "What is your address?" << endl;
                string address;
                getline(cin,address);

                person individual = {name, age, address};
                //serach for my vertex
                bool success = g.enqueueIndividuals(individual);

                cout << "You are successfully registered!" <<endl;

                break;
            }
            case 5:
            {
                cout << "Where do you currently live? Choose from below:" << endl;
                    cout << "1. Boulder" << endl; 
                    cout << "2. Broomfield" << endl;
                    cout << "3. Erie" << endl;
                    cout << "4. Lafayette" << endl;
                    cout << "5. Louisville" << endl;
                    cout << "6. Thornton" << endl;
                    cout << "7. Quit" << endl;

                int choice2;
                cin >> choice2;
                switch(choice2){
                    case 1:
                    {
                        
                        break;
                    }
                    case 2:
                    {
                        
                        break;
                    }
                    case 3:
                    {
                        
                        break;
                    }
                    case 4:
                    {
                        
                        break;
                    }
                    case 5: 
                    {
                        
                        break;
                    }
                    case 6:
                    {
                        
                        break;
                    }
                    case 7:
                    default:
                        {
                            done = true;
                            break;
                        }
                }

                break;
            }
            case 6:
            {
                cout << "\nWhat is the name of the first center?" << endl;
                string name1;
                getline(cin,name1);
                cout << "\nWhat is the name of the second center?" << endl;
                string name2;
                getline(cin,name2);
                
                g.dijkstra(name1,name2);

                break;
            }
            case 7:
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
