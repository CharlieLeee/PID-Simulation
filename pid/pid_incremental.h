#pragma once

#include <QThread>

class pid_incremental : public QThread
{
    Q_OBJECT

public:
    pid_incremental(float dt);

    ~pid_incremental();


public slots:
    // update pid class
    void pid_incremental_update_slot(float p, float i, float d, float tar, float act);

    // get N param value
    void pid_incremental_get_N_slot(int);

protected:
    virtual void run();

signals:
    //void pid_incremental_show_signal();
    void pid_incremental_return_result_signal(float, float, float);
	
private:
	float kp;
	float ki;
	float kd;
	float target;
	float actual;
	float e;
    float e_pre_1;
    float e_pre_2;
	float A;
	float B;
	float C;
    float dt;

private:
    int N;   // calc times

};

