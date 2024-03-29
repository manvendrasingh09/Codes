#include<iostream>
#include<string.h>
using namespace std;
int main(){
    char msg[] = "VIT VELLORE";
    char key[] = "CSE";
    int msgLen = strlen(msg), keyLen = strlen(key), i, j;
    char newKey[msgLen], encryptedMsg[msgLen], decryptedMsg[msgLen];
    for(i = 0, j = 0; i < msgLen; ++i, ++j){
        if(j == keyLen)
            j = 0;
        newKey[i] = key[j];
    }
    newKey[i] = '\0';
    for(i = 0; i < msgLen; ++i)
        encryptedMsg[i] = ((msg[i] + newKey[i]) % 26) + 'A';
    encryptedMsg[i] = '\0';
    for(i = 0; i < msgLen; ++i)
        decryptedMsg[i] = (((encryptedMsg[i] - newKey[i]) + 26) % 26) + 'A';
    decryptedMsg[i] = '\0';
    cout<<"Original Message: "<<msg;
    cout<<"\nKey: "<<key;
    cout<<"\nNew Generated Key: "<<newKey;
    cout<<"\nEncrypted Message: "<<encryptedMsg;
    cout<<"\nDecrypted Message: "<<decryptedMsg;
return 0;
}