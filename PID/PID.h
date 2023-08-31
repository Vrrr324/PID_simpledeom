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
	double			_max;				// 被操控变量最大值
	double			_min;				// 被操控变量最小值
	double			_Kp;				// 比例权重
	double			_Kd;				// 微分权重
	double			_Ki;				// 积分权重
	double			_pre_error;			// 积分
	double			_inergral;			// 积分

};

PID::PID(double Kp, double Kd, double Ki, double dt = 1, double max = 20, double min = 0) :
	_Kp(Kp), _Kd(Kd), _Ki(Ki), _dt(dt), _max(max), _min(min), _pre_error(0), _inergral(0) {}

double PID::calculate(double target, double cur) 
{
	// 计算误差
	double error = target - cur;
	
	// 比例项
	double Pout = _Kp * error;

	// 积分项
	_inergral += error * _dt;
	double Iout = _Ki * _inergral;

	// 微分项
	double derivative = (error - _pre_error) / _dt;
	double Dout = _Kd * derivative;

	// 计算总的输出
	double output = Pout + Iout + Dout;

	if (output > _max) 
	{
		output = _max;
	}
	else if (output < _min)
	{
		output = _min;
	}


	// 存储当前误差
	_pre_error = error;
	return output;
}
