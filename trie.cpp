/*
@author Hussam
Trie data structure
it adds / searches for string in O(L) L=length of string
*/
#include<bits/stdc++.h>
#include<complex>
#include<math.h>
#include<algorithm>
using namespace std;
#define MAX_CHAR 26



class trie
{
private:
	trie* child[MAX_CHAR];
	bool endOfWord;
public:
	trie()
	{
		memset(child, 0, sizeof(child));
		endOfWord = false;
	}

	void insert(string data)
	{
		int size = int(data.length());
		for (int i = 0; i < size; ++i)
		{
			int current = data[i] - 'a';
			if (child[current] == 0)
				child[current] = new trie();
		}
		endOfWord = true;
	}

	bool isWord(string data)
	{
		int size = int(data.length());
		for (int i = 0; i < size; ++i)
		{
			int current = data[i] - 'a';
			if (child[current] == 0)
				return false;
		}
		return endOfWord;

	}

	bool isPrefix(string data)
	{
		int size = int(data.length());
		for (int i = 0; i < size; ++i)
		{
			int current = data[i] - 'a';
			if (child[current] == 0)
				return false;
		}
		return true;
	}

};



int main()
{
	trie root;

	string s1 = "abc";
	string s2 = "abl";
	string s3 = "fgh";
	root.insert(s1);
	root.insert(s2);
	root.insert(s3);
	cout << root.isWord(s2) << '\n';
	cout << root.isPrefix("ab") << '\n';
	return 0;
}