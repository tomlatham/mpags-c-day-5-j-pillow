#ifndef MPAGSCIPHER_VIGENERECIPHER_HPP
#define MPAGSCIPHER_VIGENERECIPHER_HPP

// Standard library includes
#include <string>
#include <map>

// Our project headers
#include "CipherMode.hpp"
#include "CaesarCipher.hpp"

class VigenereCipher {
	public:
	VigenereCipher ( const std::string& key );
	
	void setKey ( const std::string& key );
	
	std::string applyCipher ( const std::string& inputText, const CipherMode cipherMode ) const;
	
	private:
	
	/// The cipher key
	std::string key_="";
	
	/// Lookup table
	std::map<char,CaesarCipher> charLookup_;
};

#endif