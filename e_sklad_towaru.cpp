//MAGDALENA LIPKA//

#include <iostream>
using namespace std;

string polecenie;

struct place
{
    unsigned short etykieta;
    unsigned short ilosc;
};

struct shelf
{
    unsigned short ilosc;
    place Places[128];
};

struct rack
{
    unsigned long long suma;
    unsigned short ilosc;
    shelf Shelves[128];
};

struct warehouse
{
    unsigned long long suma;
    unsigned short ilosc;
    rack Racks[128];
    shelf HandyShelf;
};

struct depot
{
    unsigned short ilosc;
    warehouse Warehouses[128];
    shelf HandyShelf;
    rack HandyRack;
};

depot DEPOT;

//////////////FUNKCJE////////////////

void SET_AP(unsigned short wb, unsigned short rb, unsigned short sb, unsigned short pe)
{
    if (wb < 128 && rb < 128 && sb < 128 && pe <= 128)
    {
        for (unsigned short i = 0; i < pe; i++)
        {
            if (i >= DEPOT.Warehouses[wb].Racks[rb].Shelves[sb].ilosc)
            {
                DEPOT.Warehouses[wb].Racks[rb].Shelves[sb].Places[i].ilosc = 0;
                DEPOT.Warehouses[wb].Racks[rb].Shelves[sb].Places[i].etykieta = 100;
            }
        }
        for (unsigned short i = pe; i <= DEPOT.Warehouses[wb].Racks[rb].Shelves[sb].ilosc; i++)
        {
            DEPOT.Warehouses[wb].Racks[rb].Shelves[sb].Places[i].ilosc = 0;
            DEPOT.Warehouses[wb].Racks[rb].Shelves[sb].Places[i].etykieta = 100;
        }
        DEPOT.Warehouses[wb].Racks[rb].Shelves[sb].ilosc = pe;
    }
    else
        cout << endl
             << "error";
}

void SET_AS(unsigned short wb, unsigned short rb, unsigned short se, unsigned short pe)
{
    if (wb < 128 && rb < 128 && se <= 128 && pe <= 128)
    {
        for (unsigned short i = 0; i < se; i++)
        {
            if (se < DEPOT.Warehouses[wb].Racks[rb].ilosc)
            {
                DEPOT.Warehouses[wb].Racks[rb].Shelves[i].ilosc = pe;
                for (unsigned short j = 0; j < pe; j++)
                {
                    DEPOT.Warehouses[wb].Racks[rb].Shelves[i].Places[j].ilosc = 0;
                    DEPOT.Warehouses[wb].Racks[rb].Shelves[i].Places[j].etykieta = 100;
                }
            }
            else
                SET_AP(wb, rb, se, pe);
        }
        DEPOT.Warehouses[wb].Racks[rb].ilosc = se;
    }
    else
        cout << endl
             << "error";
}

void SET_AR(unsigned short wb, unsigned short re, unsigned short se, unsigned short pe)
{
    if (wb < 128 && re <= 128 && se <= 128 && pe <= 65535)
    {
    }
    else
        cout << endl
             << "error";
}

void SET_AW(unsigned short we, unsigned short re, unsigned short se, unsigned short pe)
{
}

void SET_HW(unsigned short w, unsigned short p)
{
}

void SET_HR(unsigned short s, unsigned short p)
{
}

void SET_HS(unsigned short p)
{
}

void PUT_W(unsigned short w, unsigned short r, unsigned short s, unsigned short p, unsigned short A)
{
}

void PUT_H(unsigned short w, unsigned short p, unsigned short a)
{
}

void PUT_R(unsigned short s, unsigned short p, unsigned short a)
{
}

void PUT_S(unsigned short p, unsigned short A)
{
}

