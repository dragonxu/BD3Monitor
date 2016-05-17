/*
 * trk.cpp
 * Date   : 11-14-2014
 * Author : HouBiao
*/
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include "../inc/cfg.h"
#include "../inc/type.h"
#include "../../pub/inc/fft.h"

/*
 * void initAcq(B2ChnlPrms *chnlInst)
 * ��ʼ��һ��ͨ������׶α���
*/
static void initAcq(B2ChnlPrms *chnlInst)
{

	B2AcqPrms *acqInst = & (chnlInst->acqInst);				// ��ȡ����׶νṹ��ָ��
	
	
	//����������ֵ����
	acqInst->dopplerIndex = 0;
	acqInst->doppler[0] = 0;
	int i;
	int j = 1;
	for (i=1;i<2*(DOPPLERRANGE/DOPPLERSTEP)+1;i=i+2)
	{
		acqInst->doppler[i] = DOPPLERSTEP*j;
		acqInst->doppler[i+1]= -DOPPLERSTEP*j;
		j++;
	}

	//�����ز�����
	FLOAT intermediateFrequency;
	FLOAT ratioFrequency;
	if (chnlInst->chnlID == B2PID ||chnlInst->chnlID == B2DID)
	{
		intermediateFrequency = B2INTFRQ;
		ratioFrequency = B2CARFRQ;
	}
	else
	{
		intermediateFrequency = B3INTFRQ;
		ratioFrequency = B3CARFRQ;
	}
	acqInst->car.fo = intermediateFrequency+(acqInst->doppler[acqInst->dopplerIndex]);
	acqInst->car.phs = 0;
	acqInst->car.fcw = floor(acqInst->car.fo/SMPFRQ*NCOTOTAL);
	

	//�������
	acqInst->packetIndex = 0;
	acqInst->pkg.phs = 0;
	acqInst->pkg.fo = B2PKGFRQ*(1+(acqInst->doppler[acqInst->dopplerIndex])/ratioFrequency);
	acqInst->pkg.fcw = floor(acqInst->pkg.fo/SMPFRQ*NCOTOTAL);
	//������
	for (i=0;i<B2PKGLEN;i++)
	{
		acqInst->packetReceive[i].real = 0.0;
		acqInst->packetReceive[i].imag = 0.0;
	}
	//����ʹ��FFT���������ڽ��벶��ǰ��ɱ�����FFT�ļ���
	FLOAT phase;
	FLOAT fcw;
	unsigned short index;
	phase = 0;
	index = 0 ;
	fcw = floor(B2PRNFRQ/(B2PKGLEN*1000)*NCOTOTAL);
		for (i = 0; i < B2PKGLEN;i++)
		{

			acqInst->packetLocal[i].real = chnlInst->code[index];
			acqInst->packetLocal[i].imag = 0.0;
			phase = phase +fcw;
			if(phase >=NCOTOTAL)
			{
				phase = phase - NCOTOTAL;
				index = index +1;
				if (index == B2PRNLEN )
				{
					index = 0 ;
				}
			}
		}
		FFT(acqInst->packetLocal, B2PKGLEN);

	printf("Chnl %d: \tdoppler searching:%dHz\n",chnlInst->chnlID,acqInst->doppler[acqInst->dopplerIndex]);

}

/*
 * void initTrk(B2ChnlPrms * chnlInst)
 * ��ʼ�����ٽ׶β��ֱ���
 */
static void initTrk(B2ChnlPrms * chnlInst)
{
	

	FLOAT omegacode;												// �뻷����Ƶ��
	FLOAT omegafll;													// ��Ƶ������Ƶ��
	FLOAT omegapll;													// ���໷����Ƶ��
	B2TrkPrms * trkInst = &(chnlInst->trkInst);						// ��ȡ���ٽ׶β����ṹ��ָ��
	
	//�뻷�˲���ϵ��
	omegacode = BANDWITHCODE/0.53;
	trkInst->lpf.dll_a = omegacode*omegacode;
	trkInst->lpf.dll_b = ALPHACODE*omegacode;
	trkInst->lpf.dll_gain = CODELOOPGAIN;
	trkInst->lpf.dll_reg = 0;
	//�ز����˲�������
	omegafll = BANDWITHFLL/0.53;
	omegapll = BANDWITHPLL/0.7845;
	trkInst->lpf.fll_a = omegafll*omegafll;
	trkInst->lpf.fll_b = ALPHAFLL*omegafll;
	trkInst->lpf.pll_a = omegapll*omegapll*omegapll;
	trkInst->lpf.pll_b = ALPHAPLL*omegapll*omegapll;
	trkInst->lpf.pll_c = BETAPLL*omegapll;
	trkInst->lpf.pll_gain = CARRIERLOOPGAINPLL;
	trkInst->lpf.fll_gain = CARRIERLOOPGAINFLL;  
    trkInst->lpf.pll_reg0 = 0;
    trkInst->lpf.pll_reg1 = 0;

	trkInst->fll_time = 0;
	trkInst->fll_timemax = B2FLLMAXTIME;
	

	   
}

/*
 * void B2ChnlInit(B2ChnlPrms *chnlInst)
 * ��ʼ��һ��ͨ���Ĳ���
*/
void B2ChnlInit(B2ChnlPrms *chnlInst)

{	
	int i ;
	for (i=2;i<4;i++)
	{
		// ͨ��ID
		(chnlInst+i)->chnlID = i+3;
		//ͨ������
		(chnlInst+i)->chnlPros = ACQ_FLG;
		//ͨ����Ƶ��
		FILE *fp;
		switch(i+3)
		{
		case B2DID:
			fp = fopen(B2DCODEPATH,"rb");
			break;
		case B2PID:
			fp = fopen(B2PCODEPATH,"rb");
			break;
		case B3DID:
			fp = fopen(B3DCODEPATH,"rb");
			break;
		case B3PID:
			fp = fopen(B3PCODEPATH,"rb");
			break;
		default:
			break;
		}
		if (fp ==NULL)
		{
			printf("�޷���B2B3��Ƶ���ļ�����ָ����ȷ���ļ�·����\n");
			exit(1);
		}
		fread((chnlInst+i)->code,sizeof(char),B2PRNLEN,fp);
		fclose(fp);

		// ����׶γ�ʼ��
		initAcq(chnlInst+i);
		// ���ٽ׶γ�ʼ��
		initTrk(chnlInst+i);
		
		// ����������������for test����������������
		// �ź�ԴNCO��ʼ��
		(chnlInst+i)->TCAR.phs = 0.0;
		if (i==2||i==3)
		{
			(chnlInst+i)->TCAR.fcw = 260741328872.0;//B3
		}
		else
		{
			(chnlInst+i)->TCAR.fcw = 356984294732.0;//B2
		}
		(chnlInst+i)->TPRN.phs = 0.0;
		(chnlInst+i)->TPRN.fcw = 73038986702.0;
		(chnlInst+i)->prnIndex = 0;
		// ����������������for test����������������
	}

}

