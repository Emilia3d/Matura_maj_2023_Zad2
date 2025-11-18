// Matura_maj_2023_Zad2.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>
#include <fstream>
#include <string>


using namespace std;

//ifstream plik("bin_przyklad.txt");
ifstream plik("bin.txt");

int liczba_blokow(int n) {
    int b = 1;
    int poprz = n % 2;
    n = n / 2;
    while (n > 0) {
        int cyfra = n % 2;
        if (cyfra != poprz) {
            b++;
        }
        n = n / 2;
        poprz = cyfra;
    }
    return b;
}

int main()
{
    cout << "zad2.1"<< endl;
    cout << liczba_blokow(67) << endl;
    cout << liczba_blokow(245) << endl;

    cout << "zad2.2" << endl;
    string liczba;
    int ile2blok=0;

    for (int i = 0; i < 100; i++) {
        getline(plik, liczba);
        int n = stoi(liczba, nullptr, 2);
        if (liczba_blokow(n)<=2) ile2blok++;
    }
    cout << ile2blok;
  }
