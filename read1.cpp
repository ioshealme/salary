#include<studio.h>
#include<fstream>
#include<fstream>
int n=0;//��¼Ա��������ȫ�ֱ���
using namespace std;
struct member{
	char name[50];//����
	char ID[50];                // ��λ���ʡ�н�����ʡ�ְ���������Ч���ʡ�Ӧ�����ʡ���������˰��ʵ������
	float gwsalary;
	float ransalary;
	float zwsalary;
	float jxsalary;
    float yfsalary;
	float grsalary;
	float reasalary;

   }member1[50],*p,*q;
    
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
      for(int i=0;i<50;i++)     //��ʼ��ְ����Ϣ
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
	  for(i=n;i>0;i--)//�����ݸ�ֵ��zggz�ṹ������
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
  

void write()               //��zggz�ṹ�������еļ�¼���浽gz.dat�����ļ��С�
{     FILE *fp;
        

		if(n>0)
	{
		                                          //ofstream fout1("gx.date",ios::binary);
		if ((fp=fopen("gx.date","wb+")==NULL){   //�ö����ƴ��ļ�gx.date�������ļ��ж�ȡְ���������ݡ�read���� ��ʼ��ְ�����ʽṹ�����鲢ͳ�Ƶ�ǰ�����ļ���ְ��
                                                 //������
            printf("cannot open this file\n");
			exit(-1);

		}                                       
	for(int i=0;i<n;i++)
	{ 
		
	     fwrite(&zggz[i],sizeof(struct member),1,fp)  //дһ�Σ�ÿ�γ�����member�ĳ���,��n��Ա��д���ļ�
         rewind(fp);//��λ��ƫ��������ʼ״̬��

		 fclose(fp);
		 	    

         
	}
		

	}

void find()         //���ݹ��Ų�ѯ��Ӧְ���Ĺ��ʼ�¼
{   char gonghao[50];
    q=zggz;
	for(q=zggz;q<zggz+50;q++)
		
		

}

void list()
{
	for(int i=0;i<n;i++)
		{
			printf("���Ա��������");
			printf("%c",zggz[i].name);
			printf("%c",zggz[i].ID);
			printf("%f",zggz[i].gwsalary);
            printf("%f",zggz[i].ransalary);
			printf("%f",zggz[i].zwsalary);
			printf("%f",zggz[i].jxsalary);
		    printf("%f",zggz[i].yfsalary);
			printf("%f",zggz[i].grsalary);
			printf("%f",zggz[i].reasalary);
						

		}


}

void modify(zggz[],int y)//��y������ ��n��Ϊȫ�ֱ����أ�ָ�����ţ��޸ĸ�ְ���Ĺ��ʼ�¼������Ҫ����grsds()���������������˰��
{
	int i;
	int x=0;
	char str[50];
	printf("��������Ҫ�޸ĵĹ���")��
    scanf("%c",str);
	for(i=0;i<y;i++)
	{
		if(!strcmpy(str,zggz[i].ID)||!strcmp(str,zggz[i].name))
		{ printf("�������޸ĵ���Ϣ\n");
		 scanf("%c",&member1[i].name);
		  scanf("%c",&member1[i].ID);
		  scanf("%f",&member1[i].gwsalary);
		  scanf("%f",&member1[i].ransalary);
          scanf("%f",&member1[i].zwsalary);
          scanf("%f",&member1[i].jxsalary);
		  scanf("%f",&member1[i].yfsalary);
		  scanf("%f",&member1[i].grsalary);
		  scanf("%f",&member1[i].reasalary);


		  printf("�޸ĳɹ���");  //û�м����������˰��




          x=x+1;



		}

        if(x==0)
		{
			printf("û���ҵ���Ӧ��Ա�����ţ�");

		}

	


	}




}
  
int del(zggz[],int y)
{
	int i=0;
	int x=0;
	char gonghao[15];
	printf("��������Ҫɾ�����˵Ĺ���");
	scanf("%c",gonghao);

	printf("ɾ���ɹ���");

	for(i=0;i<y;i++)
	{
		if(strcmp(gonghao,zggz[i].ID))
		{
			while(i<y)
			{
				strcpy(zggz[i].name,zggz[i+1].name);
				strcpy(zggz[i].ID,zggz[i+1].ID);
				zggz[i].gwsalary=zggz[i+1].gwsalary;
				zggz[i].ransalary=zggz[i+1].
			}
		
		
		}
	}
}




int main()
{









return 0;
}








}