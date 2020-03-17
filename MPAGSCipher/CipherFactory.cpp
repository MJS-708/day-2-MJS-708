#include <memory>

#include "CipherFactory.hpp"
#include "CipherBase.hpp"
#include "CaesarCipher.hpp"
#include "PlayfairCipher.hpp"
#include "VignereCipher.hpp"

std::unique_ptr<CipherBase> cipherFactory(const CipherType type, const std::string inputKey){
  switch(type){

    case CipherType::Caesar :
      return std::make_unique <CaesarCipher>(inputKey); //constructs the CaesarCipher object with inputKey

    case CipherType::Playfair :
      return std::make_unique <PlayfairCipher>(inputKey); //constructs the CaesarCipher object with inputKey

    case CipherType::Vignere :
      return std::make_unique <VignereCipher>(inputKey); //constructs the CaesarCipher object with inputKey
  }
}
