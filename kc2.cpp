#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string>
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

   }member1[50],newmember;
    
    member zggz[n];

   void read()
	{  FILE *fp;
		  int i;                                        //ofstream fout1("gx.date",ios::binary); n Ϊ��¼Ա��������
		if ((fp=fopen("gx.date","wb"))==NULL){   //�ö����ƴ��ļ�gx.date�������ļ��ж�ȡְ���������ݡ�read���� ��ʼ��ְ�����ʽṹ�����鲢ͳ�Ƶ�ǰ�����ļ���ְ��
                                                 //������
            printf("cannot build this file\n");
			exit(1);
		}                                       //����ְ����������ȫ�ֱ���n�У��Ա���������ʹ�á�
	
	

	if(fp)
	{  
		fp=fopen("gx.date","rb");//���ļ�
	    fseek(fp,0,SEEK_END);   //�ļ�ָ���Ƶ��ļ�β  
      for(int i=0;i<n;i++)     //��ʼ��ְ����Ϣ
	  {
		  scanf("%s",&member1[i].name);
		  scanf("%s",&member1[i].ID);
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
	      zggz[n].ID=member1[n].ID;
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
{  
	FILE *fp;
        

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
		
	     fwrite(&zggz[i],sizeof(struct member),1,fp);  //дһ�Σ�ÿ�γ�����member�ĳ���,��n��Ա��д���ļ�
         rewind(fp);//��λ��ƫ��������ʼ״̬��

		 fclose(fp);
		 	    

         
	}
		

	}

void find()         //���ݹ��Ų�ѯ��Ӧְ���Ĺ��ʼ�¼
{   
	FILE *fp;
	int i;	
	char gonghaop[15];
    if((fp=open("gz,date","rb"))==NULL)
	{
		printf("cannot open this file\n");
			exit(1);
	
	}
	
    printf("������Ҫ���ҵı�ţ�\n");
    scanf("%s",gonghao);
	for(i=0;fread(&zggz[i],sizeof(struct member),1,fp)!=0;i++)
	{
		print("Ա�����Ϊ��%s",zggz[i].ID);
		printf("Ա������Ϊ��%s",zggz[i].name);  
		printf("Ա����λ����Ϊ��%f",zggz[i].gwsalary);
		printf("Ա��н������Ϊ��%f",zggz[i].ransalary);
		printf("Ա��ְ�����Ϊ��%f",zggz[i].zwsalary);
		printf("Ա����Ч����Ϊ��%f", zggz[i].jxsalary);
		printf("Ա��Ӧ������Ϊ��%f",zggz[i].yfsalary);
		printf("Ա����������˰Ϊ��%f",zggz[i].grsalary);
		printf("Ա��ʵ������Ϊ��%f",  zggz[i].reasalary);
		i=i+1;

		
	}

	if(!strcmp(zggz[i].ID,gonghao));
    if(feof(fp))
	{
		printf("δ�ҵ���Ա����\n");

		exit(2);

	}


	fclose(fp);





	
		

}

void list()// 
{
	FILE *fp;
	int i;	
	
    if((fp=open("gz,date","r"))==NULL)
	{
		printf("cannot open this file\n");
			exit(0);
	
	}
	printf("���Ա��������");
	for(i=0;fread(&zggz[i],sizeof(struct member),1,fp)!==NULL)
	{
		    printf("%6d",i+1);
		    printf("%s",zggz[i].name);
			printf("%s",zggz[i].ID);
			printf("%f",zggz[i].gwsalary);
            printf("%f",zggz[i].ransalary);
			printf("%f",zggz[i].zwsalary);
			printf("%f",zggz[i].jxsalary);
		    printf("%f",zggz[i].yfsalary);
			printf("%f",zggz[i].grsalary);
			printf("%f",zggz[i].reasalary);
					


	
	}
	
	fclose(fp);
}

void modify()                  //ָ�����ţ��޸ĸ�ְ���Ĺ��ʼ�¼������Ҫ����grsds()���������������˰��
{
	FILE *fp;
	int i,j;	
	char gonghao[15];

    if((fp=open("gz,date","rb+"))==NULL)
	{
		printf("cannot open this file\n");
			exit(1);
	
	}
	
	printf("��������Ҫ�޸ĵĹ���")��
    scanf("%s",gonghao);

	for(i=0;fread(&zggz[i],sizeof(struct member),1,fp);i++)
		if(!strcmp(zggz[i].ID,gonghao))break;
	if(feof(fp))
	{
		printf("δ�ҵ���Ա����\n");

		exit(2);

	}
	    printf("���ְ������Ϣ\n");
	        printf("%6d",i+1);
	        printf("%s",zggz[i].name);
			printf("%s",zggz[i].ID);
			printf("%f",zggz[i].gwsalary);
            printf("%f",zggz[i].ransalary);
			printf("%f",zggz[i].zwsalary);
			printf("%f",zggz[i].jxsalary);
		    printf("%f",zggz[i].yfsalary);
			printf("%f",zggz[i].grsalary);
			printf("%f",zggz[i].reasalary);
					
           printf("�����ʽ��������ְ���ţ���λ���ʣ�н�����ʣ�ְ���ʣ���Ч���ʣ�Ӧ�����ʣ�����˰����ʵ����\n");
		   printf("��%d����¼",i+1);
		  scanf("%s",&newmember.name);//��ȡְ���µ���Ϣ
		  scanf("%s",&newmember.ID);
		  scanf("%f",&newmember.gwsalary);
		  scanf("%f",&newmember.ransalary);
          scanf("%f",&newmember.zwsalary);
          scanf("%f",&newmember.jxsalary);
		  scanf("%f",&newmember.yfsalary);
		  scanf("%f",&newmember.grsalary);
		  scanf("%f",&newmember.reasalary);
		  fseek(fp,(long)sizeof(struct member),SEEK_CUR);//�ļ�ָ��ָ���޸ĵļ�¼��ͷ
		  fwrite(&newmember,sizeof(struct member),1,fp);//��newmember���ǵ�ǰ��¼
		  printf("�޸ĺ�\n");
		  fseek(fp,0,SEEK_SET);//��ʾ�޸ĺ���ļ�����
		  printf("�޸ĺ��ְ����ϢΪ��\n");
		  for(i=0;fread(&zggz[i],sizeof(struct member),1,fp)!=0;i++)
			 {
				 printf("%6d",i+1);
	             printf("%s",zggz[i].name);
			     printf("%s",zggz[i].ID);
			     printf("%f",zggz[i].gwsalary);
                 printf("%f",zggz[i].ransalary);
			     printf("%f",zggz[i].zwsalary);
			     printf("%f",zggz[i].jxsalary);
	   	         printf("%f",zggz[i].yfsalary);
			     printf("%f",zggz[i].grsalary);
			     printf("%f",zggz[i].reasalary);
		  }
		  fclose(fp);

	
}
  
void del()
{
	FILE *fp;
	int i,j,n;	
	
	char gonghao[15];
    if((fp=open("gz,date","rb"))==NULL)
	{
		printf("cannot open this file\n");
			exit(1);
	
	}
	
	printf("��������Ҫɾ�����˵Ĺ���");
	scanf("%s",gonghao);
	for(i=0;(strcmp(zggz[n].ID,gonghao)!=0&&i<n);i++)
	
		if(i>=n)
		{
			printf("û��%s��ŵ�ְ��\n",gonghao);
			exit(2);

		}
		fcolse(fp);
		fp=fopen("gz.date","w+");       //ע��
		if(n==1)                      //һ����¼��ɾ��
		{
			fclose(fp);
			exit(3);
		}
		for(j=0;j<i;j++)
			fwrite(&zggz[j],sizeof(struct member),1,fp);
            for(j=i+1;j<n;j++)
				fwrite(&zggz[j],sizeof(struct member),1,fp);


			printf("ɾ����\n");
			fseek(fp,0,SEEK_SET);
			printf("���ְ����Ϣ\n");
			for(i=0;fread(&zggz[i],sizeof(struct member),1,fp),1,fp);i++)
			{
			printf("%s",zggz[i].name);
			printf("%s",zggz[i].ID);
			printf("%f",zggz[i].gwsalary);
            printf("%f",zggz[i].ransalary);
			printf("%f",zggz[i].zwsalary);
			printf("%f",zggz[i].jxsalary);
		    printf("%f",zggz[i].yfsalary);
			printf("%f",zggz[i].grsalary);
			printf("%f",zggz[i].reasalary);
			}
						
			fclose(fp);


	

	                             //for(n=0;fread(&zggz[n],sizeof(struct member),1,fp);n++)//n Ϊ�ļ��еļ�¼��
    




      /*	printf("ɾ���ɹ���");

	for(i=0;i<y;i++)
	{
		if(strcmp(gonghao,zggz[i].ID))
		{
			while(i<y)
			{
				strcpy(zggz[i].name,zggz[i+1].name);
				strcpy(zggz[i].ID,zggz[i+1].ID);
				zggz[i].gwsalary=zggz[i+1].gwsalary;
				zggz[i].ransalary=zggz[i+1].ransalary;
				zggz[i].zwsalary=zggz[i+1].zwsalary;
				zggz[i].jxsalary=zggz[i+1].jxsalary;
                zggz[i].yfsalary=zggz[i+1].yfsalary;
				zggz[i].grsalary=zggz[i+1].grsalary;
				zggz[i].reasaraly=zggz[i+1].reasaraly;
                   
				i=i+1;



			}
		  x=x+1;

		
		}
		if(x==0)
		{ 
			
		}


	}

	return y-x;

}
*/

void add()//
{
	FILE *fp;
	int i,j;
	n=n+1;
	
	if((fp=fopen("gz.date","ab+"))==NULL)
	{
		printf("���ܴ��ļ���\n");
		exit(0);
		

	}
	printf("������ְ����Ϣ \n");
	scanf("%s%f%f%%f",zggz[n+1].name,,,,,,,,
	scanf("%s",&zggz[n+1].ID);
	scanf("%f",&zggz[n+1].gwsalary);
	scanf("%f",&zggz[n+1].ranksalary);
	scanf("%f",&zggz[n+1].zwsalary);
	scanf("%f",&zggz[n+1].jxsalary);
	scanf("%f",&zggz[n+1].yfsalary);
	scanf("%f",&zggz[n+1].grsalary);
	scanf("%f",&zggz[n+1].reasalary);

	fwrite(&zggz[n+1],sizeof(struct member),1,fp);//����Ա��д���ļ���

	fclose(fp);
}

	




                                                //Ҫ����Ӧ�����ʣ���������˰


                                                      /*for(i=0;i<y;i++)
  	                                                     {
		                                                if(strcmp(str,a[i].ID)==0)
	                                                  	{
			                                                x=i;
			                                              for(i=y;i>x+1;i--)

		                                                         }*/
	}


}


int grsds(zggz[],int y)//�����������˰�����ո�������˰˰�ʱ������㣬˰�ʱ����4.1��ʾ��
{
	FILE *fp;
	int n ,num;
	if((fp=fopen("gz.date","rb"))==NULL)
	{
		printf("���ܴ�gx.date�ļ���\n");
		exit(1);
	}
		printf("�����빤������\n");
		scanf("%d",&yfsalary);  //?num ��λ���ʡ�н�����ʡ�ְ���������Ч���ʡ�Ӧ�����ʡ���������˰��ʵ������
		if(yfsalary<500)
			grsalary=yfsalary*0.05;
		else if(yfsalary>500&&yfsalary<2000)
		{ grsalary=yfsalary*0.1;  }
		else if(yfsalary>2000&&yfsalary<5000)
		{grsalary=yfsalary*0.15;  }
		else if(yfsalary>5000&&yfsalary<20000)
		{grsalsry=yfsalary*0.2;   }
		else if(yfsalary>20000&&yfsalary<40000)
		{grsalary=yfsalary*0.25;  }
		else if(yfsalary>40000&&yfsalary<60000)
		{grsalary=yfsalary*0.3;   }
		else if(yfsalary>60000&&yfsalary<80000)
		{grsalary=yfsalary*0.35;  }
		else if(yfsalary>80000&&yfsalary<100000)
		{grsalary=yfsalary*0.4;   }
		else if(yfsalary>100000)
		{ grsalary=yfsalary*0.45; }





}


int main()
{
	read();
	ptintf("ְ�����ʹ���ϵͳ\n");
	int n,m;
	do
	{

	}

















return 0;
}

