/*
 * trie.h
 *
 * Declaration of the trie class.
 * 
 * Author: <your name here>
 */

#ifndef _TRIE_H
#define _TRIE_H

#include <string>
#include <vector>

/***
 * DO NOT put unscoped 'using namespace std;' in header files!
 * Instead put them at the beginning of class or function definitions
 * (as demonstrated below).
 */

//struct node;

class trie {
public:
    void insert(const std::string &s);
    bool contains(const std::string &s);
    bool is_prefix(const std::string &s);
    void extend(const std::string &prefix, std::vector<std::string> &result);
    trie();

private:

    struct node {
        char c{};
        bool terminal = false;
        node* children[26]{};
    };

    node* root[26];
    int conv(char c);
    void traverse(node* input, std::vector<std::string> &outputList, const std::string &prefix);
};

//struct node {
//    char c{};
//    bool terminal{};
//    trie children[26]{};
//};

#endif
