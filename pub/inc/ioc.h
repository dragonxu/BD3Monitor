/*
 * ioc.h
 * Date   : 11-14-2014
 * Author : HouBiao,WangHanCheng
*/

#ifndef IOC_H_
#define IOC_H_
#include<stdio.h>
#include"type.h"

#define FILENUM				66						// �ܵ�����ļ���

#define DLL_DIS_OUT			0						// �ļ���Ա�ţ� DLL��������� 
#define DLL_LPF_OUT			1						// �ļ���Ա�ţ� DLL���˲������
#define PLL_DIS_OUT			2						// �ļ���Ա�ţ� PLL���������
#define PLL_LPF_OUT			3						// �ļ���Ա�ţ� PLL���˲������
#define TRK_I_OUT			4						// �ļ���Ա�ţ� ����I·���
#define TRK_Q_OUT			5						// �ļ���Ա�ţ� ����Q·���
#define ACQ_OUT				6						// �ļ���Ա�ţ� ���������
#define PRN_PHS_SRC_OUT		7						// �ļ���Ա�ţ� PRN���ź�Դ��λ���
#define PRN_PHS_LCL_OUT		8						// �ļ���Ա�ţ� PRN�뱾������λ���
#define CAR_PHS_SRC_OUT		9						// �ļ���Ա�ţ� �ز��ź�Դ���
#define CAR_PHS_LCL_OUT		10						// �ļ���Ա�ţ� �ز�������λ���

#define B1D_DLL_DIS_OUT			0					// B1Dͨ���ļ���ţ�DLL���������
#define B1D_DLL_LPF_OUT			1					// B1Dͨ���ļ���ţ�DLL���˲������
#define B1D_PLL_DIS_OUT			2					// B1Dͨ���ļ���ţ�PLL���������
#define B1D_PLL_LPF_OUT			3					// B1Dͨ���ļ���ţ�PLL���˲������
#define B1D_TRK_I_OUT			4					// B1Dͨ���ļ���ţ�����I·���
#define B1D_TRK_Q_OUT			5					// B1Dͨ���ļ���ţ�����Q·���
#define B1D_ACQ_OUT				6					// B1Dͨ���ļ���ţ����������
#define B1D_PRN_PHS_SRC_OUT		7					// B1Dͨ���ļ���ţ�PRN���ź�Դ��λ���
#define B1D_PRN_PHS_LCL_OUT		8					// B1Dͨ���ļ���ţ�PRN�뱾������λ���
#define B1D_CAR_PHS_SRC_OUT		9					// B1Dͨ���ļ���ţ��ز��ź�Դ���
#define B1D_CAR_PHS_LCL_OUT		10					// B1Dͨ���ļ���ţ��ز�������λ���
				
#define B1P_DLL_DIS_OUT			11					// B1Pͨ���ļ���ţ�DLL���������
#define B1P_DLL_LPF_OUT			12					// B1Pͨ���ļ���ţ�DLL���˲������
#define B1P_PLL_DIS_OUT			13					// B1Pͨ���ļ���ţ�PLL���������
#define B1P_PLL_LPF_OUT			14					// B1Pͨ���ļ���ţ�PLL���˲������
#define B1P_TRK_I_OUT			15					// B1Pͨ���ļ���ţ�����I·���
#define B1P_TRK_Q_OUT			16					// B1Pͨ���ļ���ţ�����Q·���
#define B1P_ACQ_OUT				17					// B1Pͨ���ļ���ţ����������
#define B1P_PRN_PHS_SRC_OUT		18					// B1Pͨ���ļ���ţ�PRN���ź�Դ��λ���
#define B1P_PRN_PHS_LCL_OUT		19					// B1Pͨ���ļ���ţ�PRN�뱾������λ���
#define B1P_CAR_PHS_SRC_OUT		20					// B1Pͨ���ļ���ţ��ز��ź�Դ���
#define B1P_CAR_PHS_LCL_OUT		21					// B1Pͨ���ļ���ţ��ز�������λ���
	
#define B2D_DLL_DIS_OUT			22					// B2Dͨ���ļ���ţ�DLL���������
#define B2D_DLL_LPF_OUT			23					// B2Dͨ���ļ���ţ�DLL���˲������
#define B2D_PLL_DIS_OUT			24					// B2Dͨ���ļ���ţ�PLL���������
#define B2D_PLL_LPF_OUT			25					// B2Dͨ���ļ���ţ�PLL���˲������
#define B2D_TRK_I_OUT			26					// B2Dͨ���ļ���ţ�����I·���
#define B2D_TRK_Q_OUT			27					// B2Dͨ���ļ���ţ�����Q·���
#define B2D_ACQ_OUT				28					// B2Dͨ���ļ���ţ����������
#define B2D_PRN_PHS_SRC_OUT		29					// B2Dͨ���ļ���ţ�PRN���ź�Դ��λ���
#define B2D_PRN_PHS_LCL_OUT		30					// B2Dͨ���ļ���ţ�PRN�뱾������λ���
#define B2D_CAR_PHS_SRC_OUT		31					// B2Dͨ���ļ���ţ��ز��ź�Դ���
#define B2D_CAR_PHS_LCL_OUT		32					// B2Dͨ���ļ���ţ��ز�������λ���
	
