#include <iostream>
#include <vector>
#include <cmath>

using namespace std;
int calcDeterminant(int a, int b, int c, int d) {
    return (a * d - b * c + 26) % 26;
}
int modInverse(int a, int m) {
    a = a % m;
    for (int x = 1; x < m; x++)
        if ((a * x) % m == 1)
            return x;
    return 1;
}
string hillCipherEncrypt(const string &message, const vector<vector<int>> &keyMatrix) {
    string encryptedText = "";
    int keySize = keyMatrix.size();
    for (int i = 0; i < message.length(); i += keySize) {
        vector<int> plainBlock, cipherBlock;
        for (int j = 0; j < keySize; j++)
            plainBlock.push_back(message[i + j] - 'A');
        for (int j = 0; j < keySize; j++) {
            int sum = 0;
            for (int k = 0; k < keySize; k++)
                sum += keyMatrix[j][k] * plainBlock[k];
            cipherBlock.push_back(sum % 26);
        }
        for (int j = 0; j < keySize; j++)
            encryptedText += (char)(cipherBlock[j] + 'A');
    }
    return encryptedText;
}
string hillCipherDecrypt(const string &encryptedText, const vector<vector<int>> &keyMatrix) {
    string decryptedText = "";
    int keySize = keyMatrix.size();
    int determinant = calcDeterminant(keyMatrix[0][0], keyMatrix[0][1], keyMatrix[1][0], keyMatrix[1][1]);
    int modInverseDet = modInverse(determinant, 26);
    for (int i = 0; i < encryptedText.length(); i += keySize) {
        vector<int> cipherBlock, decryptedBlock;
        for (int j = 0; j < keySize; j++)
            cipherBlock.push_back(encryptedText[i + j] - 'A');
        for (int j = 0; j < keySize; j++) {
            int sum = 0;
            for (int k = 0; k < keySize; k++)
                sum += modInverseDet * (keyMatrix[(k + 1) % keySize][j] * cipherBlock[k] % 26) % 26;
            decryptedBlock.push_back(sum % 26);
        }
        for (int j = 0; j < keySize; j++)
            decryptedText += (char)(decryptedBlock[j] + 'A');
    }
    return decryptedText;
}
int main() {
    vector<vector<int>> keyMatrix = {{6, 24, 1},
                                    {13, 16, 10},
                                    {20, 17, 15}};
    string message = "HELLOHILL";
    string encryptedText = hillCipherEncrypt(message, keyMatrix);
    cout << "Encrypted Text: " << encryptedText << endl;
    string decryptedText = hillCipherDecrypt(encryptedText, keyMatrix);
    cout << "Decrypted Text: " << decryptedText << endl;
    return 0;
}