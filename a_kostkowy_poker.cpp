// MAGDALENA LIPKA //

#include <iostream>
using namespace std;

int n;                                                            // liczba zasadniczych danych wejsciowych
char g1, g2;                                                      //znaki graczy
int w1, w2;                                                       // wagi wygranych graczy
int dw1, dw2;                                                     // wyznaczniki wag graczy
int s1, s2;                                                       //sumy kostek graczy
int z1, z2, z3, z4, z5, z6, z7, z8;                               // kolejne wyniky graczy, 1-4 g1, 5-8 g2
float wa, wb, wc, wd, we, la, lb, lc, ld, le, ra, rb, rc, rd, re; // ilosc wygranych(w), przegranych(l) i remisow(r) graczy;

int main()
{
    cin >> n;

    wa = wb = wc = wd = we = la = lb = lc = ld = le = ra = rb = rc = rd = re = 0;

    while (n > 0)
    {
        //wa = wb = wc = wd = we = la = lb = lc = ld = le = ra = rb = rc = rd = re = 0;
        w1 = w2 = dw1 = dw2 = s1 = s2 = 0;

        cin >> g1 >> z1 >> z2 >> z3 >> z4 >> g2 >> z5 >> z6 >> z7 >> z8;

        s1 = z1 + z2 + z3 + z4;

        if (z1 == z2 && z2 == z3 && z3 == z4)
        {
            w1 = 1;
            dw1 = z1;
        }
        else
        {
            if (z1 != z2 && z1 != z3 && z1 != z4 && z2 != z3 && z2 != z4 && z3 != z4)
            {
                w1 = 2;
                dw1 = z1 + z2 + z3 + z4;
            }
            else
            {
                if (z1 == z2 && z3 == z4)
                {
                    w1 = 3;
                    if (z1 > z3)
                        dw1 = z1;
                    else
                        dw1 = z3;
                }
                else
                {
                    if (z1 == z3 && z2 == z4)
                    {
                        w1 = 3;
                        if (z1 > z2)
                            dw1 = z1;
                        else
                            dw1 = z2;
                    }
                    else
                    {
                        if (z1 == z4 && z2 == z3)
                        {
                            w1 = 3;
                            if (z1 > z2)
                                dw1 = z1;
                            else
                                dw1 = z2;
                        }
                        else
                        {
                            if (z1 == z2 && z2 == z3)
                            {
                                w1 = 4;
                                dw1 = z1;
                            }
                            else
                            {
                                if (z1 == z2 && z2 == z4)
                                {
                                    w1 = 4;
                                    dw1 = z1;
                                }
                                else
                                {
                                    if (z1 == z3 && z3 == z4)
                                    {
                                        w1 = 4;
                                        dw1 = z1;
                                    }
                                    else
                                    {
                                        if (z2 == z3 && z3 == z4)
                                        {
                                            w1 = 4;
                                            dw1 = z2;
                                        }
                                        else
                                        {
                                            if (z1 == z2)
                                            {
                                                w1 = 5;
                                                dw1 = z1;
                                            }
                                            else
                                            {
                                                if (z1 == z3)
                                                {
                                                    w1 = 5;
                                                    dw1 = z1;
                                                }
                                                else
                                                {
                                                    if (z1 == z4)
                                                    {
                                                        w1 = 5;
                                                        dw1 = z1;
                                                    }
                                                    else
                                                    {
                                                        if (z2 == z3)
                                                        {
                                                            w1 = 5;
                                                            dw1 = z2;
                                                        }
                                                        else
                                                        {
                                                            if (z2 == z4)
                                                            {
                                                                w1 = 5;
                                                                dw1 = z2;
                                                            }
                                                            else
                                                            {
                                                                if (z3 == z4)
                                                                {
                                                                    w1 = 5;
                                                                    dw1 = z3;
                                                                }
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }

        s2 = z5 + z6 + z7 + z8;

        if (z5 == z6 && z6 == z7 && z7 == z8)
        {
            w2 = 1;
            dw2 = z5;
        }
        else
        {
            if (z5 != z6 && z5 != z7 && z5 != z8 && z6 != z7 && z6 != z8 && z7 != z8)
            {
                w2 = 2;
                dw2 = z5 + z6 + z7 + z8;
            }
            else
            {
                if (z5 == z6 && z7 == z8)
                {
                    w2 = 3;
                    if (z5 > z7)
                        dw2 = z5;
                    else
                        dw2 = z7;
                }
                else
                {
                    if (z5 == z7 && z6 == z8)
                    {
                        w2 = 3;
                        if (z5 > z6)
                            dw2 = z5;
                        else
                            dw2 = z6;
                    }
                    else
                    {
                        if (z5 == z8 && z6 == z7)
                        {
                            w2 = 3;
                            if (z5 > z6)
                                dw2 = z5;
                            else
                                dw2 = z6;
                        }
                        else
                        {
                            if (z5 == z6 && z6 == z7)
                            {
                                w2 = 4;
                                dw2 = z5;
                            }
                            else
                            {
                                if (z5 == z6 && z6 == z8)
                                {
                                    w2 = 4;
                                    dw2 = z5;
                                }
                                else
                                {
                                    if (z5 == z7 && z7 == z8)
                                    {
                                        w2 = 4;
                                        dw2 = z5;
                                    }
                                    else
                                    {
                                        if (z6 == z7 && z7 == z8)
                                        {
                                            w2 = 4;
                                            dw2 = z6;
                                        }
                                        else
                                        {
                                            if (z5 == z6)
                                            {
                                                w2 = 5;
                                                dw2 = z5;
                                            }
                                            else
                                            {
                                                if (z5 == z7)
                                                {
                                                    w2 = 5;
                                                    dw2 = z5;
                                                }
                                                else
                                                {
                                                    if (z5 == z8)
                                                    {
                                                        w2 = 5;
                                                        dw2 = z5;
                                                    }
                                                    else
                                                    {
                                                        if (z6 == z7)
                                                        {
                                                            w2 = 5;
                                                            dw2 = z6;
                                                        }
                                                        else
                                                        {
                                                            if (z6 == z8)
                                                            {
                                                                w2 = 5;
                                                                dw2 = z6;
                                                            }
                                                            else
                                                            {
                                                                if (z7 == z8)
                                                                {
                                                                    w2 = 5;
                                                                    dw2 = z7;
                                                                }
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }

        if (w1 < w2)
        {
            if (g1 == 'a')
                wa++;
            else if (g1 == 'b')
                wb++;
            else if (g1 == 'c')
                wc++;
            else if (g1 == 'd')
                wd++;
            else
                we++;

            if (g2 == 'a')
                la++;
            else if (g2 == 'b')
                lb++;
            else if (g2 == 'c')
                lc++;
            else if (g2 == 'd')
                ld++;
            else
                le++;
        }
        else
        {
            if (w2 < w1)
            {
                if (g2 == 'a')
                    wa++;
                else if (g2 == 'b')
                    wb++;
                else if (g2 == 'c')
                    wc++;
                else if (g2 == 'd')
                    wd++;
                else
                    we++;

                if (g1 == 'a')
                    la++;
                else if (g1 == 'b')
                    lb++;
                else if (g1 == 'c')
                    lc++;
                else if (g1 == 'd')
                    ld++;
                else
                    le++;
            }
            else
            {
                if (dw1 > dw2)
                {
                    if (g1 == 'a')
                        wa++;
                    else if (g1 == 'b')
                        wb++;
                    else if (g1 == 'c')
                        wc++;
                    else if (g1 == 'd')
                        wd++;
                    else
                        we++;

                    if (g2 == 'a')
                        la++;
                    else if (g2 == 'b')
                        lb++;
                    else if (g2 == 'c')
                        lc++;
                    else if (g2 == 'd')
                        ld++;
                    else
                        le++;
                }
                else
                {
                    if (dw2 > dw1)
                    {
                        if (g2 == 'a')
                            wa++;
                        else if (g2 == 'b')
                            wb++;
                        else if (g2 == 'c')
                            wc++;
                        else if (g2 == 'd')
                            wd++;
                        else
                            we++;

                        if (g1 == 'a')
                            la++;
                        else if (g1 == 'b')
                            lb++;
                        else if (g1 == 'c')
                            lc++;
                        else if (g1 == 'd')
                            ld++;
                        else
                            le++;
                    }
                    else
                    {
                        if (s1 > s2)
                        {
                            if (g1 == 'a')
                                wa++;
                            else if (g1 == 'b')
                                wb++;
                            else if (g1 == 'c')
                                wc++;
                            else if (g1 == 'd')
                                wd++;
                            else
                                we++;

                            if (g2 == 'a')
                                la++;
                            else if (g2 == 'b')
                                lb++;
                            else if (g2 == 'c')
                                lc++;
                            else if (g2 == 'd')
                                ld++;
                            else
                                le++;
                        }
                        else
                        {
                            if (s2 > s1)
                            {
                                if (g2 == 'a')
                                    wa++;
                                else if (g2 == 'b')
                                    wb++;
                                else if (g2 == 'c')
                                    wc++;
                                else if (g2 == 'd')
                                    wd++;
                                else
                                    we++;

                                if (g1 == 'a')
                                    la++;
                                else if (g1 == 'b')
                                    lb++;
                                else if (g1 == 'c')
                                    lc++;
                                else if (g1 == 'd')
                                    ld++;
                                else
                                    le++;
                            }
                            else
                            {
                                if (g2 == 'a')
                                    ra++;
                                else if (g2 == 'b')
                                    rb++;
                                else if (g2 == 'c')
                                    rc++;
                                else if (g2 == 'd')
                                    rd++;
                                else
                                    re++;

                                if (g1 == 'a')
                                    ra++;
                                else if (g1 == 'b')
                                    rb++;
                                else if (g1 == 'c')
                                    rc++;
                                else if (g1 == 'd')
                                    rd++;
                                else
                                    re++;
                            }
                        }
                    }
                }
            }
        }

        //cout << endl << g1 << " " << w1 << " " << dw1 << endl << g2 << " " << w2 << " " << dw2 << endl;
        //cout << endl << wa << " " << ra << " " << la << endl;
        //cout << wb << " " << rb << " " << lb << endl;
        //cout << wc << " " << rc << " " << lc << endl;
        //cout << wd << " " << rd << " " << ld << endl;
        //cout << we << " " << re << " " << le << endl;

        n--;
    }

    bool enter = 0;

    if (wa != 0 || la != 0 || ra != 0)
    {
        if (!enter)
            enter = 1;
        else
            cout << "\n";
        cout << "gracz a"
             << "\n";
        if (wa != 0)
            cout << "    wygrane: " << 100 * wa / (wa + la + ra) << "%"
                 << "\n";
        if (ra != 0)
            cout << "    remisy: " << 100 * ra / (wa + la + ra) << "%"
                 << "\n";
        if (la != 0)
            cout << "    przegrane: " << 100 * la / (wa + la + ra) << "%"
                 << "\n";
    }

    if (wb != 0 || lb != 0 || rb != 0)
    {
        if (!enter)
            enter = 1;
        else
            cout << "\n";
        cout << "gracz b"
             << "\n";
        if (wb != 0)
            cout << "    wygrane: " << 100 * wb / (wb + lb + rb) << "%"
                 << "\n";
        if (rb != 0)
            cout << "    remisy: " << 100 * rb / (wb + lb + rb) << "%"
                 << "\n";
        if (lb != 0)
            cout << "    przegrane: " << 100 * lb / (wb + lb + rb) << "%"
                 << "\n";
    }

    if (wc != 0 || lc != 0 || rc != 0)
    {
        if (!enter)
            enter = 1;
        else
            cout << "\n";
        cout << "gracz c"
             << "\n";
        if (wc != 0)
            cout << "    wygrane: " << 100 * wc / (wc + lc + rc) << "%"
                 << "\n";
        if (rc != 0)
            cout << "    remisy: " << 100 * rc / (wc + lc + rc) << "%"
                 << "\n";
        if (lc != 0)
            cout << "    przegrane: " << 100 * lc / (wc + lc + rc) << "%"
                 << "\n";
    }

    if (wd != 0 || ld != 0 || rd != 0)
    {
        if (!enter)
            enter = 1;
        else
            cout << "\n";
        cout << "gracz d"
             << "\n";
        if (wd != 0)
            cout << "    wygrane: " << 100 * wd / (wd + ld + rd) << "%"
                 << "\n";
        if (rd != 0)
            cout << "    remisy: " << 100 * rd / (wd + ld + rd) << "%"
                 << "\n";
        if (ld != 0)
            cout << "    przegrane: " << 100 * ld / (wd + ld + rd) << "%"
                 << "\n";
    }

    if (we != 0 || le != 0 || re != 0)
    {
        if (!enter)
            enter = 1;
        else
            cout << "\n";
        cout << "gracz e"
             << "\n";
        if (we != 0)
            cout << "    wygrane: " << 100 * we / (we + le + re) << "%"
                 << "\n";
        if (re != 0)
            cout << "    remisy: " << 100 * re / (we + le + re) << "%"
                 << "\n";
        if (le != 0)
            cout << "    przegrane: " << 100 * le / (we + le + re) << "%"
                 << "\n";
    }

    return 0;
}