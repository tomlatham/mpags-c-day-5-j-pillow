#ifndef MPAGSCIPHER_CIPER_HPP
#define MPAGSCIPHER_CIPER_HPP

/**
	
*/

class Cipher {
	
	public:
	
	Cipher() = default;
	Cipher(const Cipher& rhs) = default; ///< Copy constructor
	Cipher(Cipher&& rhs) = default; ///< Move constructor
	Cipher& operator=(const Cipher& rhs) = default; ///< Copy assignment operator
	Cipher& operator=(Cipher&& rhs) = default; ///< Move assignment operator
	virtual ~Cipher() = default; ///< Virtual Destructor 
	
	virtual std::string applyCipher( const std::string& input, const CipherMode mode ) const = 0;
	
	
};

#endif