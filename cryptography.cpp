#include <iostream>

using std::cout;
using std::endl;

class CaesarCipher {
public:
	int KEY;
	CaesarCipher(const int& key) {
		 KEY = key;
	};


	std::string encrypt(const std::string& plaintext) {
		std::string ciphered = "";

		for (int i = 0; i < plaintext.length(); i++) {
			char c = plaintext[i];

			if (c >= 'A' && c <= 'Z') {
				ciphered += (char)('A' + (c - 'A' + KEY) % 26);
			} else if (c >= 'a' && c <= 'z') {
				ciphered += (char)('a' + (c - 'a' + KEY) % 26);
			}
			else if (c >= '0' && c <= '9') {
				ciphered += (char)('0' + (c - '0' + KEY) % 10);
			}
			else {
				ciphered += c;
			}
		}

		return ciphered;
	}

	std::string decrypt(const std::string& ciphered) {
		std::string plaintext = "";

		for (int i = 0; i < ciphered.length(); i++) {
			char c = ciphered[i];
			if (c >= 'A' && c <= 'Z') {
				plaintext += (char)('A' + ((c - 'A' - KEY) % 26 + 26) % 26);
			}
			else if (c >= 'a' && c <= 'z') {
				plaintext += (char)('a' + ((c - 'a' - KEY) % 26 + 26) % 26);
			}
			else if (c >= '0' && c <= '9') {
				plaintext += (char)('0' + ((c - '0' - KEY) % 10 + 10) % 10);
			}
			else {
				plaintext += c;
			}
		}


		return plaintext;
	}


};

class VigenereCipher
{
public:
	std::string KEY;
	VigenereCipher(const std::string& key) {
		KEY = key;
	}

	std::string encrypt(const std::string plaintext) {
		int keylength = KEY.length();
		std::string ciphered = "";

		for (int i = 0; i < plaintext.length(); i++) {
			int keychar = KEY[i % keylength];

			int shift = 0;
			if (keychar >= 'A' && keychar <= 'Z')
				shift = keychar - 'A';
			else if (keychar >= 'a' && keychar <= 'z')
				shift = keychar - 'a';
			else
				shift = keychar;

			char c = plaintext[i];
			if (c >= 'A' && c <= 'Z') {
				ciphered += 'A' + (((c - 'A' + shift) % 26 + 26) % 26);
			} else if (c >= 'a' && c <= 'z') {
				ciphered += 'a' + (((c - 'a' + shift) % 26 + 26) % 26);
			}
			else if (c >= '0' && c <= '9') {
				ciphered += '0' + (((c - '0' + shift) % 10 + 10) % 10);
			}
			else {
				ciphered += c;
			}

		}

		return ciphered;
	}

	std::string decrypt(const std::string& ciphered) {
		int keylength = KEY.length();
		std::string plaintext = "";

		for (int i = 0; i < ciphered.length(); i++) {
			int keychar = KEY[i % keylength];

			int shift = 0;
			if (keychar >= 'A' && keychar <= 'Z')
				shift = keychar - 'A';
			else if (keychar >= 'a' && keychar <= 'z')
				shift = keychar - 'a';
			else
				shift = keychar;

			char c = ciphered[i];
			if (c >= 'A' && c <= 'Z') {
				plaintext += 'A' + (((c - 'A' - shift) % 26 + 26) % 26);
			}
			else if (c >= 'a' && c <= 'z') {
				plaintext += 'a' + (((c - 'a' - shift) % 26 + 26) % 26);
			}
			else if (c >= '0' && c <= '9') {
				plaintext += '0' + (((c - '0' - shift) + 10) % 10);
			}
			else {
				plaintext += c;
			}

		}

		return plaintext;
	}
};
int main(void) {
	CaesarCipher caesar = CaesarCipher(3);
	std::string caesarEncrypted = caesar.encrypt("Hello, this is the Caesar Cipher");
	cout << caesarEncrypted << endl;
	cout << caesar.decrypt(caesarEncrypted) << endl;


	cout << endl;

	VigenereCipher vigenere = VigenereCipher("DUH");
	std::string vigenereEncrypted = vigenere.encrypt("This one is the Vigenere Cipher");
	cout << vigenereEncrypted << endl;
	cout << vigenere.decrypt(vigenereEncrypted) << endl;


	cout << endl;

	return 0;
}
