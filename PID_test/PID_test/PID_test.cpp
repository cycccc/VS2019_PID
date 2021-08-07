// PID_test.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <stdio.h>
#include "PID_test.h"

//函数申明
void pid_calc(PIDHandle* pid);


PIDHandle pid = {0};


int main()
{
	//系数
	pid.Kp = 0.7;
	pid.Ki = 0.0;
	pid.Kd = 0.01;

	pid.target = 1000;  //设定值

	for(int i = 0; i < 100; i++)
	{
		pid_calc(&pid);
		printf("当前实际值为：%f \n", pid.current);
	
		pid.current += pid.fnl_out;

	}
	
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件

/**********************************************************************************************//**
 * @fn	void pid_calc(PIDHandle* pid)
 *
 * @brief  PID 具体计算函数
 *
 * @param 	[in] pid 
 *
 * @return	无 N/A
 **************************************************************************************************/
void pid_calc(PIDHandle* pPid)
{
	float i_out = 0;

	pPid->err = pPid->target - pPid->current;   //本次误差 = 期望-测量
	//积分分离 (先对误差取绝对值在进行判断)
	if (((pPid->err > 0)? pPid->err : (0 - pPid->err)) < I_BAND)
	{
		pPid->err_sum += pPid->err;
		//积分限幅
		if (i_out > PID_MAX_I_OUT) i_out = PID_MAX_I_OUT;
	}
	else
	{
		pPid->err_sum = 0;
	}
	//这是位置PID控制
	pPid->fnl_out = pPid->Kp * pPid->err + pPid->Ki * pPid->err_sum + pPid->Kd * (pPid->err - pPid->last_err);
	//输出限幅
	if((pPid->fnl_out) > PID_MAX_FNL_OUT)pPid->fnl_out = PID_MAX_FNL_OUT;     //正向限幅
	if((pPid->fnl_out) < (0 - PID_MAX_FNL_OUT))pPid->fnl_out = (0 - PID_MAX_FNL_OUT);  //负向限幅
	pPid->last_err = pPid->err;  //把这次的误差放到上一次中
}


