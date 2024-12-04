#pragma once

// bit is 0 to 31, returns true if bit in mask is "on"
static inline bool bit_on( int mask, unsigned bit )
{ return mask & (1<<bit); }

// bit is 0 to 31, sets the bit to "on"
static inline void set_bit_on( int& mask, unsigned bit )
{ mask |= (1<<bit); }

/***
* You shouldn't need to turn bits in an Mnode mask "off" for this project,
* but in case you are wondering...
*/
// bit is 0 to 31, sets the bit to "off"
static inline void set_bit_off( int& mask, unsigned bit )
{ mask &= (1<<bit); }
