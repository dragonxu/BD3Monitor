/*
 * filter.h
 * Date   : 11-14-2014
 * Author : HouBiao,WangHanCheng
*/

#ifndef FILTER_H_
#define FILTER_H_
#include "type.h"
extern FLOAT codeLoopFilter(LPF * lpfInst,FLOAT dis_dll);				   // �뻷�˲��� 
extern FLOAT carrierLoopFilter(LPF * lpfInst,FLOAT dis_pll,FLOAT dis_fll); // �ز����˲���
#endif