#include "pbox.hh"

PBox::PBox(std::string seed)
{
  hash = 0xcbf29ce484222325;
  p = 0;
  for (char& c : seed) { // seed the rng
    hash = (hash & (~0xFF)) | ((hash ^ c) & 0xFF);
    hash *= 0x00000100000001b3;
  }
  for (int i = 0; i < 64; ++i)
    x[i] = 0;
  for (int i = 0; i < 64; ++i) {
    int k = randn() % 64;
    for (; x[k]; k = (k + 1) % 64);
    x[k] = i;
  }
}

PBox::~PBox()
{

}

uint64_t PBox::randn()
{
  hash ^= p;
  hash *= 0x00000100000001b3;
  p = (p + 1) % 256;
  return hash;
}

uint64_t PBox::scramble(uint64_t n)
{
  uint64_t result = 0;
  for (uint64_t i = 0; i < 64; ++i) {
    uint64_t mask = ((uint64_t)1 << i);
    result |= (uint64_t)((n & mask) != 0) << x[i];
  }
  return result;
}
