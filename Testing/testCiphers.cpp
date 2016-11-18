//! Unit Tests for MPAGSCipher CaesarCipher Class
#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include <iostream>

#include "CaesarCipher.hpp"
#include "PlayfairCipher.hpp"
#include "VigenereCipher.hpp"
#include "Cipher.hpp"


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
}