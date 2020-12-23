#ifndef TEACHER_HPP_INCLUDED
#define TEACHER_HPP_INCLUDED

#include"PERSON.hpp"

class TEACHER: virtual public PERSON
{
protected:
    std::string department;
    std::string profession;
    std::string title;
    static int teacher_sum;

public:
    TEACHER(std::string a = "xixi", bool b = 1, int c = 30, std::string d = "213",
            std::string e = "计算机与信息工程学院", std::string f = "计算机科学与技术", std::string g = "教师");
    ~TEACHER();

    static int get_teacher_sum();
    virtual void show();
    virtual void show_row();
    virtual bool change();
 
    std::string get_department(){return department;}
    std::string get_profession(){return profession;}
    std::string get_title(){return title;}
};
 
int TEACHER::teacher_sum = 0;
int TEACHER::get_teacher_sum()
{
    return teacher_sum;
}

TEACHER::TEACHER(std::string a, bool b, int c, std::string d, std::string e, std::string f, std::string g):
PERSON(a,b,c,d), department(e), profession(f), title(g)
{
    teacher_sum++;
}

TEACHER::~TEACHER()
{
    teacher_sum--;
}
 
void TEACHER::show()
{
    std::cout << "教师：\n";
    std::cout << "姓名:\t\t" << name << std::endl;
    std::cout << "姓别:\t\t";
    if(sex) std::cout << "男\n";
    else std::cout << "女\n";

    std::cout << "年龄:\t\t" << age << std::endl;
    std::cout << "ID:\t\t" << num << std::endl;
    std::cout << "院系:\t\t" << department << std::endl;
    std::cout << "专业:\t\t" << profession << std::endl;
    std::cout << "职务:\t\t" << title << std::endl;
}

void TEACHER::show_row()
{
    std::cout << std::left << std::setw(8) << name;
    if(sex) std::cout << std::left << std::setw(8) << "男";
    else std::cout << std::left << std::setw(8) << "女";
    std::cout << std::left << std::setw(8) << age;
    std::cout << std::left << std::setw(16) << num;
    std::cout << std::left << std::setw(16) << department;
    std::cout << std::left << std::setw(16) << profession;
    std::cout << std::left << std::setw(16) << title;
    std::cout << std::endl;
}

bool TEACHER::change()
{
    std::cout << "姓名:\t\t" ;
    std::string new_name;
    std::cin >> new_name;
    for(unsigned int i = 0; i < new_name.length(); i++)
    {
        if(new_name[i] >= '0' && new_name[i] <= '9')
        {
            std::cout << "输入非法，输入任意键返回\n";
            return 1;
        }
    }

    name = new_name;
    std::cout << "姓别:\t\t";
    std::string a;
    std::cin >> a;
    if(sex) man_sum--;
        else woman_sum--;

    if(a == "男") sex = 1, man_sum++;
        else sex = 0, woman_sum++;

    std::cout << "年龄:\t\t";
    std::cin >> age;
    std::cout << "院系:\t\t";
    std::cin >> department;
    std::cout << "专业:\t\t";
    std::cin >> profession;
    std::cout << "职务:\t\t";
    std::cin >> title;
    return 0;
}

#endif // TEACHER_H_INCLUDED