#define B2P_DLL_DIS_OUT			33					// B2Pͨ���ļ���ţ�DLL���������
#define B2P_DLL_LPF_OUT			34					// B2Pͨ���ļ���ţ�DLL���˲������
#define B2P_PLL_DIS_OUT			35					// B2Pͨ���ļ���ţ�PLL���������
#define B2P_PLL_LPF_OUT			36					// B2Pͨ���ļ���ţ�PLL���˲������
#define B2P_TRK_I_OUT			37					// B2Pͨ���ļ���ţ�����I·���
#define B2P_TRK_Q_OUT			38					// B2Pͨ���ļ���ţ�����Q·���
#define B2P_ACQ_OUT				39					// B2Pͨ���ļ���ţ����������
#define B2P_PRN_PHS_SRC_OUT		40					// B2Pͨ���ļ���ţ�PRN���ź�Դ��λ���
#define B2P_PRN_PHS_LCL_OUT		41					// B2Pͨ���ļ���ţ�PRN�뱾������λ���
#define B2P_CAR_PHS_SRC_OUT		42					// B2Pͨ���ļ���ţ��ز��ź�Դ���
#define B2P_CAR_PHS_LCL_OUT		43					// B2Pͨ���ļ���ţ��ز�������λ���
	
#define B3D_DLL_DIS_OUT			44					// B3Dͨ���ļ���ţ�DLL���������
#define B3D_DLL_LPF_OUT			45					// B3Dͨ���ļ���ţ�DLL���˲������
#define B3D_PLL_DIS_OUT			46					// B3Dͨ���ļ���ţ�PLL���������
#define B3D_PLL_LPF_OUT			47					// B3Dͨ���ļ���ţ�PLL���˲������
#define B3D_TRK_I_OUT			48					// B3Dͨ���ļ���ţ�����I·���
#define B3D_TRK_Q_OUT			49					// B3Dͨ���ļ���ţ�����Q·���
#define B3D_ACQ_OUT				50					// B3Dͨ���ļ���ţ����������
#define B3D_PRN_PHS_SRC_OUT		51					// B3Dͨ���ļ���ţ�PRN���ź�Դ��λ���
#define B3D_PRN_PHS_LCL_OUT		52					// B3Dͨ���ļ���ţ�PRN�뱾������λ���
#define B3D_CAR_PHS_SRC_OUT		53					// B3Dͨ���ļ���ţ��ز��ź�Դ���
#define B3D_CAR_PHS_LCL_OUT		54					// B3Dͨ���ļ���ţ��ز�������λ���
		
#define B3P_DLL_DIS_OUT			55					// B3Pͨ���ļ���ţ�DLL���������
#define B3P_DLL_LPF_OUT			56					// B3Pͨ���ļ���ţ�DLL���˲������
#define B3P_PLL_DIS_OUT			57					// B3Pͨ���ļ���ţ�PLL���������
#define B3P_PLL_LPF_OUT			58					// B3Pͨ���ļ���ţ�PLL���˲������
#define B3P_TRK_I_OUT			59					// B3Pͨ���ļ���ţ�����I·���
#define B3P_TRK_Q_OUT			60					// B3Pͨ���ļ���ţ�����Q·���
#define B3P_ACQ_OUT				61					// B3Pͨ���ļ���ţ����������
#define B3P_PRN_PHS_SRC_OUT		62					// B3Pͨ���ļ���ţ�PRN���ź�Դ��λ���
#define B3P_PRN_PHS_LCL_OUT		63					// B3Pͨ���ļ���ţ�PRN�뱾������λ���
#define B3P_CAR_PHS_SRC_OUT		64					// B3Pͨ���ļ���ţ��ز��ź�Դ���
#define B3P_CAR_PHS_LCL_OUT		65					// B3Pͨ���ļ���ţ��ز�������λ���

extern FILE *pFile;									// ����Դ�ļ�
extern FILE *FP[FILENUM];							// ����ļ�
extern void openFile();								// ���ļ�
extern void writeToFile(FLOAT data_src,int i);		// д�ļ�

extern void closeFile();							// �ر��ļ�
#endif