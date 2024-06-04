#ifndef arc
#define arc

#include <iostream>

using namespace std;

class Arc {
    public:
        int exists;
        int flow;
        int minCap;
        int maxCap;
        int cost;

    Arc(int exists, int flow, int minCap, int maxCap, int cost);

    Arc(int exists, int minCap, int maxCap, int cost);

    Arc();
    ~Arc();
};

ostream& operator<<(ostream& os, const Arc& a);

#endif