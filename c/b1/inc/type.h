/*
 * struct.h
 * Date   : 11-14-2014
 * Author : WangHanCheng
*/
#ifndef B1TYPE_H_
#define B1TYPE_H_

#include "../../pub/inc/type.h"

#include "cfg.h"



typedef struct 
{
	NCO car;										//�����ز�NCO
	NCO prn;										//������NCO
	NCO sub_1;										//����BOC��1,1��NCO
	NCO sub_6;										//����BOC��6,1��NCO
	NCO pkg;										//������NCO
	unsigned int pid;								//�������
	unsigned int PID;								//�ܴ����
	unsigned int cid;								//��Ƭ����
	unsigned int did;								//�����ղּ���
	int doppler[2*(DOPPLERRANGE/DOPPLERSTEP)+1];	//�����������б�
	unsigned int CID;								//��Ƭ����
	unsigned int FID;								//FFT����
	complex fft_prn[B1PKGLEN*2];					//�������FFT
	complex fft_boc[B1PKGLEN*2];					//����BOC��FFT
	complex fft_src[B1PKGLEN*2];					//�ź�Դ��FFT
	FLOAT corr[B1PKGLEN*2];							//�ź�Դ�뱾�ص����ֵ
	char rdy;										//1ms�����ɱ�־λ
	char flg;										//��������ֵ��־λ
	char suc;										//����ɹ���־λ
	char NH[B1NHLEN];								//NH�� ��Ƶͨ��
	FLOAT  pk_srh[2*(DOPPLERRANGE/DOPPLERSTEP)+1];	//������������ֵ
	int  phs_srh[2*(DOPPLERRANGE/DOPPLERSTEP)+1];	//������������λֵ
}B1AcqPrms;





typedef struct 
{
	NCO car;							//�����ز�NCO
	TrkNCO prn;							//������NCO
	TrkNCO sub_1;						//����BOC��1,1��NCO
	TrkNCO sub_6;						//����BOC��6,1��NCO
	int doppler;						//����Ķ�����ֵ
	char suc;							//���ٳɹ�
	char rdy;							//1��Ƭ�����������
	LPF  lpf;							//��·�˲�����
	unsigned int cidE;					//E·����Ƭ����
	unsigned int cidP;					//P·����Ƭ����
	unsigned int cidL;					//L·����Ƭ����
	FLOAT pkg_I0;						//FLL ��ǰI·
	FLOAT pkg_I1;						//FLL ��ǰI·
	FLOAT pkg_Q0;						//FLL ��ǰQ·
	FLOAT pkg_Q1;						//FLL ��ǰQ·
	complex corr_bbE;					//�ź�Դ�뱾��E·BOC���ֵ
	complex corr_bbP;					//�ź�Դ�뱾��P·BOC���ֵ
	complex corr_bbL;					//�ź�Դ�뱾��L·BOC���ֵ
	complex corr_bpE;					//�ź�Դ�뱾��E·α�����ֵ
	complex corr_bpP;					//�ź�Դ�뱾��P·α�����ֵ
	complex corr_bpL;					//�ź�Դ�뱾��L·α�����ֵ
	FLOAT disD_out;						//DLL���
	FLOAT disF_out;						//FLL���
	FLOAT disP_out;						//PLL���
	FLOAT prnE;							//E·����α��
	FLOAT bocE;							//E·����BOC
	FLOAT prnP;							//P·����α��
	FLOAT bocP;							//P·����BOC
	FLOAT prnL;							//L·����α��
	FLOAT bocL;							//L·����BOC	
	FLOAT pll_out;						// PLL�˲������
	FLOAT dll_out;						// DLL�˲������
	complex src;						//�ź�Դȥ�ز�
	unsigned int pid;					//���������
	unsigned int tmr;					//����ʱ��ms

}B1TrkPrms;



typedef struct
{
	short satID;			// ���Ǳ�ţ�Ҳ��PRN����
	B1AcqPrms acq;			// ����׶β���
	B1TrkPrms trk;			// ���ٽ׶β���

	char code[B1PRNLEN];	// PRN��Ƶ��
	char chnlPros;			// ͨ�����ȣ�=1 ����=2 ����
	char chnlID;			// ͨ��ID 1~2
	int smp_cnt;			// ��ȡ������������1ms�����λ
// for test down
	NCO TPRN;				// �ź�ԴPRN NCO
	NCO TCAR;				// �ź�Դ�ز� NCO
	short prnIndex;			// �ź�ԴPRN ������0~1022
// for test up
}B1ChnlPrms;

#endif