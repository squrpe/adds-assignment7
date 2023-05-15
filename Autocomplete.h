#ifndef AUTOCOMPLETE_H
#define AUTOCOMPLETE_H

#include <unordered_map>
#include <vector>
#include <string>

class TrieNode {
    public:
        TrieNode();
        bool isEndOfWord;
        std::unordered_map<char, TrieNode*> children;
};

class Autocomplete {
    public:
        Autocomplete();
        std::vector<std::string> getSuggestions(std::string partialWord);
        void insert(std::string word);

    private:
        TrieNode* root;
        void getSuggestionsRecursion(TrieNode* current, std::string partialWord, std::vector<std::string>& suggestions);
};

#endif