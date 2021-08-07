#pragma once

#ifndef __PID_TEST__
#define __PID_TEST__

/* exact-width unsigned integer types */
typedef unsigned char        uint8_t;
typedef unsigned short int   uint16_t;
typedef unsigned int         uint32_t;
typedef int                  int32_t;

typedef struct {
	float  Kp;      //����
	float  Ki;      //����
	float  Kd;      //΢��
	/* ------------- */
	float target;    //����ֵ
	float current;   //����ֵ
	/* ------------- */
	float err;    //�������
	float last_err;   //�ϴ����
	float err_sum;    //�����ۼӣ����ڻ��������
	float  fnl_out;   //�������
} PIDHandle;

#define I_BAND        500
#define PID_MAX_I_OUT  1000
#define PID_MAX_FNL_OUT   3000

#endif /* __PID_TEST__ */