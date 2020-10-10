#include <iostream>
#include <fstream>
#include <string>

//Magdalena Lipka//
using namespace std;

// STRUKTURY ----------------------------------------------------------------//

struct Trinity
{
    bool ToF;
    unsigned int Unsigned_Character;
    float Real_Number;
};

struct Data
{
    int Integer;
    string Word;
    int Character;
    Trinity First_Set;
    Trinity Second_Set;
    Trinity Third_Set;
    Trinity Fourth_Set;
};

Data SET;
Data Maksimum;
float CURSOR;

// ZEROWANIE ---------------------------------------------------------------------//

void ZeroSET()
{
    SET.Integer = 0;
    SET.Word = "";
    SET.Character = 0;
    SET.First_Set.ToF = 0;
    SET.First_Set.Unsigned_Character = 0;
    SET.First_Set.Real_Number = 0;
    SET.Second_Set.ToF = 0;
    SET.Second_Set.Unsigned_Character = 0;
    SET.Second_Set.Real_Number = 0;
    SET.Third_Set.ToF = 0;
    SET.Third_Set.Unsigned_Character = 0;
    SET.Third_Set.Real_Number = 0;
    SET.Fourth_Set.ToF = 0;
    SET.Fourth_Set.Unsigned_Character = 0;
    SET.Fourth_Set.Real_Number = 0;
}

void ZeroMaksimum()
{
    Maksimum.Integer = 2147483647;
    Maksimum.Word = "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
    Maksimum.Character = 0;
    Maksimum.First_Set.ToF = 0;
    Maksimum.First_Set.Unsigned_Character = 0;
    Maksimum.First_Set.Real_Number = 0;
    Maksimum.Second_Set.ToF = 0;
    Maksimum.Second_Set.Unsigned_Character = 0;
    Maksimum.Second_Set.Real_Number = 0;
    Maksimum.Third_Set.ToF = 0;
    Maksimum.Third_Set.Unsigned_Character = 0;
    Maksimum.Third_Set.Real_Number = 0;
    Maksimum.Fourth_Set.ToF = 0;
    Maksimum.Fourth_Set.Unsigned_Character = 0;
    Maksimum.Fourth_Set.Real_Number = 0;
}

//  WYPISZ DANE ----------------------------------------------------------------------//

void Print(Data Set)
{
    cout << Set.Integer << " " << Set.Word << " " << Set.Character << " " << Set.First_Set.ToF << " " << Set.First_Set.Unsigned_Character << " " << Set.First_Set.Real_Number << " " << Set.Second_Set.ToF << " " << Set.Second_Set.Unsigned_Character << " " << Set.Second_Set.Real_Number << " " << Set.Third_Set.ToF << " " << Set.Third_Set.Unsigned_Character << " " << Set.Third_Set.Real_Number << " " << Set.Fourth_Set.ToF << " " << Set.Fourth_Set.Unsigned_Character << " " << Set.Fourth_Set.Real_Number;
}

// WCZYTYWANIE --------------------------------------------------------------------------//

void Read_Data(string Source_File_Name)
{
    ifstream source(Source_File_Name.c_str());

    source.seekg(CURSOR);

    string Sth;

    source >> SET.Integer;
    getline(source, Sth);
    getline(source, SET.Word);
    source >> SET.Character >> SET.First_Set.ToF >> SET.First_Set.Unsigned_Character >> SET.First_Set.Real_Number >> SET.Second_Set.ToF >> SET.Second_Set.Unsigned_Character >> SET.Second_Set.Real_Number >> SET.Third_Set.ToF >> SET.Third_Set.Unsigned_Character >> SET.Third_Set.Real_Number >> SET.Fourth_Set.ToF >> SET.Fourth_Set.Unsigned_Character >> SET.Fourth_Set.Real_Number;

    CURSOR = source.tellg();
}

// ZAPIS --------------------------------------------------------------------------------//

void Save_Data(string Save_File_Name)
{
    ofstream save(Save_File_Name.c_str(), ios_base::app);

    save << SET.Integer << "\n"
         << SET.Word << "\n"
         << SET.Character << " " << SET.First_Set.ToF << " " << SET.First_Set.Unsigned_Character << " " << SET.First_Set.Real_Number << " " << SET.Second_Set.ToF << " " << SET.Second_Set.Unsigned_Character << " " << SET.Second_Set.Real_Number << " " << SET.Third_Set.ToF << " " << SET.Third_Set.Unsigned_Character << " " << SET.Third_Set.Real_Number << " " << SET.Fourth_Set.ToF << " " << SET.Fourth_Set.Unsigned_Character << " " << SET.Fourth_Set.Real_Number << "\n";
}

// KONIEC PLIKU ---------------------------------------------------------------------//

float Len(string File_Name)
{

    ifstream file(File_Name.c_str());
    file.seekg(-2, ios::end);
    return file.tellg();
}

// CZYSZCZENIE PLIKU -----------------------------------------------------------//

void Clear_File(string File)
{
    ofstream clear(File.c_str(), ios::trunc);
    clear.close();
}

// CZY PLIK JEST PUSTY ----------------------------------------------------------//

bool Empty(string File_Name)
{
    bool em;
    ifstream file(File_Name.c_str());
    file.seekg(0, ios::end);
    if (file.tellg() == 0)
        em = 1;
    else
        em = 0;
    return em;
}

