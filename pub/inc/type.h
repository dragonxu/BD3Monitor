/*
 * type.h
 * Date   : 11-14-2014
 * Author : HouBiao,WangHanCheng
*/
#ifndef TYPE_H_
#define TYPE_H_

typedef double FLOAT;								// ��������
	
// �����ṹ��
typedef struct
	{
		FLOAT real;									// ʵ��
		FLOAT imag;									// �鲿
	}complex;

// ���ٽ׶�����λ
typedef struct
{
	FLOAT phsE;										// E֧·����λ
	FLOAT phsP;										// P֧·����λ
	FLOAT phsL;										// L֧·����λ
}EPLPhs;
// NCO
typedef struct 
{
	FLOAT fo;										// Ƶ��
	FLOAT fcw;										// Ƶ�ʿ�����
	FLOAT phs;										// ��λ
}NCO;
// ������NCO
typedef struct 
{
	FLOAT fo;										// Ƶ��
	FLOAT fcw;										// Ƶ�ʿ�����
	EPLPhs phs;										// ���ٽ׶�����λ
}TrkNCO;

// �˲���ϵ��
typedef struct 
{
	FLOAT dll_a;									// DLL�˲���ϵ��A
	FLOAT dll_b;									// DLL�˲���ϵ��B
	FLOAT dll_reg;									// DLL�˲����Ĵ���
	FLOAT dll_gain;									// DLL�˲�������
	

	FLOAT fll_a;									// FLL�˲���ϵ��A
	FLOAT fll_b;									// FLL�˲���ϵ��B
	FLOAT pll_a;									// PLL�˲���ϵ��A
	FLOAT pll_b;									// PLL�˲���ϵ��B
	FLOAT pll_c;									// PLL�˲���ϵ��C
	FLOAT pll_reg0;									// PLL�˲����Ĵ���0
	FLOAT pll_reg1;									// PLL�˲����Ĵ���1
	FLOAT pll_gain;									// PLL�˲�������
	FLOAT fll_gain;									// FLL�˲�������
	
}LPF;

#endif