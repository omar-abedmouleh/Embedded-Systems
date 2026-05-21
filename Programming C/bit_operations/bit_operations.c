#include "first_code.h"

unsigned int reset_bit_function(unsigned int value,
                                const unsigned char bit_index) {
  return value & ~(1U << bit_index);
}

unsigned int set_bit_function(unsigned int value,
                              const unsigned char bit_index) {
  return value | (1U << bit_index);
}

unsigned int toggle_bit_function(unsigned int value,
                                 const unsigned char bit_index) {
  return value ^ (1U << bit_index);
}
