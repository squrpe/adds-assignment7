#include "PrefixMatcher.h"
#include <string>

// TrieNode::TrieNode() {
//     routerNumber = -1;
// }

PrefixMatcher::PrefixMatcher() {
    root = new TrieNode();
}

void PrefixMatcher::insert(std::string address, int routerNumber) {

    TrieNode* current = root;

    for (char temp : address) {

        if (current->children.find(temp) == current->children.end()) {
            current->children[temp] = new TrieNode();
        }

        current = current->children[temp];

    }

    current->routerNumber = routerNumber;

}

int PrefixMatcher::selectRouter(std::string networkAddress) {

    TrieNode* current = root;
    int index = 0;

    for (char temp : networkAddress) {

        if (current->children.find(temp) == current->children.end()) {
            break;
        }

        current = current->children[temp];
        index++;

    }

    return getRouterNum(current);

}

int PrefixMatcher::getRouterNum(TrieNode* current) {

    int routerNumber = -1;

    if (current->routerNumber != -1) {
        routerNumber = current->routerNumber;
    }

    for (auto& child : current->children) {

        int childRouterNumber = getRouterNum(child.second);

        if (childRouterNumber != -1 && (routerNumber == -1 || childRouterNumber < routerNumber)) {
            routerNumber = childRouterNumber;
        }

    }

    return routerNumber;

}