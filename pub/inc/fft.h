/*
 * fft.h
 * Date   : 11-14-2014
 * Author : HouBiao,WangHanCheng
*/
#ifndef FFT_H_
#define FFT_H_
#include <stdio.h>
#include "type.h"
extern complex complexMult(complex , complex );				// �������
extern void complexConj(complex *,int );					// ��������
extern void FFT(complex *, int);							// ���ٸ���Ҷ�任
extern void IFFT(complex *, int );							// ���ٸ���Ҷ���任
#endif 