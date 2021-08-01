#include<stdio.h> 
#include<string.h>
#include<string>
#include<iostream>
#include<malloc.h> 
#pragma warning(disable:4996)
#define maxsize 100
#define DataType student
using namespace std;
#include <malloc.h>
#include"标头.h" 
void show()
{

    int tag = 0;  //   tag=0 循环   =1结束循环
    shu* root = 0;

    do
    {
        //***********显示提示信息**********  
        printf("                                     学生信息管理系统                                      \n");
        printf("                                                                                           \n");
        printf("                             1.插入学生信息   2.删除学生信息                              \n");          //显示序号1的功能  
        printf("                                                                                           \n");          //显示序号2的功能  
        printf("                             3.查询学生信息   4.打印二叉树                                 \n");          //显示序号3的功能  
        printf("                                                                                           \n");          //显示序号4的功能  
        printf("                                          0.退出系统                                       \n");          //显示序号5的功能  
        printf("                                                                                           \n");          //显示序号6的功能  
        printf("请输入功能序号: ");             //提示用户输入  
        int n;
        scanf("%d", &n);
        while ((n < 0 || n > 4))                                       //对用户输入不能实现的功能序号进行处理  
        {
            printf("   抱歉,没有此功能,请重新输入功能序号: ");      //提示用户所输入的功能序号系统不能进行处理  
            rewind(stdin);
            while (!scanf("%d", &n))                                  //接收用户重新输入的功能序号  
            {
                printf("   输入序号有误,请重新输入: ");
                rewind(stdin);
            }
            printf("\n");                                           //输出回车  
        }
        switch (n)
        {
        case 0:tag = 1;
            break;
       
        case 1:  int sum2;            // a2插入学生信息 
            //shu* root = 0;
            int p;
            p = 0;
            printf("请输入所要插入的学生总数\n");
            scanf("%d", &sum2);
            student a2;
            printf("学号    姓名    性别（1是男 0是女）   年龄    专业\n");
            printf("请输入以上信息\n");
            for (int i = 0; i < sum2; i++)
            {
                while (5 != scanf("%lld %s %d  %d %s", &a2.num, a2.name, &a2.sex, &a2.age, a2.major)
                    || a2.age < 0 || a2.age > 30 || (a2.sex != 0 && a2.sex != 1))
                {
                    printf("输入有误，请选择 （1）重新输入;（2）重新选择功能\n");
                    rewind(stdin);
                    scanf("%d", &p);
                    if (p == 2) break;
                }
                rewind(stdin);

                while (chaping(&root, a2) == 0)                //插入函数 
                {
                    printf("学号输入重复，请选择 （1）重新输入;（2）重新选择功能\n");
                    rewind(stdin);
                    scanf("%d", &p);
                    if (p == 2) break;

                    while (scanf("%lld ", &a2.num) != 1)
                    {
                        printf("学号输入有误，请选择 （1）重新输入;（2）重新选择功能\n");
                        rewind(stdin);
                        scanf("%d", &p);
                        if (p == 2) break;
                    }
                }
                rewind(stdin);

                if (p != 2)printf("插入学生信息成功！\n");
            }
            break;


        case 2:unsigned long long  num3;       // 删除学生信息
            int sum3;
            int o;
            o = 0;
            //shu* root = 0;
            printf("请输入所要删除的学生总数\n");
            //printf("请输入所要删除的学生学号\n");
            while (0 == scanf("%d", &sum3) || qianxusum(root) < sum3)
            {
                printf("总数过多或有误,请选择重新输入 \n");
                rewind(stdin);

            }
            printf("请输入所要删除的学生学号\n");
            for (int i = 0; i < sum3; i++)
            {

                while (0 == scanf("%lld", &num3) || shanping(&root, num3) == 0)      //删除函数 
                {
                    printf("学号输入不存在或有误，请选择 （1）重新输入（只输入学号即可）;（2）重新选择功能 \n");
                    rewind(stdin);
                    scanf("%d", &o);
                    if (o == 2) break;
                    rewind(stdin);
                }
                rewind(stdin);
                if (o != 2) printf("删除学生信息成功！\n");
            }
            break;
        case 3:unsigned long long  num4;          //查询学生信息
            int sum4;
            int r;
            r = 0;
            //shu* root = 0;
            printf("请输入所要查找的学生总数\n");
            //printf("请输入所要查找的学生学号\n");
            while (0 == scanf("%d", &sum4) || qianxusum(root) < sum4)
            {
                printf("总数过多或有误,请选择重新输入 \n");
                rewind(stdin);

            }
            printf("请输入所要查找的学生学号\n");
            for (int i = 0; i < sum4; i++)
            {
                while (0 == scanf("%lld", &num4) || zhao(root, num4) == 0)       //查找函数 
                {
                    printf("学号不存在或有误，请选择 （1）重新输入（只输入学号即可）;（2）重新选择功能\n");

                    rewind(stdin);
                    scanf("%d", &r);
                    if (r == 2) break;

                }
                rewind(stdin);

            }

            break;
        case 4:dayin(root, 0);
            break;
        }


    } while (tag == 0);

}

int main()
{
    show();

    return 1;

}
