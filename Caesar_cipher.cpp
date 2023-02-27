#include <iostream>
#include <string>

using namespace std;

// define encryption funciton
void E(string& text, long long int key)
{
    int shift_char; // define shift characters
    for (int i = 0; i < text.length(); i++)
    {
        // check handle space and non-alphabetic characters
        if (!isalpha(text[i])) // if not characters skip to next
        {
            continue;
        }

        // case shift of upper and lower
        // check and calculater shift characters
        if (islower(text[i]))
        {
            shift_char = ((long long int) (text[i] - 'a') + key + 26) % 26;
        }
        else if (isupper(text[i]))
        {
            shift_char = ((long long int) (text[i] - 'A') + key + 26) % 26;
        }

        if (shift_char < 0) 
        {
            shift_char += 26;
        }

        if (islower(text[i]))
        {
            text[i] = 'a' + shift_char;
        }
        else if (isupper(text[i]))
        {
            text[i] = 'A' + shift_char;
        }
    }
}

// define decryption function
void D(string& text, long long int key)
{
    int shift_char;
    for (int i = 0; i < text.length(); i++)
    {
        // check handle space and non-alphabetic characters
        if (!isalpha(text[i]))
        {
            continue;
        }

        // case shift of upper and lower
        // check and calculater shift characters
        if (islower(text[i]))
        {
            shift_char = ((long long int) (text[i] - 'a') - key + 26) % 26;
        }
        else if (isupper(text[i]))
        {
            shift_char = ((long long int) (text[i] - 'A') - key + 26) % 26;
        }

        if (shift_char < 0) 
        {
            shift_char += 26;
        }
        if (islower(text[i]))
        {
            text[i] = 'a' + shift_char;
        }
        else if (isupper(text[i]))
        {
            text[i] = 'A' + shift_char;
        }
    }
}

int main()
{
    char choice;
    cout << "Encryption(E) or Decryption(D) : ";
    cin >> choice;

    cin.ignore();
    string text;
    cout << "Plaintext : ";
    getline(cin, text);

    long long int key;
    cout << "Key : ";

    key = key % 26;

    if (choice == 'E')
    {
        E(text, key);
        cout << "Ciphertext : " << text << "\n";
    }
    else if (choice == 'D')
    {
        D(text, key);
        cout << "Decryption : " << text << "\n";
    }

    return 0;
}