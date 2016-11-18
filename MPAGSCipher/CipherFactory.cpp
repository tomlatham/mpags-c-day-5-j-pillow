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
	switch(type) {
			
		case CipherType::Caesar :
			if ( ! key.empty() ) {
				for ( const auto& elem : key ) {
	    			if ( ! std::isdigit(elem) ) {
	      				std::cerr << "[error] cipher key must be an unsigned long integer for Caesar cipher,\n"
								  << "the supplied key (" << key << ") could not be successfully converted" << std::endl;
	      				return std::unique_ptr<Cipher>();
	    			}
	  			}
				size_t cKey = std::stoul(key);
				return std::make_unique<CaesarCipher>( cKey );
			}
			else {
				return std::unique_ptr<Cipher>();
			}
				
		case CipherType::Playfair :
			return std::make_unique<PlayfairCipher>( key );
			
		case CipherType::Vigenere :
			return std::make_unique<VigenereCipher>( key );
	}
	return std::unique_ptr<Cipher>();
}