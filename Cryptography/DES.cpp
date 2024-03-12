#include <iostream>
#include <string>
#include <cryptopp/des.h>
#include <cryptopp/cryptlib.h>
#include <cryptopp/modes.h>
#include <cryptopp/filters.h>

using namespace std;
using namespace CryptoPP;

int main() {
    byte key[DES::DEFAULT_KEYLENGTH] = {0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07};
    byte iv[DES::BLOCKSIZE] = {0x08, 0x09, 0x0A, 0x0B, 0x0C, 0x0D, 0x0E, 0x0F};
    string plaintext = "0123456789abcdef";
    DES::Encryption desEncryption(key, DES::DEFAULT_KEYLENGTH);
    CBC_Mode_ExternalCipher::Encryption cbcEncryption(desEncryption, iv);
    string ciphertext;
    StringSource(plaintext, true,
                new StreamTransformationFilter(cbcEncryption,
                                            new StringSink(ciphertext)
                )
    );
    cout << "Encrypted Text: " << ciphertext << endl;
    DES::Decryption desDecryption(key, DES::DEFAULT_KEYLENGTH);
    CBC_Mode_ExternalCipher::Decryption cbcDecryption(desDecryption, iv);
    string decryptedtext;
    StringSource(ciphertext, true,
                new StreamTransformationFilter(cbcDecryption,
                                            new StringSink(decryptedtext)
                )
    );
    cout << "Decrypted Text: " << decryptedtext << endl;
    return 0;
}