
#include<stdio.h>                                  
#include<conio.h>
#include<string.h>
void read(struct member zggz[]);
void write(struct member zggz[]);
void find(struct member zggz[]);
void list(struct member zggz[]);
void modify(struct member zggz[]);
void del(struct member zggz[]);
void add(struct member zggz[]);
float grsds(float a);

int n=0;//��¼Ա��������ȫ�ֱ���
                                   
 struct member{
	char name[15];//����
	char ID[15];                // ��λ���ʡ�н�����ʡ�ְ���������Ч���ʡ�Ӧ�����ʡ���������˰��ʵ������
	float gwsalary;
	float ransalary;
	float zwsalary;
	float jxsalary;
    float yfsalary;
	float grsalary;
	float reasalary;

};  
 struct member zggz[100];
void main()
{
	char ch;
    struct member zgg[100];
	read(zgg);
            	
	   
			printf("ְ�����ʹ���ϵͳ\n");
			printf("��ѡ��1-7��\n");			
			printf("=========================================================\n");
			printf("|               1.��ѯְ�����ʼ�¼                      |\n");
	      	printf("|               2.�޸�ְ�����ʼ�¼                      |\n");
		    printf("|               3.���ְ�����ʼ�¼                      |\n");
	     	printf("|               4.ɾ��ְ�����ʼ�¼                      |\n");
		    printf("|               5.����ְ�����ʼ�¼                      |\n");
	     	printf("|               6.���ְ����¼                          |\n");
		    printf("|               7.�˳�ϵͳ                              |\n");
	     	printf("=========================================================\n");
		    printf("���ѡ���ǣ�\n");
			ch=getch();
		   
		                              
			switch(ch)
			{
			case '1':find(zgg);break;
			case '2':modify(zgg);break;
			case '3':add(zgg);break;
			case '4':del(zgg);break;
			case '5':write(zgg);break;
			case '6':list(zgg);break;
			case '7': return;
			default:printf("����������أ�����ѡ��");//�˳�ϵͳ��

			getch();
			}
							
}





void read(struct member zggz[])  //�������ļ��ж�ȡְ���������ݡ���ʼ��ְ�����ʽṹ�����鲢ͳ�Ƶ�ǰ�����ļ���ְ������������ְ����������ȫ�ֱ���n�У��Ա�����
{                  
	  
	     FILE *fp;
	     struct  member z;                                           
		 if ((fp=fopen("gz.dat","rb"))==NULL){       //ֻ�򿪻���һ���������ļ�gz.date�������ļ��ж�ȡְ����������
          
			printf("cannot open this file\n");
			getch();
            return;
		}                                       


			while(!feof(fp))
	{
		fscanf(fp,"%s\t",z.ID);
		fscanf(fp,"%s\t",z.name);
		fscanf(fp,"%f\t",&z.gwsalary);
		fscanf(fp,"%f\t",&z.ransalary);
		fscanf(fp,"%f\t",&z.zwsalary);
		fscanf(fp,"%f\t",&z.jxsalary);
		fscanf(fp,"%f\t",&z.yfsalary);
		fscanf(fp,"%f\t",&z.grsalary);
		fscanf(fp,"%f\n",&z.reasalary);
		zggz[n]=z;
		n++;   //����ְ������
	}
			printf("%s\t",zggz[0].ID);


	    fclose(fp);    //�ر�ָ���ļ���
     	printf("ְ�����ʶ�ȡ��ϣ�����%d�ˣ�\n",n);
		
		

	
}

		  
                                  
void write(struct member zggz[])     //��zggz�ṹ�������еļ�¼���浽gz.dat�����ļ��С�         
                                              
