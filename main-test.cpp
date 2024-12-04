#include <fstream>
#include "random220.h"
#include "trie.h"

#include "liltrie.h"

int main()
{




//	std::cout << "If you are reading this, you've successfully built main-test in the LilTrieAdventure!" << std::endl;
//	trie t;
//
    trie trie;
    std::vector<size_t> histo(LETTERS+1);
    std::vector<std::string> words;

    std::ifstream input("../wordlists/dictionary256.txt");
    std::string word;

    while (input >> word) {
        words.emplace_back(word);
    }

    test_child_histogram( trie, words, histo );

//    for (auto item: histo) {
//        std::cout << item << std::endl;
//    }

#if defined(TEST_NODE_FUNCTIONS) || 0
	std::vector<std::string> v = {"intergossip", "homovanillin", "restiaceous", "misguidingly", "travelled" };
	test_node_functions<trie>( t, v );
#endif
	return 0;
}

