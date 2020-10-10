//MAGDALENA LIPKA//

#include <iostream>
using namespace std;

bool Element(int x, int Tab[])
{
    int i = 0;
    int j = 0;
    while (Tab[j] != -1)
        j++;
    while (Tab[i] != x && Tab[i] != -1)
        i++;
    if (i == j)
        return false;
    else
        return true;
}

void Add(int x, int Tab[])
{
    int i = 0;
    int j = 0;
    while (Tab[j] != -1)
        j++;
    while (Tab[i] != x && Tab[i] != -1)
        i++;
    if (j == i && x <= 4095 && x >= 1 && !Element(x, Tab))
    {
        Tab[j] = x;
        Tab[j + 1] = -1;
    }
}

void Create(int n, int T[], int Tab[])
{
    int i = 0;
    int j = 0;
    Tab[0] = -1;
    while (j < n)
    {
        if (T[j] <= 4095 && T[j] >= 1 && !Element(T[j], Tab))
        {
            Tab[i] = T[j];
            i++;
        }
        j++;
    }
    Tab[i] = -1;
}

void Union(int T1[], int T2[], int Tab[])
{
    int i = 0;
    int j = 0;
    while (T1[i] != -1)
    {
        Tab[j] = T1[i];
        i++;
        j++;
    }
    i = 0;
    while (T2[i] != -1)
    {
        if (!Element(T2[i], T1))
        {
            Tab[j] = T2[i];
            j++;
        }
        i++;
    }
    Tab[j] = -1;
}

bool Subset(int T1[], int T2[])
{
    bool czy = 1;
    int i = 0;
    while (T1[i] != -1)
    {
        if (!Element(T1[i], T2))
            czy = 0;
        i++;
    }
    return czy;
}

bool Equal(int T1[], int T2[])
{
    bool czy = 1;
    int n1, n2;
    int i = 0;
    ;
    while (T1[i] != -1)
        i++;
    n1 = i;
    i = 0;
    while (T2[i] != -1)
        i++;
    n2 = i;
    i = 0;
    if (n1 != n2)
        czy = 0;
    if (czy)
    {
        while (T1[i] != -1)
        {
            if (!Element(T1[i], T2))
                czy = 0;
            i++;
        }
    }
    return czy;
}

void Intersection(int T1[], int T2[], int Tab[])
{
    int i = 0;
    int j = 0;
    while (T1[i] != -1)
    {
        if (Element(T1[i], T2))
        {
            Tab[j] = T1[i];
            j++;
        }
        i++;
    }
    Tab[j] = -1;
}

void Difference(int Odjemna[], int Odjemnik[], int Tab[])
{
    int i = 0;
    int j = 0;
    while (Odjemna[i] != -1)
    {
        if (!Element(Odjemna[i], Odjemnik))
        {
            Tab[j] = Odjemna[i];
            j++;
        }
        i++;
    }
    Tab[j] = -1;
}

void Symmetric(int T1[], int T2[], int Tab[])
{
    int i = 0;
    int j = 0;
    while (T1[i] != -1)
    {
        if (!Element(T1[i], T2))
        {
            Tab[j] = T1[i];
            j++;
        }
        i++;
    }
    i = 0;
    while (T2[i] != -1)
    {
        if (!Element(T2[i], T1))
        {
            Tab[j] = T2[i];
            j++;
        }
        i++;
    }
    Tab[j] = -1;
}

void Complement(int T1[], int T2[])
{
    int i = 1;
    int j = 0;
    while (i <= 4095)
    {
        if (!Element(i, T1))
        {
            T2[j] = i;
            j++;
        }
        i++;
    }
    T2[j] = -1;
}

bool Empty(int Tab[])
{
    if (Tab[0] == -1)
        return true;
    else
        return false;
}

bool Nonempty(int Tab[])
{
    if (Tab[0] == -1)
        return false;
    else
        return true;
}

double Arithmetic(int T1[])
{
    double srednia = 0;
    if (Empty(T1))
        return 0;
    else
    {
        int i = 0;
        while (T1[i] != -1)
        {
            srednia += T1[i];
            i++;
        }
        srednia = srednia / i;
        return srednia;
    }
}

double Harmonic(int T[])
{
    double srednia = 0;
    if (Empty(T))
        return 1;
    else
    {
        int i = 0;
        while (T[i] != -1)
        {
            double ele = T[i];
            srednia = srednia + (1 / ele);
            i++;
        }
        double liczba = i;
        srednia = liczba / srednia;
        return srednia;
    }
}

void MinMax(int T[], int *min, int &max)
{
    if (T[0] != -1)
    {
        int i = 1;
        max = T[0];
        *min = T[0];
        while (T[i] != -1)
        {
            if (T[i] > max)
            {
                max = T[i];
            }
            if (T[i] < *min)
            {
                *min = T[i];
            }
            i++;
        }
    }
}

void Cardinality(int T[], int *n)
{
    int i = 0;
    while (T[i] != -1)
        i++;
    *n = i;
}

void Properties(int T[], char literki[], double &A, double *H, int &min, int *max, int &n)
{
    int i = 0;
    while (literki[i] != '\0')
    {
        if (literki[i] == 'a')
            A = Arithmetic(T);
        if (literki[i] == 'h')
            *H = Harmonic(T);
        if (literki[i] == 'm')
            MinMax(T, &min, *max);
        if (literki[i] == 'c')
            Cardinality(T, &n);
        i++;
    }
}
