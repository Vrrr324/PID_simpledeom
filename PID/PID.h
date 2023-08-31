#pragma once

#include <iostream>

using namespace std;

class PID
{
public:
	PID(double dt, double max, double min, double Kp, double Kd, double Ki);
	double			calculate(double target, double cur);
private:
	double			_dt;
	double			_max;				// ���ٿر������ֵ
	double			_min;				// ���ٿر�����Сֵ
	double			_Kp;				// ����Ȩ��
	double			_Kd;				// ΢��Ȩ��
	double			_Ki;				// ����Ȩ��
	double			_pre_error;			// ����
	double			_inergral;			// ����

};

PID::PID(double Kp, double Kd, double Ki, double dt = 1, double max = 20, double min = 0) :
	_Kp(Kp), _Kd(Kd), _Ki(Ki), _dt(dt), _max(max), _min(min), _pre_error(0), _inergral(0) {}

double PID::calculate(double target, double cur) 
{
	// �������
	double error = target - cur;
	
	// ������
	double Pout = _Kp * error;

	// ������
	_inergral += error * _dt;
	double Iout = _Ki * _inergral;

	// ΢����
	double derivative = (error - _pre_error) / _dt;
	double Dout = _Kd * derivative;

	// �����ܵ����
	double output = Pout + Iout + Dout;

	if (output > _max) 
	{
		output = _max;
	}
	else if (output < _min)
	{
		output = _min;
	}


	// �洢��ǰ���
	_pre_error = error;
	return output;
}
