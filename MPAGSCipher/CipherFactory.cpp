#include <memory>
#include <iostream>
#include "Cipher.hpp"
#include "CipherFactory.hpp"
#include "CipherMode.hpp"
#include "CaesarCipher.hpp"
#include "PlayfairCipher.hpp"
#include "VigenereCipher.hpp"

std::unique_ptr<Cipher> cipherFactory ( const CipherType type, const std::string& key ) 
{
	switch(type) { // Switch on the type of cipher to be used
			
		case CipherType::Caesar :
			{
				// We have the key as a string, but the Caesar cipher needs an unsigned long, so we first need to convert it
				// We default to having a key of 0, i.e. no encryption, if no key was provided on the command line
				size_t cKey {0};

				if ( ! key.empty() ) {

					for ( const auto& elem : key ) { // For Caesar cipher check if key is numeric

						if ( ! std::isdigit(elem) ) {
							std::cerr << "[error] cipher key must be an unsigned long integer for Caesar cipher,\n"
								<< "the supplied key (" << key << ") could not be successfully converted" << std::endl;
							return std::unique_ptr<Cipher>(); // If key is not numeric return null pointer
						}

					}

					cKey = std::stoul(key);

				}

				return std::make_unique<CaesarCipher>( cKey );
			}
				
		case CipherType::Playfair :
			return std::make_unique<PlayfairCipher>( key );
			
		case CipherType::Vigenere :
			return std::make_unique<VigenereCipher>( key );
	}
	
	return std::unique_ptr<Cipher>();
}
