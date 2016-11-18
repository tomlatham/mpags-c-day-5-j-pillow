
// Standard library includes
#include <string>
#include <algorithm>

// Out project headers
#include "Alphabet.hpp"
#include "VigenereCipher.hpp"


VigenereCipher::VigenereCipher ( const std::string& key )
{
	// Set the given key
	setKey(key);
}

void VigenereCipher::setKey ( const std::string& key )
{
	
	// Store the key
	key_=key;
	
	// Make sure the key is uppercase
	std::transform( std::begin(key_), std::end(key_), std::begin(key_), ::toupper );
	
	// Remove non-alpha characters
	key_.erase( std::remove_if( std::begin(key_), std::end(key_), [](char c){ return !std::isalpha(c); } ), std::end(key_) );
	
	// Loop over the key to find the letter pos in the alphabet
	for ( const auto elem : key_ ) {
		if ( charLookup_.find(elem) != charLookup_.end() ) { // Check for repeated letters
			continue;
		}
		size_t index = Alphabet::alphabet.find(elem);
		CaesarCipher cipher { index }; // Create a CaesarCipher using this pos as a key
		charLookup_.insert( std::make_pair(elem,cipher) ); // Insert a std::pair of the letter and CaesarCipher into the lookup
	}
}

std::string VigenereCipher::applyCipher ( const std::string& inputText, const CipherMode cipherMode ) const
{

	/* For each letter in input:
		- Find the corresponding letter in the key,
		  repeating/truncating as required
		  */
	std::string outputText{""};
	for ( size_t i{0} ; i < inputText.length() ; i++ ) {
		const char keyLet = key_[ i % key_.length() ]; 
		const auto cipher = (charLookup_.find( keyLet ))->second; // Find what the shift value for that letter is
		const std::string letterStr{inputText[i]}; 
		outputText += cipher.applyCipher( letterStr, cipherMode );	// Caesar Cipher (De)Encryption	 // Add to the output text
	}
	return outputText;
}