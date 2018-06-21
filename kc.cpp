#include<studio.h>
#include<fstream>
#include<fstream>
int n=0;//记录员工数量，全局变量
using namespace std;
struct member{
	char name[10];//姓名
	char ID[3];                // 岗位工资、薪级工资、职务津贴、绩效工资、应发工资、个人所得税、实发工资
	float gwsalary;
	float ransalary;
	float zwsalary;
	float jxsalary;
    float yfsalary;
	float grsalary;
	float reasalary;

   }member1[3];
    
    member zggz[n];

   void read()
	{  FILE *fp
		                                          //ofstream fout1("gx.date",ios::binary);
		if ((fp=open("gx.date","rb")==NULL){   //用二进制打开文件gx.date从数据文件中读取职工工资数据、read函数 初始化职工工资结构体数组并统计当前数据文件中职工
                                                 //人数，
            printf("cannot open this file\n");
		}                                       //并将职工人数存在全局变量n中，以备其他函数使用。
	
	

	if(fp)
	{  
		fp=open("gx,date","rb");//打开文件
	    fseek(fp,0,SEEK_END);   //文件指针移到文件尾  
      for(int i=0;i<3;i++)     //初始化职工信息
	  {
		  scanf("%c",&member1[i].name);
		  scanf("%c",&member1[i].ID);
		  scanf("%f",&member1[i].gwsalary);
		  scanf("%f",&member1[i].ransalary);
          scanf("%f",&member1[i].zwsalary);
          scanf("%f",&member1[i].jxsalary);
		  scanf("%f",&member1[i].yfsalary);
		  scanf("%f",&member1[i].grsalary);
		  scanf("%f",&member1[i].reasalary);
           
		  n=n+1;//统计输入的员工人数
		
	
	  }
	  for(i=n;i>0;i--)
	  {   zggz[n].name=member1[n].name;
	      zggz[n].ID=member[n].ID;
		  zggz[n].gwsalary= member1[n].gwsalary;
		  zggz[n].ransalary=member1[n].ransalary;
	      zggz[n].zwsalary=member1[n].zwsalary;
		  zggz[n].jxsalary=member1[n].jxsalary;
		  zggz[n].yfsalary=member1[n].yfsalary;
          zggz[n].grsalary=member1[n].grsalary;
		  zggz[n].reasalary=member1[n].reasalary;
	  }

	
	fclose(fp);
   
   }
  

void write()
{     FILE *fp;

		if(n>0)
	{
		                                          //ofstream fout1("gx.date",ios::binary);
		if ((fp=open("gx.date","rb")==NULL){   //用二进制打开文件gx.date从数据文件中读取职工工资数据、read函数 初始化职工工资结构体数组并统计当前数据文件中职工
                                                 //人数，
            printf("cannot open this file\n");
		}                                       
	
		

	}










}
