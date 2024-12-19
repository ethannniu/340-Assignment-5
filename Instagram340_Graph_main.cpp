#include <iostream>
#include <string>
#include <vector>

#include "Graph.h"
#include "LinkedBagDS/LinkedBag.h"
#include "User.cpp"

int main() {
	// Create a list of Users
	vector<User> users; 
	users.push_back(User("Ethan", "E@123", "word", "bio", "url") );
	users.push_back(User("Fred", "F@123", "word", "bio", "url") );
	users.push_back(User("Smith", "S@123", "word", "bio", "url") );
	users.push_back(User("Curt", "C@123", "word", "bio", "url") );
	users.push_back(User("Joe", "J@123", "word", "bio", "url") );
	users.push_back(User("Rob", "R@123", "word", "bio", "url") );
	users.push_back(User("Bob", "B@123", "word", "bio", "url") );
	users.push_back(User("Peter", "eP@123", "word", "bio", "url") );
	users.push_back(User("Salem", "S@123", "word", "bio", "url") );
	users.push_back(User("Alex", "A@123", "word", "bio", "url") );

	// Add 10 distinct users to the vector
	// TO DO 
	
	// Initialize a graph with n vertices (where n is the number of Users) 
	//	 Indicate whether it is directed or undirected 
	// TO DO 


	//It is directed because you can follow someone without them following you back so it only goes one way. 
	Graph<int> g(10, true);



	// Add edges (userA, userB, weight)
	// TO DO 
	g.addEdge(1, 2, 9);
	g.addEdge(3, 2, 5);
	g.addEdge(7, 2, 3);
	g.addEdge(7, 3, 5);
	g.addEdge(3, 6, 6);
	g.addEdge(9, 1, 1);
	g.addEdge(4, 2, 7);
	g.addEdge(6, 2, 9);
	g.addEdge(8, 9, 4);
	g.addEdge(7, 8, 1);
	g.addEdge(2, 5, 3);
	g.addEdge(5, 1, 7);
	g.addEdge(5, 7, 5);
	g.addEdge(6, 3, 6);
	g.addEdge(9, 6, 2);
	g.addEdge(0, 2, 4);
	g.addEdge(1, 0, 7);


		


	// Print the adjacency list
	g.printGraph();

	// Depth First traversal should print User information not just indices
	int start = 0;
	// Call DFT 
	g.DFT(0, users);
	// g.DFT(0, ...);
	cout << boolalpha;
	cout<< g.DFS(0, users, "Ethan")<< endl;


	bool found = false;
	// Depth First search
	string username1 = ""; //replace with a username that exists 
	// Call DFS 
	// TO DO:  
	// found = g.DFS(username1, ...);
	if(found){
		cout << username1 << " has been found in the graph!" << endl;
	}else{
		cout << username1 << " has not been found in the graph!" << endl;
	}

	string username2 = ""; //replace with a username that DOES NOT exist 
	// Call DFS 
	// TO DO:
	// found = g.DFS(username2, ...);
	if(found){
		cout << username1 << " has been found in the graph!" << endl;
	}else{
		cout << username1 << " has not been found in the graph!" << endl;
	}

	return 0;
}
