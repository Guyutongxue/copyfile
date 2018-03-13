#include<iostream>
#include<cstring>
#include<windows.h>
#include<io.h>
#include<direct.h>
#include<ctime>

using namespace std;
char contain[28];
int length=1;

string getCurDir(){
	char chPath[1000];
	GetModuleFileName(NULL,(LPSTR)chPath,sizeof(chPath));
	strrchr(chPath,'\\')[1]= 0;
	string strPath(chPath);  // ÀýÈçstr_url==e:\program\Debug
	return strPath;
}


void initial(){
	length=1;
	char rootPath[10]={0};
    UINT nType;
    for(char i='A';i<='Z';i++){
		sprintf(rootPath,"%c:\\",i);
		nType = GetDriveType(rootPath);
		if(nType != DRIVE_NO_ROOT_DIR){
			contain[length++]=rootPath[0];
			//cout<<rootPath<<"\t"<<driveType<<endl;
		}
	}
}
char diff(){
	char rootPath[10]={0},aim='0';
    UINT nType;
    for(char i='A';i<='Z';i++){
		sprintf(rootPath,"%c:\\",i);
		nType=GetDriveType(rootPath);
		if(nType!=DRIVE_NO_ROOT_DIR){
			int isFound=false;
			for(int i=1;i<length;i++){
    			if(rootPath[0]==contain[i]){
    				isFound=true;
    				break;
				}
			}
			if(!isFound){
				aim=rootPath[0];
			}
			//cout<<rootPath<<"\t"<<driveType<<endl;
		}
	}
	initial();
	return aim;
}
string formatTime(time_t time1){
	char chTime[20]; 
	struct tm tm1;
	tm1=*localtime(&time1);  
	sprintf(chTime,"%4.4d%2.2d%2.2d%2.2d%2.2d%2.2d",tm1.tm_year+1900,tm1.tm_mon+1,tm1.tm_mday,tm1.tm_hour,tm1.tm_min,tm1.tm_sec);  
	string strTime(chTime);
	return strTime;
}  

int main(){
	cout<<"copyfile (U-Disk Copier) v1.1 by Guyutongxue"<<endl;
	string proDir=getCurDir();
	cout<<"Program Directory: "<<proDir<<endl;
	
    initial();
	while(true){
		string strTime=formatTime(time(NULL));
		char aimDrive=diff();
		if(aimDrive!='0'){
			cout<<"Disk "<<aimDrive<<" found."<<endl;
			string aimDriveRoot;
			(aimDriveRoot+=aimDrive)+=":\\";
			string destDir=proDir+aimDrive+"("+strTime+")";
			string command="xcopy "+aimDriveRoot+" "+destDir+"\\ /s /e /h";
			cout<<command<<endl;
			system(command.c_str());
		}
		else{
			cout<<"No disk found."<<endl; 
		}
		Sleep(1000);
	}
	return 0;  
}
