//��bug �йص��Ҷ���ע�͸����ˣ�serverҲ�� 

//-std=c++11 -lwsock32 -lgdi32
#include<windows.h>
#include<windowsx.h>
#include<bits/stdc++.h>
#define ll long long
#define STR_MAX_LEN	500
#define MEM_STR_LEN	10000
#define IN_TEXT	 101
#define IN_TEXT_ 102
#define IN_TEXTp 103
#define OUT_TEXT 201
#define B_DOWN	 301
#define qd_DOWN	 401
#define zc_DOWN	 601
#define js_DOWN  701
#define ch_DOWN  801
#define fh_DOWN  901
#define Ch_DOWN 1001
#define SS_DOWN 1101
#define GUANL   1201
#define SC_DOWN 1301
#define ReturnBug_DOWN 2001
#define FUYU    1401
#define XIU     1501
#define ABVC    1601
#define cond     0.6
#define cond3    0.618
#define NAME_MAX_LEN 20
#define PWD_MAX_LEN  16
#define NAME_MIN_LEN 3
#define PWD_MIN_LEN  6
#define IN_MAX_CO    5
#define DK 5328
#define KEY_DOWN(VK_NONAME) ((GetAsyncKeyState(VK_NONAME)&0x8000)?1:0)
using namespace std;
char recvname[100],ownname[21];
const int W_s=11,W_ss=15;
bool SHOW_SUCCESSFUL=0;
const char zcc[]="zc",dlc[]="dl",ltc[]="lt",tcc[]="tc",quake[]="quake",rbug[]="rbug",o_IP[]="49.234.202.167";
char sendbuf[STR_MAX_LEN],recvbuf[STR_MAX_LEN],memobuf[MEM_STR_LEN],namebuf[NAME_MAX_LEN+1],nameee[NAME_MAX_LEN+1],pwdbuf[PWD_MAX_LEN+1];
SOCKET connection;
bool outlock=0;
int cgd=-1;
char time_l[20],time_n[20];
time_t timep;
int dltry;
double Start,End;
int sumofbad;
bool cannot;
void show_time(HWND hwndout)
{
	time(&timep);
	strftime(time_n,sizeof(time_n),"%Y-%m-%d %H:%M",localtime(&timep));
	if(strcmp(time_l,time_n))
	{
		strcpy(time_l,time_n);
		strcat(memobuf,"//             ");
		strcat(memobuf,time_n);
		strcat(memobuf,"\r\n");
	}
}
void hwndOutput_add_buf(HWND hwnd,const char* buf,bool n=1)
{
	outlock=1;
	static int len=strlen(memobuf);
	if(len>MEM_STR_LEN-500)strcpy(memobuf,"//=========�Զ������ڴ�=========//");
	show_time(hwnd);
	if(len>MEM_STR_LEN-1000)strcpy(memobuf,"//=!����������ʷ;��ע�Ᵽ������!=//");
	strcat(memobuf,buf);
	if(n)strcat(memobuf,"\r\n");
	SetWindowText(hwnd,memobuf);
	SendMessage(hwnd,EM_LINESCROLL,0,Edit_GetLineCount(hwnd));
	outlock=0;
}
SOCKET gotsock(HWND hwndmind)
{
	WSADATA wsd;
	WSAStartup(MAKEWORD(2,2),&wsd);
	SOCKET SockUser;
	sockaddr_in ServerAddr;
	ServerAddr.sin_family          =AF_INET;
	ServerAddr.sin_port            =htons(DK);
	ServerAddr.sin_addr.S_un.S_addr=inet_addr(o_IP);
	SockUser=socket(AF_INET,SOCK_STREAM,0);
	if (connect(SockUser,(sockaddr*)&ServerAddr,sizeof(sockaddr))!=SOCKET_ERROR)
	{
		if(SHOW_SUCCESSFUL==0)
		{
			strcat(memobuf,"//========���������ӳɹ�========//\r\n");
			hwndOutput_add_buf(hwndmind,"",0);
		}
		SHOW_SUCCESSFUL=1;
		return SockUser;
	}
	else
	{
		MessageBox(NULL,"������������!","Error!",MB_ICONEXCLAMATION|MB_OK);
		exit(0);
	}
}
HWND hwnd;
string FUCK[16]= {"fuck","FUCK","Fuck","shit","SHIT","Shit","ass","ASS","ass","bitch","BITCH","Bitch","jiangwenzhuo"};
int flen[16]= {4,4,4,4,4,4,3,3,3,5,5,5,12};
void Pass_Message()
{
	string pdbuf=sendbuf;
	for(int i=0; i<13; ++i)
	{
		while(1)
		{
			ll Is=pdbuf.find(FUCK[i]),fucklen=flen[i];
			if(Is==string::npos)break;
			sumofbad++;
			for(int j=Is+1; j<Is+fucklen-1; ++j)pdbuf[j]='*';
		}
	}
	for(int i=0; i<pdbuf.length(); ++i)sendbuf[i]=pdbuf[i];
}
void restart_exe()
{
	string ak="start "+(string)(_pgmptr);
	system(ak.c_str());
	exit(0);
}
void w_send(HWND hwndin,HWND hwndlog)
{
	GetWindowText(hwndin,sendbuf,STR_MAX_LEN);
	SetWindowText(hwndin,"");
	if(strlen(sendbuf)>200)
	{
		MessageBox(hwnd,"�������ݹ���","Error!",MB_ICONEXCLAMATION|MB_OK);
		return;
	}
	if(!strcmp(sendbuf,"ord::cls"))
	{
		strcpy(memobuf,"//==========�������ڴ�==========//");
		hwndOutput_add_buf(hwndlog,"");
		return;
	}
	if(strlen(sendbuf)==0)
	{
		MessageBox(hwnd,"�������ݲ���Ϊ��!","Error!",MB_ICONEXCLAMATION|MB_OK);
		return;
	}
	Pass_Message();
	send(connection,ltc,strlen(ltc),0);
	send(connection,sendbuf,STR_MAX_LEN,0);
	if(!strcmp(sendbuf,"ord::EXIT"))exit(0);
}
int wmID,step;
int mmyyy=0;
vector<string>q;
DWORD WINAPI w_recv(LPVOID hwndout)
{
	recv(connection,recvbuf,STR_MAX_LEN,0);
	if(recvbuf[0]=='1')mmyyy=1;
	HWND hwndOut=(HWND)hwndout;
	int noxtime=0;
	while(noxtime<3)
	{
		recv(connection,recvbuf,STR_MAX_LEN,0);
		string kk=recvbuf;
		if(kk=="�ɹ�")
		{
			MessageBox(hwnd,"�ɹ�!","Aceept",MB_ICONEXCLAMATION|MB_OK);
			step=22;
			continue;
		}
		else if(kk=="ʧ��")
		{
			MessageBox(hwnd,"ʧ��!","Error!",MB_ICONEXCLAMATION|MB_OK);
			continue;
		}
		else if(kk[0]=='@')
		{
			if(kk[1]=='@')MessageBox(hwnd,"����@������鿴","Hint!",MB_ICONEXCLAMATION|MB_OK);
			else if(kk[2]='T')hwndOutput_add_buf(hwndOut,"ϵͳ��Ϣ����@�˵��ٶ�̫������ϵͳ�������ѣ�");
			continue;
		}
		else if(recvbuf[0]=='%')
		{
			if(recvbuf[1]=='0')step=10;
			else if(recvbuf[1]=='1')step=11;
			else step=12;
			continue;
		}
		else if(recvbuf[0]=='L'&&recvbuf[1]=='T')
		{
			if(recvbuf[2]=='t')MessageBox(hwnd,"�����͵�̫������ЪһЪ��~","Hint!",MB_ICONEXCLAMATION|MB_OK);
			continue;
		}
		else if(recvbuf[0]=='d'&&recvbuf[1]=='l')
		{
			if(recvbuf[2]=='r')
			{
				MessageBox(hwnd,"�����������ط���¼�������˺ţ����Ǳ��˲������뾡���޸����룡","��������...",MB_ICONEXCLAMATION|MB_OK);
				exit(0);
			}
		}
	////////////////------------------------------------------------------------
		else if(recvbuf[0]=='s'&&recvbuf[1]=='o'&&recvbuf[7]=='c')
		{
			recv(connection,recvname,STR_MAX_LEN,0);
			string msg="ϵͳ��Ϣ��";
			msg+=recvname;
			msg+=" �û����ڷ��͹��಻������Ϣ��ϵͳ�Զ�����һ���ӣ���ע���Լ������С�";
			hwndOutput_add_buf(hwndOut,msg.c_str());
			continue;
		}
	////////////////------------------------------------------------------------
		if(recvbuf[0]=='*')
		{
			q.push_back(recvbuf+1);
			continue;
		}
		if(*recvbuf)
		{
			noxtime=0;
			hwndOutput_add_buf(hwndOut,recvbuf);
		}
		else noxtime++;
		*recvbuf='\0';
	}
	MessageBox(hwnd,"������������,���˳�����!","Error!",MB_ICONEXCLAMATION|MB_OK);
	exit(0);
}
int zc(LPVOID hwndout)
{
	HWND hwndOut=(HWND)hwndout;
	int aaaa;
	send(connection,zcc,strlen(zcc),0);
	send(connection,namebuf,NAME_MAX_LEN,0);
	send(connection,pwdbuf,PWD_MAX_LEN,0);
	int noxtime=0;
	*recvbuf='\0';
	while(noxtime<3)
	{
		recv(connection,recvbuf,STR_MAX_LEN,0);
		if(*recvbuf)
		{
			noxtime=0;
			break;
		}
		else noxtime++;
		*recvbuf='\0';
	}
	if(noxtime==3)
	{
		MessageBox(hwnd,"������������,���˳�����!","Error!",MB_ICONEXCLAMATION|MB_OK);
		exit(0);
	}
	if(recvbuf[0]=='3')
	{
		MessageBox(hwnd,"ע��ʧ�ܣ��˻��ظ������������ٴγ���|���ȷ�����Զ�.","Error!",MB_ICONEXCLAMATION|MB_OK);
		restart_exe();
	}
	else
	{
		MessageBox(hwnd,"ע��ɹ�!���������¼!|���ȷ�����Զ�.","OK",MB_ICONEXCLAMATION|MB_OK);
		restart_exe();
	}
	sscanf(recvbuf,"%d",&aaaa);
	return aaaa;
}
void messgage_error(string ark)
{
	MessageBox(hwnd,ark.c_str(),"Error!",MB_ICONEXCLAMATION|MB_OK);
	return;
}
int dl(LPVOID hwndout)
{
	dltry+=1;
	HWND hwndOut=(HWND) hwndout;
	int aaaa;
	send(connection,dlc,strlen(dlc),0);
	send(connection,namebuf,NAME_MAX_LEN,0);
	send(connection,pwdbuf,PWD_MAX_LEN,0);
	int noxtime=0;
	while(noxtime<3)
	{
		recv(connection,recvbuf,STR_MAX_LEN,0);
		if(recvbuf[0]=='F')
		{
			messgage_error("��¼ʧ�ܣ��˻������ڣ�\n���������ٴγ��ԣ����ȷ���Զ���");
			restart_exe();
			return 2;
		}
		else if(recvbuf[0]=='T')return 0;
		else if(recvbuf[0]=='W')
		{
			messgage_error( "��¼ʧ�ܣ��������\n���������ٴγ��ԣ����ȷ���Զ���");
			restart_exe();
			return 1;
		}
		if(*recvbuf)
		{
			noxtime=0;
			break;
		}
		else noxtime++;
		*recvbuf='\0';
	}
	if(noxtime==3)
	{
		messgage_error("//=!������������,3����˳�����!=//");
		Sleep(3000);
		exit(0);
	}
	sscanf(recvbuf,"%d",&aaaa);
	return aaaa;
}
int bjj=0;
DWORD wc_listenID;
HANDLE wc_listen;
HWND B_send,qd_send,tc_send,ReturnBug,zc_send,hwndOut,hwndIn,hwndts,hwndname,hwndpwd,js_send,ch_send,back,chong,shou,shou_,guanl,shan,fuyu,xiu,yuan,xiu_,queren;
HWND Return;
HWND xin,xiu_2;
HDC hdc,hc2;
int kkksc03;
LRESULT CALLBACK WndProc(HWND hwnd,UINT Message,WPARAM wParam,LPARAM lParam)
{
	if(Message==WM_PAINT)if(0)BitBlt(hdc,0,0,630,448,hc2,0,0,SRCCOPY);
	switch(Message)
	{
		case WM_CREATE:
			hwndOut=CreateWindow(TEXT("edit"),NULL,WS_CHILD|WS_VSCROLL|WS_BORDER|ES_MULTILINE|WS_DISABLED,
			                     0,0,630,346,hwnd,(HMENU)OUT_TEXT,((LPCREATESTRUCT)lParam)->hInstance,NULL);
			hwndIn=CreateWindow(TEXT("edit"),NULL,WS_CHILD|WS_HSCROLL|WS_VSCROLL|WS_BORDER|ES_LEFT|ES_MULTILINE|ES_AUTOVSCROLL,
			                    0,346,488,102,hwnd,(HMENU)IN_TEXT,((LPCREATESTRUCT)lParam)->hInstance,NULL);
			B_send=CreateWindow(TEXT("BUTTON"),TEXT("����"),WS_CHILD|BS_DEFPUSHBUTTON,
			                    488,346,143,61,hwnd,(HMENU)B_DOWN,NULL,NULL);
			hwndts=CreateWindow(TEXT("edit"),TEXT("�û���:\r\n    ����:"),WS_CHILD|WS_VISIBLE|WS_BORDER|ES_LEFT|ES_MULTILINE|WS_DISABLED,
			                    200,180,59,36,hwnd,(HMENU)IN_TEXT,((LPCREATESTRUCT)lParam)->hInstance,NULL);
			hwndname=CreateWindow(TEXT("edit"),NULL,WS_CHILD|WS_VISIBLE|WS_BORDER|ES_LEFT|ES_MULTILINE,
			                      259,180,180,18,hwnd,(HMENU)NAME_MAX_LEN,((LPCREATESTRUCT)lParam)->hInstance,NULL);
			hwndpwd=CreateWindow(TEXT("edit"),NULL,WS_CHILD|WS_VISIBLE|WS_BORDER|ES_LEFT|ES_MULTILINE,
			                     259,198,180,18,hwnd,(HMENU)PWD_MAX_LEN,((LPCREATESTRUCT)lParam)->hInstance,NULL);
			qd_send=CreateWindow(TEXT("BUTTON"),TEXT("��¼"),WS_VISIBLE|WS_CHILD|BS_DEFPUSHBUTTON,
			                     259,216,72,36,hwnd,(HMENU)qd_DOWN,NULL,NULL);
			zc_send=CreateWindow(TEXT("BUTTON"),TEXT("ע��"),WS_VISIBLE|WS_CHILD|BS_DEFPUSHBUTTON,
			                     331,216,72,36,hwnd,(HMENU)zc_DOWN,NULL,NULL);
			js_send=CreateWindow(TEXT("edit"),TEXT("��ӭʹ��CT_TALK����ϵͳ.\r\nĿǰ�汾:1.4.7\r\n�ϰ����Ctrl+F12"),WS_CHILD|WS_VISIBLE|WS_BORDER|ES_LEFT|ES_MULTILINE|WS_DISABLED,
			                     0,0,250,60,hwnd,(HMENU)IN_TEXT,((LPCREATESTRUCT)lParam)->hInstance,NULL);
			ch_send=CreateWindow(TEXT("BUTTON"),TEXT("����"),WS_CHILD|BS_DEFPUSHBUTTON,
			                     488,407,143,43,hwnd,(HMENU)ch_DOWN,NULL,NULL);
			back=CreateWindow(TEXT("BUTTON"),TEXT("����"),WS_CHILD|BS_DEFPUSHBUTTON,
			                  0,0,50,50,hwnd,(HMENU)fh_DOWN,NULL,NULL);
			chong=CreateWindow(TEXT("BUTTON"),TEXT("����������"),WS_CHILD|BS_DEFPUSHBUTTON,
			                   50,0,100,50,hwnd,(HMENU)Ch_DOWN,NULL,NULL);
			shou_=CreateWindow(TEXT("edit"),NULL,WS_CHILD|WS_BORDER|ES_LEFT|ES_MULTILINE,
			                   270,0,180,18,hwnd,(HMENU)NAME_MAX_LEN,((LPCREATESTRUCT)lParam)->hInstance,NULL);
			shou=CreateWindow(TEXT("BUTTON"),TEXT("�����û�"),WS_CHILD|BS_DEFPUSHBUTTON,
			                  200,0,70,20,hwnd,(HMENU)SS_DOWN,NULL,NULL);
			ReturnBug=CreateWindow(TEXT("BUTTON"),TEXT("Bug����"),WS_CHILD|BS_DEFPUSHBUTTON,
			                       200,70,70,20,hwnd,(HMENU)ReturnBug_DOWN,NULL,NULL);
			guanl=CreateWindow(TEXT("BUTTON"),TEXT("�����û�"),WS_VISIBLE|WS_CHILD|BS_DEFPUSHBUTTON,
			                   450,20,70,20,hwnd,(HMENU)GUANL,NULL,NULL);
			shan=CreateWindow(TEXT("BUTTON"),TEXT("ɾ���û�"),WS_CHILD|BS_DEFPUSHBUTTON,
			                  0,100,70,20,hwnd,(HMENU)SC_DOWN,NULL,NULL);
			fuyu=CreateWindow(TEXT("BUTTON"),TEXT("�����ʺŹ���ԱȨ��"),WS_CHILD|BS_DEFPUSHBUTTON,
			                  70,100,170,20,hwnd,(HMENU)FUYU,NULL,NULL);
			xiu=CreateWindow(TEXT("BUTTON"),TEXT("�޸��ҵ�����"),WS_CHILD|BS_DEFPUSHBUTTON,
			                 200,50,130,20,hwnd,(HMENU)XIU,NULL,NULL);
			yuan=CreateWindow(TEXT("edit"),TEXT("ԭ����:"),WS_CHILD|WS_BORDER|ES_LEFT|ES_MULTILINE|WS_DISABLED,
			                  0,50,50,20,hwnd,(HMENU)IN_TEXT,((LPCREATESTRUCT)lParam)->hInstance,NULL);
			xin=CreateWindow(TEXT("edit"),TEXT("������:"),WS_CHILD|WS_BORDER|ES_LEFT|ES_MULTILINE|WS_DISABLED,
			                 0,70,50,20,hwnd,(HMENU)IN_TEXT,((LPCREATESTRUCT)lParam)->hInstance,NULL);
			xiu_=CreateWindow(TEXT("edit"),NULL,WS_CHILD|WS_BORDER|ES_LEFT|ES_MULTILINE,
			                  50,50,180,18,hwnd,(HMENU)NAME_MAX_LEN,((LPCREATESTRUCT)lParam)->hInstance,NULL);
			xiu_2=CreateWindow(TEXT("edit"),NULL,WS_CHILD|WS_BORDER|ES_LEFT|ES_MULTILINE,
			                   50,70,180,18,hwnd,(HMENU)NAME_MAX_LEN,((LPCREATESTRUCT)lParam)->hInstance,NULL);
			queren=CreateWindow(TEXT("BUTTON"),TEXT("ȷ��"),WS_CHILD|BS_DEFPUSHBUTTON,
			                    230,70,40,20,hwnd,(HMENU)ABVC,NULL,NULL);
			Edit_LimitText(hwndIn,STR_MAX_LEN);
			Edit_LimitText(hwndname,NAME_MAX_LEN);
			Edit_LimitText(hwndpwd,PWD_MAX_LEN);
			break;
		case WM_CLOSE:
			exit(0);
		case WM_COMMAND:
			wmID=LOWORD(wParam);
			switch(wmID)
			{
				case ReturnBug_DOWN:
				{
					MessageBox(hwnd,"�ù�����δ���ƣ������ڴ�","Error!",MB_ICONEXCLAMATION|MB_OK);
					break;
				}
				case ABVC:
				{
					MessageBox(hwnd,"�ù�����δ���ƣ������ڴ�","Error!",MB_ICONEXCLAMATION|MB_OK);
					break;
				}
				case XIU:
				{
					kkksc03=step;
					step=100;
					break;
				}
				case FUYU:
				{
					MessageBox(hwnd,"��û��Ȩ��������!","Error!",MB_ICONEXCLAMATION|MB_OK);
					break;
				}
				case SC_DOWN:
				{
					if(mmyyy)
					{
						if(MessageBox(hwnd,"ȷ��ɾ���û���","?",MB_YESNO)==6)
						{
							send(connection,"del",4,0);
							send(connection,namebuf,strlen(namebuf)+1,0);
						}
					}
					else MessageBox(hwnd,"��û��Ȩ��������!","Error!",MB_ICONEXCLAMATION|MB_OK);
					break;
				}
				case GUANL:
				{
					step=20;
					break;
				}
				case B_DOWN:
				{
					bool jinyangg=0;
					if(sumofbad>13)
					{
						sumofbad=0;
						cannot=1;
						jinyangg=1;
						Start=clock();
					}
					if(cannot==1)
					{
						End=clock();
						double cha=End-Start;
						if(cha<60000.0)  
						{
							int until=(60000-(int)cha)/1000;
							string msg="ϵͳ��Ϣ�����ڶ�η��Ͳ��������ԣ�����������1���ӡ�|����";
							char add[25];
							itoa(until,add,10);
							msg+=add;
							msg+="��...";
							hwndOutput_add_buf(hwndOut,msg.c_str());
						}
						else cannot=0;
						Sleep(1);
						//---------------------------------------------------------------------//�������˹������˱�����... 
						if(jinyangg==1)
						{
							send(connection,"cannottalk",11,0);
							send(connection,ownname,strlen(ownname)+1,0);//Ȼ�����ﴫ��ȥ�����Ϊ�գ��������ownname����ȷ�� 
							jinyangg=0;
						}
						//---------------------------------------------------------------------
						break;
					}
					w_send(hwndIn,hwndOut);
					break;
				}
				case SS_DOWN:
				{
					memset(namebuf,0,sizeof namebuf);
					GetWindowText(shou_,namebuf,NAME_MAX_LEN);
					send(connection,"����",5,0);
					send(connection,namebuf,strlen(namebuf)+1,0);
					break;
				}
				case Ch_DOWN:
				{
					MessageBox(hwnd,"��û��Ȩ��������!","Error!",MB_ICONEXCLAMATION|MB_OK);
					break;
				}
				case qd_DOWN:
				{
					connection=gotsock(hwndOut);
					memset(namebuf,0,sizeof namebuf);
					memset(pwdbuf,0,sizeof pwdbuf);
					GetWindowText(hwndname,namebuf,NAME_MAX_LEN);
					GetWindowText(hwndpwd,pwdbuf,PWD_MAX_LEN);
					for(int i=0;i<strlen(namebuf);++i)ownname[i]=namebuf[i];
					if(strlen(namebuf)<NAME_MIN_LEN)MessageBox(hwnd,"���ֹ���!","Error!",MB_ICONEXCLAMATION|MB_OK);
					else if(strlen(namebuf)>NAME_MAX_LEN)MessageBox(hwnd,"���ֹ���!","Error!",MB_ICONEXCLAMATION|MB_OK);
					else if(strlen(pwdbuf)<PWD_MIN_LEN)MessageBox(hwnd,"�������!","Error!",MB_ICONEXCLAMATION|MB_OK);
					else if(strlen(pwdbuf)>PWD_MAX_LEN)MessageBox(hwnd,"�������!","Error!",MB_ICONEXCLAMATION|MB_OK);
					else
					{
						if(cgd==0)send(connection,tcc,strlen(tcc),0);
						cgd=dl((LPVOID)hwndOut);
						if(cgd==0)
						{
							strcat(memobuf,"\r\n");
							char his[STR_MAX_LEN],kp[1];
							step=1;
							wc_listen=(HANDLE)::CreateThread(NULL,0,w_recv,(LPVOID)hwndOut,0,&wc_listenID);
						}
						else
						{
							if(cgd==1)MessageBox(NULL,"�������!���˳������µ�¼�����ȷ�����Զ�!","Error!",MB_ICONEXCLAMATION|MB_OK);
							if(cgd==2)MessageBox(NULL,"�˺Ų�����!���˳������µ�¼�����ȷ�����Զ���","Error!",MB_ICONEXCLAMATION|MB_OK);
							restart_exe();
						}
					}
					SetWindowText(hwndOut,memobuf);
					break;
				}
				case zc_DOWN:
				{
					int cg;
					connection=gotsock(hwndOut);
					GetWindowText(hwndname,namebuf,NAME_MAX_LEN);
					GetWindowText(hwndpwd,pwdbuf,PWD_MAX_LEN);
					string pdbuf=namebuf;
					bool badwordpd=0;
					for(int i=0; i<13; ++i)
					{
						ll Is=pdbuf.find(FUCK[i]);
						if(Is>=100||Is<=-1)continue;
						badwordpd=1;
					}
					if(badwordpd==1)MessageBox(hwnd,"���������������","Error!",MB_OK);
					else if(strlen(namebuf)<NAME_MIN_LEN)MessageBox(NULL,"���ֹ���!","Error!",MB_ICONEXCLAMATION|MB_OK);
					else if(strlen(namebuf)>NAME_MAX_LEN)MessageBox(NULL,"���ֹ���!","Error!",MB_ICONEXCLAMATION|MB_OK);
					else if(strlen(pwdbuf)<PWD_MIN_LEN)MessageBox(hwnd,"�������!","Error!",MB_OK);
					else if(strlen(pwdbuf)>PWD_MAX_LEN)MessageBox(hwnd,"�������!","Error!",MB_OK);
					else
					{
						cg=zc((LPVOID)hwndOut);
						if(cg==3)MessageBox(hwnd,"�ʺ��ظ�!���˳������µ�¼�����ȷ���Զ�","Error!",MB_OK);
						restart_exe();
					}
					SetWindowText(hwndOut,memobuf);
					break;
				}
				case ch_DOWN:
				{
					step=3;
					break;
				}
				case fh_DOWN:
				{
					if(step==101)step=102;
					else if(step==21)step=22;
					else step=5;
					break;
				}
			}
			break;
		default:
			return DefWindowProc(hwnd,Message,wParam,lParam);
	}
	return 0;
}
HDC fff(HDC a,int x,int y)
{
	HDC ret=CreateCompatibleDC(a);
	HBITMAP bmp=CreateCompatibleBitmap(a,x,y);
	SelectObject(ret,bmp);
	return ret;
}
int WinMain(HINSTANCE hin,HINSTANCE w,LPSTR lp,int s)
{
	srand(static_cast<unsigned int>(time(0)));
	MSG Msg;
	WNDCLASSEX wc;
	memset(&wc,0,sizeof(wc));
	wc.hIcon        =LoadIcon(NULL,IDI_APPLICATION);
	wc.hCursor      =LoadCursor(NULL,IDC_ARROW);
	wc.hIconSm      =LoadIcon(NULL,IDI_APPLICATION);
	wc.lpfnWndProc  =WndProc;
	wc.lpszClassName="q";
	wc.cbSize       =sizeof(WNDCLASSEX);
	wc.hbrBackground=(HBRUSH)(6);
	wc.hInstance    =hin;
	if(!RegisterClassEx(&wc))
	{
		MessageBox(NULL,"Window Registration Failed!","Error!",MB_ICONEXCLAMATION|MB_OK);
		return 0;
	}
	hwnd=CreateWindowEx(WS_EX_CLIENTEDGE,"q","CT_v1.2.1.1",WS_VISIBLE|WS_OVERLAPPED|WS_CAPTION|WS_SYSMENU|WS_MINIMIZEBOX,
	                    CW_USEDEFAULT,CW_USEDEFAULT,640,480,NULL,NULL,hin,NULL);
	if(hwnd==NULL)
	{
		MessageBox(NULL,"Window Creation Failed!","Error!",MB_ICONEXCLAMATION|MB_OK);
		return 0;
	}
	hdc=GetDC(hwnd);
	hc2=fff(hdc,630,448);
	SetPixel(hc2,0,0,RGB(153,217,234));
	StretchBlt(hc2,0,0,630,185,hc2,0,0,1,1,SRCCOPY);
	StretchBlt(hc2,0,210,630,238,hc2,0,0,1,1,SRCCOPY);
	for(int i=185; i<210; i++)
		for(int j=0; j<630; j++)
			SetPixel(hc2,j,i,(rand()*rand())&16777215);
	while(GetMessage(&Msg,NULL,0,0)>0)
	{
		if(KEY_DOWN(VK_F12)&&KEY_DOWN(VK_CONTROL)&&!KEY_DOWN(VK_DOWN))
		{
			HWND hwnd=GetForegroundWindow();
			ShowWindow(hwnd,0);
			Sleep(1000);
			while(1)
			{
				Sleep(1);
				ShowWindow(hwnd,0);
				if(KEY_DOWN(VK_CONTROL)&&KEY_DOWN(VK_F12)&&!KEY_DOWN(VK_DOWN))
				{
					ShowWindow(hwnd,1);
					Sleep(1000);
					break;
				}
			}
		}
		TranslateMessage(&Msg);
		DispatchMessage(&Msg);
		if(step==1)
		{
			ShowWindow(hwndOut,1);
			ShowWindow(B_send,1);
			ShowWindow(ReturnBug,0);
			ShowWindow(ch_send,1);
			ShowWindow(hwndIn,1);
			ShowWindow(qd_send,0);
			ShowWindow(zc_send,0);
			ShowWindow(hwndts,0);
			ShowWindow(hwndpwd,0);
			ShowWindow(hwndname,0);
			ShowWindow(js_send,0);
			step=2;
		}
		if(step==3)
		{
			ShowWindow(hwndOut,0);
			ShowWindow(B_send,0);
			ShowWindow(ch_send,0);
			ShowWindow(hwndIn,0);
			ShowWindow(back,1);
			ShowWindow(chong,1);
			ShowWindow(ReturnBug,1);
			ShowWindow(shou,1);
			ShowWindow(shou_,1);
			step=4;
			q.clear();
			send(connection,"�û�",4,0);
		}
		if(step==5)
		{
			step=2;
			ShowWindow(shou,0);
			ShowWindow(shou_,0);
			ShowWindow(back,0);
			ShowWindow(chong,0);
			ShowWindow(ReturnBug,0);
			ShowWindow(hwndOut,1);
			ShowWindow(B_send,1);
			ShowWindow(ch_send,1);
			ShowWindow(hwndIn,1);
			ShowWindow(qd_send,0);
			ShowWindow(zc_send,0);
			ShowWindow(hwndts,0);
			ShowWindow(hwndpwd,0);
			ShowWindow(hwndname,0);
			ShowWindow(js_send,0);
		}
		if(step==4||step==10||step==11||step==12)
		{
			if(nameee[0]==0)memcpy(nameee,namebuf,sizeof(namebuf));
			char c[]="                                         ";
			RECT a;
			a.left=0;
			a.top=50;
			a.right=a.bottom=500;
			sprintf(c,"�ҵ����֣�%s             ",nameee);
			DrawText(hdc,c,22,&a,DT_SINGLELINE);
			char c1[]="                                         ";
			sprintf(c1,"�����û���              ",namebuf);
			a.top+=16;
			DrawText(hdc,c1,22,&a,DT_SINGLELINE);
			char now[]="                                         ";
			for(int i=0; i<q.size(); i++)
			{
				sprintf(now,"                  ");
				sprintf(now,"%s                          ",q[i].c_str());
				a.top+=16;
				DrawText(hdc,now,22,&a,DT_SINGLELINE);
			}
			ShowWindow(xiu,1);
		}
		else ShowWindow(xiu,0);
		if(step==10)
		{
			char c1[]="                                         ";
			sprintf(c1,"%s û�й���ԱȨ��            ",namebuf);
			RECT a;
			a.left=200;
			a.top=20;
			a.right=a.bottom=500;
			DrawText(hdc,c1,30,&a,DT_SINGLELINE);
			ShowWindow(guanl,1);
		}
		else if(step==11)
		{
			char c1[]="                                         ";
			sprintf(c1,"%s �й���ԱȨ��              ",namebuf);
			RECT a;
			a.left=200;
			a.top=20;
			a.right=a.bottom=500;
			DrawText(hdc,c1,30,&a,DT_SINGLELINE);
			ShowWindow(guanl,1);
		}
		else ShowWindow(guanl,0);
		if(step==11)bjj=1;
		if(step==10)bjj=0;
		if(step==12)
		{
			char c1[]="                                            ";
			sprintf(c1,"%s û�и��û�                     ",namebuf);
			RECT a;
			a.left=200;
			a.top=20;
			a.right=a.bottom=500;
			DrawText(hdc,c1,30,&a,DT_SINGLELINE);
		}
		if(step==20)
		{
			step=21;
			ShowWindow(guanl,0);
			ShowWindow(shou,0);
			ShowWindow(shou_,0);
			ShowWindow(ReturnBug,0);
			ShowWindow(chong,0);
			ShowWindow(shan,1);
			ShowWindow(fuyu,1);
			StretchBlt(hdc,0,50,630,398,hdc,100,100,1,1,SRCCOPY);
			PostMessage(hwnd,WM_PAINT,0,0);
		}
		if(step==21)
		{
			char c1[]="                                                     ";
			RECT a;
			a.left=200;
			a.top=20;
			a.right=a.bottom=500;
			DrawText(hdc,c1,50,&a,DT_SINGLELINE);
			a.left=0;
			a.top=50;
			a.right=a.bottom=500;
			sprintf(c1,"�û�:%s                             ",namebuf);
			DrawText(hdc,c1,30,&a,DT_SINGLELINE);
			ShowWindow(shan,1);
		}
		if(step==22)
		{
			ShowWindow(shou,1);
			ShowWindow(shou_,1);
			ShowWindow(ReturnBug,1);
			ShowWindow(chong,1);
			ShowWindow(shan,0);
			ShowWindow(fuyu,0);
			step=10+bjj;
		}
		if(step==100)
		{
			step=101;
			char c1[]="                                                     ";
			RECT a;
			a.left=200;
			a.top=20;
			a.right=a.bottom=500;
			DrawText(hdc,c1,50,&a,DT_SINGLELINE);
			StretchBlt(hdc,0,50,630,398,hdc,100,100,1,1,SRCCOPY);
			ShowWindow(chong,0);
			ShowWindow(shou,0);
			ShowWindow(shou_,0);
			ShowWindow(yuan,1);
			ShowWindow(xiu_,1);
			ShowWindow(ReturnBug,0);
			ShowWindow(xiu_2,1);
			ShowWindow(queren,1);
			ShowWindow(xin,1);
		}
		if(step==102)
		{
			step=kkksc03;
			ShowWindow(chong,1);
			ShowWindow(shou,1);
			ShowWindow(shou_,1);
			ShowWindow(ReturnBug,1);
			ShowWindow(yuan,0);
			ShowWindow(xiu_,0);
			ShowWindow(xiu_2,0);
			ShowWindow(queren,0);
			ShowWindow(xin,0);
		}
	}
	return Msg.wParam;
}