{  
	    FILE *fp;
		int i;
		if(n==0)//ְ������Ϊ0
		{
			printf("û�����ݣ�\n");
			getch();
			return;
		}
		
		if ((fp=fopen("gz.dat","wb"))!=NULL)  //�Զ����ƴ��ļ������ж��Ƿ�ʧ��
		{
		
		

			for(i=0;i<n;i++)
			{
				fprintf(fp,"%s\t",zggz[i].ID);
		        fprintf(fp,"%s\t",zggz[i].name);
		        fprintf(fp,"%f\t",zggz[i].gwsalary);
		        fprintf(fp,"%f\t",zggz[i].ransalary);
		        fprintf(fp,"%f\t",zggz[i].zwsalary);
		        fprintf(fp,"%f\t",zggz[i].jxsalary);
		        fprintf(fp,"%f\t",zggz[i].yfsalary);
		        fprintf(fp,"%f\t",zggz[i].grsalary);
		        fprintf(fp,"%f\n",zggz[i].reasalary);
			}
			
				

		fclose(fp);
	

        printf("\n\n\t%d��ְ����¼������ϣ�\n",n);

		}
		else 
                                              
        printf("cannot open this file\n");
		printf("��������������˵�\n");
		getch();
		return;
		

}   

void find(struct member zggz[])         //���ݹ��Ų�ѯ��Ӧְ���Ĺ��ʼ�¼
{   
	FILE *fp;
	int i;	
	int flag;
	char gonghao[15];
    if((fp=fopen("gz.dat","rb"))==NULL)
	{
		printf("cannot open this file\n");
		getch();
        return;
	
	}
	
    printf("������Ҫ���ҵı�ţ�\n");
    scanf("%s",gonghao);

	for(i=0;i<n;i++)
	{
		if(strcmp(zggz[i].ID,gonghao)==0)                               //�Ƚϲ��ҵ�  
		{
			flag=1;   
			break;
		}
	}
		if(flag)
		{

		      printf("��ְ���Ĺ���������£�\n");                   
 
		printf("Ա�����Ϊ��%s\n",zggz[i].ID);
		printf("Ա������Ϊ��%s\n",zggz[i].name);  
		printf("Ա����λ����Ϊ��%f\n",zggz[i].gwsalary);
		printf("Ա��н������Ϊ��%f\n",zggz[i].ransalary);
		printf("Ա��ְ�����Ϊ��%f\n",zggz[i].zwsalary);
		printf("Ա����Ч����Ϊ��%f\n", zggz[i].jxsalary);
		printf("Ա��Ӧ������Ϊ��%f\n",zggz[i].yfsalary);
		printf("Ա����������˰Ϊ��%f\n",zggz[i].grsalary);
		printf("Ա��ʵ������Ϊ��%f\n",  zggz[i].reasalary);

		}

		else
		{
			printf("δ�ҵ���Ա�� \n");
		}

	fclose(fp);


}
	

void list(struct member zggz[])
{
	
	int i;		  
	for(i=0;i<n;i++)                                               
	{
		printf("Ա�����Ϊ��%s\n",zggz[i].ID);
		printf("Ա������Ϊ��%s\n",zggz[i].name);  
		printf("Ա����λ����Ϊ��%f\n",zggz[i].gwsalary);
		printf("Ա��н������Ϊ��%f\n",zggz[i].ransalary);
		printf("Ա��ְ�����Ϊ��%f\n",zggz[i].zwsalary);
		printf("Ա����Ч����Ϊ��%f\n", zggz[i].jxsalary);
		printf("Ա��Ӧ������Ϊ��%f\n",zggz[i].yfsalary);
		printf("Ա����������˰Ϊ��%f\n",zggz[i].grsalary);
		printf("Ա��ʵ������Ϊ��%f\n",  zggz[i].reasalary);
				
	}
	
	                  
	return;
}

