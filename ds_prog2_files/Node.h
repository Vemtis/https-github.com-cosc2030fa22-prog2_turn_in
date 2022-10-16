#ifndef NODE_
#define NODE_

#include<string>
using namespace std;

struct node 
{
	string data;
	node* left;
	node* right;
	node()
	{
		left = nullptr;
		right = nullptr;
	}
	node(string item)
	{
		data = item;
		left = nullptr;
		right = nullptr;
	}
	~node()
	{
		left = nullptr;
		right = nullptr;
	}
};
#endif