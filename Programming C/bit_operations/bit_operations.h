#ifndef _FIRST_CODE_H
#define _FIRST_CODE_H

#define reset_bit(value, bit_index)   ((value) &= ~(1U << (bit_index)))
#define set_bit(value, bit_index)     ((value) |= (1U << (bit_index)))
#define toggle_bit(value, bit_index)  ((value) ^= (1U << (bit_index)))

unsigned int reset_bit_function(unsigned int value, const unsigned char bit_index);
unsigned int set_bit_function(unsigned int value, const unsigned char bit_index);
unsigned int toggle_bit_function(unsigned int value, const unsigned char bit_index);

#endif