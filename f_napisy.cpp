//Magdalena Lipka//

#include <string>
using namespace std;

int dlugosc(string s)
{
    int dl = 0;
    while (s[dl] != '\0')
        dl++;
    return dl;
}

int char_to_int(string s, int i)
{
    return s[i] - 48;
}

string P_(string napis, int ilosc, char znak)
{
    string Insert = "";

    for (int i = 0; i < ilosc; i++)
        Insert += znak;

    return Insert;
}

string NormalizujNapis(string napis)
{

    string Napis_Pom;

    string Nowy_Napis = "";
    int i = 0;

    while (napis[i] == ' ')
        i++; // usuwanie pierwszych spacji

    while (napis[i] != '\0')
    {

        while (napis[i] == ' ' && napis[i + 1] == ' ')
            i++; //usuwanie wielokrotnych spacji//

        if ((napis[i - 1] == '.' || napis[i - 1] == ',') && napis[i] != ' ')
            Nowy_Napis += ' '; // dodawanie spacji po znakach interpunkcyjnych//

        Nowy_Napis += napis[i];
        i++;
    }

    //usuwanie spacji przed interpunckja//
    Napis_Pom = Nowy_Napis;
    Nowy_Napis = "";

    i = 0;

    while (Napis_Pom[i] != '\0')
    {
        if (Napis_Pom[i] == ' ' && (Napis_Pom[i + 1] == '.' || Napis_Pom[i + 1] == ','))
            i++;
        Nowy_Napis += Napis_Pom[i];
        i++;
    }

    //usuwanie ostatnich spacji//

    Napis_Pom = Nowy_Napis;
    Nowy_Napis = "";

    int j = dlugosc(Napis_Pom) - 1;
    while (Napis_Pom[j] == ' ')
        j--; // ostatnia nie spacja
    int k = 0;
    while (k <= j)
    {
        Nowy_Napis += Napis_Pom[k];
        k++;
    }
    return Nowy_Napis;
}

string FormatujNapis(string napis, string arg1, string arg2, string arg3)
{
    string Nowy_Napis;
    int i = 0;
    int pom1;
    int pom2;
    int liczba;
    string Napis_Pom;

    while (napis[i] != '\0')
    {
        //cout<<"---" << i << "---"<< napis[i] << endl;

        pom1 = pom2 = 0;
        Napis_Pom = "";
        if (napis[i] == '{')
        {
            i++;
            switch (napis[i])
            {

                //------------------------------

            case 'p':

                i += 2;

                Nowy_Napis += P_(napis, char_to_int(napis, i), napis[i + 2]);

                i += 4;

                break;

                //------------------------------

            case 'u':

                i += 4 + napis[i + 2] - 48;

                break;

                //------------------------------

            case 'U':

                pom2 = char_to_int(napis, i + 2);

                while (pom1 < dlugosc(Nowy_Napis) - pom2)
                {

                    Napis_Pom += Nowy_Napis[pom1];
                    pom1++;
                }

                Nowy_Napis = Napis_Pom;
                i += 4;

                break;

                //------------------------------

            case 'w':

                i += 2;

                if (napis[i] - 48 == 1)
                    Nowy_Napis += arg1;
                else if (napis[i] - 48 == 2)
                    Nowy_Napis += arg2;
                else if (napis[i] - 48 == 3)
                    Nowy_Napis += arg3;

                i += 2;

                break;

                //------------------------------

            case 'W':

                i += 2;

                if (napis[i] - 48 == 1)
                {
                    i += 2;
                    if (dlugosc(arg1) > napis[i] - 48)
                    {
                        while (pom1 < napis[i] - 48)
                        {
                            Nowy_Napis += arg1[pom1];
                            pom1++;
                        }
                    }
                    else if (dlugosc(arg1) < napis[i] - 48)
                    {
                        Nowy_Napis += arg1;
                        while (pom1 < napis[i] - 48 - dlugosc(arg1))
                        {
                            Nowy_Napis += " ";
                            pom1++;
                        }
                    }
                    else
                        Nowy_Napis += arg1;
                }
                //----
                else if (napis[i] - 48 == 2)
                {
                    i += 2;
                    if (dlugosc(arg2) > napis[i] - 48)
                    {
                        while (pom1 < napis[i] - 48)
                        {
                            Nowy_Napis += arg2[pom1];
                            pom1++;
                        }
                    }
                    else if (dlugosc(arg2) < napis[i] - 48)
                    {
                        Nowy_Napis += arg2;
                        while (pom1 < napis[i] - 48 - dlugosc(arg2))
                        {
                            Nowy_Napis += " ";
                            pom1++;
                        }
                    }
                    else
                        Nowy_Napis += arg2;
                }
                //----
                else
                {
                    i += 2;
                    if (dlugosc(arg3) > napis[i] - 48)
                    {
                        while (pom1 < napis[i] - 48)
                        {
                            Nowy_Napis += arg3[pom1];
                            pom1++;
                        }
                    }
                    else if (dlugosc(arg3) < napis[i] - 48)
                    {
                        Nowy_Napis += arg3;
                        while (pom1 < napis[i] - 48 - dlugosc(arg3))
                        {
                            Nowy_Napis += " ";
                            pom1++;
                        }
                    }
                    else
                        Nowy_Napis += arg3;
                }

                i += 2;
                break;
            }
        }
        else
        {
            Nowy_Napis += napis[i];
            i++;
        }
    }

    return Nowy_Napis;
}

//----------------------------------------------------------------------------------------------------

string UsunSlowo(string Oryginalny, int liczba)
{
    string Nowy_Napis;
    int i = 0;
    int pom1;
    int pom2;
    int licznik_slow = 0;
    string Napis_Pom = "";

    string napis = Oryginalny;
    napis += ' ';

    while (napis[i] != '\0' && i < dlugosc(napis))
    {

        if ((i == 0 && napis[i] != ' ') || (napis[i - 1] == ' ' && napis[i] != ' ' && napis[i] != '\0'))
        {

            licznik_slow++;
            if (licznik_slow == liczba)
            {
                while (napis[i] != ' ' && napis[i] != '\0')
                    i++;
                licznik_slow++;
            }
        }
        Nowy_Napis += napis[i];
        i++;
    }

    for (int j = 0; j < dlugosc(Nowy_Napis) - 1; j++)
        Napis_Pom += Nowy_Napis[j];

    Nowy_Napis = Napis_Pom;

    return Nowy_Napis;
}

string NajwiekszeSlowo(string napis)
{
    string Nowy_Napis;
    int i = 0;
    string Max_Napis;
    string Akt_Napis;

    while (napis[i] != ' ' && napis[i] != '\0')
    {
        Max_Napis += napis[i];
        i++;
    }

    while (napis[i] != '\0' && i < dlugosc(napis))
    {
        Akt_Napis = "";

        while (napis[i] != ' ' && napis[i] != '\0')
        {
            Akt_Napis += napis[i];
            i++;
        }

        i++;

        if (Max_Napis < Akt_Napis)
            Max_Napis = Akt_Napis;
    }
    return Max_Napis;
}
