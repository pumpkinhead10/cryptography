#include <iostream>

using std::cout;
using std::endl;

class CaesarCipher {
public:
	int KEY;
	CaesarCipher() {
		 KEY = 3;

	};

	void setKey(int key) {
		KEY = key;
	};

	std::string encrypt(std::string& plaintext) {
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

	std::string decrypt(std::string& ciphered) {
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
int main(void) {
	std::string plainText = "Hello, world!";
	CaesarCipher caesar = CaesarCipher();

	std::string cipherText = caesar.encrypt(plainText);
	cout << cipherText << endl;

	std::string decrypted = caesar.decrypt(cipherText);
	cout << decrypted << endl;

	return 0;
}