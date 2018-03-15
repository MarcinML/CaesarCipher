#include <iostream>
#include <string>
#include <cstdlib>
#include <cmath>

int main()
{

    int key;
    std::string text;
    std::string decryptedText;
    std::string encryptedText;

    std::cout<<"Please enter the key: ";
    std::cin>>key;

    std::cout<<"Enter text to encrypt : ";
    std::cin.ignore();
    std::getline(std::cin, text);

    for(int i=0, n=text.length(); i<n; ++i)
    {
        if(isalpha(text[i]))
        {
            int offset=65;
            if (islower(text[i]))
             offset = 97;

            int cipheredLetter = abs(((reinterpret_cast<int>(text[i] - offset + key) % 26) + offset));

            decryptedText+= cipheredLetter;
        }
        else decryptedText += text[i];
    }
    std::cout<<decryptedText<<std::endl;

    std::cout<<"If you want to encrypt this text press enter vlid key :";
    std::cin>>key;
    for(int i=0, n=decryptedText.length(); i<n; ++i)
    {
        if(isalpha(decryptedText[i]))
        {
            int offset=65;
            if (islower(decryptedText[i]))
             offset = 97;

            int cipheredLetter = ((reinterpret_cast<int>(decryptedText[i] - offset - key) % 26) + offset);

            encryptedText+= cipheredLetter;
        }
        else encryptedText += text[i];
    }
    std::cout<<encryptedText<<std::endl;

    return 0;
}
