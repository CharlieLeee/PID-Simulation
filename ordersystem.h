#ifndef ORDERSYSTEM_H
#define ORDERSYSTEM_H


class thirdtustinsystem{
public:
    double y, y1, y2, y3, u, u1, u2, u3;

    thirdtustinsystem():y(0), y1(0), y2(0), y3(0), u(0), u1(0), u2(0), u3(0) {}
    void setu(double inp)
    {
        u = inp;
        y = 1.596*y1-0.9699*y2+0.3734*y3+38.85*u+116.5*u1+116.5*u2+38.85*u3;
        u3 = u2; u2 = u1; u1 = u;
        y3 = y2; y2 = y1; y1 = y;
    }
    double gety() {return y;}
    void restart()
    {
        u3 = u2; u2 = u1; u1 = u=0;
        y3 = y2; y2 = y1; y1 = y=0;
    }

};

class thirdbacksystem{
public:
    double y, y1, y2, y3, u;

    thirdbacksystem():y(0), y1(0), y2(0), y3(0), u(0) {}
    void setu(double inp)
    {
        u = inp;
        y = 1.85*y1-1.11*y2+0.2597*y3+163.9*u;
        y3 = y2; y2 = y1; y1 = y;
    }
    double gety() {return y;}
    void restart()
    {
        u=0;
        y3 = y2; y2 = y1; y1 = y=0;
    }

};



#endif // ORDERSYSTEM_H
