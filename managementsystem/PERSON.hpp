#ifndef PERSON_HPP_INCLUDED

#define PERSON_HPP_INCLUDED

 

#include<string>

#include<iostream>

#include<iomanip>

 

class PERSON

{

protected:

    std::string name;

    bool sex;

    int age;

    std::string num;

    static int person_sum;

    static int man_sum;

    static int woman_sum;

public:

    PERSON(std::string a, bool b, int c, std::string d);//name(a), sex(b), age(c), id(d)

    virtual ~PERSON();

    static int get_person_sum();

    static int get_man_sum();

    static int get_woman_sum();

    virtual void show(){}

    virtual void show_row(){}

 

    std::string get_name(){return name;}

    bool get_sex(){return sex;}

    int get_age(){return age;}

    std::string get_num(){return num;}

};

 

int PERSON::person_sum = 0;

int PERSON::man_sum = 0;

int PERSON::woman_sum = 0;

 

int PERSON::get_person_sum()

{

    return person_sum;

}

 

int PERSON::get_man_sum()

{

    return man_sum;

}

 

int PERSON::get_woman_sum()

{

    return woman_sum;

}

 

PERSON::PERSON(std::string a, bool b, int c, std::string d): name(a), sex(b), age(c), num(d)

{

    person_sum++;

    if(b) man_sum++;

    else woman_sum++;

}

 

PERSON::~PERSON()

{

    person_sum--;

    if(sex) man_sum--;

    else woman_sum--;

}

 

#endif 
