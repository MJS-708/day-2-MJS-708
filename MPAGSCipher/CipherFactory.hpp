#ifndef MPAGSCIPHER_CIPHERFACTORY_HPP
#define MPAGSCIPHER_CIPHERFACTORY_HPP

#include <memory>
#include "CipherBase.hpp"
#include "CipherType.hpp"

std::unique_ptr<CipherBase> cipherFactory(const CipherType type, const std::string inputKey);

#endif
