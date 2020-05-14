// Kruskal Algorithm
// Yatish Kelkar SE IT S1 8001 
// Assignemnt 7


#include<iostream>
#define SIZE 20
using namespace std;

// KRUSKAL ALGORITHM IS FOR UNDIRECTED GRAPH ONLY


/*

Graph taken for test case : 

			0 
      wt=1 /|\ wt=1
		  / | \
		 3  |  1 
	wt=2  \ | / wt=2
		   \|/ 
		    2 
			
			wt(0,2) = 3   

Expected MST : 

			0 
    wt=1   / \  wt=1
		  /   \
		 3     1 
	          / wt=2
		     / 
		    2 
			
Expected cost of MST : 4


*/


class edge {
	int u,v;
	// u & v are end vertices of every edge 
	int w;
	// w is the weight of every edge 
	
	public : 
	edge(){
		w = 0;
	}
	
	friend class graph;
};

class graph {
	
	edge list[SIZE];
	// n is number of vertices 
	int n;
	int G[SIZE][SIZE];
	edge spanlist[SIZE];
	int k=0;
	// k will be number of edges in original graph
	int kmst = 0;
	// kmst is number of edges in MST
	int cost=0;
	
	public : 
	
	void readGraph();
	void printGraph();
	void kruskal();
	void sort();
	//int findGraph(int[],int);
	void unionGraph(int[],int,int);
	
	~graph(){
		cout << "\nDestructor called. Memory freed!";
	}
};



void graph::readGraph(){
	cout << "\nHow many vertices in graph? ";
	cin >> n;
	
	cout << "\nEnter the adjacency matrix for graph : \n";
	
	for(int i=0; i<n; i++) {
		for(int j=0; j<n; j++){
			cin >> G[i][j];
		}
	}
	
	cout << "\nGraph has been read and stored successfully!";
}

void graph::printGraph(){
	
	cout << "\n\nThe matrix input by user is : \n";
	
	for(int i=0; i<n; i++) {
		for(int j=0; j<n; j++){
			cout << "\t" << G[i][j];
		}
		cout << "\n";
	}
	
}

void graph::sort(){
	edge temp;
	

// bubble sort 
	for(int j=0; j <k-1; j++){ 
	
		for(int i=0; i < k-j-1; i++){
			
			if(list[i].w > list[i+1].w) {
				temp = list[i];
				list[i] = list[i+1];
				list[i+1] = temp;
		}
		
		}
	
	}
	
	cout << "\nList of edges has been sorted successfully!";
	
}

//int graph::findGraph(int belongs[], int vertexno){
//	return belongs[vertexno];
//}

void graph::unionGraph(int belongs[], int c1, int c2){
	for(int i=0; i<k; i++){
		if(belongs[i] == c2)  
			belongs[i] = c1;
	}
}

void graph::kruskal(){
	int belongs[SIZE];
	int c1, c2;
	
	
	// read adj matrix G and convert to edgelist 
	for(int i=1; i<n; i++){
		for(int j=0; j<i; j++) {
			if(G[i][j] != 0){
				list[k].u = i;
				list[k].v = j;
				list[k].w = G[i][j];
				k++;
			}
		}
	}  
	
	// sort list
	sort(); 
	
	// intialise belongs
	// initially each vertex will have its own component number
	for(int i=0; i<k; i++){
		belongs[i] = i;
	}
	
	kmst = 0;
	
	for(int i =0; i<k; i++){
		
		// find the component number of vertices of each edge
		c1 = belongs[list[i].u];
		c2 = belongs[list[i].v];
		
		
		// if not of same compoent number, add to spanning tree and combine compnonet number 
		if(c1 != c2){
			
			spanlist[kmst] = list[i];
			kmst++;
			unionGraph(belongs,c1,c2);
		}
	}
	
	cout << "\nNumber of edges in MST is " << kmst;
	
	cout << "\nMST is : \n\n";
	
	cout << "\tU\tV\tWeight\n\n";
	
	for(int i=0; i< kmst; i++) {
		cout << "\t" << spanlist[i].u;
		cout << "\t" << spanlist[i].v;
		cout << "\t" << spanlist[i].w;
		cout << "\n";
		
		cost += spanlist[i].w;
		
	}
	
	cout << "\nCost of MST is : " << cost;
	
	
}


int main(){
	
	graph OBJ;
	
	OBJ.readGraph();
	
	int choice;
	
	do {
	
	
	cout << "\n========== MENU ==========\n";
	cout << "\n1. Read new graph\n2. Print Matrix\n3. Kruskal's Algorithm\n4. Exit\n";
	cout << "\nEnter your choice : ";
	cin >> choice;
	
	
	switch(choice){
		case 1 : OBJ.readGraph(); break;
		case 2 : OBJ.printGraph(); break;
		case 3 : OBJ.kruskal(); break;
		case 4 : exit(0);
		default : cout << "\nInvalid choice!";
	}
	
	
	} while(true);
	
	
	return 0;
}


/*

How many vertices in graph? 4

Enter the adjacency matrix for graph :
0
1
3
1
1
0
2
0
3
2
0
2
1
0
2
0

Graph has been read and stored successfully!
========== MENU ==========

1. Read new graph
2. Print Matrix
3. Kruskal's Algorithm
4. Exit

Enter your choice : 2


The matrix input by user is :
        0       1       3       1
        1       0       2       0
        3       2       0       2
        1       0       2       0

========== MENU ==========

1. Read new graph
2. Print Matrix
3. Kruskal's Algorithm
4. Exit

Enter your choice : 3

List of edges has been sorted successfully!
Number of edges in MST is 3
MST is :

        U       V       Weight

        1       0       1
        3       0       1
        2       1       2

Cost of MST is : 4
========== MENU ==========

1. Read new graph
2. Print Matrix
3. Kruskal's Algorithm
4. Exit

Enter your choice : 5

Invalid choice!
========== MENU ==========

1. Read new graph
2. Print Matrix
3. Kruskal's Algorithm
4. Exit

Enter your choice : 4

--------------------------------
Process exited after 35.59 seconds with return value 0


*/
