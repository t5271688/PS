#include <bits/stdc++.h>
#define ALPHABET 26
using namespace std;

struct TrieNode {
    struct TrieNode* children[ALPHABET];
    bool isEndOfWord;
    int childCount;
};

struct TrieNode* getNode(void) {
    struct TrieNode* pNode = new TrieNode;
    pNode->isEndOfWord = false;
    pNode->childCount = 0;
    for (int i = 0; i < ALPHABET; i++) pNode->children[i] = NULL;

    return pNode;
}

void insert(struct TrieNode* root, string key) {
    struct TrieNode* pCrawl = root;
    for (int i = 0;i < key.length();i++) {
        int index = key[i] - 'a';

        if (!pCrawl->children[index]) {
            pCrawl->children[index] = getNode();
            pCrawl->childCount++;
        }
        pCrawl = pCrawl->children[index];
    }

    pCrawl->isEndOfWord = true;
}

void free_all(struct TrieNode* cur) {
    if (!cur) return;

    for (int i = 0;i < ALPHABET;i++) {
        free_all(cur->children[i]);
    }
    delete(cur);
}

int countWord(struct TrieNode* root, string key) {
    int count = 1;
    struct TrieNode* pCrawl = root->children[key[0] - 'a'];

    for (int i = 1;i < key.length();i++) {
        int index = key[i] - 'a';

        if (pCrawl->childCount > 1 || pCrawl->isEndOfWord == true) count++;

        pCrawl = pCrawl->children[index];
    }

    return count;
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tmp;
    while (cin >> tmp) {
        int sum = 0;
        struct TrieNode* root = getNode();
        string str[100000];
        for (int i = 0;i < tmp;i++) {
            cin >> str[i];
            insert(root, str[i]);
        }

        for (int i = 0;i < tmp;i++)
            sum += countWord(root, str[i]);

        cout << fixed;
        cout.precision(2);
        cout << (double)sum / tmp << '\n';

        free_all(root);
    }
}