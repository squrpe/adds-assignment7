#include "Autocomplete.h"
#include <unordered_map>

TrieNode::TrieNode() {
    isEndOfWord = false;
}

Autocomplete::Autocomplete() {
    root = new TrieNode();
}

void Autocomplete::insert(std::string word) {

    TrieNode* current = root;

    for (char temp : word) {

        if (current->children.find(temp) == current->children.end()) {
            current->children[temp] = new TrieNode();
        }

        current = current->children[temp];
    }

    current->isEndOfWord = true;

}

std::vector<std::string> Autocomplete::getSuggestions(std::string partialWord) {

    std::vector<std::string> suggestions;
    TrieNode* current = root;

    for (char temp : partialWord) {

        if (current->children.find(temp) == current->children.end()) {
            return suggestions;
        }

        current = current->children[temp];

    }

    getSuggestionsRecursion(current, partialWord, suggestions);
    return suggestions;

}

void Autocomplete::getSuggestionsRecursion(TrieNode* current, std::string partialWord, std::vector<std::string>& suggestions) {

    if (current->isEndOfWord) {
        suggestions.push_back(partialWord);
    }

    for (auto& child : current->children) {
        getSuggestionsRecursion(child.second, partialWord + child.first, suggestions);
    }
    
}
