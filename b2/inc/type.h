/*
 * struct.h
 * Date   : 11-14-2014
 * Author : HouBiao
*/
#ifndef B2TYPE_H_
#define B2TYPE_H_
#include <stdio.h>
#include "../../pub/inc/type.h"
#include "cfg.h"

// һ�ζ������������
typedef struct
	{
		FLOAT value;											// һ�ζ���������������ֵ
		FLOAT doppler;											// һ�ζ���������ֵ
		FLOAT phase;											// һ�ζ������������ֵ��Ӧ��λֵ

	}acqResult;

// ����׶εĲ���
typedef struct 
	{
		FLOAT dopplerAcq;										// ���������
		FLOAT phaseAcq;											// ������λ	

		NCO car;												// �ز�NCO
		NCO pkg;												// ���NCO
		unsigned short packetIndex;								// �������

		unsigned short dopplerIndex;							// ��������������
		int doppler[2*(DOPPLERRANGE/DOPPLERSTEP)+1];
		complex packetReceive[B2PKGLEN];						// �����źŴ��
		complex packetLocal[B2PKGLEN];							// �����źŴ��
		acqResult acqResultInst[2*DOPPLERRANGE/DOPPLERSTEP+1];  // ������

	}B2AcqPrms;

// ���ٽ׶β���
typedef struct
	{
		NCO car;												// �ز� NCO

		TrkNCO prn;												// �� NCO
		short codeIndexEarly;									// ��ǰ������
		short codeIndexPrompt;									// ��ʱ������
		short codeIndexLate;									// �ͺ�������

		LPF lpf;												// �˲���
		int fll_time;											// ��Ƶ��ʱ��,ms
		int fll_timemax;										// ��Ƶ�����ʱ��,ms

		unsigned char oneCircle;								// һ��������Ƶ�����ڱ�־

		complex accumulatorEarly;								// �ۼ���E֧·
		complex accumulatorPrompt;								// �ۼ���P֧·
		complex accumulatorLate;								// �ۼ���L֧·
		complex accumulatorPromptOld;							// �����ۼ���P֧·��ֵ��������Ƶ��

		FLOAT dis_dll;											// �뻷�������
		FLOAT dis_pll;											// �ز������໷�������
		FLOAT dis_fll;											// �ز�����Ƶ���������
		FLOAT flt_codeLoop;										// �뻷�˲������
		FLOAT flt_carrierLoop;									// �ز����˲������
	}B2TrkPrms;

// ͨ������
typedef struct 
	{		
		char chnlPros;											// ͨ�����ȣ�=1 ����=2 ����
	    char chnlID;											// ͨ��ID 3~6
		char code[B2PRNLEN];									// ��Ƶ��

		B2AcqPrms acqInst;										// ������̲���
		B2TrkPrms trkInst;										// ���ٹ��̲���
	// for test
		NCO TCAR;												// �ź�ԴԴ�ز� NCO
		NCO TPRN;												// �ź�PRN NCO
		short prnIndex;											// �ź�ԴPRN ������0~10229
	// for test
	}B2ChnlPrms;

#endif