void FILL(unsigned short w, unsigned short r, unsigned short s, unsigned short p, unsigned short a)
{

    if (w <= 128 && r <= 128 && s <= 128 && p <= 128 && a < 65535)
    {

        DEPOT.ilosc = w - 1;
        DEPOT.HandyRack.ilosc = s - 1;
        DEPOT.HandyShelf.ilosc = p - 1;

        DEPOT.HandyShelf.ilosc = a;
        for (unsigned short i = 0; i < p; i++)
        {
            DEPOT.HandyShelf.Places[i].etykieta = 100;
        }

        for (unsigned short i = 0; i < s; i++)
        {
            DEPOT.HandyRack.Shelves[i].ilosc = a;
            for (unsigned short j = 0; j < p; j++)
            {
                DEPOT.HandyRack.Shelves[i].Places[j].etykieta = 100;
                DEPOT.HandyRack.suma += a;
                DEPOT.HandyRack.Shelves[i].Places[j].ilosc += a;
            }
        }

        for (unsigned short i = 0; i < w; i++)
        {
            DEPOT.Warehouses[i].ilosc = w - 1;
            for (unsigned short j = 0; j < r; j++)
            {
                DEPOT.Warehouses[i].Racks[j].ilosc = r - 1;
                for (unsigned short k = 0; k < s; k++)
                {
                    DEPOT.Warehouses[i].Racks[j].Shelves[k].ilosc = s - 1;
                    for (unsigned short l = 0; l < p; l++)
                    {
                        DEPOT.Warehouses[i].Racks[j].Shelves[k].Places[l].ilosc = a;
                        DEPOT.Warehouses[i].Racks[j].Shelves[k].Places[l].etykieta = 100;
                        DEPOT.Warehouses[i].suma += a;
                        DEPOT.Warehouses[i].Racks[j].suma += a;
                    }
                }
            }

            for (unsigned short l = 0; l < p; l++)
            {
                DEPOT.Warehouses[i].HandyShelf.Places[l].ilosc = a;
                DEPOT.Warehouses[i].HandyShelf.Places[l].etykieta = 100;
                DEPOT.Warehouses[i].ilosc += a;
                DEPOT.Warehouses[i].HandyShelf.ilosc += a;
            }
        }
    }
    else
        cout << endl
             << "error";
}

void POP_W(unsigned short w, unsigned short r, unsigned short s, unsigned short p, unsigned short a)
{
}

void POP_H(unsigned short w, unsigned short p, unsigned short a)
{
}

void POP_R(unsigned short s, unsigned short p, unsigned short a)
{
}

void POP_S(unsigned short p, unsigned short a)
{
}

void MOV_W(unsigned short wb, unsigned short rb, unsigned short sb, unsigned short we, unsigned short re, unsigned short se, unsigned short p, unsigned short a)
{
}

void MOV_H(unsigned short w, unsigned short r, unsigned short s, unsigned short p, unsigned short a)
{
}

void MOV_R(unsigned short w, unsigned short r, unsigned short sb, unsigned short se, unsigned short p, unsigned short a)
{
}

void MOV_S(unsigned short s, unsigned short p, unsigned short a)
{
}

void GET_E()
{
    unsigned long long suma = 0;
    for (unsigned short i = 0; i < 128; i++)
    {
        suma += DEPOT.Warehouses[i].suma;
    }
    cout << endl
         << suma;
}

void GET_W(unsigned short w)
{
    if (w < DEPOT.ilosc)
        cout << endl
             << DEPOT.Warehouses[w].suma;
    else
        cout << endl
             << "error";
}

void GET_RW(unsigned short w, unsigned short r)
{
    if (w < DEPOT.ilosc && r < DEPOT.Warehouses[w].ilosc)
        cout << endl
             << DEPOT.Warehouses[w].Racks[r].suma;
    else
        cout << endl
             << "error";
}

void GET_RH()
{
    cout << endl
         << DEPOT.HandyRack.ilosc;
}

