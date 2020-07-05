// PID_Control.cpp : ��������̨Ӧ�ó��������ڵ㡣
//

#include "pid_position.h"
#include "pid_incremental.h"

using namespace std;

int main()
{
	// ��������PID
	pid_incremental pid_inc(0.35, 0.65, 0.005);
	float target = 1000;
	float actual = 0;
	float pid_increment = 0.0;
	int N = 50;
	pid_inc.pid_show();

	cout << endl;
	cout << "target = " << target << endl;
	for (; N > 0; N--)
	{
		pid_increment = pid_inc.pid_control(target, actual);
		actual += pid_increment;
		cout << "N = " << 50 - N << " actual = " << actual << endl;
	}
	pid_inc.pid_show();
	
	// ����λ��pid
	pid_position pid_pos(0.59, 0.35, 0.002);
	pid_pos.pid_show();
	cout << "target = " << target << endl;
	N = 100;
	for (; N > 0; N--)
	{
		actual = pid_pos.pid_control(target, actual);
		cout << "N = " << 100 - N << " actual = " << actual << endl;
	}
	pid_pos.pid_show();

	system("pause");
    return 0;
}

