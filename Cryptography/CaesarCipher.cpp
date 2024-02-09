//Implement Caesar Cipher Algorithm
#include<iostream>
using namespace std;

string caesarCipher(string text, int shift)
{
    string result="";
    for(int i=0;i<text.length();i++)
    {
        if(isalpha(text[i]))
        {
            char shifted=islower(text[i])?'a'+(text[i]-'a'+shift)%26: 'A'+(text[i]-'A'+shift)%26;
            result+=shifted;
        }
        else
        {
            result+=text[i];
        }
    }
    return result;
}

string caesarDecipher(string text, int shift)
{
    return caesarCipher(text,26-shift);
}

int main()
{
    string text;
    int shift;
    cout<<"Enter text to Encrypt: ";
    getline(cin,text);
    cout<<"Enter Shift Value: ";
    cin>>shift;
    string entext=caesarCipher(text,shift);
    cout<<"Encrypted Text: "<<entext<<endl;
    string detext=caesarDecipher(entext,shift);
    cout<<"Decrypted Text: "<<detext<<endl;
    return 0;
}