//! Unit Tests for MPAGSCipher CaesarCipher Class
#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include <iostream>
#include <memory>
#include <vector>

#include "CaesarCipher.hpp"
#include "PlayfairCipher.hpp"
#include "VigenereCipher.hpp"
#include "Cipher.hpp"
#include "CipherFactory.hpp"

bool testCipher( const Cipher& cipher, const CipherMode mode, const std::string& inputText, const std::string& outputText )
{
  return cipher.applyCipher( inputText, mode ) == outputText;
}

TEST_CASE( "Test encryption and decryption of ciphers", "[Cipher]") {
	
	std::string cc {"10"};
	std::string pc {"hello"};
	std::string vc {"key"};

	// Create list of ciphers
	std::vector<std::unique_ptr<Cipher>> testCiphers = {};
	testCiphers.push_back( cipherFactory( CipherType::Caesar,cc ) );
	testCiphers.push_back( cipherFactory( CipherType::Playfair,pc ) );
	testCiphers.push_back( cipherFactory( CipherType::Vigenere,vc ) );
	
	// Create lists of encryption and decryption knowns. 
	std::vector<std::string> encryptVec = { "HELLOWORLD","BOBISSOMESORTOFJUNIORCOMPLEXXENOPHONEONEZEROTHING","HELLOWORLD" };
	std::vector<std::string> encryptAnsVec = { "ROVVYGYBVN","FHIQXLTLKLTLSUFNPQPKETFENIOLVSWLTFIAFTLAKOWATEQOKPPA","RIJVSUYVJN" };
	std::vector<std::string> decryptAnsVec = {"HELLOWORLD","BOBISXSOMESORTOFIUNIORCOMPLEXQXENOPHONEONEZEROTHINGZ","HELLOWORLD" };
	
	// Run loop over lists
	for (size_t i{0} ; i < testCiphers.size() ; i++) {
		REQUIRE( testCiphers[i] );
		REQUIRE( testCipher( *testCiphers[i], CipherMode::Encrypt, encryptVec[i],    encryptAnsVec[i]) );
		REQUIRE( testCipher( *testCiphers[i], CipherMode::Decrypt, encryptAnsVec[i], decryptAnsVec[i]) );
	}
}
