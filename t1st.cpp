#include <iostream>
#include <string>
#include <typeinfo>
#include "department.h"
#include "employee.h"
#include "LinkList.h"
using namespace std;

void Create_new_employee(LinkList<Department> &departments); //����һ��employ�ҳ�ʼ��������� 
void Add_information_to_department(LinkList<Department> &departments); //��department��ֵ 
int main()
{
    double SortByBudget = 1.0;//use variable instead of magic number
    double SortBySalary = 1.0;//use variable instead of magic number
    LinkList<Department> departments;
    
    for (int i = 0; i < 5; i++)
    {
        Department new_department; //Create new department
        departments.Append(new_department);
        //if (i == 2)
            //departments.CurData().set_department_info("technic supports", 25000);
        
        Add_information_to_department(departments);
        cout << departments.CurData() << endl;
        Create_new_employee(departments);
		Create_new_employee(departments);
		Create_new_employee(departments); //��������employ���� SortByEmployeeSalary()���� 
        departments.CurData().SortEmployee(SortBySalary);//sort by salary
    }
    departments.ShowList();
    departments.Sort(SortByBudget);
    cout << "==============This is a split line==============" << endl; 
    departments.ShowList();
    
    //departments.CurData().set_department_info("technic support", 25000);
    //string search1 = "technic supports";
    //departments.Locate(search1, true); //never use Locate(char*,true);
    //string name = "NO_NAMES";           //you should never try departments.CurData().delete_employee("NO_NAME");
    //departments.CurData().delete_employee(name);
    //cout << departments.CurData();
    return 0;
}
void Create_new_employee(LinkList<Department> &departments)
{
	int id;
    double salary;
    int work_hour;
    string position;
    string employee_name;
    double rate;
    
	cin >> id >> salary >> work_hour >> position >> employee_name >> rate;
    Employee new_employee(id, employee_name, salary, work_hour, position, rate); //Create new employee
    departments.CurData().add_employee(new_employee); //add employee
    cout << new_employee << endl;
}
void Add_information_to_department(LinkList<Department> &departments)
{
	int budget;
	string department_name;
	cin >> department_name >> budget;
    departments.CurData().set_department_info(department_name, budget);
}
