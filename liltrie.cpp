#include "liltrie.h"
/***
 * Count the total number of nodes represented in a |children| histogram
 */
template<>
size_t nodecount( const std::vector<size_t>& histo )
{
	size_t nc = 0;
	for( auto count: histo ) nc += count;
	return nc;
}

