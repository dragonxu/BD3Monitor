/*
 * main.cpp
 * Date   : 11-14-2014
 * Author : HouBiao,WangHanCheng
*/
/*
 * �������иó�����Ҫע�������������⣺
 * 1��ΪB2B3ͨ��ָ����ȷ����Ƶ��·��
 * 2��������λ���ʱ���׼��־outflag������ĳһ·�ź�Ϊ��׼
 * 3�����Ҫ�ֱ����B1����B2B3,��ð������ͨ��ע�͵�
*/
#include<stdio.h>


#include "./pub/inc/cfg.h"
#include "./pub/inc/ioc.h"

#include "./b1/inc/type.h"
#include "./b1/inc/init.h"
#include "./b1/inc/acq.h"
#include "./b1/inc/trk.h"

#include "./b2/inc/type.h"
#include "./b2/inc/init.h"
#include "./b2/inc/acq.h"
#include "./b2/inc/trk.h"


B1ChnlPrms chnlInst0[2];		// B1Ƶ��
B2ChnlPrms chnlInst1[4];		// B2��B3Ƶ��
int outflag;					// ����ͳ�������ԣ�һ���Ե����⣬��Ҫ��ͬһʱ�̲�����ͬͨ�������ݣ���ˣ���������һ��ȫ�ֱ�����Ϊʱ���׼
int main(){
	int i;
	int num;
	char dat_src;
	// ��ʼ��B1Ƶ������ͨ������

	B1ChnlInit(chnlInst0);

	// ��ʼ��B2B3Ƶ���ĸ�ͨ������

	B2ChnlInit(chnlInst1);

	// �򿪸��۲�������ļ�

	openFile();

	// ��ȡһ������
	//for (i=0;i<1000;i++)
	num = fread(&dat_src,sizeof(char),1,pFile);

	// ��ȡ�����ɹ�

	while(num != 0){
		
    // B1Ƶ������ͨ���ź�Դ��λ�ۼ�

		for (i=0;i<2;i++)
		{
			(chnlInst0[i]).TCAR.phs += (chnlInst0[i]).TCAR.fcw;
			if ((chnlInst0[i]).TCAR.phs >= NCOTOTAL)
				(chnlInst0[i]).TCAR.phs -= NCOTOTAL;
			(chnlInst0[i]).TPRN.phs += (chnlInst0[i]).TPRN.fcw;
			if ((chnlInst0[i]).TPRN.phs >= NCOTOTAL)
			{
				(chnlInst0[i]).TPRN.phs -= NCOTOTAL;
				(chnlInst0[i]).prnIndex += 1;
				if ((chnlInst0[i]).prnIndex == 1023)
				{
					(chnlInst0[i]).prnIndex = 0;

				}
			}
		}

	// B2B3Ƶ���ĸ�ͨ���ź�Դ��λ�ۼ�

		for (i=2;i<4;i++)
		{
			(chnlInst1[i]).TCAR.phs += (chnlInst1[i]).TCAR.fcw;
			if ((chnlInst1[i]).TCAR.phs >= NCOTOTAL)
				(chnlInst1[i]).TCAR.phs -= NCOTOTAL;
			(chnlInst1[i]).TPRN.phs += (chnlInst1[i]).TPRN.fcw;
			if ((chnlInst1[i]).TPRN.phs >= NCOTOTAL)
			{
				(chnlInst1[i]).TPRN.phs -= NCOTOTAL;
				(chnlInst1[i]).prnIndex += 1;
				if ((chnlInst1[i]).prnIndex == 10230)
				{
					(chnlInst1[i]).prnIndex = 0;
					if ( i==2)
					outflag =1;
				}
			}
		}

    // B1Ƶ������ͨ�������ȡ����


		for(i=0; i<2; i++ )
		{
			switch(chnlInst0[i].chnlPros)
			{
				case ACQ_FLG: B1AcqASPT(chnlInst0+i,dat_src);break;
				case TRK_FLG: B1TrkASPT(chnlInst0+i,dat_src);break;
				default:break;
			}
		}

    // B2B3Ƶ���ĸ�ͨ�������ȡ����

		for(i=2; i<4; i++ )
		{
			switch(chnlInst1[i].chnlPros)
			{
				case ACQ_FLG: B2Acq(chnlInst1+i,dat_src);break;
				case TRK_FLG: B2Trk(chnlInst1+i,dat_src);break;
				default:break;
			}
		}

    // ���۲��������־����

		outflag = 0;


	// ��ȡ��һ������

		num = fread(&dat_src,sizeof(char),1,pFile);


	}


    // �رո��۲�������ļ�

	closeFile();

	return 0;
}