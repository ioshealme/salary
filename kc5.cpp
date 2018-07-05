
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

int n=0;//记录员工数量，全局变量
                                   
 struct member{
	char name[15];//姓名
	char ID[15];                // 岗位工资、薪级工资、职务津贴、绩效工资、应发工资、个人所得税、实发工资
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
            	
	   
			printf("职工工资管理系统\n");
			printf("请选择1-7：\n");			
			printf("=========================================================\n");
			printf("|               1.查询职工工资记录                      |\n");
	      	printf("|               2.修改职工工资记录                      |\n");
		    printf("|               3.添加职工工资记录                      |\n");
	     	printf("|               4.删除职工工资记录                      |\n");
		    printf("|               5.保存职工工资记录                      |\n");
	     	printf("|               6.浏览职工记录                          |\n");
		    printf("|               7.退出系统                              |\n");
	     	printf("=========================================================\n");
		    printf("你的选择是：\n");
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
			default:printf("按任意键返回，重新选择");//退出系统，

			getch();
			}
							
}





void read(struct member zggz[])  //从数据文件中读取职工工资数据、初始化职工工资结构体数组并统计当前数据文件中职工人数，并将职工人数存在全局变量n中，以备其他
{                  
	  
	     FILE *fp;
	     struct  member z;                                           
		 if ((fp=fopen("gz.dat","rb"))==NULL){       //只打开或建立一个二进制文件gz.date从数据文件中读取职工工资数据
          
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
		n++;   //计算职工人数
	}
			printf("%s\t",zggz[0].ID);


	    fclose(fp);    //关闭指针文件。
     	printf("职工工资读取完毕，共有%d人！\n",n);
		
		

	
}

		  
                                  
void write(struct member zggz[])     //将zggz结构体数组中的记录保存到gz.dat数据文件中。         
                                              
{  
	    FILE *fp;
		int i;
		if(n==0)//职工人数为0
		{
			printf("没有数据！\n");
			getch();
			return;
		}
		
		if ((fp=fopen("gz.dat","wb"))!=NULL)  //以二进制打开文件并并判断是否失败
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
	

        printf("\n\n\t%d条职工记录保存完毕！\n",n);

		}
		else 
                                              
        printf("cannot open this file\n");
		printf("按任意键返回主菜单\n");
		getch();
		return;
		

}   

void find(struct member zggz[])         //根据工号查询相应职工的工资记录
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
	
    printf("请输入要查找的编号：\n");
    scanf("%s",gonghao);

	for(i=0;i<n;i++)
	{
		if(strcmp(zggz[i].ID,gonghao)==0)                               //比较并找到  
		{
			flag=1;   
			break;
		}
	}
		if(flag)
		{

		      printf("该职工的工资情况如下：\n");                   
 
		printf("员工编号为：%s\n",zggz[i].ID);
		printf("员工姓名为：%s\n",zggz[i].name);  
		printf("员工岗位工资为：%f\n",zggz[i].gwsalary);
		printf("员工薪级工资为：%f\n",zggz[i].ransalary);
		printf("员工职务津贴为：%f\n",zggz[i].zwsalary);
		printf("员工绩效工资为：%f\n", zggz[i].jxsalary);
		printf("员工应发工资为：%f\n",zggz[i].yfsalary);
		printf("员工个人所得税为：%f\n",zggz[i].grsalary);
		printf("员工实发工资为：%f\n",  zggz[i].reasalary);

		}

		else
		{
			printf("未找到该员工 \n");
		}

	fclose(fp);


}
	

void list(struct member zggz[])
{
	
	int i;		  
	for(i=0;i<n;i++)                                               
	{
		printf("员工编号为：%s\n",zggz[i].ID);
		printf("员工姓名为：%s\n",zggz[i].name);  
		printf("员工岗位工资为：%f\n",zggz[i].gwsalary);
		printf("员工薪级工资为：%f\n",zggz[i].ransalary);
		printf("员工职务津贴为：%f\n",zggz[i].zwsalary);
		printf("员工绩效工资为：%f\n", zggz[i].jxsalary);
		printf("员工应发工资为：%f\n",zggz[i].yfsalary);
		printf("员工个人所得税为：%f\n",zggz[i].grsalary);
		printf("员工实发工资为：%f\n",  zggz[i].reasalary);
				
	}
	
	                  
	return;
}

