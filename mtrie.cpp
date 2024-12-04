//
// Created by nathan on 12/3/24.
//

#include "mtrie.h"
#include "bitwiseops.h"
#include "liltrie.h"

void mtrie::insert(const std::string &s) {
    node* ptr = &root;
    node* ptr_prev = nullptr;

    for (size_t i = 0; i < s.length(); ++i) {
        size_t count(0);
        size_t bit = mtrie::conv(s[i]);

        size_t len(0);

        for (int j = 0; j < LETTERS; ++j) {
            len += bit_on(ptr->mask, j);
        }

        if (!bit_on(ptr->mask, bit))
            set_bit_on(ptr->mask, bit);

        auto temp = new node::node_ptr;
        size_t idx(0);

        for (int j = 0; j < mtrie::conv(s[i]); ++j) {
            idx += bit_on(ptr->mask, j);
        }



        if (len > idx) {
            for (size_t j = 0; j < idx; ++j) {
                temp[j] = ptr->children[j];
            }

            temp[idx] = new node;

            for (size_t j = idx; j < len; ++j) {
                temp[j + 1] = new node;
                temp[j + 1] = ptr->children[j];
            }
        } else {
            temp[idx] = new node;
        }



        for (size_t j = 0; j < len; ++j) {
            temp[j] = ptr->children[j];
        }

        ptr->children = temp;
        ptr_prev = ptr;
        ptr = ptr->children[idx];
    }
    set_bit_on(ptr_prev->mask, 31);
}

bool mtrie::contains(const std::string &s) {
    return false;
}

mtrie::mtrie() = default;

int mtrie::conv(char c) {
    return (int) c - 97;
}
