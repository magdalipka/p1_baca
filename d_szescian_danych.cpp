//MAGDALENA LIPKA//

#include <iostream>
using namespace std;

int ph, pw, pd;          //poziomy, piony, panele//
int Tablica[32][32][32]; //poziom, pion, panel//
int N;                   //musi byc parzyste i niewieksze od 32//
int Il_D = N * N * N;
char Op = 'A';
char znak;
int d1, d2, d3, d4, d5, d6;
long long T_W[32][32];

void Clvphwd(int l, int v, int p, int h, int w, int d)
{
    //cout<<endl<<"..."<<N/2<<"..."<<l<<"..."<<v<<"..."<<p<<"..."<<endl;
    //zamiana wartosci h, w, d, w kierunku srodka szescianu//
    if (l >= N / 2)
        l -= h;
    if (v >= N / 2)
        v -= w;
    if (p >= N / 2)
        p -= d;

    //sumowanie warosci komorek//
    long long suma = 0;
    for (int i = l; i <= l + h; i++)
    {
        for (int j = v; j <= v + w; j++)
        {
            for (int k = p; k <= p + d; k++)
            {
                if (i >= 0 && i < N && j >= 0 && j < N && k >= 0 && k < N)
                    suma += Tablica[i][j][k];
            }
        }
    }
    cout << suma << endl;
}

void Tlvpe(int t, int v, int p, int e)
{
    //zamiana wartosci h, w, d, w kierunku srodka szescianu//
    if (t >= N / 2)
        t -= e;
    if (v >= N / 2)
        v -= e;
    if (p >= N / 2)
        p -= e;

    //sumowanie warosci komorek//
    long long suma = 0;
    for (int i = t; i <= t + e; i++)
    {
        for (int j = v; j <= v + e; j++)
        {
            for (int k = p; k <= p + e; k++)
            {
                if (i >= 0 && i < N && j >= 0 && j < N && k >= 0 && k < N && t + v + p + e >= i + j + k)
                    suma += Tablica[i][j][k];
            }
        }
    }
    cout << suma << endl;
}

int potega(int p)
{
    if (p % 2 == 0)
        return 1;
    else
        return -1;
}

void Olvpr(int l, int v, int p, int r)
{
    //zamiana wartosci h, w, d, w kierunku srodka szescianu//
    int dl = 1;
    int dv = 1;
    int dp = 1;

    if (l >= N / 2)
        dl = -1;
    if (v >= N / 2)
        dv = -1;
    if (p >= N / 2)
        dp = -1;
    ;

    //sumowanie warosci komorek//
    long long suma = 0;
    for (int i = l; i <= l + r && i >= l - r; i += dl)
    {
        for (int j = v; j <= v + r && j >= v - r; j += dv)
        {
            for (int k = p; k <= p + r && k >= p - r; k += dp)
            {
                if (i >= 0 && i < N && j >= 0 && j < N && k >= 0 && k < N && (l - i) * (l - i) + (v - j) * (v - j) + (p - k) * (p - k) <= r * r)
                    suma += Tablica[i][j][k];
            }
        }
    }
    cout << suma << endl;
}

long long wyznacznik(long long Tab[32][32], int wymiar)
{
    long long D = 0;
    long long subTab[32][32];
    if (wymiar == 2)
        return Tab[0][0] * Tab[1][1] - Tab[0][1] * Tab[1][0];
    else
    {
        for (int k = 0; k < wymiar; k++)
        {
            int licznik_i = 0;
            for (int i = 1; i < wymiar; i++)
            {
                int licznik_j = 0;
                for (int j = 0; j < wymiar; j++)
                {
                    if (j != k)
                    {
                        subTab[licznik_i][licznik_j] = Tab[i][j];
                        licznik_j++;
                    }
                }
                licznik_i++;
            }
            D = D + (potega(k) * Tab[0][k] * wyznacznik(subTab, wymiar - 1));
        }
    }
    return D;
}

long long W_Wyznacznik(long long Tab[32][32], int wymiar)
{
    bool czy1 = 1;
    for (int i = 0; i < N; i++)
    {
        for (int j = i + 1; j < N; j++)
        {
            if (T_W[i][j] != 0)
                czy1 = 0;
        }
    }

    bool czy2 = 1;
    for (int i = 0; i < N; i++)
    {
        for (int j = i - 1; j >= 0; j--)
        {
            if (T_W[i][j] != 0)
                czy2 = 0;
        }
    }

    if (czy1 || czy2)
    {
        long long D = 1;
        for (int i = 0; i < N; i++)
            D *= Tab[i][i];
        return D;
    }
    else
        return wyznacznik(Tab, wymiar);
}

void wypisz()
{
    for (int i = 0; i < 32; i++)
    {
        for (int j = 0; j < 32; j++)
        {
            cout << T_W[i][j] << " ";
        }
        cout << endl;
    }
}

void Dki(char k, int liczba)
{

    switch (znak)
    {
    case 'l':
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                T_W[i][j] = Tablica[liczba][i][j];
            }
        }
        cout << W_Wyznacznik(T_W, N) << endl;
        break;
    case 'v':
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                T_W[i][j] = Tablica[i][liczba][j];
            }
        }
        cout << W_Wyznacznik(T_W, N) << endl;
        break;
    case 'p':
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                T_W[i][j] = Tablica[i][j][liczba];
            }
        }
        cout << W_Wyznacznik(T_W, N) << endl;
        break;
    }
    //wypisz();
}

int main()
{

    cin >> N;

    for (int panel = 0; panel < N; panel++)
    {
        for (int poziom = 0; poziom < N; poziom++)
        {
            for (int pion = 0; pion < N; pion++)
            {
                cin >> Tablica[poziom][pion][panel];
            }
        }
    }

    while (Op != 'E')
    {
        cin >> Op;

        switch (Op)
        {
        case 'C':
            cin >> d1 >> d2 >> d3 >> d4 >> d5 >> d6;
            Clvphwd(d1, d2, d3, d4, d5, d6);
            break;
        case 'T':
            cin >> d1 >> d2 >> d3 >> d4;
            Tlvpe(d1, d2, d3, d4);
            break;
        case 'O':
            cin >> d1 >> d2 >> d3 >> d4;
            Olvpr(d1, d2, d3, d4);
            break;
        case 'D':
            cin >> znak >> d2;
            Dki(znak, d2);
            break;
        case 'E':
            break;
        }
    }
    return 0;
}
