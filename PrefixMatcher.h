#ifndef PREFIXMATCHER_H
#define PREFIXMATCHER_H

#include <unordered_map>
#include <string>

class TrieNode {
    public:
        TrieNode() {
            routerNumber = -1;
        };
        int routerNumber;
        std::unordered_map<char, TrieNode*> children;
};

class PrefixMatcher {
    public:
        PrefixMatcher();
        int selectRouter(std::string networkAddress);
        void insert(std::string address, int routerNumber);

    private:
        TrieNode* root;
        int getRouterNum(TrieNode* current);

};

#endif

