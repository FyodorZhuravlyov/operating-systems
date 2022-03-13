#include <string>
#include <iostream>
#include <fstream>
#include <conio.h>
#include <windows.h> 


struct employee
{
    int num;
    char name[10];
    double hours;
};

int main(int argc, char* argv[])
{
    std::string result;
    std::string binary_file;
    std::string report_file;
    double salary;
    int number_of_entries;
    std::cout << "binary file name " << std::endl;
    std::cin >> binary_file;
    std::cout << "number_of_entries " << std::endl;
    std::cin >> number_of_entries;
    const char *lpszAppName = 0;
    std::string arguments = "Creator.exe" + binary_file + " " + std::to_string(number_of_entries);
    STARTUPINFO si;
    PROCESS_INFORMATION piApp;
    ZeroMemory(&si, sizeof(STARTUPINFO));
    si.cb = sizeof(STARTUPINFO);

    CreateProcess(0, (LPWSTR)(char*)arguments.c_str(), NULL, NULL, FALSE,
        CREATE_NEW_CONSOLE, NULL, NULL, &si, &piApp);

    WaitForSingleObject(piApp.hProcess, INFINITE);
    CloseHandle(piApp.hThread);
    CloseHandle(piApp.hProcess);
    std::ifstream in(binary_file, std::ios::binary);
    employee emp;
    while (in.read((char*)&emp, sizeof(employee))) {
        std::cout << emp.num << " " << emp.name << " " << emp.hours << std::endl;
    }
    std::cout << std::endl;
    in.close();

    std::cout << "report file name ";
    std::cin >> report_file;
    std::cout << "salary per hour ";
    std::cin >> salary;
    std::cout << std::endl;
    const char* lpszAppName2 = 0;
    std::string arguments2 = "Creator.exe" + binary_file + " " + report_file + " " + std::to_string(salary);
    STARTUPINFO si2;
    PROCESS_INFORMATION piApp2;
    ZeroMemory(&si2, sizeof(si2));
    si2.cb = sizeof(si2);

    CreateProcess(0, (LPWSTR)(char*)arguments2.c_str(), NULL, NULL, FALSE,
        CREATE_NEW_CONSOLE, NULL, NULL, &si2, &piApp2);

    WaitForSingleObject(piApp2.hProcess, INFINITE);
    CloseHandle(piApp2.hThread);
    CloseHandle(piApp2.hProcess);
    
    in.open(report_file);
    while (getline(in, result))
    {
        std::cout << result << std::endl;
    }
    return 0;
}