#include <iostream>
#include <string>
#include <cstdlib>
#include <cmath>
#include <cstring>

int main()
{
    int key;
    std::string text;
    std::string decryptedText;
    std::string encryptedText;

    std::cout<<"Please enter the key: ";
    std::cin>>key;
    key%=26;

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

    std::cout<<"If you want to decrypt this text press enter valid key :";
    std::cin>>key;
    key%=26;

    char message[100], ch;
        int i;

        std::strcpy(message, decryptedText.c_str());

        for(i = 0; message[i] != '\0'; ++i){
            ch = message[i];

            if(ch >= 'a' && ch <= 'z'){
                ch = ch - key;

                if(ch < 'a'){
                    ch = ch + 'z' - 'a' + 1;
                }

                message[i] = ch;
            }
            else if(ch >= 'A' && ch <= 'Z'){
                ch = ch - key;

                if(ch > 'a'){
                    ch = ch + 'Z' - 'A' + 1;
                }

                message[i] = ch;
            }
        }

        std::cout << "Decrypted message: " << message<<std::endl;
    return 0;
}
