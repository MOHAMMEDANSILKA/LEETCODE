class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int count = 0;
        for (string& word : words) {
            if (word.find(pref) == 0) {
                count++;
            }
        }
        return count;
    }
};


//Approach-2 (Using Trie)
//T.C : O(n^l + m), where n = number of words, m = length of pref, l = average length of word
//S.C : O(n^l)
struct trieNode {
    trieNode* children[26];
    bool isEndOfWord;
    int count; //count of prefix ending at this node
};

trieNode* getNode() {
    trieNode* newNode = new trieNode();
    newNode->isEndOfWord = false;
    newNode->count = 0;
    for(int i = 0; i < 26; i++) {
        newNode->children[i] = NULL;
    }

    return newNode;
}

class Trie{
    public:
        trieNode* root;

        Trie() {
            root = getNode();
        }

        void insert(string &word) { //O(l)
            trieNode* pCrawl = root;
            for(char &ch : word) {
                int idx = ch - 'a';
                if(pCrawl->children[idx] == NULL) {
                    pCrawl->children[idx] = getNode();
                }
                pCrawl = pCrawl->children[idx];
                pCrawl->count++; //Count increased for prefix ending at this character node
            }
