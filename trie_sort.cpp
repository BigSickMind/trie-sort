#include <cassert>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <cmath>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <iomanip>
#include <cstdlib>
#include <climits>

using namespace std;


struct TrieNode {
    TrieNode * children[26];
    bool isLeaf;
};

typedef TrieNode * trie;

trie getNode()
{
    trie pNode;
    pNode = (trie)malloc(sizeof(struct TrieNode));
    if (pNode)
    {
        pNode->isLeaf = false;
        for (int i = 0; i < 26; i++)
            pNode->children[i] = NULL;
    }
    return pNode;
}

void insert(trie root, string &str, int num)
{
    trie key = root;
    int size = str.length();
    for (int i = 0; i < size; i++)
    {
        int index = (int) (str[i] - 'a');
        if (!key->children[index])
                key->children[index] = getNode();
        key = key->children[index];
    }
    key->isLeaf = true;
}

void TrieSort (trie root, vector <string> &vec, string str)
{
    trie key = root;
    for (int i = 0; i < 26; i++)
    {
        if (key->isLeaf)
        {
            vec.push_back(str);
            break;
        }
        if (key->children[i])
            TrieSort(key->children[i], vec, str + ((char) (i + 'a')));
    }
}


int main()
{
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    string t;
    trie root = getNode();
    for (int i = 0; i < n; i++)
    {
        cin >> t;
        insert(root, t, i + 1);
    }
    vector <string> vec;
    t = "";
    TrieSort(root, vec, t);
    for (int i = 0; i < (int) vec.size(); i++)
        cout << vec[i] << endl;
    return 0;
}
