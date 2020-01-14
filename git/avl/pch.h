//
// pch.h
// Header for standard system include files.
//

#pragma once

#include "gtest/gtest.h"
//
// pch.cpp
// Include the standard header and generate the precompiled header.
//


#ifndef AVL_h
#define AVL_h
#define COUNT 10
using namespace std;
struct Avl_node {
	int Element;
	Avl_node* Left;
	Avl_node* Right;
	int Height;
	Avl_node(int y) {
		Element = y;

	}
	Avl_node() {	}

};
typedef struct Avl_node* Position;
typedef struct Avl_node* AVLTree;
Avl_node* makeEmpty(Avl_node* T);
Avl_node* Find(int X, Avl_node* T);
Avl_node* FindMin(Avl_node* T);
Avl_node* FindMax(Avl_node* T);
Avl_node* Delete(int X, Avl_node* T);
int Retrieve(Avl_node P);
int Height(Avl_node* P) {
	if (P == NULL)
		return -1;
	else
		return P->Height;
}
int Max(int a, int b) {
	if (a > b) {
		return a;
	}
	return b;
}
Avl_node* SingleRotateWithRight(Avl_node* K1) {
	Avl_node* K2;
	K2 = K1->Right; // K1: node whose balance factor is violated K1->Right = K2->Left;
	K2->Left = K1;
	K1->Height = Max(Height(K1->Left), Height(K1->Right)) + 1;
	K2->Height = Max(Height(K2->Right), K1->Height) + 1;
	return K2; /* New root */
}
Avl_node* SingleRotateWithLeft(Avl_node* K1) {
	Position K2;
	K2 = K1->Left; // K1: node whose balance factor is violated K1->Left = K2->Right;
	K2->Right = K1;
	K1->Height = Max(Height(K1->Left), Height(K1->Right)) + 1;
	K2->Height = Max(Height(K2->Left), K1->Height) + 1;
	return K2; /* New root */
}
Avl_node* DoubleRotateWithRight(Avl_node* K1) {
	/* RR rotation between K3 and K2 */
	K1->Right = SingleRotateWithLeft(K1->Right);
	/* LL rotation between K1 and K2 */
	return SingleRotateWithRight(K1);
}
Avl_node* DoubleRotateWithLeft(Avl_node* K3) {
	/* LL rotation between K1 and K2 */
	K3->Left = SingleRotateWithRight(K3->Left);
	/* RR rotation between K3 and K2 */
	return SingleRotateWithLeft(K3);
}
Avl_node* Insert(int X, Avl_node* T) {
	if (T == NULL) { /* Create and return a one-node tree */
		T = new Avl_node;
		T->Element = X;
		T->Left = T->Right = NULL;
	}
	else if (X < T->Element) {
		T->Left = Insert(X, T->Left);
		if (Height(T->Left) - Height(T->Right) == 2) {
			if (X < T->Left->Element) {
				T = SingleRotateWithLeft(T);
			}
			else
				T = DoubleRotateWithLeft(T);
		}
	}
	else if (X > T->Element) {
		T->Right = Insert(X, T->Right);
		if (Height(T->Right) - Height(T->Left) == 2) {
			if (X > T->Right->Element) {
				T = SingleRotateWithRight(T);
			}
			else
				T = DoubleRotateWithRight(T);
		}
	}
	T->Height = Max(Height(T->Left), Height(T->Right));
	return T;
}
int getBalance(Avl_node* N)
{
	if (N == NULL)
		return 0;
	return Height(N->Left) -
		Height(N->Right);
}
Avl_node* minValueNode(Avl_node* node)
{
	Avl_node* current = node;

	/* loop down to find the leftmost leaf */
	while (current->Left != NULL)
		current = current->Left;

	return current;
}
// In Order Traversal
void inOrder(Avl_node* root) {
	if (root->Left != NULL) {
		inOrder(root->Left);
	}
	cout << root->Element << " ";
	if (root->Right != NULL) {
		inOrder(root->Right);
	}
}
void print2DUtil(Avl_node* root, int space)
{
	if (root == NULL)
		return;
	space += COUNT;
	print2DUtil(root->Right, space);
	cout << endl;
	for (int i = COUNT; i < space; i++)
		cout << " ";
	cout << root->Element << "\n";
	print2DUtil(root->Left, space);
}
void print2D(Avl_node* root)
{
	// Pass initial space count as 0
	print2DUtil(root, 0);
}
#endif /* AVL_h */