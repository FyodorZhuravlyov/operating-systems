#include<iostream>
#include<fstream>

struct employee
{
    int num;
    char name[10]; 
    double hours; 
};


int main(int argc, char* argv[])
{

    std::fstream out(argv[0], std::ios::out | std::ios::binary);
    int number = atoi(argv[1]);

    for (int i = 0; i < number; i++)
    {
        employee emp;
        std::cout << " input number of employee = " << std::endl;
        std::cin >> emp.num;
        std::cout << " input employee name = " << std::endl;
        std::cin.getline(emp.name, 10);
        std::cout << " input hours = " << std::endl;
        std::cin >> emp.hours;
        out.write((char*)&emp, sizeof(employee));
    }
    out.close();
    return 0;
}