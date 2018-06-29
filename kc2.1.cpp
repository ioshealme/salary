#include<iostream>
#include<stdio.h>                                   //#include<stdlib.h>
#include<conio.h>
#include<string.h>

void read();
void write();
void find();
void list();
void modify();
void del();
void add();
float grsds(float m);

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

}zggz[50];                          //member1[50],newmember;;// 

void main()
{
	int n,w1;
	read();

	
                      //,int n,m;;
	
	    do
		{
			printf("职工工资管理系统\n");		
			printf("=========================================================\n");
			printf("|               1.查询职工工资记录                      |\n");
	      	printf("|               2.修改职工工资记录                      |\n");
		    printf("|               3.添加职工工资记录                      |\n");
	     	printf("|               4.删除职工工资记录                      |\n");
		    printf("|               5.保存职工工资记录                      |\n");
	     	printf("|               6.浏览职工记录                          |\n");
		    printf("|               7.退出系统                              |\n");
	     	printf("=========================================================\n");
		    printf("请选择1-7：\n");

		    printf("你的选择是：\n");
		    scanf("%d",&n);
		    if(n<7||n>7)
			{
				w1=1;
				printf("你的输入不正确：\n");
				getchar();


			}
			else w1=0;
		}

	                                 	//	printf("你的输入不正确，请重新输入1-7的数字\n");
		   while(w1==1);
			switch(n)
			{
			case 1:find();break;
			case 2:modify();break;
			case 3:add();break;
			case 4:del();break;
			case 5:write();break;
			case 6:list();break;
			case 7:return;
			default:printf("按任意键返回，重新选择");//退出系统，
			}
							
			
			
	}

 
}

void read()
{           //从数据文件中读取职工工资数据、初始化职工工资结构体数组并统计当前数据文件中职工人数，并将职工人数存在全局变量n中，以备其他函数使用。
	  
	   FILE *fp;
		int i;                                  //ofstream fout1("gx.date",ios::binary); n 为记录员工的数量
		if ((fp=fopen("gx.date","wb"))==NULL){  //用二进制打开文件gx.date从数据文件中读取职工工资数据
            printf("cannot open this file\n");
			exit(1);
		}                                       //并将职工人数存在全局变量n中，以备其他函数使用。
	
	

		else
	{  
 //en("gx.date","rb");//打开文件

		n=n+1;    //n++
	    fseek(fp,0,SEEK_END);  //文件指针移到文件尾  ?
		while(fread(&zggz[n],sizeof(zggz[n]),1,fp)==1)
		n=n+1;
	    fclose(fp);//关闭指针文件。
     	printf("职工工资读取完毕，共有%d人！",n);
		
		}

	
}

       /*for(int i=0;i<n;i++)     //初始化职工信息
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
	 */
	
	

  
  
void write()               //将zggz结构体数组中的记录保存到gz.dat数据文件中。
{  
	FILE *fp;
        

		if(n>0)
	{
		                                          //ofstream fout1("gx.date",ios::binary);
		if ((fp=fopen("gz.dat","wb"))==NULL){ //用二进制打开文件gx.date从数据文件中读取职工工资数据、read函数 初始化职工工资结构体数组并统计当前数据文件中职工
                                                 //人数，
            printf("cannot open this file\n");
			exit(-1);

		}                                       
	for(int i=0;i<n;i++)
	{ 
		
	     fwrite(&zggz[i],sizeof(struct member),n,fp);  //写n次，每次长度是member的长度,将n个员工写入文件gz. 对的
         rewind(fp);//复位置偏移量到初始状态；

		 fclose(fp);
	}
         
	}
		
}


void find()         //根据工号查询相应职工的工资记录
{   
	FILE *fp;
	int i;	
	char gonghao[15];
    if((fp=fopen("gz.date","rb"))==NULL)
	{
		printf("cannot open this file\n");
			exit(1);
	
	}
	
    printf("请输入要查找的编号：\n");
    scanf("%s",gonghao);
	for(i=0;fread(&zggz[i],sizeof(struct member),1,fp)!=0;i++)
		if(!strcmp(zggz[i].ID,gonghao)) break;
    if(feof(fp))
	{
		printf("未找到该员工：\n");

		exit(2);

	}
	
		printf("员工编号为：%s",zggz[i].ID);
		printf("员工姓名为：%s",zggz[i].name);  
		printf("员工岗位工资为：%f",zggz[i].gwsalary);
		printf("员工薪级工资为：%f",zggz[i].ransalary);
		printf("员工职务津贴为：%f",zggz[i].zwsalary);
		printf("员工绩效工资为：%f", zggz[i].jxsalary);
		printf("员工应发工资为：%f",zggz[i].yfsalary);
		printf("员工个人所得税为：%f",zggz[i].grsalary);
		printf("员工实发工资为：%f",  zggz[i].reasalary);
		i=i+1;

		
	

	


	fclose(fp);





	
		

}

