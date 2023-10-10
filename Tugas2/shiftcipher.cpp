/*
Nama        : Aliya Rahmania
NPM         : 140810210005
Kelas       : Kriptografi (A)
dekripsi    : Enkripsi Dekripsi dengan Shift Cipher
*/

#include <iostream>
using namespace std;

string enkripsi(int key, char str[])
{
    char temp;  // temp akan diisi oleh char sementara
    for (int i = 0; str[i] != '\0'; i++)
    {
        temp = str[i];
        if (temp >= 'a' && temp <= 'z')
        {
            temp = temp + key;  // char ditambahkan dengan key
            if (temp > 'z')
            {
                temp = temp - 'z' + 'a' - 1;    // jika char lebih dari 'z' , maka posisi akan disesuaikan
            }
            str[i] = temp;  // variable str akan diisi dengan char dari temp
        }
        else if (temp >= 'A' && temp <= 'Z')    // sama dengan yg diatas, namun ini operasi untuk capslock
        {
            temp = temp + key;
            if (temp > 'Z')
            {
                temp = temp - 'Z' + 'A' - 1;
            }
            str[i] = temp;
        }
    }
    return str;
}

string dekripsi(int key, char str[])
{
    char temp;
    for (int i = 0; str[i] != '\0'; i++)
    {
        temp = str[i];
        if (temp >= 'a' && temp <= 'z') 
        {
            temp = temp - key;  // char dikurangi dengan key
            if (temp > 'z')
            {
                temp = temp - 'z' + 'a' - 1;
            }
            str[i] = temp;
        }
        else if (temp >= 'A' && temp <= 'Z')
        {
            temp = temp - key;
            if (temp > 'Z')
            {
                temp = temp - 'Z' + 'A' - 1;
            }
            str[i] = temp;
        }
    }
    return str;
}

int main()
{
    int key;
    int menu;
    char str[99];

    do
    {
        cout << "=== PROGRAM SHIFT CIPHER ===\n";
        cout << "1. Enkripsi\n";
        cout << "2. Dekripsi\n";
        cout << "3. Keluar\n";
        cout << "Masukkan Pilihan : ";
        cin >> menu;
        cout << endl;

        switch (menu)
        {
        case 1:
            cout << "Masukkan Kata : ";
            cin.ignore(100, '\n');
            cin.getline(str, sizeof(str));
            cout << "Masukkan Key : ";
            cin >> key;
            cout << "Hasil Enkripsi : " << enkripsi(key, str) << endl;
            system("pause");
            system("cls");
            break;
        case 2:
            cout << "Masukkan Kata : ";
            cin.ignore(100, '\n');
            cin.getline(str, sizeof(str));
            cout << "Masukkan Key : ";
            cin >> key;
            cout << "Hasil Dekripsi : " << dekripsi(key, str) << endl;
            system("pause");
            system("cls");
            break;
        case 3:
            cout << "Terima kasih! Sampai jumpa!\n";
            break;
        default:
            cout << "Input Salah.\n\n";
            break;
        }
    } while (menu != 3);
}