#ifndef MPAGSCIPHER_CIPHERBASE_HPP
#define MPAGSCIPHER_CIPHERBASE_HPP

#include <string>

#include "CipherMode.hpp"

class CipherBase { //Base class fo ciphers
  public:
    CipherBase() = default;
    CipherBase(const CipherBase& rhs) = default;
    CipherBase(CipherBase&& rhs) = default;
    CipherBase& operator=(const CipherBase& rhs) = default;
    CipherBase& operator=(CipherBase&& rhs) = default;
    virtual ~ CipherBase() = default;

    virtual std::string applyCipher( const std::string& input, const Cipher mode ) const = 0;
};

#endif