void list()// 
{
	FILE *fp;
	int i;	
	
    if((fp=fopen("gz.date","rb"))==NULL)
	{
		printf("cannot open this file\n");
			exit(0);
	
	}
	printf("浏览员工的数据");
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

void modify()                  //指定工号，修改该职工的工资记录，其中要调用grsds()函数计算个人所得税。
{
	FILE *fp;
	int i;
	char gonghao[15];

    if((fp=fopen("gz,date","rb+"))==NULL)
	{
		printf("cannot open this file\n");
			exit(1);
	
	}
	
 	printf("请输入你要修改的工号");
    scanf("%s",gonghao);//从这开始不一样，另一种的
	for(i=0;i<=n;i++)
	{
		 printf("输出该职工的信息");
		 printf("%s",zggz[i].name);
          printf("%s",zggz[i].ID);
	      printf("%f",zggz[i].gwsalary);
            printf("%f",zggz[i].ransalary);
			printf("%f",zggz[i].zwsalary);
			printf("%f",zggz[i].jxsalary);
		    printf("%f",zggz[i].yfsalary);
			printf("%f",zggz[i].grsalary);
			printf("%f",zggz[i].reasalary);	

			printf("请输入该职工新的信息");
			 scanf("%s",&zggz[i].name);
		  scanf("%s",&zggz[i].ID);
		  scanf("%f",&zggz[i].gwsalary);
		  scanf("%f",&zggz[i].ransalary);
          scanf("%f",&zggz[i].zwsalary);
          scanf("%f",&zggz[i].jxsalary);
		  scanf("%f",&zggz[i].yfsalary);
		  scanf("%f",&zggz[i].grsalary);
		  scanf("%f",&zggz[i].reasalary);

		  zggz[i].yfsalsry=zggz[i].gwsalary+zggz[i].xjsalary+zggz[i].zwsalary+zggz[i].jxsalary;
		  zggz[i].grsds=grsds(zggz[i].yfsalsry);
		  zggz[i].reasalary=zggz[i].yfsalary-zggz[i].grsds;

		  return;


	}


	/*

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
		  */


		  fclose(fp);

	
}
  
void del()
{
	char gonghao[15];/*接收职工工号字符数组*/

    int i,j;	/*循环变量*/

    char d;	/*接收确认删除字符：y/n*/

    printf("\t请输入待删除职工工号：");

    gets(gonghao);
  
    for(i=0;i<=n;i++)/*在职工总数范围内循环查找*/
	{
		if(strcmp(zggz[i].gonghao,gonghao)==0)/*比较并找到*/
		{
			printf("\n\t\t你确认要删除%s号职工工资信息吗(y/n)？",zggz[i].gonghao);
			d=getche();
			if(d=='y'||d=='Y')/*确认删除*/
			{
				if(i==n)/*如果是最后一条记录*/
					n--;
				else	/*不是最后一条记录时*/
				{
					for(j=i;j<=n;j++)/*从该记录开始后续记录更新前一条记录*/
					{
						strcpy(zggz[j].name,zggz[j+1].name);
						strcpy(zggz[j].ID,zggz[j+1].ID);

                       	zggz[j].gwsalary=zggz[j+1].gwsalary;
			         	zggz[j].ransalary=zggz[j+1].ransalary;
				        zggz[j].zwsalary=zggz[j+1].zwsalary;
				        zggz[j].jxsalary=zggz[j+1].jxsalary;
                        zggz[j].yfsalary=zggz[j+1].yfsalary;
				        zggz[j].grsalary=zggz[j+1].grsalary;
				        zggz[j].reasaraly=zggz[j+1].reasaraly;
					}
					n--;
				}
				printf("\n\n\t\t该职工记录成功删除，按任意键返回主菜单……");
				getch();
				break;
			}
			else	/*未确认删除记录*/
			{
				printf("\n\n\t\t你选择了不删除该职工记录，按任意键返回主菜单……");
				getch();
				return;
			}
		}
	}
	if(i==n+1)	/*未找到指定工号或未删除记录*/
	{
		printf("\n\t\t本单位无此工号，按任意键返回主菜单……");
		getch();
	}
}

	/*FILE *fp;
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
						
			fclose(fp);*/


	

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
	printf("请输入新的职工信息 \n");

	scanf("%s",zggz[n+1].name);
	scanf("%s",zggz[n+1].ID);
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








float grsds(float m)  //计算个人所得税，按照个人所得税税率表来计算，税率表如表4.1所示。

{

        float x;	/*当月应纳税所得额*/

        float y=0;	/*当月应纳税额*/

        int n;

        x=m-2000;

        if(x>0)

        if(x<500)
        n=1;

        else if(x<2000)
        n=2;

        else if(x<5000)
        n=3;

        else if(x<20000)
        n=4;

        else if(x<40000)
        n=5;

        else if(x<60000)
        n=6;

        else if(x<80000)
        n=7;

        else if(x<100000)
        n=8;

        else n=9;

        switch(n)	/*此处利用case的特点*/
		{
		case 9:y=(x-100000)*0.45;x=100000;

        case 8:y+=(x-80000)*0.40;x=80000;

        case 7:y+=(x-60000)*0.35;x=60000;

        case 6:y+=(x-40000)*0.30;x=40000;

        case 5:y+=(x-20000)*0.25;x=20000;
 
        case 4:y+=(x-5000)*0.20;x=5000;
 
        case 3:y+=(x-2000)*0.15;x=2000;

        case 2:y+=(x-500)*0.10;x=500;

        case 1:y+=x*0.05;

		}

     return y;

}





	/*
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


*/

//fclose(fp);
