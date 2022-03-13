#include <string>
#include <iostream>
#include <fstream>

struct employee
{
    int num;
    char name[10];
    double hours;
};

int main(int argc, char* argv[])
{

    std::ifstream in(argv[1], std::ios::binary);
    std::ofstream out(argv[2]);
    out << argv[0] << std::endl;
    double sel = atof(argv[3]);
    employee emp;
    while (in.read((char*)&emp, sizeof(employee)))
    {
        out << emp.num << " " << emp.name << " " << emp.hours << " " << emp.hours * sel << std::endl;
    }
    in.close();
    out.close();
    return 0;
}