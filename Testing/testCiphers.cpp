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


TEST_CASE( "Test encryption and decryption of ciphers", "[Cipher]") {
	
	std::string cc {"10"};
	std::string pc {"hello"};
	std::string vc {"key"};

	// Create list of ciphers
	std::vector<std::unique_ptr<Cipher>> testCiphers = {};
	testCiphers.push_back( cipherFactory( CipherType::Caesar,cc ) );
	testCiphers.push_back( cipherFactory( CipherType::Playfair,pc ) );
	testCiphers.push_back( cipherFactory( CipherType::Vigenere,vc ) );
	
	// Create lists of what encryption and decryption knowns
	std::vector<std::string> encryptVec = { "HELLOWORLD","THEDOGSATONTHEMATS","HELLOWORLD" };
	std::vector<std::string> decryptVec = { "ROVVYGYBVN","QOLCAFULYFTYELPLUT","RIJVSUYVJN" };

	// Run loop over lists
	for (size_t i{0} ; i < testCiphers.size() ; i++) {
		REQUIRE( testCiphers[i]->applyCipher(encryptVec[i],CipherMode::Encrypt) == decryptVec[i] );
		REQUIRE( testCiphers[i]->applyCipher(decryptVec[i],CipherMode::Decrypt) == encryptVec[i] );
	}
}



/*
bool testCipher( const Cipher& cipher, const CipherMode mode, const std::string& inputText, const std::string& outputText)
{
	return cipher.applyCipher( inputText, mode ) == outputText;
}

TEST_CASE("Caesar Cipher encryption", "[Caesar]") {
  CaesarCipher cc{10};
  REQUIRE( testCipher ( cc, CipherMode::Encrypt, "HELLOWORLD", "ROVVYGYBVN") );
}

TEST_CASE("Caesar Cipher decryption", "[Caesar]") {
  CaesarCipher cc{10};
  REQUIRE( testCipher ( cc, CipherMode::Decrypt, "ROVVYGYBVN", "HELLOWORLD") );
}

TEST_CASE("Playfair Cipher encryption", "[Playfair]") {
  PlayfairCipher cc{"hello"};
  REQUIRE( testCipher ( cc, CipherMode::Encrypt, "BOBISSOMESORTOFJUNIORCOMPLEXXENOPHONEONEZEROTHING", "FHIQXLTLKLTLSUFNPQPKETFENIOLVSWLTFIAFTLAKOWATEQOKPPA") );
}

TEST_CASE("Playfair Cipher decryption", "[Playfair]") {
  PlayfairCipher cc{"hello"};
  REQUIRE( testCipher ( cc, CipherMode::Decrypt, "FHIQXLTLKLTLSUFNPQPKETFENIOLVSWLTFIAFTLAKOWATEQOKPPA", "BOBISXSOMESORTOFIUNIORCOMPLEXQXENOPHONEONEZEROTHINGZ") );
}

TEST_CASE("Vigenere Cipher encryption", "[Vigenere]") {
  VigenereCipher cc{"key"};
  REQUIRE( testCipher ( cc, CipherMode::Encrypt, "HELLOWORLD", "RIJVSUYVJN") );
}

TEST_CASE("Vigenere Cipher decryption", "[Vigenere]") {
  VigenereCipher cc{"key"};
  REQUIRE( testCipher ( cc, CipherMode::Decrypt, "RIJVSUYVJN", "HELLOWORLD") );
}*/