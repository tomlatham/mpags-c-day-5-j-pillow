#ifndef MPAGSCIPHER_CIPER_HPP
#define MPAGSCIPHER_CIPER_HPP

/**
	
*/

class Cipher {
	
	public:
	
	Cipher() = default;
	Cipher(const Cipher& rhs) = default; ///<  
	Cipher(Cipher&& rhs) = default; ///<
	Cipher & operator=(const Cipher rhs) = default; ///< 
	Cipher& operator=(Cipher&& rhs) = default; ///< 
	virtual ~Cipher() = default; ///< Virtual Destructor 
	
	virtual std::string applyCipher( cons std::string& input, const CipherMode mode ) const = 0;
	
	
}

#endif