void GET_SW(unsigned short w, unsigned short r, unsigned short s)
{
    unsigned long long suma = 0;
    if (w < DEPOT.ilosc && r < DEPOT.Warehouses[w].ilosc && s < DEPOT.Warehouses[w].Racks[r].ilosc)
    {
        for (unsigned short i = 0; i < 128; i++)
        {
            suma += DEPOT.Warehouses[w].Racks[r].Shelves[s].Places[i].ilosc;
        }
        cout << endl
             << suma;
    }
    else
        cout << endl
             << "error";
}

void GET_SH(unsigned short w)
{
    unsigned long long suma = 0;
    if (w < DEPOT.ilosc)
    {
        for (unsigned short i = 0; i < 128; i++)
        {
            suma += DEPOT.Warehouses[w].HandyShelf.Places[i].ilosc;
        }
        cout << endl
             << suma;
    }
    else
        cout << endl
             << "error";
}

void GET_SR(unsigned short s)
{
    unsigned long long suma = 0;
    if (s < DEPOT.HandyRack.ilosc)
    {
        for (unsigned short i = 0; i < 128; i++)
        {
            suma += DEPOT.HandyRack.Shelves[s].Places[i].ilosc;
        }
        cout << endl
             << suma;
    }
    else
        cout << endl
             << "error";
}

void GET_S()
{
    unsigned long long suma = 0;
    for (unsigned short i = 0; i < 128; i++)
    {
        suma += DEPOT.HandyShelf.Places[i].ilosc;
    }
    cout << endl
         << suma;
}

void SET_LW(unsigned short w, unsigned short r, unsigned short s, unsigned short p, unsigned short dd)
{
    if (dd >= 0 && dd <= 99 && w <= DEPOT.ilosc && r <= DEPOT.Warehouses[w].ilosc && s <= DEPOT.Warehouses[w].Racks[r].ilosc && p <= DEPOT.Warehouses[w].Racks[r].Shelves[s].ilosc)
        DEPOT.Warehouses[w].Racks[r].Shelves[s].Places[p].etykieta = dd;
    else
        cout << endl
             << "error";
}

void SET_LH(unsigned short w, unsigned short p, unsigned short dd)
{
    if (dd >= 0 && dd <= 99 && w <= DEPOT.ilosc && p <= DEPOT.Warehouses[w].HandyShelf.ilosc)
        DEPOT.Warehouses[w].HandyShelf.Places[p].etykieta = dd;
    else
        cout << endl
             << "error";
}

void SET_LR(unsigned short s, unsigned short p, unsigned short dd)
{
    if (dd >= 0 && dd <= 99 && s <= DEPOT.HandyRack.ilosc && p <= DEPOT.HandyRack.Shelves[s].ilosc)
        DEPOT.HandyRack.Shelves[s].Places[p].etykieta = dd;
    else
        cout << endl
             << "error";
}

void SET_LS(unsigned short p, unsigned short dd)
{
    if (dd >= 0 && dd <= 99 && p <= DEPOT.HandyShelf.ilosc)
        DEPOT.HandyShelf.Places[p].etykieta = dd;
    else
        cout << endl
             << "error";
}

void GET_LW(unsigned short w, unsigned short r, unsigned short s, unsigned short p)
{
    if (w < DEPOT.ilosc && r < DEPOT.Warehouses[w].ilosc && s < DEPOT.Warehouses[w].Racks[r].ilosc && p < DEPOT.Warehouses[w].Racks[r].Shelves[s].ilosc)
    {
        if (DEPOT.Warehouses[w].Racks[r].Shelves[s].Places[p].etykieta == 0)
            cout << endl
                 << "00";
        else if (DEPOT.Warehouses[w].Racks[r].Shelves[s].Places[p].etykieta == 100)
            cout << endl
                 << "--";
        else if (DEPOT.Warehouses[w].Racks[r].Shelves[s].Places[p].etykieta < 10)
            cout << endl
                 << "0" << DEPOT.Warehouses[w].Racks[r].Shelves[s].Places[p].etykieta;
        else
            cout << endl
                 << DEPOT.Warehouses[w].Racks[r].Shelves[s].Places[p].etykieta;
    }
    else
        cout << endl
             << "error";
}

