# Tadiparthi_CSCI2275_FinalProject

Introduction:
This project mimics a graph of all the covid recovery centers in Boulder County. The interface mostly provides ways of interacting with each of the centers. For example, some functions let the user add new covid testing centers in different locations, by inputting the distance in miles between each. There is also the functionality of a built-in queue for each of the testing center where the user can "admit" patients into the center. This feature takes in data of the patient and stores it at their respective center only. In addition to this framework, the user can interact between test centers with maps being created, finding certain test centers in a specific radius of the starting location, finding the distance between any two test centers, and finding the shortest path to get from one test center to another.

How To Run:
It is very simple. Once you run the program on command line using "g++ -std=c++11 Graph-1.cpp Final.cpp Queue.cpp -o Final" and "./Final Centers.txt" a menu pops up giving you 9 options. The first option "Display Test Centers" displays all the test centers that are currently in the graph. The second option "Display Entire Map" displays the entire map showing how each test center is connected. The Third option "Add New Test Center" lets the user add a new test by taking in a name of an existing test center and connecting to it with an edge weight that represents the distance between the two. The fourth option "Register a patient" allows the user to select a specific testing center, where a patient can be registered(takes in their name and age). The fifth option "List of registered patients at a center" displays the list of patients that are already registered at a specific center. The user inputs a testing center location and the program displays all the patients at that testing center. The sixth option "Find the Testing Centers Near Me" allows the user to start at a testing center and find nearby testing centers in a specific radius that the user inputs. The seventh option "Find the Shortest Path Between Two Centers" allows the user to find the shortest path from one test center to another. The eighth option "Distance Between Any Two Centers" allows the user to view the distance between any two testing centers. The user inputs the locations of both the testing centers. The last option exits the program.

Dependencies:
No third party libraries are needed

System Requirements:
Both Mac and PC shoudl be able to run the program as long as they have the mingw or GCC compiler.

Team members:
Akhil Tadiparthi

Contributors:
BJ Kim - helped fix some bugs

Open Issues/bugs:
The program won't throw an error when an invalid location is entered: will soon be fixed!
