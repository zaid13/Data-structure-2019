#ifndef UNTITLED1_GRAPH_H
#define UNTITLED1_GRAPH_H
#include "Graph_node.h"
#include "Graph_list.h"
using namespace std;
template<class T>
class Graph {
public:
    int NoOfVertex;
    graph_List<T> *arr;


    Graph(int size){
        NoOfVertex = size;
        arr=new  graph_List<T>[size] ;

        for(int i=0;i<size;i++){
            arr[i].head=NULL;
            arr[i].data = "PPPP";
        }

    }
    void addEdge(int src,int dest,T data){
        Node_Graph<T>  *nptr =new Node_Graph<T>;
        nptr->data=data;
        nptr->next=NULL;
        nptr->next=arr[src].head;
        arr[src].head=nptr;



        //    nptr=newAdjListNode(src); commented for not makin git two way
        //     nptr->next=arr[dest].head;
        //    arr[dest].head=nptr;

    }

    void printer(){
        for(int i=0;i<NoOfVertex;i++){
            Node_Graph<T> *root=arr[i].head;
            std::cout<<"Adjacency list of vertex "<<i<<arr[i].data;
            while(root!=NULL){
                cout<<root->data<<" -> ";
                root=root->next;
            }
            cout<<endl;
        }

    }
};
#endif //UNTITLED1_GRAPH_H
