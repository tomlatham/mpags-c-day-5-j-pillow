#ifndef MPAGSCIPHER_CIPHERFACTORY_HPP
#define MPAGSCIPHER_CIPHERFACTORY_HPP

#include <string>
#include <memory>

#include "Cipher.hpp"
#include "CipherType.hpp"


std::unique_ptr<Cipher> cipherFactory ( const CipherType type, const std::string& key );

#endif