void modify(struct member zggz[])                  //指定工号，修改该职工的工资记录，其中要调用grsds()函数计算个人所得税。
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
		printf("当前还没有职工记录....\n");
		getch();
		return;
	}
	
 	printf("请输入你要修改的工号\n");
    gets(gonghao);
	for(i=0;i<=n;i++)
	{
		if(strcmp(zggz[i].ID,gonghao)==0)//比较并找到
		{
			printf("输出该职工的信息");
		    printf("姓名：%s\n",zggz[i].ID);
            printf("工号：%s\n",zggz[i].name);
	        printf("岗位工资：%f\n",zggz[i].gwsalary);
            printf("薪级工资：%f\n",zggz[i].ransalary);
			printf("职务津贴：%f\n",zggz[i].zwsalary);
			printf("绩效工资：%f\n",zggz[i].jxsalary);
		    printf("应发工资：%f\n",zggz[i].yfsalary);
			printf("个人所得税：%f\n",zggz[i].grsalary);
			printf("实发工资：%f\n",zggz[i].reasalary);	

			printf("请输入该职工新的信息\n");
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
				 zggz[i].yfsalary,zggz[i].grsalary,zggz[i].reasalary);//写入文件

		    printf("\n该职工应发工资是：%f\n",zggz[i].yfsalary);
		    printf("\n该职工个人所得税是：%f\n",zggz[i].grsalary);
		    printf("\n该职工实发工资是：%f\n",zggz[i].reasalary);

             printf("\n按任意键返回主菜单\n");
             getch();
			 return;
		}
	}

		printf("你输入的职工工号有无或不存在\n");
		 getch();
		 return;
		 fclose(fp);


}
		 	
  
void del(struct member zggz[])
{
	FILE *fp;
	char gonghao[15];/*接收职工工号字符数组*/

    int i,j;	/*循环变量*/

    char d;	/*接收确认删除字符：y/n*/

	if((fp=fopen("gz.dat","rb+"))==NULL){
	
		printf("cannot open the file!\n");
		printf("\n按任意键返回主页：");
		getch();
		return;
	}

    printf("\t请输入待删除职工工号：");

    gets(gonghao);
  
    for(i=0;i<=n;i++)/*在职工总数范围内循环查找*/
	{
		if(strcmp(zggz[i].ID,gonghao)==0)/*比较并找到*/
		{
			printf("\n\t\t你确认要删除%s号职工工资信息吗(y/n)？",zggz[i].ID);
			d=getche();
			if(d=='y'||d=='Y')/*确认删除*/
			{
				if(i==n)/*如果是最后一条记录*/
					n=n-1;
				else	/*不是最后一条记录时*/
				{
					for(j=i;j<n;j++)/*从该记录开始后续记录更新前一条记录*/
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
				printf("\n\n\t\t该职工记录成功删除，按任意键返回主菜单……");
				list(zggz);
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

	

void add(struct member zggz[])//
{
	FILE *fp;
	

	struct member z;
	if((fp=fopen("gz.dat","rb+"))==NULL)
	{
		printf("不能打开文件：\n");
		
		 getch();
         return;

	}
	printf("请输入新的职工信息 \n");

    printf("\n请输入工号：");
	scanf("%s",z.ID);
	printf("\n请输入姓名：");
	scanf("%s",z.name);

    printf("\n请输入岗位工资：");
	scanf("%f",&z.gwsalary);

	printf("\n请输入薪级工资：");
	scanf("%f",&z.ransalary);

	printf("\n请输入职务工资：");
	scanf("%f",&z.zwsalary);

	printf("请输入绩效工资：");
    scanf("%f",&z.jxsalary);  //计算应发工资，个人所得税，实发工资
	
	z.yfsalary=z.gwsalary+z.ransalary+z.zwsalary+z.jxsalary;
    z.grsalary=grsds(z.yfsalary);
	z.reasalary=z.yfsalary-z.grsalary;

	 zggz[n]=z;
	 n++;
	 printf("\n员工信息已经添加\n");
	 write(zggz);//写入文件

     fclose(fp);
	 printf("\n按任意键返回主菜单\n");
	 getch();
     return;

}


float grsds(float a)  //计算个人所得税，按照个人所得税税率表来计算，税率表如表4.1所示。

{

        float x;	/*当月应纳税所得额*/

        float y=0;	/*当月应纳税额*/
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





