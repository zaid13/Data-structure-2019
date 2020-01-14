#pragma once

#include "Graph_node.h"

template<class T>

class graph_List{
public:
    Node_Graph<T> *head;  //pointer to head node of list
    int numberOFNodes;
    T data;
    graph_List (){


    }
};