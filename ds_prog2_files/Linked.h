#ifndef LINKED_
#define LINKED_

#include "Node.h"
#include<iostream>
#include<string>
using namespace std;



struct linked
{
	node* root;
	long long int size;
	long long int height;
	long long int goodChecks = 0;
	long long int badChecks = 0;
	long long int toFill = 0;
	linked()
	{
		root = new node();
		size = 0;
		height = 0;
	}
	linked(string thing)
	{
		root = new node(thing);
		size = 1;
		height = 0;
	}

	void placeData(node * tmp, node * base)
	{
		if(tmp->data.compare(base->data) < 0)
		{
			if(base->left == nullptr)
			{
				base->left = tmp;
			}
			else
			{
				placeData(tmp, base->left);
			}
		}
		else if (tmp->data.compare(base->data) > 0)
		{
			if(base->right == nullptr)
			{
				base->right = tmp;
			}
			else
			{
				placeData(tmp, base->right);
			}
		}
		else
		{
			size--;
		}
	}

	void insert(string thing)
	{	

		size++;
		node * tmp = new node(thing);
		if(root == nullptr)
		{
			root = tmp;
		}
		else
		{
			placeData(tmp, root);
		}
	}

	void print(node * base)
	{
		if(base != nullptr)
		{
			cout << base->data << endl;
			print(base-> left);
			print(base-> right);
		}
	}

	void print()
	{
		if(root != nullptr)
		{
			cout << root->data << endl;
			print(root-> left);
			print(root-> right);
		}
	}

	bool find(string test)
	{
		long long int bad = 1;
		node* tmp = root;
		long long int i = 1;
		while(tmp != nullptr)
		{
			bad++;
			i++;
			if(test.compare(tmp->data) < 0)
			{
				tmp = tmp->left;
			}
			else if (test.compare(tmp->data) > 0)
			{
				tmp = tmp->right;
			}
			else
			{
				goodChecks= goodChecks + i;
				return true;
			}
		}
		/*for (int i = 0; i < size; i++)
		{
			string word = tmp->data;
			bad++;
			if (!test.compare(word))
			{
				goodChecks= goodChecks + i + 1;
				return true;
			}
			
		}*/
		badChecks = badChecks + bad;
		return false;
	}

	long long int getGood()
	{
		return goodChecks;
	}

	long long int breakBad()
	{
		return badChecks;
	}
};

#endif