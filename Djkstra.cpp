// Yatish Kelkar
// SE IT 8001

#include<iostream>
#define SIZE 30
#define infinite 9999
using namespace std;


class graph{
	int G[SIZE][SIZE];
	int n;
	
	
	public :
		graph(){
			n = 0;
		}
		
	void readGraph();
	void printGraph();
	void djkstra();
		
};

void graph::readGraph(){
	
	cout << "\nHow many vertices does the graph have ? ";
	cin >> n;
	cout << "\nPlease input the adjacency matrix : \n";
	
	for(int i =0; i<n; i++ ){
		for(int j = 0; j < n; j++){
			cin >> G[i][j];
		}
	}
	
	cout << "\nGraph has been successfully stored in the form of adjacency matrix.";
}

void graph::printGraph(){
	cout << "\nThe adjacency matrix input by user is : \n";
	
	for(int i =0; i<n; i++ ){
		for(int j = 0; j < n; j++){
			cout << "\t" << G[i][j];
		}
		cout << "\n";
	}
}

void graph::djkstra(){
	
	// cost matrix will find cost form each vertex
	// pred[] stores the predecesor of each node
	// distance[] will contain distance of each vertex from latest vertex
	int cost[SIZE][SIZE];
	int pred[SIZE], distance[SIZE];
	bool visited[SIZE];
	int c=1;
	int next;
	int mindistance = infinite;
	int j;
	
	
	
	// find out cost matrix
	
	for(int i =0; i<n; i++ ){
		for(int j = 0; j < n; j++){
			if(G[i][j] != 0) {
				cost[i][j] = G[i][j];
			}
			else cost[i][j] = infinite;
		}
		
	}
	cout << "\nCost matrix created successfully.";
	
	// init distance, pred and visited wrt to 0th vertex
	
	for(int i=0; i<n; i++) {
		distance[i] = cost[0][i];
		pred[i] = 0;
		visited[i] = false;
	}
	
	// now 0th node is visited
	visited[0] = true;
	distance[0] = 0;
	
	
	while(c < n-1){
		
		// find neighbour with smallest distance 
		mindistance = infinite;
	
		
		for(int i=0; i <n; i++){
			if((mindistance > distance[i]) && !visited[i]){
				mindistance = distance[i];
				next = i;
			}
		}
		
		
		// path is through next 
		
		visited[next] = true;
		
		for(int i =0; i <n; i++){
			if(!visited[i]) {
				
				// this is same as comparing sum of mindistance and of current vertex wrt next and distance of current vertex from previous vertex
				if((mindistance + cost[next][i]) < distance[i]){
					distance[i] = mindistance + cost[next][i];
					pred[i] = next;
				}
			}
		}
		
		c++;
	}
	
	// print the path
	
	for(int i=0; i<n; i++){
		if(i != 0) {
			cout << "\nDistance of node " << i << " is " << distance[i];
			cout << "\nPath = " << i;
			j = i;
			
			do {
				
				// traverse through j using pred[]
				j = pred[j];
				cout << "\t" <<j;
			} while(j != 0); 
		}
	}
	
}



int main(){
	graph OBJ;
	
	OBJ.readGraph();
	
	int choice;
	
	do  {
		cout << "\n ========== MENU ==========\n\n";
		cout << "\n1. Read new graph\n2. Print Graph\n3. Djkstra Algorithm\n4. Exit\n";
		cin >> choice;
		
		switch(choice){
			case 1 : OBJ.readGraph(); break;
			case 2 : OBJ.printGraph(); break;
			case 3 : OBJ.djkstra(); break;
			case 4 : exit(0);
			default : cout << "\nInvalid choice!";
		}
	} while(true);
	
	return 0;
}

/*
How many vertices does the graph have ? 5

Please input the adjacency matrix :
0
10
0
30
100
10
0
50
0
0
0
50
0
20
10
30
0
20
0
60
100
0
10
60
0

Graph has been successfully stored in the form of adjacency matrix.
 ========== MENU ==========


1. Read new graph
2. Print Graph
3. Djkstra Algorithm
4. Exit
2

The adjacency matrix input by user is :
        0       10      0       30      100
        10      0       50      0       0
        0       50      0       20      10
        30      0       20      0       60
        100     0       10      60      0

 ========== MENU ==========


1. Read new graph
2. Print Graph
3. Djkstra Algorithm
4. Exit
3

Cost matrix created successfully.
Distance of node 1 is 10
Path = 1        0
Distance of node 2 is 50
Path = 2        3       0
Distance of node 3 is 30
Path = 3        0
Distance of node 4 is 60
Path = 4        2       3       0
 ========== MENU ==========


1. Read new graph
2. Print Graph
3. Djkstra Algorithm
4. Exit
5

Invalid choice!
 ========== MENU ==========


1. Read new graph
2. Print Graph
3. Djkstra Algorithm
4. Exit
4

--------------------------------
Process exited after 56.49 seconds with return value 0

*/
