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
    void finalize();
    std::size_t size();
    void children_histogram(std::vector<size_t>& histo);
    trie();

private:

    class node {
    public:
        char c{};
        bool terminal = false;
        node* children[26]{};

        std::size_t node_children() {
            int count = 0;
            for (int i = 0; i < 26; ++i) {
                if (children[i] != nullptr) count++;
            }
            return count;
        }

        void children_histogram(std::vector<size_t>& histo) {
            histo[this->node_children()]++;
            for (std::size_t i = 0; i < 26; ++i) {
                if (children[i] != nullptr) {

                    children[i]->children_histogram(histo);
                }
            }
        }
    };

    node* root[26];
    int conv(char c);
    void traverse(node* input, std::vector<std::string> &outputList, const std::string &prefix);

public:
    std::vector<node*> noderef;
};


//struct node {
//    char c{};
//    bool terminal{};
//    trie children[26]{};
//};

#endif
