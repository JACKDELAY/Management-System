#ifndef INTERFACE_HPP_INCLUDED
#define INTERFACE_HPP_INCLUDED
 
# include "TEACHER.hpp"
# include "TESTER.hpp"
# include "ADMINISTRATOR.hpp"
# include "TEAADMIN.hpp"
# include "MYFUN.hpp"
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
/*===========---函数声明===========------*/
 
void interface_Manager();        //管理者界面
 

 
/*===========---函数定义===========------*/
 
void interface_Manager() //管理界面
{
    int n=1;
    while(n)
    {
        system("cls");
	    std::cout<<"==============================================================="<<std::endl;
	    std::cout<<"欢迎使用南京信息工程大学学生管理系统"<<std::endl;
	    std::cout<<"==============================================================="<<std::endl;
        std::cout << "==============     输入1 添加信息              ===================\n";
        std::cout << "==============     输入2 查询信息              ===================\n";
        std::cout << "==============     输入3 浏览信息              ===================\n";
        std::cout << "==============     输入4 修改信息              ===================\n";
        std::cout << "==============     输入5 删除信息              ===================\n";
        std::cout << "==============     输入6 统计信息              ===================\n";
        std::cout << "==============     输入0 结束                  ===================\n";
        std::cout << "=============================================================\n";
        std::cout << "=============================================================\n";
        std::cin >> n;
        switch(n)
        {
            case 0:break;
            case 1:Add_information();break;
            case 2:
            {
                int a = 1;
                if(!Query_information()) break;
                while(a)
                {
                    std::cout << "输入1 修改信息\n";
                    std::cout << "输入2 删除信息\n";
                    std::cout << "输入0 返回上一级\n";
                    std::cin >> a;
                    switch(a)
                    {
                        case 1:Edit_information(); a = 0; break;
                        case 2:Delete_information(); a= 0; break;
                    }
                }
                break;
            }
            case 3:
            {
                int a=1;
                while(a)
                {
                    Browse_information();
                    std::cout << "输入1 修改信息\n";
                    std::cout << "输入2 删除信息\n";
                    std::cout << "输入0 返回上一级\n";
                    std::cin >> a;
                    switch(a)
                    {
                        case 1:Edit_information(); break;
                        case 2:Delete_information(); break;
                    }
                }
                break;
            }
            case 4:Edit_information(); break;
            case 5:Delete_information(); break;
            case 6:count_information(); break;
        }
    }
}

#endif // INTERFACE_H_INCLUDED