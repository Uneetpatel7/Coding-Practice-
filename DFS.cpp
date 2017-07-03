#include <bits/stdc++.h>
using namespace std;
class Graph{
private:
	int no_of_vertices;
	list<int> *adj_list;

public:
	Graph(int no_of_vertices);
	void Add_Edge(int a, int b);
	void DFS(int vertex);
	//bool is_all_adjV_visited(int vertex);
};

Graph::Graph(int no_of_vertices){

	this->no_of_vertices = no_of_vertices;
	adj_list = new list<int> [no_of_vertices];

}

void Graph::Add_Edge(int v, int w){
	adj_list[v].push_back(w);
}

// bool Graph::is_all_adjV_visited(int vertex){
// 	bool flag = true;
// 	list<int>::iterator itr;
// 	for (itr = adj_list[vertex].begin(); itr != adj_list[vertex].end(); itr++){
// 		if(!visited[*i]){
// 			flag = false;
// 		}
// 	} 
// 	return flag;
// }


void Graph::DFS(int vertex){

	bool *visited = new bool[no_of_vertices];
	memset(visited, 0, sizeof(visited));

	stack<int> q;

	q.push(vertex);
	visited[vertex]=true;

	list<int>::iterator itr;
	cout<< vertex << " ";
	while(!q.empty()){
	vertex = q.top();
		for (itr = adj_list[vertex].begin(); itr != adj_list[vertex].end(); ){
			if(!visited[*itr]){
				q.push(*itr);
				visited[*itr] = true;
				cout<<" "<< *itr;
				vertex = *itr;
				itr = adj_list[vertex].begin();
			}
			else
				itr++;
		}
		q.pop();
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
    g.DFS(2);



	return 0;
}