void GET_LH(unsigned short w, unsigned short p)
{
    if (w < DEPOT.ilosc && p < DEPOT.Warehouses[w].HandyShelf.ilosc)
    {
        if (DEPOT.Warehouses[w].HandyShelf.Places[p].etykieta == 0)
            cout << endl
                 << "00";
        else if (DEPOT.Warehouses[w].HandyShelf.Places[p].etykieta == 100)
            cout << endl
                 << "--";
        else if (DEPOT.Warehouses[w].HandyShelf.Places[p].etykieta < 10)
            cout << endl
                 << "0" << DEPOT.Warehouses[w].HandyShelf.Places[p].etykieta;
        else
            cout << endl
                 << DEPOT.Warehouses[w].HandyShelf.Places[p].etykieta;
    }
    else
        cout << endl
             << "error";
}

void GET_LR(unsigned short s, unsigned short p)
{
    if (s < DEPOT.HandyRack.ilosc && p < DEPOT.HandyRack.Shelves[s].ilosc)
    {
        if (DEPOT.HandyRack.Shelves[s].Places[p].etykieta == 0)
            cout << endl
                 << "00";
        else if (DEPOT.HandyRack.Shelves[s].Places[p].etykieta == 100)
            cout << endl
                 << "--";
        else if (DEPOT.HandyRack.Shelves[s].Places[p].etykieta < 10)
            cout << endl
                 << "0" << DEPOT.HandyRack.Shelves[s].Places[p].etykieta;
        else
            cout << endl
                 << DEPOT.HandyRack.Shelves[s].Places[p].etykieta;
    }
    else
        cout << endl
             << "error";
}

void GET_LS(unsigned short p)
{
    if (p < DEPOT.HandyShelf.ilosc)
    {
        if (DEPOT.HandyShelf.Places[p].etykieta == 0)
            cout << endl
                 << "00";
        else if (DEPOT.HandyShelf.Places[p].etykieta == 100)
            cout << endl
                 << "--";
        else if (DEPOT.HandyShelf.Places[p].etykieta < 10)
            cout << endl
                 << "0" << DEPOT.HandyShelf.Places[p].etykieta;
        else
            cout << endl
                 << DEPOT.HandyShelf.Places[p].etykieta;
    }
    else
        cout << endl
             << "error";
}

//////////////////MAIN//////////////////

