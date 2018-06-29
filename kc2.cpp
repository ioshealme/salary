#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string>
#include<fstream>

int n=0;//记录员工数量，全局变量
using namespace std;
struct member{
	char name[50];//姓名
	char ID[50];                // 岗位工资、薪级工资、职务津贴、绩效工资、应发工资、个人所得税、实发工资
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
		  int i;                                        //ofstream fout1("gx.date",ios::binary); n 为记录员工的数量
		if ((fp=fopen("gx.date","wb"))==NULL){   //用二进制打开文件gx.date从数据文件中读取职工工资数据、read函数 初始化职工工资结构体数组并统计当前数据文件中职工
                                                 //人数，
            printf("cannot build this file\n");
			exit(1);
		}                                       //并将职工人数存在全局变量n中，以备其他函数使用。
	
	

	if(fp)
	{  
		fp=fopen("gx.date","rb");//打开文件
	    fseek(fp,0,SEEK_END);   //文件指针移到文件尾  
      for(int i=0;i<n;i++)     //初始化职工信息
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
           
		  n=n+1;//统计输入的员工人数
		
	
	  }
	  for(i=n;i>0;i--)//将数据赋值给zggz结构体数组
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
  

void write()               //将zggz结构体数组中的记录保存到gz.dat数据文件中。
{  
	FILE *fp;
        

		if(n>0)
	{
		                                          //ofstream fout1("gx.date",ios::binary);
		if ((fp=fopen("gx.date","wb+")==NULL){   //用二进制打开文件gx.date从数据文件中读取职工工资数据、read函数 初始化职工工资结构体数组并统计当前数据文件中职工
                                                 //人数，
            printf("cannot open this file\n");
			exit(-1);

		}                                       
	for(int i=0;i<n;i++)
	{ 
		
	     fwrite(&zggz[i],sizeof(struct member),1,fp);  //写一次，每次长度是member的长度,将n个员工写入文件
         rewind(fp);//复位置偏移量到初始状态；

		 fclose(fp);
		 	    

         
	}
		

	}

void find()         //根据工号查询相应职工的工资记录
{   
	FILE *fp;
	int i;	
	char gonghaop[15];
    if((fp=open("gz,date","rb"))==NULL)
	{
		printf("cannot open this file\n");
			exit(1);
	
	}
	
    printf("请输入要查找的编号：\n");
    scanf("%s",gonghao);
	for(i=0;fread(&zggz[i],sizeof(struct member),1,fp)!=0;i++)
	{
		print("员工编号为：%s",zggz[i].ID);
		printf("员工姓名为：%s",zggz[i].name);  
		printf("员工岗位工资为：%f",zggz[i].gwsalary);
		printf("员工薪级工资为：%f",zggz[i].ransalary);
		printf("员工职务津贴为：%f",zggz[i].zwsalary);
		printf("员工绩效工资为：%f", zggz[i].jxsalary);
		printf("员工应发工资为：%f",zggz[i].yfsalary);
		printf("员工个人所得税为：%f",zggz[i].grsalary);
		printf("员工实发工资为：%f",  zggz[i].reasalary);
		i=i+1;

		
	}

	if(!strcmp(zggz[i].ID,gonghao));
    if(feof(fp))
	{
		printf("未找到该员工：\n");

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
	printf("浏览员工的数据");
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

void modify()                  //指定工号，修改该职工的工资记录，其中要调用grsds()函数计算个人所得税。
{
	FILE *fp;
	int i,j;	
	char gonghao[15];

    if((fp=open("gz,date","rb+"))==NULL)
	{
		printf("cannot open this file\n");
			exit(1);
	
	}
	
	printf("请输入你要修改的工号")；
    scanf("%s",gonghao);

	for(i=0;fread(&zggz[i],sizeof(struct member),1,fp);i++)
		if(!strcmp(zggz[i].ID,gonghao))break;
	if(feof(fp))
	{
		printf("未找到该员工：\n");

		exit(2);

	}
	    printf("输出职工的信息\n");
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
					
           printf("输入格式：姓名，职工号，岗位工资，薪级工资，职务工资，绩效工资，应发工资，个人税，真实工资\n");
		   printf("第%d个记录",i+1);
		  scanf("%s",&newmember.name);//获取职工新的信息
		  scanf("%s",&newmember.ID);
		  scanf("%f",&newmember.gwsalary);
		  scanf("%f",&newmember.ransalary);
          scanf("%f",&newmember.zwsalary);
          scanf("%f",&newmember.jxsalary);
		  scanf("%f",&newmember.yfsalary);
		  scanf("%f",&newmember.grsalary);
		  scanf("%f",&newmember.reasalary);
		  fseek(fp,(long)sizeof(struct member),SEEK_CUR);//文件指针指向修改的记录开头
		  fwrite(&newmember,sizeof(struct member),1,fp);//用newmember覆盖当前记录
		  printf("修改后\n");
		  fseek(fp,0,SEEK_SET);//显示修改后的文件数据
		  printf("修改后的职工信息为：\n");
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
	
	printf("请输入你要删除的人的工号");
	scanf("%s",gonghao);
	for(i=0;(strcmp(zggz[n].ID,gonghao)!=0&&i<n);i++)
	
		if(i>=n)
		{
			printf("没有%s编号的职工\n",gonghao);
			exit(2);

		}
		fcolse(fp);
		fp=fopen("gz.date","w+");       //注意
		if(n==1)                      //一个记录已删除
		{
			fclose(fp);
			exit(3);
		}
		for(j=0;j<i;j++)
			fwrite(&zggz[j],sizeof(struct member),1,fp);
            for(j=i+1;j<n;j++)
				fwrite(&zggz[j],sizeof(struct member),1,fp);


			printf("删除后\n");
			fseek(fp,0,SEEK_SET);
			printf("输出职工信息\n");
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


	

	                             //for(n=0;fread(&zggz[n],sizeof(struct member),1,fp);n++)//n 为文件中的记录数
    




      /*	printf("删除成功！");

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
		printf("不能打开文件：\n");
		exit(0);
		

	}
	printf("请输入职工信息 \n");
	scanf("%s%f%f%%f",zggz[n+1].name,,,,,,,,
	scanf("%s",&zggz[n+1].ID);
	scanf("%f",&zggz[n+1].gwsalary);
	scanf("%f",&zggz[n+1].ranksalary);
	scanf("%f",&zggz[n+1].zwsalary);
	scanf("%f",&zggz[n+1].jxsalary);
	scanf("%f",&zggz[n+1].yfsalary);
	scanf("%f",&zggz[n+1].grsalary);
	scanf("%f",&zggz[n+1].reasalary);

	fwrite(&zggz[n+1],sizeof(struct member),1,fp);//将该员工写入文件。

	fclose(fp);
}

	




                                                //要核算应发工资，个人所得税


                                                      /*for(i=0;i<y;i++)
  	                                                     {
		                                                if(strcmp(str,a[i].ID)==0)
	                                                  	{
			                                                x=i;
			                                              for(i=y;i>x+1;i--)

		                                                         }*/
	}


}


int grsds(zggz[],int y)//计算个人所得税，按照个人所得税税率表来计算，税率表如表4.1所示。
{
	FILE *fp;
	int n ,num;
	if((fp=fopen("gz.date","rb"))==NULL)
	{
		printf("不能打开gx.date文件：\n");
		exit(1);
	}
		printf("请输入工资数：\n");
		scanf("%d",&yfsalary);  //?num 岗位工资、薪级工资、职务津贴、绩效工资、应发工资、个人所得税、实发工资
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
	ptintf("职工工资管理系统\n");
	int n,m;
	do
	{

	}

















return 0;
}

