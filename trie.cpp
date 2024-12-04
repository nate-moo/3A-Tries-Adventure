/*
 * trie.cpp
 *
 * Method definitions for the trie class.
 *
 * Author: <your name here>
 */

#include "trie.h"

void trie::insert(const std::string &s) {

    int begin = trie::conv(s[0]);

    if (root[begin] == nullptr) root[begin] = new node{};

    if (s.empty()) return;

    node *point = root[begin];

    for (size_t i = 0; i < s.length() - 1; ++i) {
        point->c = s[i];

        if (point->children[trie::conv(s[i + 1])] == nullptr) {
            point->children[trie::conv(s[i + 1])] = new node{};
        }

        point = point->children[trie::conv(s[i + 1])];
    }

    point->c = s[s.length() - 1];

    point->terminal = true;

}

bool trie::contains(const std::string &s) {
    node *point = root[trie::conv(s[0])];

    if (point == nullptr) return false;

    if (s.empty()) return false;

    for (size_t i = 0; i < s.length() - 1; ++i) {
        if (point == nullptr || point->c != s[i]) return false;
        point = point->children[trie::conv(s[i + 1])];
    }

    if (point != nullptr && (point->c == s[s.length() - 1] && point->terminal)) return true;

    return false;
}

bool trie::is_prefix(const std::string &s) {
    node *point = root[trie::conv(s[0])];

    if (s.empty()) return true;

    if (point == nullptr) return false;

    for (size_t i = 0; i < s.length() - 1; ++i) {
        if (point == nullptr || point->c != s[i]) return false;
        point = point->children[trie::conv(s[i + 1])];
    }

    if (point != nullptr && point->c == s[s.length() - 1]) return true;

    return false;
}

void trie::extend(const std::string &prefix, std::vector<std::string> &result) {
    std::vector<node *> nodeList;

    if (!prefix.empty()) {
        node *point = root[trie::conv(prefix[0])];
        if (trie::is_prefix(prefix)) {

            for (size_t i = 0; i < prefix.length() - 1; ++i) {
                point = point->children[trie::conv(prefix[i + 1])];
            }

            traverse(point, result, prefix);
            return;

        } else { return; }
    } else {
        for (int i = 0; i < 26; ++i) {
            if (root[i] != nullptr) {
                std::string initialPrefix;
                initialPrefix += (char) ('a' + i);
                traverse(root[i], result, initialPrefix);
            }
        }
    }
}

int trie::conv(char c) {
    return (int) c - 97;
}

trie::trie() {
    for (int i = 0; i < 26; ++i) {
        root[i] = nullptr;
    }
}

void trie::traverse(trie::node *input, std::vector<std::string> &outputList, const std::string &prefix) {
    if (input->terminal) {
        outputList.emplace_back(prefix);
        noderef.emplace_back(input);
    }
    for (int i = 0; i < 26; ++i) {
        if (input->children[i] != nullptr) {
            std::string newPrefix = prefix + input->children[i]->c;

            traverse(input->children[i], outputList, newPrefix);
        }
    }
}

void trie::finalize() {

}

std::size_t trie::size() {
    std::vector<std::string> outlist;
//    size_t count = 0;

    for (int i = 0; i < 26; ++i) {
        if (root[i] == nullptr) continue;
        traverse(root[i], outlist, "");
//        count += outlist.size();
    }

    return outlist.size();
}

// void trie::children_histogram(std::vector<size_t> &histo) {
//     int count = 0;
//
//     for (int i = 0; i < 26; ++i) {
//         if (root[i] != nullptr) {
//             count++;
//             root[i]->children_histogram(histo);
//         }
//     }
//
//     histo[count]++;
//     histo[0] = size();
// }
