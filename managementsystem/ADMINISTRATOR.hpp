
#ifndef ADMINISTRATOR_HPP_INCLUDED
#define ADMINISTRATOR_HPP_INCLUDED
 
#include"PERSON.hpp"
 
class ADMINISTRATOR: virtual public PERSON
{
protected:
    std::string office;
    std::string position;
    static int administrator_sum;
public:
    ADMINISTRATOR(std::string a = "huhu", bool b = 1, int c = 39, std::string d = "176",
                  std::string e = "群众", std:: string f = "社会主义新青年");
    ~ADMINISTRATOR();
 
    static int get_administrator_sum();
    virtual void show();
    virtual void show_row();
    virtual bool change();
    std::string get_office(){return office;}
    std::string get_position(){return position;}
};
 
int ADMINISTRATOR::administrator_sum = 0;
int ADMINISTRATOR::get_administrator_sum()
{
    return administrator_sum;
}
 
ADMINISTRATOR::ADMINISTRATOR(std::string a, bool b, int c, std::string d, std::string e, std::string f):
PERSON(a,b,c,d), office(e), position(f)
{
    administrator_sum++;
}
 
ADMINISTRATOR::~ADMINISTRATOR()
{
    administrator_sum--;
}
 
void ADMINISTRATOR::show()
{
    std::cout << "行政人员：\n";
    std::cout << "姓名:\t\t" << name << std::endl;
    std::cout << "姓别:\t\t";
    if(sex) std::cout << "男\n";
    else std::cout << "女\n";
    std::cout << "年龄:\t\t" << age << std::endl;
    std::cout << "num:\t\t" << num << std::endl;
    std::cout << "办公室:\t" << office << std::endl;
    std::cout << "职称:\t\t" << position << std::endl;
}
 
void ADMINISTRATOR::show_row()
{
    std::cout << std::left << std::setw(8) << name;
    if(sex) std::cout << std::left << std::setw(8) << "男";
    else std::cout << std::left << std::setw(8) << "女";
    std::cout << std::left << std::setw(8) << age;
    std::cout << std::left << std::setw(16) << num;
    std::cout << std::left << std::setw(16) << office;
    std::cout << std::left << std::setw(16) << position;
    std::cout << std::endl;
}
 
bool ADMINISTRATOR::change()
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
 
    std::cout << "办公室:\t";
    std::cin >> office;
 
    std::cout << "职称:\t\t";
    std::cin >> position;
    return 0;
}
 
#endif // ADMINISTRATOR_H_INCLUDED
