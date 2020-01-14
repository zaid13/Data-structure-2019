//
// pch.h
// Header for standard system include files.
//

#pragma once

#include "gtest/gtest.h"
#include <iostream>
#pragma once
#include<iostream>
using namespace std;

template<typename T>

class Node_ptr
{
public:
	T val;
	Node_ptr* left;
	Node_ptr* right;
	Node_ptr()
	{
		left = NULL;
		right = NULL;
	}
	Node_ptr(T a)
	{
		val = a;
		left = NULL;
		right = NULL;
	}
};
template<typename T>
class Tree
{
public:

	Node_ptr<T>* root;
	Node_ptr<T>* child;
	Tree()
	{
		root = NULL;
		child = NULL;
		//Node_ptr* root = NULL;
		//root = new <T>Node_ptr(10);
		//root->left = new <T>Node_ptr(20);
		//root->right = new <T>Node_ptr(30);

		//root->left->right = new <T>Node_ptr(40);
		//root->left->left = new<T> Node_ptr(50);
		//root->right->left = new<T> Node_ptr(60);
		//root->right->right = new Node_ptr(70);

		//root->left->left->left = new Node_ptr(80);
		//root->left->left->right = new Node_ptr(90);
		//root->left->right->left = new Node_ptr(80);
		//root->left->right->right = new <T>Node_ptr(90);
		//root->right->left->left = new <T>Node_ptr(80);
		//root->right->left->right = new <T>Node_ptr(90);
		//root->right->right->left = new <T>Node_ptr(80);
		//root->right->right->right = new<T> Node_ptr(90);


	}
	void insert(Node_ptr<T>& n1)
	{
		int i = 0;
		if (root == NULL) {
			root = &n1;
			child = &n1;
		}
		else
		{

			while (i == 0)
			{
				if (n1.val > child->val)
				{

					if (child->right == NULL)
					{

						child->right = &n1;

						i = 1;
					}
					else
						child = child->right;


				}
				else if (n1.val < child->val)
				{

					if (child->left == NULL)
					{
						child->left = &n1;
						i = 1;
					}
					else
					{
						child = child->left;
					}

				}
				else if (n1.val == child->val) {
					child = child->left;
				}

			}
		}


		child = root;
	}

	int max(int a, int b)
	{
		return (a >= b) ? a : b;
	}
	int getHeight(Node_ptr<T>* p)
	{
		if (p == NULL)
		{
			return 0;
		}
		else
		{
			return  1 + max(getHeight(p->left), getHeight(p->right));
		}
	}
	bool isEmpty()
	{
		if (root == NULL)
		{
			return true;
		}
		return false;
	}
	void inorder(Node_ptr<T>* p)
	{
		if (p != NULL)
		{
			inorder(p->left);
			cout << p->val << " ";
			inorder(p->right);
		}
	}
	bool FullBinaryTree(Node_ptr<T>* p)
	{
		if (p == NULL)
		{
			return true;
		}

		if (p->left == NULL && p->right == NULL)
		{
			return true;
		}
		if ((p->left) && (p->right))
		{
			return (FullBinaryTree(p->left) && FullBinaryTree(p->right));
		}
		return false;
	}
	bool Perfect(Node_ptr<T>* p)
	{
		int h1 = getHeight(p->left);
		int h2 = getHeight(p->right);
		if (h1 == h2)
		{
			return true;

		}
		else
		{
			return false;

		}
	}
	int countNode_ptrs(struct Node_ptr<T>* p)
	{
		if (p == NULL)
		{
			return 0;
		}
		return (1 + countNode_ptrs(p->left) + countNode_ptrs(p->right));
	}

	bool isComplete(struct Node_ptr<T>* p, int TOTAL_Node_ptrS, int CURRNET_Node_ptr)
	{
		if (p == NULL)
		{
			return true;
		}
		if (TOTAL_Node_ptrS <= CURRNET_Node_ptr)
		{
			return false;
		}
		return (isComplete(p->left, TOTAL_Node_ptrS, (2 * CURRNET_Node_ptr) + 1) &&
			isComplete(p->right, TOTAL_Node_ptrS, (2 * CURRNET_Node_ptr) + 2));
	}

	bool isBalanced(Node_ptr<T>* p)
	{
		int HEIGHT_LEFT;
		int HEIGHT_RIGHT;

		if (p == NULL)
		{
			return 1;
		}
		HEIGHT_LEFT = getHeight(p->left);
		HEIGHT_RIGHT = getHeight(p->right);

		if (abs(HEIGHT_LEFT - HEIGHT_RIGHT) <= 1 && isBalanced(p->left) && isBalanced(p->right))
		{
			return 1;
		}

		return 0;
	}
};


