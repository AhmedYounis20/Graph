#include <bits/stdc++.h>



using namespace std;

struct Node {


int id=-1;
bool visited=0;



vector<Node *> neighbours={};
Node(){};
Node (int id ):id(id) {}








};
void DFS(Node * root , bool traverse){
root->visited=1;
if(!traverse) cout<<root->id<<' ';
for(auto & node : root->neighbours){

    if (node->visited) continue;
    node->visited=true;
    DFS(node,traverse);



}

if(traverse) cout<<root->id<<' ';



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

cout<< "preorder traversing:  ";
DFS(graph[0],0);
initial(graph);
cout<<"\n\npostorder traversing:  ";
DFS(graph[0],1);



return 0;
}
