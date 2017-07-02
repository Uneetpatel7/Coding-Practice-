#include <bits/stdc++.h>
using namespace std;
class Graph{
private:
	int no_of_vertices;
	list<int> *adj_list;

public:
	Graph(int no_of_vertices);
	void Add_Edge(int a, int b);
	void BFS(int vertex);
};

Graph::Graph(int no_of_vertices){

	this->no_of_vertices = no_of_vertices;
	adj_list = new list<int> [no_of_vertices];

}

void Graph::Add_Edge(int v, int w){
	adj_list[v].push_back(w);
}

void Graph::BFS(int vertex){

	bool *visited = new bool[no_of_vertices];
	memset(visited, 0, sizeof(visited));

	queue<int> q;

	q.push(vertex);
	visited[vertex]=true;

	list<int>::iterator itr;

	while(!q.empty()){
	vertex = q.front();
	cout<< vertex << " ";
	q.pop();	
		for (itr = adj_list[vertex].begin(); itr != adj_list[vertex].end(); itr++){
			if(!visited[*itr]){
				q.push(*itr);
				visited[*itr] = true;
			}
		}	

	} 

}

int main(){

	Graph g(4);
    g.Add_Edge(0, 1);
    g.Add_Edge(0, 2);
    g.Add_Edge(1, 2);
    g.Add_Edge(2, 0);
    g.Add_Edge(2, 3);
    g.Add_Edge(3, 3);
 
    cout << "Following is Breadth First Traversal "
         << "(starting from vertex 2) n";
    g.BFS(2);



	return 0;
}





