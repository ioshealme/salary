#include<studio.h>
#include<fstream>
#include<fstream>
int n=0;//��¼Ա��������ȫ�ֱ���
using namespace std;
struct member{
	char name[10];//����
	char ID[3];                // ��λ���ʡ�н�����ʡ�ְ���������Ч���ʡ�Ӧ�����ʡ���������˰��ʵ������
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
		if ((fp=open("gx.date","rb")==NULL){   //�ö����ƴ��ļ�gx.date�������ļ��ж�ȡְ���������ݡ�read���� ��ʼ��ְ�����ʽṹ�����鲢ͳ�Ƶ�ǰ�����ļ���ְ��
                                                 //������
            printf("cannot open this file\n");
		}                                       //����ְ����������ȫ�ֱ���n�У��Ա���������ʹ�á�
	
	

	if(fp)
	{  
		fp=open("gx,date","rb");//���ļ�
	    fseek(fp,0,SEEK_END);   //�ļ�ָ���Ƶ��ļ�β  
      for(int i=0;i<3;i++)     //��ʼ��ְ����Ϣ
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
           
		  n=n+1;//ͳ�������Ա������
		
	
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
		if ((fp=open("gx.date","rb")==NULL){   //�ö����ƴ��ļ�gx.date�������ļ��ж�ȡְ���������ݡ�read���� ��ʼ��ְ�����ʽṹ�����鲢ͳ�Ƶ�ǰ�����ļ���ְ��
                                                 //������
            printf("cannot open this file\n");
		}                                       
	
		

	}










}
