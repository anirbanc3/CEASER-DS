#ifndef __CEASER_DS_PBOX_H__
#define __CEASER_DS_PBOX_H__

#include <cstdint>
#include <string>

class PBox {
  public:
    PBox(std::string seed) : PBox(seed, 64);
    PBox(std::string seed, int nbits);
    ~PBox();
    uint64_t scramble(uint64_t n);
    
  private:
    int width;
    uint64_t randn();
    uint64_t hash;
    uint64_t p;
    uint8_t x[64];
};

#endif
