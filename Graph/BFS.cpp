#include <bits/stdc++.h>



using namespace std;

struct Node {


int id=-1;
bool visited=0;



vector<Node *> neighbours={};
Node(){};
Node (int id ):id(id) {}








};

void BFS(Node * root ){


    queue<pair<Node *,int>> levels;
    levels.push({root,1});
    int current_level=1;

root->visited=1;
pair<Node*,int> current;

while(!levels.empty()){
    current=levels.front();
    levels.pop();
    if(current.second!=current_level) {
            current_level++;
            cout<<endl;
    }
        cout<<current.first->id<<' ';

    for(auto & node : current.first->neighbours){

    if (node->visited) continue;
    node->visited=true;
    levels.push({node,current.second+1});



}


}





}

void initial(vector<Node *> graph){

for(auto & node:graph)node->visited=0;
}

int main(){


int numberofNodes=10,numberofEdges=9; // just to have tree in tree nodes number = number of edges+1
vector<pair<int,int>> edges={{1,4},{1,3},{1,7},{4,6},{4,10},{6,9},{6,8},{7,2},{7,5}};

string treeShape="\t\t\t\t\t\t   1\n\t\t\t\t\t\t / | \\\n\t\t\t\t\t\t/  |  \\\n\t\t\t\t\t       /   |   \\\n\t\t\t\t\t      /    |    \\\n\t\t\t\t\t     4     3     7\n\t\t\t\t\t    / \\         / \\\n\t\t\t\t\t   /   \\       /   \\\n\t\t\t\t\t  6     10    2     5\n\t\t\t\t\t / \\\n\t\t\t\t\t/   \\\n\t\t\t\t       9     8\n";
cout<<treeShape<<"\n\n";

vector<Node *> graph(numberofNodes) ; // the tree itself

for(int i=0;i<numberofNodes;i++) {

    Node * temp= new Node(i+1);   // two have different node for each index with id equals its role
    graph[i]=temp;


}

for (int i=0;i<numberofEdges;i++){
    graph[edges[i].first-1]->neighbours.push_back(graph[edges[i].second-1]);
        graph[edges[i].second-1]->neighbours.push_back(graph[edges[i].first-1]);    // for undirected edges



}

cout<< "level by level (BFS) traverse "<<endl;
BFS(graph[0]);
initial(graph);




return 0;
}
