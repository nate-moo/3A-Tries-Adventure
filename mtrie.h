//
// Created by nathan on 12/3/24.
//

#ifndef PROJECT3A_LILTRIEADVENTURE_MTRIE_H
#define PROJECT3A_LILTRIEADVENTURE_MTRIE_H


#include <string>

class mtrie {
public:
    void insert(const std::string &s);
    bool contains(const std::string &s);
    mtrie();

private:

    struct node {
        // bits 0-25 chars, bit 31 - terminal
        int mask = 0;
        typedef node* node_ptr;
        node_ptr* children{};
    };

    node root;
    int conv(char c);
//    size_t len = 0;
public:
    mtrie( const node& trie ) = delete;
    mtrie& operator =( const node& trie ) = delete;
};


#endif //PROJECT3A_LILTRIEADVENTURE_MTRIE_H
