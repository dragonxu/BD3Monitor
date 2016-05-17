%% ��Ȩ����
% ����������B1�ź���������ƽ̨���ָ���㷨�������
% ����ͨ��: BOC(1,1)  ��Ƶͨ����TMBOC(6,1,4/33)
% ������: 16MHz   ��Ƶ��5MHz
% ����: Hancheng Wang
% ����:   2014.9
% ��Ȩ����, ��ӭ����, ������ע������!

clear;
%% Initialization Parameter
BGN = 10001;
END = 49000;
K = 50;
M = 20;
LEN = (END - BGN + 1)/1000;

%% load data
load('BD_DATA_60dB_50s_0_8.mat')
figure
subplot(2,1,1)
plot(Channel.syn.pkg_PB.I),title('I·')
subplot(2,1,2) 
plot(Channel.syn.pkg_PB.Q),title('Q·')
Ik = reshape(Channel.syn.pkg_PB.I(BGN:END),K,length(Channel.syn.pkg_PB.I(BGN:END))/K);
Qk = reshape(Channel.syn.pkg_PB.Q(BGN:END),K,length(Channel.syn.pkg_PB.Q(BGN:END))/K);
format long;
%% α���⾫��
PrnPhs = mean(reshape(dll_out(BGN:END),1000,length(dll_out(BGN:END))/1000));
figure;
subplot(2,1,1)
plot(dll_out(BGN:END));title('α���� ƽ��ǰ');
subplot(2,1,2)
plot(PrnPhs);title('α���� ƽ����');
StdPrnPhs = std(PrnPhs);


%% �ز���λ��⾫��
CarPhs = pll_out;
StdCarPhs = std(CarPhs(BGN:END)); 


%% Ƶ�ʼ�⾫ȷ��
CarFrq = mean(reshape(car_filter_out(BGN:END),1000,length(car_filter_out(BGN:END))/1000)) - 80;
figure;
subplot(2,1,1)
plot(car_filter_out(BGN:END));title('Ƶ�ʼ�� ƽ��ǰ');
subplot(2,1,2)
plot(CarFrq);title('Ƶ�ʼ�� ƽ����');
StdCarFrq = std(CarFrq);


%% �����
WBPm = sum(Ik.^2 + Qk.^2);
NBPm = (sum(abs(Ik))).^2 + (sum((Qk))).^2; 
temp = reshape(NBPm./WBPm,M,length(Channel.syn.pkg_PB.I(BGN:END))/K/M);
Etam = sum(temp)/M;
CN0 = 10*log10(1000*(Etam - 1)./(K - Etam));
std_CN0 = std(CN0);
CNO = mean(CN0);




% NPm = reshape(NBPm./WBPm,M,length(Channel.syn.pkg_PB.I(BGN:END))/K/M);
% uNP = 1/K*sum(NPm);
% CN0 = 10*log10(1000*(uNP-1)/(M-uNP));


















