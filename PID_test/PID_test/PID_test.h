#pragma once

#ifndef __PID_TEST__
#define __PID_TEST__

/* exact-width unsigned integer types */
typedef unsigned char        uint8_t;
typedef unsigned short int   uint16_t;
typedef unsigned int         uint32_t;
typedef int                  int32_t;

typedef struct {
	float  Kp;      //比例
	float  Ki;      //积分
	float  Kd;      //微分
	/* ------------- */
	float target;    //期望值
	float current;   //测量值
	/* ------------- */
	float err;    //本次误差
	float last_err;   //上次误差
	float err_sum;    //误差的累加，用于积分项调整
	float  fnl_out;   //最终输出
} PIDHandle;

#define I_BAND        500
#define PID_MAX_I_OUT  1000
#define PID_MAX_FNL_OUT   3000

#endif /* __PID_TEST__ */