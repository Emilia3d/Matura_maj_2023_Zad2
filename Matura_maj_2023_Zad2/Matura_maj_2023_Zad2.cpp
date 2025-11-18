// Matura_maj_2023_Zad2.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>
#include <fstream>


using namespace std;

int zad2_1(int n) {
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
        cout << poprz << endl;
    }
    return b;
}

ifstream we("bin_przyklad.txt");
//ifstream we("bin.txt");


int main()
{
    cout << zad2_1(67) << endl;
    cout << zad2_1(245) << endl;

    string liczba;

    for (int i = 0; i < 100; i++) {
        liczba = we.getline;
        zad2_1(stoi(liczba));
    }
  }