void modify(struct member zggz[])                  //ָ�����ţ��޸ĸ�ְ���Ĺ��ʼ�¼������Ҫ����grsds()���������������˰��
{
	FILE *fp;
	int i;
	char gonghao[15];

    if((fp=fopen("gz.dat","rb+"))==NULL)
	{
		printf("cannot open this file\n");
		getch();
	    return;
	
	}
	if(n==0)
	{
		printf("��ǰ��û��ְ����¼....\n");
		getch();
		return;
	}
	
 	printf("��������Ҫ�޸ĵĹ���\n");
    gets(gonghao);
	for(i=0;i<=n;i++)
	{
		if(strcmp(zggz[i].ID,gonghao)==0)//�Ƚϲ��ҵ�
		{
			printf("�����ְ������Ϣ");
		    printf("������%s\n",zggz[i].ID);
            printf("���ţ�%s\n",zggz[i].name);
	        printf("��λ���ʣ�%f\n",zggz[i].gwsalary);
            printf("н�����ʣ�%f\n",zggz[i].ransalary);
			printf("ְ�������%f\n",zggz[i].zwsalary);
			printf("��Ч���ʣ�%f\n",zggz[i].jxsalary);
		    printf("Ӧ�����ʣ�%f\n",zggz[i].yfsalary);
			printf("��������˰��%f\n",zggz[i].grsalary);
			printf("ʵ�����ʣ�%f\n",zggz[i].reasalary);	

			printf("�������ְ���µ���Ϣ\n");
		    scanf("%s",&zggz[i].ID);
		    scanf("%s",&zggz[i].name);
		    scanf("%f",&zggz[i].gwsalary);
		    scanf("%f",&zggz[i].ransalary);
            scanf("%f",&zggz[i].zwsalary);
            scanf("%f",&zggz[i].jxsalary);
		    zggz[i].yfsalary=zggz[i].gwsalary+zggz[i].ransalary+zggz[i].zwsalary+zggz[i].jxsalary;
		    zggz[i].grsalary=grsds(zggz[i].yfsalary);
		    zggz[i].reasalary=zggz[i].yfsalary-zggz[i].grsalary;


			fprintf(fp,"%s\t%s\t%f\t%f\t%f\t%f\t%f\t%f\t%f\n",zggz[i].ID,zggz[i].name,zggz[i].gwsalary,
				 zggz[i].ransalary,zggz[i].zwsalary,zggz[i].jxsalary,
				 zggz[i].yfsalary,zggz[i].grsalary,zggz[i].reasalary);//д���ļ�

		    printf("\n��ְ��Ӧ�������ǣ�%f\n",zggz[i].yfsalary);
		    printf("\n��ְ����������˰�ǣ�%f\n",zggz[i].grsalary);
		    printf("\n��ְ��ʵ�������ǣ�%f\n",zggz[i].reasalary);

             printf("\n��������������˵�\n");
             getch();
			 return;
		}
	}

		printf("�������ְ���������޻򲻴���\n");
		 getch();
		 return;
		 fclose(fp);


}
		 	
  
void del(struct member zggz[])
{
	FILE *fp;
	char gonghao[15];/*����ְ�������ַ�����*/

    int i,j;	/*ѭ������*/

    char d;	/*����ȷ��ɾ���ַ���y/n*/

	if((fp=fopen("gz.dat","rb+"))==NULL){
	
		printf("cannot open the file!\n");
		printf("\n�������������ҳ��");
		getch();
		return;
	}

    printf("\t�������ɾ��ְ�����ţ�");

    gets(gonghao);
  
    for(i=0;i<=n;i++)/*��ְ��������Χ��ѭ������*/
	{
		if(strcmp(zggz[i].ID,gonghao)==0)/*�Ƚϲ��ҵ�*/
		{
			printf("\n\t\t��ȷ��Ҫɾ��%s��ְ��������Ϣ��(y/n)��",zggz[i].ID);
			d=getche();
			if(d=='y'||d=='Y')/*ȷ��ɾ��*/
			{
				if(i==n)/*��������һ����¼*/
					n=n-1;
				else	/*�������һ����¼ʱ*/
				{
					for(j=i;j<n;j++)/*�Ӹü�¼��ʼ������¼����ǰһ����¼*/
					{
						strcpy(zggz[j].ID,zggz[j+1].ID);
						strcpy(zggz[j].name,zggz[j+1].name);
                       	zggz[j].gwsalary=zggz[j+1].gwsalary;
			         	zggz[j].ransalary=zggz[j+1].ransalary;
				        zggz[j].zwsalary=zggz[j+1].zwsalary;
				        zggz[j].jxsalary=zggz[j+1].jxsalary;
                        zggz[j].yfsalary=zggz[j+1].yfsalary;
				        zggz[j].grsalary=zggz[j+1].grsalary;
				        zggz[j].reasalary=zggz[j+1].reasalary;
					}
					n--;
					write(zggz);
				}
				printf("\n\n\t\t��ְ����¼�ɹ�ɾ������������������˵�����");
				list(zggz);
				getch();
				break;
			}
			else	/*δȷ��ɾ����¼*/
			{
				printf("\n\n\t\t��ѡ���˲�ɾ����ְ����¼����������������˵�����");
				getch();
				return;
			}
		}
	}
	if(i==n+1)	/*δ�ҵ�ָ�����Ż�δɾ����¼*/
	{
		printf("\n\t\t����λ�޴˹��ţ���������������˵�����");
		getch();
	}
}

	

