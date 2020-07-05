#pragma once
#include <QThread>
#include <QDebug>
#include "ordersystem.h"
#include "matlabpid.h"





class pid_position : public QThread
{
    Q_OBJECT

public:
    pid_position(float dt);

    ~pid_position();

public slots:
    // update pid class
    void pid_position_update_slot(float p, float i, float d, float tar, float act);

    // get N param value
    void pid_position_get_N_slot(float);

protected:
    virtual void run();

signals:
    void pid_position_return_result_signal(float, float, float);
    void pid_position_return_property_signal(float, float, float, float);

private:
	float kp;
	float ki;
	float kd;
    float target;
    float actual;
    float e;
    float e_pre;
    float integral;
    float dt; //delta t: update time

private:
    int N; // calc times


};

