//
// Created by nathan on 12/3/24.
//

#ifndef PROJECT3A_LILTRIEADVENTURE_MTRIE_H
#define PROJECT3A_LILTRIEADVENTURE_MTRIE_H


#include <string>
#include "liltrie.h"
#include "bitwiseops.h"

class mtrie {
    struct node {
        // bits 0-25 chars, bit 31 - terminal
        int mask = 0;
        // typedef node* node_ptr;
        node** children{nullptr};

        void destruct() const {
            size_t len(0);

            for (int j = 0; j < LETTERS; ++j) {
                len += bit_on(this->mask, j);
            }

            for (size_t i = 0; i < len; i++) {
                children[i]->destruct();
                delete children[i];
            }

            delete[] children;

        }
    };

    node root;
    int conv(char c);
//    size_t len = 0;
public:
    void insert(const std::string &s, node* ptr = nullptr);
    bool contains(const std::string &s, node* ptr = nullptr);

    static void finalize() {};

    mtrie();
    ~mtrie();
    mtrie( const node& trie ) = delete;
    mtrie& operator =( const node& trie ) = delete;
};


#endif //PROJECT3A_LILTRIEADVENTURE_MTRIE_H
