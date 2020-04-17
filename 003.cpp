#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#define I 100
using namespace std;
struct node
{
    char name[20];
    char ad[20];
    char ach[20];
    char mow;
    char email[20];
    char tele[20];
    node *next;
}*head=NULL,*thisn,*newn,sta[I]={0},temp;
void scan(void) ;
void seek();
void printmsg(int i);
void modify(void);
int record(void);
void del(void);
void seek1();
void seek2();
void seek3();
void education(void);
void descending(void);
void ascending(void);
int main()
{
    printf("欢迎使用群决策专家基本信息管理系统！\n");
    printf("请输入指令：\n1.录入\n2.修改\n3.删除\n4.查询\n5.排序\n");
    switch (getchar())
     {
       case '1':scan();break;        /*调用输入信息的函数*/
       case '2':modify();break;     /*调用修改信息的函数*/
       case '3':del();break;         /*调用删除信息函数*/
       case '4':seek();break;       /*查询信息*/
       case '5':education();break;       /*调用排序的函数*/
     }
    return 0;
}
void scan(void)                    /*输入信息的函数*/
{
   FILE *fp;
   if((fp=fopen("information.txt","a+"))==NULL)   /*为读写打开一个文本文件*/
    {
      printf("文件打开错误\n");
      exit(1);    /*关闭所有文件，终止正在执行的程序，待用户检查出错误，修改后再运行*/
    }
   newn=(struct node *)malloc(sizeof(struct node));
   if(head==NULL)                         /*连接链表*/
    {
      head=newn;
      thisn=newn;
      thisn->next=NULL;
    }
   else
    {
      thisn=head;
      while(thisn->next!=NULL)
        thisn=thisn->next;
      thisn->next=newn;
      thisn=newn;
    }
   getchar();                             /*接收缓冲区中选择菜单时多余的回车*/
   fputc('\n',fp);                         /*每次记录信息前先换行*/
   printf("请输入姓名：");
   gets(thisn->name);
   fputs(thisn->name,fp);
   fputs("\t",fp);

   printf("请输入性别(填M或W)：");
   thisn->mow=getchar();getchar();
   fputc(thisn->mow,fp);
   fputs("\t",fp);

   printf("请输入电话号码：");
   gets(thisn->tele);
   fputs(thisn->tele,fp);
   fputs("\t",fp);

   printf("请输入研究方向:");
   gets(thisn->ach);
   fputs(thisn->ach,fp);
   fputs("\t",fp);

   printf("请输入E-MAIL：");
   gets(thisn->email);
   fputs(thisn->email,fp);
   fputs("\t",fp);

   printf("请输入地址：");
   gets(thisn->ad);
   fputs(thisn->ad,fp);

   thisn->next=NULL;
   fclose(fp);
   system("cls");   /*清屏*/
}
void seek()    //查询信息
{
    printf("按照。。。查询\n1.姓名  2.地址  3.研究方向\n");
    switch (getchar())
    {
        case '1': seek1();break;
        case '2': seek2();break;
        case '3': seek3();break;
    }
}
void seek1()    //姓名查询
{
 FILE *fp;
 system("cls");
 char name[20];
 int i,j;
 if((fp=fopen("information.txt","r"))==NULL)
  {
  	 printf("文件打开错误");
  	 exit(1);
  }
 for(i=0,j=0;i<I;i++,j++)                /*将文件中的信息按行写入结构体数组 */
 {
 fscanf(fp,"%s\t%c\t%s\t%s\t%s\t%s\n",&sta[i].name,&sta[i].mow,&sta[i].tele,sta[i].ach,&sta[i].email,&sta[i].ad);
 }

printf("请输入要查询的姓名:  ");
scanf("%s",name);
printf("姓名    性别   电话       研究方向      E-mail      地址\n");
printf("-----------------------------------------------------------------------------\n");
for(i=0;i<I;i++)
{ if(strcmp(sta[i].name,name)==0)
  printmsg(i);
}
 getchar();
 printf("\n\n\n\n\n回到主界面请按r   退出系统请按其他键\n");
 switch (getchar())
   {
   	  case 'r':getchar();system("cls");break;        /*接收回车*/
   	  default:exit(0);
   }
}
void seek2()    //地址查询
{
 FILE *fp;
 system("cls");
 char ad[20];
 int i,j;
 if((fp=fopen("information.txt","r"))==NULL)
  {
  	 printf("文件打开错误");
  	 exit(1);
  }
 for(i=0,j=0;i<I;i++,j++)                /*将文件中的信息按行写入结构体数组 */
 {
 fscanf(fp,"%s\t%c\t%s\t%s\t%s\t%s\n",&sta[i].name,&sta[i].mow,&sta[i].tele,sta[i].ach,&sta[i].email,&sta[i].ad);
 }

printf("请输入要查询的地址:  ");
scanf("%s",ad);
printf("姓名    性别   电话       研究方向      E-mail      地址\n");
printf("-----------------------------------------------------------------------------\n");
for(i=0;i<I;i++)
{ if(strcmp(sta[i].ad,ad)==0)
  printmsg(i);
}
 getchar();
 printf("\n\n\n\n\n回到主界面请按r   退出系统请按其他键\n");
 switch (getchar())
   {
   	  case 'r':getchar();system("cls");break;        /*接收回车*/
   	  default:exit(0);
   }
}
void seek3()    //研究方向查询
{
 FILE *fp;
 system("cls");
 char ach[20];
 int i,j;
 if((fp=fopen("information.txt","r"))==NULL)
  {
  	 printf("文件打开错误");
  	 exit(1);
  }
 for(i=0,j=0;i<I;i++,j++)                /*将文件中的信息按行写入结构体数组 */
 {
 fscanf(fp,"%s\t%c\t%s\t%s\t%s\t%s\n",&sta[i].name,&sta[i].mow,&sta[i].tele,sta[i].ach,&sta[i].email,&sta[i].ad);
 }

printf("请输入要查询的研究方向:  ");
scanf("%s",ach);
printf("姓名    性别   电话       研究方向      E-mail      地址\n");
printf("-----------------------------------------------------------------------------\n");
for(i=0;i<I;i++)
{ if(strcmp(sta[i].ach,ach)==0)
  printmsg(i);
}
 getchar();
 printf("\n\n\n\n\n回到主界面请按r   退出系统请按其他键\n");
 switch (getchar())
   {
   	  case 'r':getchar();system("cls");break;        /*接收回车*/
   	  default:exit(0);
   }
}
void printmsg(int i)    /*输出信息*/
{
printf("%s\t%c\t%s\t%s\t%s\t%s\n",&sta[i].name,&sta[i].mow,&sta[i].tele,sta[i].ach,&sta[i].email,&sta[i].ad);
}
void modify(void)    /*修改信息*/
{
 FILE *fp;
 int i,j;
 getchar();          /*接收回车*/
 system("cls");
 if((fp=fopen("information.txt","r"))==NULL)
  {
  	 printf("文件打开错误");
  	 exit(1);
  }
  char name[20];
  for(i=0,j=0;i<I;i++,j++)                /*将文件中的信息按行写入结构体数组 */
 {
 fscanf(fp,"%s\t%c\t%s\t%s\t%s\t%s\n",&sta[i].name,&sta[i].mow,&sta[i].tele,sta[i].ach,&sta[i].email,&sta[i].ad);
 }
printf("请输入要修改专家的姓名:  ");
scanf("%s",name);
for(i=0;i<I;i++)
{ if(strcmp(sta[i].name,name)==0)
	 {
           printf("            【1】 修改姓名               【2】修改电话 \n");
           printf("            【3】 修改研究方向           【4】修改E-MAIL\n");
           printf("            【5】 修改住址               【6】修改性别 \n");
           printf("请输入以上数字，选择相应的功能： ");
  switch (getchar())
  {
    case '1':getchar();
		    printf("请输入新姓名：");
           	gets(sta[i].name);
			printf("修改成功！按任意键返回主界面");
		    getchar();break;
    case '2':getchar();
		    printf("请输入新电话号码：");
            gets(sta[i].tele);
			printf("修改成功！按任意键返回主界面");
		    getchar();break;
    case '3':getchar();
		    printf("请输入新研究方向:");
           	gets(sta[i].ach);
			printf("修改成功！按任意键返回主界面");
		    getchar();break;
    case '4':getchar();
            printf("请输入新E-MAIL:");
           	gets(sta[i].email);
			printf("修改成功！按任意键返回主界面");
		    getchar();break;
    case '5':getchar();
		    printf("请输入新地址：");
            gets(sta[i].ad);
			printf("修改成功！按任意键返回主界面");
		    getchar();break;
    case '6':getchar();
            if(sta[i].mow=='m')
                sta[i].mow='w';
            else
                sta[i].mow='m';
			printf("修改成功！按任意键返回主界面");
		    getchar();break;
    default:break;
  }
     }
}
 fclose(fp);
 if((fp=fopen("information.txt","w"))==NULL)          /*重新向文件输入所有信息*/
  {
  	 printf("文件打开错误");
  	 exit(1);
  }
 for(i=0;i<j;i++)
   {
      fputs(sta[i].name,fp);
      fputs("\t",fp);

      fputc(sta[i].mow,fp);
      fputs("\t",fp);

      fputs(sta[i].tele,fp);
      fputs("\t",fp);

      fputs(sta[i].ach,fp);
      fputs("\t",fp);

      fputs(sta[i].email,fp);
      fputs("\t",fp);

      fputs(sta[i].ad,fp);
      fputc('\n',fp);
   }
 	fclose(fp);
}
void del(void)                         /*删除信息*/
{
 FILE *fp;
 int i,j,k;
 getchar();                                  /*接收回车*/
 system("cls");
 printf("请输入要删除的专家姓名：");
 char name[20];
scanf("%s",name);
 system("cls");
 if((fp=fopen("information.txt","r"))==NULL)
  {
  	 printf("文件打开错误");
  	 exit(1);
  }
 for(i=0;i<I;i++)                /*将文件中的信息按行写入结构体数组中并输出 */
    {
        fscanf(fp,"%s\t%c\t%s\t%s\t%s\t%s\n",&sta[i].name,&sta[i].mow,&sta[i].tele,sta[i].ach,&sta[i].email,&sta[i].ad);
	  if(sta[i].name==name)
	  	  j=i;
    }
 fclose(fp);

 if((fp=fopen("information.txt","w"))==NULL)          /*重新向文件输入所有信息*/
  {
  	 printf("文件打开错误");
  	 exit(1);
  }

 for(k=j;k<record();k++)
       sta[k]=sta[k+1];

 for(i=0;i<record();i++)
   {
      fputs(sta[i].name,fp);
      fputs("\t",fp);

      fputc(sta[i].mow,fp);
      fputs("\t",fp);

      fputs(sta[i].tele,fp);
      fputs("\t",fp);

      fputs(sta[i].ach,fp);
      fputs("\t",fp);

      fputs(sta[i].email,fp);
      fputs("\t",fp);

      fputs(sta[i].ad,fp);
      fputc('\n',fp);
   }

 	fclose(fp);
}
int record(void)
{
 FILE *fp;
 int i,j;                                /*j用于记录人数*/
 system("cls");
 if((fp=fopen("information.txt","r"))==NULL)
  {
  	 printf("文件打开错误");
  	 exit(1);
  }
 for(i=0,j=0;i<I;i++,j++)                /*将文件中的信息按行写入结构体数组中 */
 {
    fscanf(fp,"%s\t%c\t%s\t%s\t%s\t%s\n",&sta[i].name,&sta[i].mow,&sta[i].tele,sta[i].ach,&sta[i].email,&sta[i].ad);
 }
 fclose(fp);
 return j;
}
void education(void)               /*排序*/
{
 FILE *fp;
 int i;
 if((fp=fopen("information.txt","r"))==NULL)
  {
  	 printf("文件打开错误");
  	 exit(1);
  }
 for(i=0;i<I;i++)                /*将文件中的信息按行写入结构体数组中 */
 {
     fscanf(fp,"%s\t%c\t%s\t%s\t%s\t%s\n",&sta[i].name,&sta[i].mow,&sta[i].tele,sta[i].ach,&sta[i].email,&sta[i].ad);
 }
 fclose(fp);
 getchar();
 printf("             【1】降序排列        【2】升序排列\n");
 printf("请输入以上数字，选择相应的功能:  ");
 switch(getchar())
 {
 	case '1':descending();break;
 	case '2':ascending();break;
 }
 printf("\n\n按任意键返回上一级");
}
void descending(void)          /*按降序排列*/
{
    int i,j,k,n;
    n=record();
    system("cls");
  for(i=0;i<n-1;i++)
     for(j=0;j<=n-i-1;j++)
        {
        	for(k=0;!sta[j].name[k] || !sta[j+1].name[k];k++)
            {
                if(sta[j].name[k]<sta[j+1].name[k])
                {
                    temp=sta[j];
        	        sta[j]=sta[j+1];
        	        sta[j+1]=temp;
        	        break;
                }
            }
        }
    printf("姓名    性别   电话       研究方向      E-mail      地址\n");
printf("-----------------------------------------------------------------------------\n");
  for(i=0;i<=j-1;i++)
printf("%s\t%c\t%s\t%s\t%s\t%s\n",&sta[i].name,&sta[i].mow,&sta[i].tele,sta[i].ach,&sta[i].email,&sta[i].ad);
 printf("          【1】返回上一级        【2】退出系统\n");
 printf("请输入以上数字，选择相应的功能:  ");
 switch (getchar())
  {
  	case '1':system("cls");break;
  	case '2':exit(1);break;
  }
}
void ascending(void)             /*按升序排列*/
{
    int i,j,k,n;
    n=record();
    system("cls");
  for(i=0;i<n-1;i++)
     for(j=0;j<=n-i-1;j++)
        {
        	for(k=0;!sta[j].name[k] || !sta[j+1].name[k];k++)
            {
                if(sta[j].name[k]>sta[j+1].name[k])
                {
                    temp=sta[j];
        	        sta[j]=sta[j+1];
        	        sta[j+1]=temp;
        	        break;
                }
            }
        }
    printf("姓名    性别   电话       研究方向      E-mail      地址\n");
printf("-----------------------------------------------------------------------------\n");
  for(i=0;i<=j-1;i++)
printf("%s\t%c\t%s\t%s\t%s\t%s\n",&sta[i].name,&sta[i].mow,&sta[i].tele,sta[i].ach,&sta[i].email,&sta[i].ad);
 printf("          【1】返回上一级        【2】退出系统\n");
 printf("请输入以上数字，选择相应的功能:  ");
 switch (getchar())
  {
  	case '1':system("cls");break;
  	case '2':exit(1);break;
  }
}
