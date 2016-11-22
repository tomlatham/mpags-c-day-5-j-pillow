#ifndef MPAGSCIPHER_VIGENERECIPHER_HPP
#define MPAGSCIPHER_VIGENERECIPHER_HPP

// Standard library includes
#include <string>
#include <map>

// Our project headers
#include "CipherMode.hpp"
#include "CaesarCipher.hpp"
#include "Cipher.hpp"

/**
	* \file VigenereCipher.hpp
	* \brief Contains the declaration of the VigenereCipher class
*/

/**
	* \class VigenereCipher
	* \brief Encrypt or decrypt text using the Vigenere cipher with the given key
*/
class VigenereCipher : public Cipher {
	public:
	/**
	* Create a new VigenereCipher with the given key
	*
	* \param key the key to use in the cipher
	*/
	VigenereCipher ( const std::string& key );
	
	/**
	* Set the key to be used for the ecnryption/decryption
	*
	* \param key the key to use in the cipher
	*/
	void setKey ( const std::string& key );
	
	/**
	* Apply the cipher to the provided text
	* \param inputText the text to encrypt or decrypt
	* \param cipherMode wehter to encrypt or decrypt inputText
	* \return the result of applying the cipher to inputText
	*/
	virtual std::string applyCipher ( const std::string& inputText, const CipherMode cipherMode ) const override;
	
	private:
	/// The cipher key
	std::string key_="";
	
	/// Lookup table for the chars
	std::map<char,CaesarCipher> charLookup_;
};

#endif