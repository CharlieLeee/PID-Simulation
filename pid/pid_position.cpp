#include "pid_position.h"
#include <QDebug>


pid_position::pid_position(float dt):
    kp(0), ki(0), kd(0), target(0), actual(0), e(0), e_pre(0), integral(0), N(0), dt(dt)
{
}

pid_position::~pid_position()
{
}

void pid_position::run()
{
    float u = 0;
    matlabpid c;
    c.setpid(kp, ki, kd, dt);

    // calculate settle time
    QVector<float> response;


    e = 0;
    actual = 0;
    e_pre = 0;
    integral = 0;
    // Third order Tustin
    thirdtustinsystem h;
    // Third order back
    //thirdbacksystem h;

    qDebug() << "h init";
    static float x = 0;
    int total = N;
    for (; N >= 0; N--)
    {
        e = target - actual;

        //integral += e;
        c.setinput(e);
        //output of PID
        //u = kp*e + ki*integral + kd*(e - e_pre);
        u = c.output();
        e_pre = e;
        //actual = u;
        h.setu(u);
        actual = h.gety();


        response.push_back(actual);
        emit pid_position_return_result_signal(target, actual, x);
        x += dt;
        qDebug() << actual;
        msleep(20);
    }
    x = 0;
    c.restart();
    h.restart();
    bool isos = false;
    float max = -999;
    int N1, N9;
    for (int i = 0; i < response.length(); i++)
    {
        if (response[i] - 0.1*target <= 0.001)
            N1 = i;
        if (response[i] - 0.9 * target <= 0.001)
            N9 = i;


        if (response[i] > max && response[i] > target)
        {
            max = response[i];
            isos = true;
        }
    }
    //qDebug() << total;
    //qDebug() << response.length();

    float overshoot = (max - target)/target * 100;
    if (isos)
        qDebug() << "overshoot:" << overshoot << "%";

    else
        overshoot = -1;
    // find ts
    float ts = 0;
    bool is_ts = false;
    qDebug() << "start find ts";
    for (int i = response.length()-1; i >= 0; i--)
    {
        //qDebug() <<abs(response[i] - target) << "index" << i;
        if (abs(response[i] - target) > 0.02 * target && !is_ts)
        {
            is_ts = true;
            ts = (i) * dt;
            qDebug() << "Found ts: " << ts;
        }
    }
    qDebug() << "N1: "<< N1 << "N9: " << N9;
    float tr = (N9 - N1) * dt;
    float se = abs((response[response.length()-1] - target)/target*100);

    emit pid_position_return_property_signal(overshoot, ts, tr, se);
}


void pid_position::pid_position_update_slot(float p, float i, float d, float tar, float act)
{
//    kp = p;
//    ki = i*dt;
//    kd = d/dt;
    kp = p;
    ki = i;
    kd = d;
    target = tar;
    actual = act;
    e = target - actual;
    e_pre = e;
}

void pid_position::pid_position_get_N_slot(float n)
{
    N = int(n/dt);
    qDebug() << "N:" << N;
}