void add(struct member zggz[])//
{
	FILE *fp;
	

	struct member z;
	if((fp=fopen("gz.dat","rb+"))==NULL)
	{
		printf("���ܴ��ļ���\n");
		
		 getch();
         return;

	}
	printf("�������µ�ְ����Ϣ \n");

    printf("\n�����빤�ţ�");
	scanf("%s",z.ID);
	printf("\n������������");
	scanf("%s",z.name);

    printf("\n�������λ���ʣ�");
	scanf("%f",&z.gwsalary);

	printf("\n������н�����ʣ�");
	scanf("%f",&z.ransalary);

	printf("\n������ְ���ʣ�");
	scanf("%f",&z.zwsalary);

	printf("�����뼨Ч���ʣ�");
    scanf("%f",&z.jxsalary);  //����Ӧ�����ʣ���������˰��ʵ������
	
	z.yfsalary=z.gwsalary+z.ransalary+z.zwsalary+z.jxsalary;
    z.grsalary=grsds(z.yfsalary);
	z.reasalary=z.yfsalary-z.grsalary;

	 zggz[n]=z;
	 n++;
	 printf("\nԱ����Ϣ�Ѿ����\n");
	 write(zggz);//д���ļ�

     fclose(fp);
	 printf("\n��������������˵�\n");
	 getch();
     return;

}


float grsds(float a)  //�����������˰�����ո�������˰˰�ʱ������㣬˰�ʱ����4.1��ʾ��

{

        float x;	/*����Ӧ��˰���ö�*/

        float y=0;	/*����Ӧ��˰��*/
        x=a;

        if(x<500)
			y=y+float(x*0.05);

        else if(x<2000)
			y=y+float((x-500)*0.10+500*0.05);

        else if(x<5000)
			y=y+float((x-2000)*0.15+1500*0.10+500*0.05);

        else if(x<20000)
			
        y=y+float((x-5000)*0.2+3000*0.15+1500*0.10+500*0.05);
       
        else if(x<40000)
			y=y+float((x-20000)*0.25+15000*0.2+3000*0.15+1500*0.10+500*0.05);

       

        else if(x<60000)
			y=y+float((x-40000)*0.3+20000*0.25+15000*0.2+3000*0.15+1500*0.10+500*0.05);
        

        else if(x<80000)
				y=y+float((x-60000)*0.35+20000*0.3+20000*0.25+15000*0.2+3000*0.15+1500*0.10+500*0.05);

       

        else if(x<100000)
			y=y+float((x-80000)*0.4+20000*0.35+20000*0.3+20000*0.25+15000*0.2+3000*0.15+1500*0.10+500*0.05);

        else 
			y=y+float((x-100000)*0.45+20000*0.4+20000*0.35+20000*0.3+20000*0.25+15000*0.2+3000*0.15+1500*0.10+500*0.05);

   
     return y;

}





