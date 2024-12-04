//
// Created by nathan on 12/3/24.
//

#include "mtrie.h"
#include "bitwiseops.h"
#include "liltrie.h"

void mtrie::insert(const std::string &s, node* ptr) {
    if (ptr == nullptr) ptr = &root;

    std::string newString = s.substr(1);

    size_t len = 0;
    size_t idx = 0;

    for (int j = 0; j < LETTERS; ++j) { // EQ9
        if (j < mtrie::conv(s[0])) idx += bit_on(ptr->mask, j);
        len += bit_on(ptr->mask, j);
    }

    // size_t childLen = sizeof(ptr->children) / (double)sizeof(ptr->children[0]);
    if (ptr->children == nullptr || len == 0) {
        ptr->children = new node*[len];
    }

    if (!bit_on(ptr->mask, mtrie::conv(s[0]))) {
        auto newArr = new node*[len + 1];

        for (int i = 0; i < len; ++i) {
            if (i < idx) {
                newArr[i] = ptr->children[i];
            } else if (i >= idx) {
                newArr[i+1] = ptr->children[i];
            }
        }


        delete[] ptr->children;
        ptr->children = newArr;
        ptr->children[idx] = nullptr;
    }

    if (ptr->children[idx] == nullptr) {
        ptr->children[idx] = new node;
    }
    // node *child = ;

    set_bit_on(ptr->mask, mtrie::conv(s[0]));

    if (newString.empty()) {
        set_bit_on(ptr->mask, 31); // terminal bit
        return;
    }

    insert(newString, ptr->children[idx]);

}

bool mtrie::contains(const std::string &s, node* ptr) {
    if (ptr == nullptr) ptr = &root;

    if (s.empty()) { return false; }

    std::string newString = s.substr(1);

    size_t len = 0;
    size_t idx = 0;

    for (int j = 0; j < LETTERS; ++j) { // EQ9
        if (j < mtrie::conv(s[0])) idx += bit_on(ptr->mask, j);
        len += bit_on(ptr->mask, j);
    }

    if (ptr->children == nullptr || len == 0) {
        ptr->children = new node*[len];
    }

    if (!bit_on(ptr->mask, mtrie::conv(s[0]))) {
        return false;
    }

    if (newString.empty()) {
        return bit_on(ptr->mask, 31);
    }

    return contains(newString, ptr->children[idx]);
}

mtrie::mtrie() {

};

mtrie::~mtrie() {

}

int mtrie::conv(char c) {
    return (int) c - 97;
}
