
#ifndef TESTER_HPP_INCLUDED
#define TESTER_HPP_INCLUDED
 
#include"PERSON.hpp"
 
class TESTER: public PERSON
{
private:
    std::string laboratory;
    std::string title;
    static int tester_sum;
public:
    TESTER(std::string a = "haha", bool b = 1, int c = 19, std::string d = "1",
           std::string e = "tt", std::string f = "学生");
    ~TESTER();
 
    static int get_tester_sum();
    virtual void show();
    virtual void show_row();
    virtual bool change();
 
    std::string get_laboratory(){return laboratory;}
    std::string get_title(){return title;}
};
 
int TESTER::tester_sum = 0;
 
int TESTER::get_tester_sum()
{
    return tester_sum;
}
 
TESTER::TESTER(std::string a, bool b, int c, std::string d, std::string e, std::string f):
PERSON(a,b,c,d), laboratory(e), title(f)
{
    tester_sum++;
}
 
TESTER::~TESTER()
{
    tester_sum--;
}
 
void TESTER::show()
{
    std::cout << "实验员：\n";
    std::cout << "姓名:\t\t" << name << std::endl;
    std::cout << "姓别:\t\t";
    if(sex) std::cout << "男\n";
    else std::cout << "女\n";
    std::cout << "年龄:\t\t" << age << std::endl;
    std::cout << "ID:\t\t" << num << std::endl;
    std::cout << "实验室:\t" << laboratory << std::endl;
    std::cout << "职务:\t\t" << title << std::endl;
}
 
void TESTER::show_row()
{
    std::cout << std::left << std::setw(8) << name;
    if(sex) std::cout << std::left << std::setw(8) << "男";
    else std::cout << std::left << std::setw(8) << "女";
    std::cout << std::left << std::setw(8) << age;
    std::cout << std::left << std::setw(16) << num;
    std::cout << std::left << std::setw(16) << laboratory;
    std::cout << std::left << std::setw(16) << title;
    std::cout << std::endl;
}
 
bool TESTER::change()
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
 
    std::cout << "实验室:\t";
    std::cin >> laboratory;
 
    std::cout << "职务:\t\t";
    std::cin >> title;
    return 0;
}
 
#endif 