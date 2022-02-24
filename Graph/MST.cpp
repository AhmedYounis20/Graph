#include <bits/stdc++.h>
using namespace std;


struct Node
{

    int id=-1;
    int component_size=1;

    Node * parent=this;

    Node () {}
    vector<Node*> children= {};
    void add(Node * node)
    {
        this->component_size+=node->component_size;
        node->parent=this;


    }
    Node (int i)
    {
        id=i;

    }
};

struct Edge
{

    Node * fromNode=NULL;
    Node * toNode=NULL ;
    int weight =0;
    Edge() {} // empty constructor
    Edge(Node * _from,Node* _to,int _weight):weight(_weight),fromNode(_from),toNode(_to) {} // constructor with parameters
    bool operator < (const Edge & edge2)const
    {

        return weight<edge2.weight;
    }
};
///////////   DSU Disjoint

Node * findParent(Node * node)
{
    if (node -> parent==node) return node;
    return node->parent=findParent(node->parent);

};

void   joinNodes(Node * firstNode,Node * secondNode )    // join two nodes to same component by connect parent of each node
{
    firstNode=findParent(firstNode);
    secondNode=findParent(secondNode);
    if (firstNode!= secondNode)    // if two nodes has same parent (same component) so no need to do anything.
    {
        if (firstNode->component_size < secondNode->component_size) swap(firstNode,secondNode); // swap for just save memory and optimizing the code

        firstNode->add(secondNode);
    }
}


// Minimum spanning Tree
int MST (vector<Edge > & edges )
{
    sort(edges.begin(),edges.end());
    int cost=0;
    for(auto & edge : edges)
    {

        if(findParent(edge.fromNode)!=findParent(edge.toNode))
        {

            joinNodes(edge.fromNode,edge.toNode);
            cost+=edge.weight;
        }
    }
    return cost;
}


int main()
{
    int  n,m,a,b;
    int weight=0;

    cout<<"\n\t\t******\tNOTE : this is just algorithm implementation and there's no error handling :)\t******\t\n\n"<<endl;
    cout<<"Enter number of nodes and number of edges you want: ";

    cin>>n>>m;

    vector<Node *> graph(n);
    vector<Edge> edges(m);
    for (int i=0; i<n; i++)
    {
        graph[i]=new Node(i+1);
    }


    Node * x;
    Node* y;
    for(int _=0; _<m; _++)
    {
        cout<<"Enter first & second numbers and weight of edge:";
        cin>>a>>b>>weight;
        a--,b--;
        edges[_]=Edge(graph[a],graph[b],weight);

    }



    cout<<"\n\nMinimum Cost is: "<<MST(edges)<<endl<<endl;



    return 0;
}