int main()
{

    unsigned short z1, z2, z3, z4, z5, z6, z7, z8;

    while (polecenie != "END")
    {
        cin >> polecenie;
        if (polecenie == "SET-AP")
        {
            cin >> z1 >> z2 >> z3 >> z4;
            SET_AP(z1, z2, z3, z4);
        }
        else if (polecenie == "SET-AS")
        {
            cin >> z1 >> z2 >> z3 >> z4;
            SET_AS(z1, z2, z3, z4);
        }
        else if (polecenie == "SET-AR")
        {
            cin >> z1 >> z2 >> z3 >> z4;
            SET_AR(z1, z2, z3, z4);
        }
        else if (polecenie == "SET-AW")
        {
            cin >> z1 >> z2 >> z3 >> z3;
            SET_AW(z1, z2, z3, z4);
        }
        else if (polecenie == "SET-HW")
        {
            cin >> z1 >> z2;
            SET_HW(z1, z2);
        }
        else if (polecenie == "SET-HR")
        {
            cin >> z1 >> z2;
            SET_HR(z1, z2);
        }
        else if (polecenie == "SET-HS")
        {
            cin >> z1;
            SET_HS(z1);
        }
        else if (polecenie == "PUT-W")
        {
            cin >> z1 >> z2 >> z3 >> z4 >> z5;
            PUT_W(z1, z2, z3, z4, z5);
        }
        else if (polecenie == "PUT-H")
        {
            cin >> z1 >> z2 >> z3;
            PUT_H(z1, z2, z3);
        }
        else if (polecenie == "PUT-R")
        {
            cin >> z1 >> z2 >> z3;
            PUT_R(z1, z2, z3);
        }
        else if (polecenie == "PUT-S")
        {
            cin >> z1 >> z2;
            PUT_S(z1, z2);
        }
        else if (polecenie == "FILL")
        {
            cin >> z1 >> z2 >> z3 >> z4 >> z5;
            FILL(z1, z2, z3, z4, z5);
        }
        else if (polecenie == "POP-W")
        {
            cin >> z1 >> z2 >> z3 >> z4 >> z5;
            POP_W(z1, z2, z3, z4, z5);
        }
        else if (polecenie == "POP-H")
        {
            cin >> z1 >> z2 >> z3;
            POP_H(z1, z2, z3);
        }
        else if (polecenie == "POP-R")
        {
            cin >> z1 >> z2 >> z3;
            POP_R(z1, z2, z3);
        }
        else if (polecenie == "POP-S")
        {
            cin >> z1 >> z2;
            POP_S(z1, z2);
        }
        else if (polecenie == "MOV-W")
        {
            cin >> z1 >> z2 >> z3 >> z4 >> z5 >> z6 >> z7 >> z8;
            MOV_W(z1, z2, z3, z4, z5, z6, z7, z8);
        }
        else if (polecenie == "MOV-H")
        {
            cin >> z1 >> z2 >> z3 >> z4 >> z5;
            MOV_H(z1, z2, z3, z4, z5);
        }
        else if (polecenie == "MOV-R")
        {
            cin >> z1 >> z2 >> z3 >> z4 >> z5 >> z6;
            MOV_R(z1, z2, z3, z4, z5, z6);
        }
        else if (polecenie == "MOV-S")
        {
            cin >> z1 >> z2 >> z3;
            MOV_S(z1, z2, z3);
        }
        else if (polecenie == "GET-E")
        {
            GET_E();
        }
        else if (polecenie == "GET-W")
        {
            cin >> z1;
            GET_W(z1);
        }
        else if (polecenie == "GET-RW")
        {
            cin >> z1 >> z2;
            GET_RW(z1, z2);
        }
        else if (polecenie == "GET-RH")
        {
            GET_RH();
        }
        else if (polecenie == "GET-SW")
        {
            cin >> z1 >> z2 >> z3;
            GET_SW(z1, z2, z3);
        }
        else if (polecenie == "GET-SH")
        {
            cin >> z1;
            GET_SH(z1);
        }
        else if (polecenie == "GET-SR")
        {
            cin >> z1;
            GET_SR(z1);
        }
        else if (polecenie == "GET-S")
        {
            GET_S();
        }
        else if (polecenie == "SET-LW")
        {
            cin >> z1 >> z2 >> z3 >> z4 >> z5;
            SET_LW(z1, z2, z3, z4, z5);
        }
        else if (polecenie == "SET-LH")
        {
            cin >> z1 >> z2 >> z3;
            SET_LH(z1, z2, z3);
        }
        else if (polecenie == "SET-LR")
        {
            cin >> z1 >> z2 >> z3;
            SET_LR(z1, z2, z3);
        }
        else if (polecenie == "SET-LS")
        {
            cin >> z1 >> z2;
            SET_LS(z1, z2);
        }
        else if (polecenie == "GET-LW")
        {
            cin >> z1 >> z2 >> z3 >> z4;
            GET_LW(z1, z2, z3, z4);
        }
        else if (polecenie == "GET-LH")
        {
            cin >> z1 >> z2;
            GET_LH(z1, z2);
        }
        else if (polecenie == "GET-LR")
        {
            cin >> z1 >> z2;
            GET_LR(z1, z2);
        }
        else if (polecenie == "GET-LS")
        {
            cin >> z1;
            GET_LS(z1);
        }
    }

    return 0;
}