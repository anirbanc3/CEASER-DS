#include "pbox.hh"

/* nbits (which gets stored in `width`) specifies the
 bit width of the p-box. seed is used to seed the PRNG. */
PBox::PBox(std::string seed, int nbits)
{
  assert(nbits > 0);
  assert(nbits <= 64);
  width = nbits;
  hash = 0xcbf29ce484222325;
  p = 0;
  for (char& c : seed) { // seed the rng
    hash = (hash & (~0xFF)) | ((hash ^ c) & 0xFF);
    hash *= 0x00000100000001b3;
  }
  
  // clear x just to be safe
  for (int i = 0; i < width; ++i)
    x[i] = 0;
  
  // randomly fill each position 1..width in x
  // with a number between 0 and width-1
  for (int i = 0; i < width; ++i) {
    int k = randn() % width;
    for (; x[k]; k = (k + 1) % width);
    x[k] = i;
  }
}

PBox::~PBox()
{

}

/* pseudorandom number generator based on the FNV-1A
 hash function */
uint64_t PBox::randn()
{
  hash ^= p;
  hash *= 0x00000100000001b3;
  p = (p + 1) % 256;
  return hash;
}

uint64_t PBox::scramble(uint64_t n)
{
  /* scramble a number using the pbox. For each bit k
   in n, where 0<k<width-1, bit k will be put into
   bit position x[k] in the result. */
  uint64_t result = 0;
  for (uint64_t i = 0; i < width; ++i) {
    uint64_t mask = ((uint64_t)1 << i);
    result |= (uint64_t)((n & mask) != 0) << x[i];
  }
  return result;
}
