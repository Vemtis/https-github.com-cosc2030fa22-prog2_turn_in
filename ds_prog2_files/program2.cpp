#include "Node.h"
#include "Linked.h"
#include "timer.h"
#include <iostream>
#include <string>
#include<fstream>


using namespace std;

string cleanWord(string client)
{
	int length = client.length();
	for (int i = 0; i <= length; i++)
	{
		if (client[i] != '\'')
		{
			if (isalnum(client[i]))
			{
				if (isupper(client[i]))
				{
					client[i] = tolower(client[i]);
				}
			}
			else
			{
				client.erase(i, 1);
				length--;
				i--;
			}
		}
	}
	return client;
}

void readDict(linked stuff)
{
	string readIn;
	ifstream dict;
	long long int words = 0;
	dict.open("dict.txt");

	while (dict >> readIn)
	{
		string clean = cleanWord(readIn);
		stuff.insert(readIn);
		words++;
	}
	dict.close();
	cout << "dictionary size:" + to_string(words) << endl;
}

void readBook(linked stuff)
{
	Timer tim;
	tim.Start();
	string readIn;
	ifstream book;
	ofstream wrong;
	wrong.open("MissSpelled.txt");
	long long int skip = 0;
	long long int bad = 0;
	long long int gComp = 0;
	long long int bComp = 0;
	long long int good = 0;
	book.open("book.txt");
	while (book >> readIn)
	{
		string clean = cleanWord(readIn);

		if (isalpha(clean[0]))
		{
			if (stuff.find(clean))
			{
				good++;
			}
			else
			{
				bad++;
				wrong << clean + "\n";
			}
		}
		else if(!clean.empty())
		{
			skip++;
		}
	}
	cout << "Done checking all these results\n";
	cout << "finished in time: " + to_string(tim.Time()) + "\n";
	tim.Stop();
	tim.~Timer();
	cout << "There are " + to_string(good) + " words found in the dictionary\n\t";
	for (int i = 0; i < 27; i++)
	{
		gComp = gComp + stuff.getGood();
	}
	long long int gAvg = 0;
	if (good != 0)
	{
		gAvg = gComp / good;
	}
	cout << to_string(gComp) + " compares. Average: " + to_string(gAvg);
	cout << "\nThere are " + to_string(bad) + " word NOT found in the dictionary\n\t";
	for (int i = 0; i < 27; i++)
	{
		bComp = bComp + stuff.breakBad();
	}
	long long int bAvg = 0;
	if (bad != 0)
	{
		bAvg = bComp / bad;
	}
	cout << to_string(bComp) + " compares. Average: " + to_string(bAvg);
	cout << "\nThere are " + to_string(skip) + " words not checked.\n";
	wrong.close();
	book.close();

}

int main()
{
	linked stuff;

	readDict(stuff);
	
	readBook(stuff);

	return 0;
}