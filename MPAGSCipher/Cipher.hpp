#ifndef MPAGSCIPHER_CIPHER_HPP
#define MPAGSCIPHER_CIPHER_HPP

// Standard library includes
#include <string>

// Our project headers
#include "CipherMode.hpp"

/**
 * \file Cipher.hpp
 * \brief Contains the declaration of the purely abstract Cipher base class
 */

/**
 * \class Cipher
 * \brief Defines the interface for a cipher
 *
 * A purely abstract base class that defines the interface for a cipher
 *
 * It can be used as follows:
 * \code{.cpp}
 * class MyCipher : public Cipher {...};
 * \endcode
 */
class Cipher {
	
	public:
	
	Cipher() = default; ///< Default constructor
	Cipher(const Cipher& rhs) = default; ///< Copy constructor
	Cipher(Cipher&& rhs) = default; ///< Move constructor
	Cipher& operator=(const Cipher& rhs) = default; ///< Copy assignment operator
	Cipher& operator=(Cipher&& rhs) = default; ///< Move assignment operator
	virtual ~Cipher() = default; ///< Virtual Destructor 
	
	/**
	 * Apply the cipher to the provided text
	 *
	 * \param inputText the text to encrypt or decrypt
	 * \param cipherMode whether to encrypt or decrypt the input text
	 * \return the result of applying the cipher to the input text
	 */
	virtual std::string applyCipher( const std::string& inputText, const CipherMode cipherMode ) const = 0;
};

#endif
