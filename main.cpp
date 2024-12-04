#include "random220.h"
#include "trie.h"
#include <fstream>

#include "liltrie.h"
#include "mtrie.h"

size_t TFootprintEquation(size_t n, size_t t, size_t s);

size_t tNodeSize(size_t c, size_t t);

size_t LnodeFootprintEquation(size_t n);

size_t MnodeFootprintEquation(std::vector<size_t> h);

int main()
{

    mtrie trie;
    trie.insert("hello");
    trie.insert("bye");
//    trie trie;
//    std::vector<size_t> histo(LETTERS+1);

//    std::vector<std::string> dict;
//
//    std::ifstream input("dictionary.txt");
//    std::string word;
//
//    while (input >> word) {
//        dict.emplace_back(word);
//    }

//    int W;

//    for( size_t w=1; w<=500; ++w ) {  // will generate 5 series of data for varying word count W
////        W = 30*1024*w;
//        trie theTrie;
//        std::vector<size_t> histo(LETTERS+1);
////        ideal_tnode_histogram( theTrie, dict, W, histo );
//        collect_child_histogram( theTrie, dict, histo);
//
//        // number of nodes in theTrie
//        size_t N = histo[0];
//        for( size_t n=1; n<histo.size(); ++n ) N+= histo[n];
//
//        size_t s=histo[0];  // number of nodes in trie with zero children
////        std::cout << "# T series for " << W << "words" << std::endl;
//
//        size_t W = theTrie.size();
//
//        size_t n = nodecount(histo);
//
//        size_t LnodeFootprint = LnodeFootprintEquation(n);
//        size_t Tfootprint = TFootprintEquation(n, 1, s);
//        size_t MnodeFootprint = MnodeFootprintEquation(histo);
//
//        std::cout << W << "," << LnodeFootprint << " " << W << "," << Tfootprint << " " << W << "," << MnodeFootprint << std::endl;
//
////        for( size_t T=1; T<LETTERS; ++T ) {
////            s += histo[T];    // now the number of nodes with T or less children
////
////            std::cout << T << "," << (Tfootprint) << std::endl;
////        }
//    }

//    ideal_tnode_histogram( trie, dict, 30000, histo );

	return 0;
}

size_t MnodeFootprintEquation(std::vector<size_t> h) {
    size_t total(0);

    for (size_t i = 0; i < h.size(); ++i) {
        total += (INTBYTES + (i + 1) * PTRBYTES) * h[i];
    }

    return total;
}

size_t LnodeFootprintEquation(size_t n) {
    return n * (BOOLBYTES + LETTERS * PTRBYTES);
}

size_t TFootprintEquation(size_t n, size_t t, size_t s) {
    return s * tNodeSize(1, t) + (n - s) * tNodeSize(LETTERS, t);
}

size_t tNodeSize(size_t c, size_t t) {
    if (c <= t) {
        return BOOLBYTES + t * CHARBYTES + t * PTRBYTES * 2;
    } else {
        return BOOLBYTES + t * CHARBYTES + t * PTRBYTES * 2 + (LETTERS - t) * PTRBYTES;
    }
}

