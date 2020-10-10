//Magdalena Lipka//
#include <iostream>
using namespace std;

double Tab_oryginalna[10000];
double Tab_nowa[10000];
double Dane_rozkladu[21];
double Tab_maski[21];
double Tab_filtr[10000];
int n;      // ilosc elementow wczytywanej tablicy //
int iem_dr; // ilosc elementow maski = dlugosc rozkladu //
int odstep_maski, indeks_p, indeks_k, ilosc_el_filtr;
char rodzaj_filtra;
int ak_indeks_filtr, indeks_p_maski, ak_indeks_nowa;
double srednia;
int srodek_maski;

int main()
{
    //WCZYTYWANIE//
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> Tab_oryginalna[i];
    }
    cin >> iem_dr;
    for (int i = 0; i < iem_dr; i++)
    {
        cin >> Dane_rozkladu[i];
    }
    cin >> odstep_maski >> indeks_p >> indeks_k >> rodzaj_filtra;

    //DLUGOSC FILTRA//
    if (indeks_p > indeks_k)
        ilosc_el_filtr = n - indeks_p + indeks_k + 1;
    else
        ilosc_el_filtr = indeks_k - indeks_p + 1;

    //TABLICA FILTRA//
    int j = 0;
    for (int i = 0; i < n; i++)
    {
        if (indeks_p > indeks_k)
        {
            if (i >= indeks_p || i <= indeks_k)
            {
                Tab_filtr[j] = Tab_oryginalna[i];
                j++;
            }
        }
        else
        {
            if (i >= indeks_p && i <= indeks_k)
            {
                Tab_filtr[j] = Tab_oryginalna[i];
                j++;
            }
        }
    }

    if (rodzaj_filtra == 'r')
    {
        //-----------------------------------------------------------R------------------------------------------------------------//
        for (int i = 0; i < ilosc_el_filtr; i++)
        {
            //INDEKS P FILTR//
            indeks_p_maski = (i - ((iem_dr - 1) * (odstep_maski + 1)) / 2) % ilosc_el_filtr;
            if (indeks_p_maski < 0)
                indeks_p_maski += ilosc_el_filtr;

            //TABLICA MASKI I SREDNIA//
            srednia = 0;
            for (int j = 0; j < iem_dr; j++)
            {
                Tab_maski[j] = Tab_filtr[(indeks_p_maski + (odstep_maski + 1) * j) % ilosc_el_filtr];
                srednia += Tab_maski[j];
            }
            srednia /= iem_dr;
            Tab_nowa[i] = srednia;
        }
        //ZLOZENIE TABLICY NOWEJ I ORYGINALEJ TO WYJSCIOWEJ//
        j = 0;
        for (int i = 0; i < n; i++)
        {
            if (indeks_p > indeks_k)
            {
                if (i >= indeks_p || i <= indeks_k)
                {
                    Tab_oryginalna[i] = Tab_nowa[j];
                    j++;
                }
            }
            else
            {
                if (i >= indeks_p && i <= indeks_k)
                {
                    Tab_oryginalna[i] = Tab_nowa[j];
                    j++;
                }
            }
        }
    }
    else if (rodzaj_filtra == 'm')
    {
        //-----------------------------------------------------------M------------------------------------------------------------//
        for (int i = 0; i < ilosc_el_filtr; i++)
        {
            //INDEKS P FILTR//
            indeks_p_maski = (i - ((iem_dr - 1) * (odstep_maski + 1)) / 2) % ilosc_el_filtr;
            if (indeks_p_maski < 0)
                indeks_p_maski += ilosc_el_filtr;

            //TABLICA MASKI I SREDNIA//
            for (int j = 0; j < iem_dr; j++)
            {
                Tab_maski[j] = Tab_filtr[(indeks_p_maski + (odstep_maski + 1) * j) % ilosc_el_filtr];
            }
            //SORTOWANIE TABLICY MASKI//
            int klucz, ji;
            for (int a = 1; a < iem_dr; a++)
            {
                klucz = Tab_maski[a];
                ji = a - 1;
                while (ji >= 0 && Tab_maski[ji] > klucz)
                {
                    Tab_maski[ji + 1] = Tab_maski[ji];
                    ji--;
                }
                Tab_maski[ji + 1] = klucz;
            }
            Tab_nowa[i] = Tab_maski[(iem_dr - 1) / 2];
        }
        //ZLOZENIE TABLICY NOWEJ I ORYGINALEJ TO WYJSCIOWEJ//
        j = 0;
        for (int i = 0; i < n; i++)
        {
            if (indeks_p > indeks_k)
            {
                if (i >= indeks_p || i <= indeks_k)
                {
                    Tab_oryginalna[i] = Tab_nowa[j];
                    j++;
                }
            }
            else
            {
                if (i >= indeks_p && i <= indeks_k)
                {
                    Tab_oryginalna[i] = Tab_nowa[j];
                    j++;
                }
            }
        }
    }
    else if (rodzaj_filtra == 'w')
    {
        //-----------------------------------------------------------W------------------------------------------------------------//
        for (int i = 0; i < ilosc_el_filtr; i++)
        {
            //INDEKS P FILTR//
            indeks_p_maski = (i - ((iem_dr - 1) * (odstep_maski + 1)) / 2) % ilosc_el_filtr;
            if (indeks_p_maski < 0)
                indeks_p_maski += ilosc_el_filtr;

            //TABLICA MASKI I SREDNIA//
            srednia = 0;
            for (int j = 0; j < iem_dr; j++)
            {
                Tab_maski[j] = Tab_filtr[(indeks_p_maski + (odstep_maski + 1) * j) % ilosc_el_filtr] * Dane_rozkladu[j];
                srednia += Tab_maski[j];
            }
            Tab_nowa[i] = srednia;
        }
        //ZLOZENIE TABLICY NOWEJ I ORYGINALEJ TO WYJSCIOWEJ//
        j = 0;
        for (int i = 0; i < n; i++)
        {
            if (indeks_p > indeks_k)
            {
                if (i >= indeks_p || i <= indeks_k)
                {
                    Tab_oryginalna[i] = Tab_nowa[j];
                    j++;
                }
            }
            else
            {
                if (i >= indeks_p && i <= indeks_k)
                {
                    Tab_oryginalna[i] = Tab_nowa[j];
                    j++;
                }
            }
        }
    }

    for (int i = 0; i < n; i++)
        cout << (double)((int)((Tab_oryginalna[i]) * 100)) / 100 << " ";
    return 0;
}