// CZY ZESTAWY ROWNE -----------------------------------------------------------//

bool Equal(Data SET1, Data SET2)
{
    bool eq;
    if (SET1.Integer != SET2.Integer || SET1.Word != SET2.Word || SET1.Character != SET2.Character || SET1.First_Set.ToF != SET2.First_Set.ToF || SET1.First_Set.Unsigned_Character != SET2.First_Set.Unsigned_Character || SET1.First_Set.Real_Number != SET2.First_Set.Real_Number || SET1.Second_Set.ToF != SET2.Second_Set.ToF || SET1.Second_Set.Unsigned_Character != SET2.Second_Set.Unsigned_Character || SET1.Second_Set.Real_Number != SET2.Second_Set.Real_Number || SET1.Third_Set.ToF != SET2.Third_Set.ToF || SET1.Third_Set.Unsigned_Character != SET2.Third_Set.Unsigned_Character || SET1.Third_Set.Real_Number != SET2.Third_Set.Real_Number || SET1.Fourth_Set.ToF != SET2.Fourth_Set.ToF || SET1.Fourth_Set.Unsigned_Character != SET2.Fourth_Set.Unsigned_Character || SET1.Fourth_Set.Real_Number != SET2.Fourth_Set.Real_Number)
        eq = 0;
    else
        eq = 1;
    return eq;
}

// PRZEPISZ PLIK -----------------------------------------------------------//

void Copy(string Source_File, string Save_File)
{
    ifstream source(Source_File.c_str());
    ofstream save(Save_File.c_str());

    CURSOR = 0;
    while (CURSOR < Len(Source_File) && CURSOR >= 0)
    {
        Read_Data(Source_File);
        Save_Data(Save_File);
    }
}

// SORT COUNT ---------------------------------------------------------------------------//

void SortCount(string Source_File_Name, string Handy_File_1, string Handy_File_2)
{
}

// SORT INT -----------------------------------------------------------------------------//

void SortInt(string Source_File_Name, string Handy_File_1, string Handy_File_2)
{

    ZeroSET();
    ZeroMaksimum();

    Clear_File(Handy_File_2);
    Clear_File(Handy_File_1);

    ifstream source(Source_File_Name.c_str());
    ofstream save(Handy_File_1.c_str());

    while (Len(Source_File_Name) >= 27)
    {
        CURSOR = 0;

        ZeroMaksimum();

        CURSOR = 0;

        while (CURSOR < Len(Source_File_Name) && CURSOR >= 0)
        {
            ZeroSET();
            Read_Data(Source_File_Name);
            if (SET.Integer < Maksimum.Integer)
                Maksimum = SET;
        }
        SET = Maksimum;
        Save_Data(Handy_File_2);

        CURSOR = 0;
        bool ifif = 1;
        while (CURSOR < Len(Source_File_Name) && CURSOR >= 0)
        {
            ZeroSET();
            Read_Data(Source_File_Name);
            if (!Equal(SET, Maksimum) && ifif)
            {
                Save_Data(Handy_File_1);
                ifif = 0;
            }
        }
        Clear_File(Source_File_Name);
        Copy(Handy_File_1, Source_File_Name);
        Clear_File(Handy_File_1);
    }

    Clear_File(Source_File_Name);
    Copy(Handy_File_2, Source_File_Name);
}

// SORT STRING ---------------------------------------------------------------------------//

void SortString(string Source_File_Name, string Handy_File_1, string Handy_File_2)
{
    Clear_File(Handy_File_2);
    Clear_File(Handy_File_1);
    ZeroSET();
    ZeroMaksimum();

    ifstream source(Source_File_Name.c_str());
    ofstream save(Handy_File_1.c_str());

    while (Len(Source_File_Name) >= 27)
    {
        CURSOR = 0;

        ZeroMaksimum();

        CURSOR = 0;

        while (CURSOR < Len(Source_File_Name) && CURSOR >= 0)
        {
            ZeroSET();
            Read_Data(Source_File_Name);
            if (SET.Word < Maksimum.Word)
                Maksimum = SET;
        }
        SET = Maksimum;
        Save_Data(Handy_File_2);

        CURSOR = 0;
        bool ifif = 1;
        while (CURSOR < Len(Source_File_Name) && CURSOR >= 0)
        {
            ZeroSET();
            Read_Data(Source_File_Name);
            if (!Equal(SET, Maksimum) && ifif)
            {
                Save_Data(Handy_File_1);
                ifif = 0;
            }
        }
        Clear_File(Source_File_Name);
        Copy(Handy_File_1, Source_File_Name);
        Clear_File(Handy_File_1);
    }

    Clear_File(Source_File_Name);
    Copy(Handy_File_2, Source_File_Name);
}

// SYMMETRIC DIFFERENCE -------------------------------------------------------------------//

void SymmetricDifference(string Source_File_Name, string Handy_File_1, string Handy_File_2)
{
}

// MAIN -----------------------------------------------------------------------------------//

int main()
{

    CURSOR = 0;

    SortString("plik.txt", "pom1.txt", "pom2.txt");

    //Copy("plik.txt", "pom1.txt");
    //CURSOR = 0;
    //Copy("pom1.txt", "pom2.txt");
    //CURSOR = 0;
    //Copy("pom2.txt", "plik.txt");

    return 0;
}