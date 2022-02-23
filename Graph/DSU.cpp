#include <bits/stdc++.h>
#include <iostream>
using namespace std;


struct Node {

int id=-1;
int component_size=1;

Node * parent=this;

Node (){}
vector<Node*> children={};
void add(Node * node){
this->component_size+=node->component_size;
node->parent=this;


}
Node (int i){
id=i;



}



};


///////////   DSU Disjoint


Node * findParent(Node * node){
if (node -> parent==node) return node;
return node->parent=findParent(node->parent);



};

void   joinNodes(Node * firstNode,Node * secondNode ){   // join two nodes to same component by connect parent of each node
firstNode=findParent(firstNode);
secondNode=findParent(secondNode);
if (firstNode!= secondNode) {  // if two nodes has same parent (same component) so no need to do anything.
if (firstNode->component_size < secondNode->component_size) swap(firstNode,secondNode); // swap for just save memory and optimizing the code

firstNode->add(secondNode);
}
}

int main(){
int  n,m,a,b;
bool type=0;

cout<<"\n\t\t******\tNOTE : This is just an algorithm implementation and there's no error handling :)\t******\t\n\n"<<endl;
cout<<"Enter number of nodes and number of operations you want: ";

cin>>n>>m;

vector<Node *> graph(n);

for (int i=0;i<n;i++){
    graph[i]=new Node(i+1);
}


Node * x;
Node* y;
for(int _=0;_<m;_++){
    if (_==0)cout<<"Enter the two nodes id and 0 for connect them or 1 for check input sample( 1 3 0): ";
    else cout<<"Enter first & second numbers and action: ";
    cin>>a>>b>>type;
    a--,b--;
    x=findParent(graph[a]);
    y=findParent(graph[b]);
    if (type){


        cout<<(x==y ? "Same Parent (same Component) \n":"Different Parents (different Components)\n");


    }
    else{
        joinNodes(x,y);
        cout<<"Joining done :)"<<endl;

    }

if (_==m-1) cout<<"\n\nIt was Honor serving you sur :) BYE \n\n";

}



return 0;
}
