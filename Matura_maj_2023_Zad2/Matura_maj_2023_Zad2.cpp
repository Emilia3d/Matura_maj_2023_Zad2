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

string XOR(string a, string b) {
    // 1. wyrównanie długości
    string wynik = "";
    if (a.size() > b.size()) {
        b = string(a.size() - b.size(), '0') + b;
    }
    else if (b.size() > a.size()) {
        a = string(b.size() - a.size(), '0') + a;
    }
    for (int i=0; i<a.size();i++){
        if (a[i] == b[i]) wynik = wynik + "0";
        else wynik = wynik + "1";
    }
    return wynik;
}
string na_binarny(int n) {
    string s = "";
    if (n == 0) return "0";
    while (n > 0) {
        s = char('0' + n % 2) + s;
        n /= 2;
    }
    return s;
}


int main()
{
    cout << "zad2.1" << endl;
    cout  << liczba_blokow(67) << endl;
    cout  <<liczba_blokow(245) << endl;

    cout << "zad2.2" << endl;
    string binarna;
    int ile2blok = 0;

    for (int i = 0; i < 100; i++) {
        getline(plik, binarna);
        int n = stoi(binarna, nullptr, 2);
        if (liczba_blokow(n) <= 2) ile2blok++;
    }
    cout << ile2blok << endl;

    plik.clear();
    plik.seekg(0);

    cout << "zad2.3" << endl;
    string maksBin;
    int maksInt = 0;
    for (int i = 0; i < 100; i++) {
        getline(plik, binarna);
        int n = stoi(binarna, nullptr, 2);
        if (n > maksInt) {
            maksInt = n;
            maksBin = binarna;
        }
    }
    cout << maksBin << endl;
    plik.clear();
    plik.seekg(0);

    cout << "zad2.4" << endl;
    cout << "przyklad " <<stoi(XOR("0100","0111"), nullptr, 2) << endl;
    cout << "przyklad " << stoi(XOR("0110", "1011"), nullptr, 2) << endl;
    cout << "docelowo " << stoi(XOR(XOR("01111011", "101101"), "00101101"),nullptr,2) << endl;;

    plik.clear();
    plik.seekg(0);
    cout << "zad2.5" << endl;
    while (getline(plik, binarna)) {
        string pol_binarnej = na_binarny(floor(stoi(binarna,nullptr,2) / 2)); //floor nie jest konieczne
        cout << XOR(binarna, pol_binarnej) << endl;
        }
}

