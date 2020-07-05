#ifndef MATLABPID_H
#define MATLABPID_H
class matlabpid{
public:
    double u, u1, e, e1, e2;
    double dt;
    double p, i, d;
    matlabpid():u(0), u1(0), e(0), e1(0), e2(0), p(0), i(0), d(0), dt(0.02) {}
    void setinput(double r)
    {
        e = r;
        u = u1+(p+d/dt)*e+(i*dt-p-2*d/dt)*e1+d/dt*e2;
        u1 = u;
        e2 = e1;
        e1 = e;
    }
    void setpid(double p, double i, double d, double dt) {this->restart();this->p = p; this->i = i; this->d = d; this->dt = dt;}
    double output() {return u;}
    void restart()
    {
        e=e1=e2=u=u1=0;
    }

};
#endif // MATLABPID_H
