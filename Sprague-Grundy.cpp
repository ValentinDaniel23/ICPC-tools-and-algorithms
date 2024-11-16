#include <bits/stdc++.h>

using namespace std;

struct SpragueGrundy
{
    int calculateMEX(const unordered_set<int> &grundySet)
    {
        int mex = 0;
        while (grundySet.count(mex))
        {
            ++mex;
        }
        return mex;
    }

    // Functie generica pentru calculul nimber-urilor
    vector<int> computeGrundy(int maxState, const function<vector<int>(int)> &getMoves)
    {
        vector<int> grundy(maxState + 1, 0); // Nimber-ul pentru fiecare stare

        for (int state = 1; state <= maxState; ++state)
        {
            unordered_set<int> reachableGrundy; // Toate nimber-urile accesibile din mutarile posibile

            // Obtin mutarile posibile din starea curenta
            vector<int> moves = getMoves(state);

            // Adaug in set nimber-urile pentru mutarile posibile
            for (int move : moves)
            {
                if (move >= 0)
                { // Mutarile negative nu sunt valide
                    reachableGrundy.insert(grundy[move]);
                }
            }

            // Calculez MEX pentru starea curenta
            grundy[state] = calculateMEX(reachableGrundy);
        }

        return grundy;
    }
}

// nimber-ul unei stari dintr-un joc este egal cu cel mai mic nimber la care nu putem ajunge printr-o mutare din acea stare