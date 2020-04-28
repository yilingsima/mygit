#include <iostream>
#include <bits/stdc++.h>
//#include <sstream>
using namespace std;
char math_symbol[4]={'+','-','*','/'};      //算术运算符
int user_math_symbol[4]={0};                //使用者是否需要运算符
double deci_num[9]={0.1,0.2,0.3,0.4,0.5,0.6,0.7,0.8,0.9};
                                           
int max_num; int is_brac=0; int is_deci=0;                              
int exam_num=0;                             
int brac_sum=0;                            
void init1(){
	cout<<"老师您好，欢迎来到XX出题软件"<<endl;
	cout<<"请您设置题目要求:"<<endl;
	cout<<"请您选择题目数量:"<<endl;
	cin>>exam_num;
	cout<<"请您选择需要运算符的数量"<<endl;
	cin>>brac_sum;
	cout<<"注意：0—代表加法;1—代表减法;2—代表乘法;3—代表除法"<<endl;
	for(int i=0;i<brac_sum;++i){
		int temp;
		printf("请输入第%d个运算符\n",i+1);
		while(1){
		  scanf("%d",&temp);
		  if(temp>3||temp<0){
			printf("您输入的运算符不符合要求：请选择0~3里面的数字,重新输入:\n");
		  }
		  if(temp>=0&&temp<=3){
		  	break;
		  }
		}
		user_math_symbol[temp]=1;
	}
	printf("请输入您要选择的数字的最大值:\n");
	scanf("%d",&max_num);
	printf("您是否需要括号，需要写1，不需要写0:\n");
	scanf("%d",&is_brac);
	printf("您是否需要小数，需要写1，不需要写0:\n");
	scanf("%d",&is_deci);
}
void inerts1(int num,string &str){              //类型转化函数，将int数字类型转换成string字符串
	stringstream ss;
	ss<<num;
	ss>>str;
}
void inerts2(double num,string &str){          //类型转化函数，将浮点数类型转化成string字符串
	stringstream ss;
	ss<<num;
	ss>>str;
}
void inerts3(char ch,string &str){             //类型转化函数，将ch字符转化成string字符串
	stringstream ss;
	ss<<ch;
	ss>>str;
}
void inerts4(string str,int &t){             //类型转化函数，将string字符转化成int类型
	stringstream ss;
	ss<<str;
	ss>>t;
}
void inerts5(string str,double &t){          //类型转化函数，将string字符转化成double类型
	stringstream ss;
	ss<<str;
	ss>>t;
}
//is4
string gen_exam(){                         //自动生成算术表达式，返回string字符串
	string exam_ans;
	if (is_brac==1){
		exam_ans+="(";
	}                                      //当用户需要括号运算时，先添加左括号
	int a1=rand()%max_num;                  //生成第一个随机数
	string temp_str1;                      //临时变量
	inerts1(a1,temp_str1);                     //将第一个数字转换成字符串
	exam_ans+=temp_str1;
	if(user_math_symbol[0]==1){            //判断用户是否需要“+”或“-”
		exam_ans+="+";
	}else{
		exam_ans+="-";
	}
	int a2=rand()%max_num;                  //生成第二个随机数
	double a3=0.0;
	if(is_deci==1){                        //判断用户需要小数
		a3+=(double)a2+deci_num[rand()%10];
		inerts2(a3,temp_str1);
		exam_ans+=temp_str1;
	}else{                                  //用户不需要小数
		inerts1(a2,temp_str1);
		exam_ans+=temp_str1;
	}
	if(is_brac==1){                         //当用户需要括号时，加上右括号
		exam_ans+=")";
	}
	if(user_math_symbol[2]==1&&user_math_symbol[3]==0){      //用户只选择了乘法
		 inerts3(math_symbol[2],temp_str1);
		 exam_ans+=temp_str1;
	}else if(user_math_symbol[2]==0&&user_math_symbol[3]==1){//用户只选择了除法
		inerts3(math_symbol[3],temp_str1);
		exam_ans+=temp_str1;
	}else if(user_math_symbol[2]==1&&user_math_symbol[3]==1){//用户既选择了乘法又选择了除法，此时乘法与除法随机选择
		inerts3(math_symbol[rand()%2+2],temp_str1);
		 exam_ans+=temp_str1;
	}else{
		if(user_math_symbol[0]==1){
			exam_ans+="+";
		}else{
		    exam_ans+="-";
		}
	}
	int a4=rand()%(max_num+1);
	inerts1(a4,temp_str1);
	exam_ans+= temp_str1;
	return exam_ans;
}
void do_exam(){                                     //函数功能：开始做题
	printf("请听题\n");
	for(int i=0;i<exam_num;++i){
		printf("这是第%d题：\n",i+1);
		cout<<gen_exam()<<endl;
		int t;
		printf("您是否还想继续作答，继续作答输入1，退出输入0\n");
		scanf("%d",&t);
        if(t==0){
			break;
		}
		//is_brac=0;                              //用户是否选择括号，1—代表选择，0—代表不选择，这里默认是0
        //is_deci=0;                              //用户是否选择小数，1—代表选择，0—代表不选择，这里默认是0
        //exam_num=0;                             //用户选择的题目数量
        brac_sum=0;                             //用户需要的算符个数
	}
	int judge=0;
	cout<<"还需要题目吗？需要输入1，不需要输入0"<<endl;
}

int judge_end(){                                //用户判断用户是否想结束本次作答
	int judge;
	scanf("%d",&judge);
	if(judge==0){
		return 0;
	}else{
		return 1;
	}
}
int main(int argc,const char *argv[]){          //主函数
	while(1){
    init1();
	do_exam();
	if(judge_end()==0){
		break;
	  }
	}
	cout<<"请选择您的输出方式：1-代表输出到文件；2-代表打印机"<<endl;
	int choose;
	scanf("%d",&choose);
	system("pause");
	return 0;
}
