#include <iostream>
#include <vector>
using namespace std;

class Date
{
public:
    int day;
    int month;
    int year;

    bool static isBetweenGivenRange(Date date, Date start, Date end)
    {
        if (date.year >= start.year && date.year <= end.year)
        {
            if (date.month >= start.month && date.month <= end.month)
            {
                if (date.day >= start.day && date.day <= end.day)
                {
                    return true;
                }
            }
        }
        return false;
    }
};

class Trip
{
public:
    static int id;
    int tripId;
    int empId;
    int cabId;
    Date date;
    double cost;

    Trip()
    {
        tripId = id;
        id++;
    }
};
int Trip::id;

class TripList
{
public:
    static vector<Trip> tripList;
};
vector<Trip> TripList::tripList;

class Type
{
public:
    string type;
    double cost;
};

class Employee
{
public:
    static int id;
    int empId;
    string name;
    string role;
    double totalCost;
    int index;

    Employee()
    {
        totalCost = 0;
        empId = id;
        id++;
    }
};
int Employee::id;

class EmployeeList
{
public:
    static vector<Employee> empList;

    Employee static getEmpById(int empId)
    {
        for (int i = 0; i < empList.size(); i++)
        {
            if (empList[i].empId == empId)
            {
                return empList[i];
            }
        }
        Employee e;
        return e;
    }
};
vector<Employee> EmployeeList::empList;

class Cab
{
public:
    static int id;
    int cabId;
    Type type;
    Cab()
    {
        cabId = id;
        id++;
    }
};
int Cab::id;
class Report
{
public:
    // To print the total cost for each employee
    void totalCostPerEmployee()
    {
        vector<Employee> empList = EmployeeList::empList;
        for (int i = 0; i < empList.size(); i++)
        {
            cout << empList[i].name << " " << empList[i].totalCost << endl;
        }
    }

    // To find total cost of given employee in given range
    void totalCostInGivenRange(int empId, Date start, Date end)
    {
        double cost = 0;
        Employee emp = EmployeeList::getEmpById(empId);

        vector<Trip> tripList = TripList::tripList;

        for (int i = 0; i < tripList.size(); i++)
        {
            if (tripList[i].empId != empId)
                continue;
            if (Date::isBetweenGivenRange(tripList[i].date, start, end))
            {
                cost += tripList[i].cost;
            }
        }

        cout << "Total cost of Employee " << emp.name << " in given range is " << cost;
    }

    // To find the total cost of given month
    void totalCostOfMonth(int month)
    {
        double cost = 0;
        vector<Trip> tripList = TripList::tripList;
        for (int i = 0; i < tripList.size(); i++)
        {
            if (tripList[i].date.month == month)
            {
                cost += tripList[i].cost;
            }
        }
        cout << "Total cost of month " << month << " is " << cost;
    }

    // To display the trip details done by given employee
    void tripsByEmployee(int empId)
    {
        Employee emp = EmployeeList::getEmpById(empId);
        vector<Trip> tripList = TripList::tripList;
        for (int i = 0; i < tripList.size(); i++)
        {
            if (tripList[i].empId != empId)
            {
                continue;
            }
            else
            {
                Trip t = tripList[i];
                cout << t.empId << " " << t.cabId << " " << t.cost << " " << t.date.day << " " << t.date.month << " " << t.date.year << endl;
            }
        }
    }
};

int main()
{

    vector<Employee> emps;

    for (int i = 0; i < 5; i++)
    {
        Employee e;
        e.name = "aaa";
        e.role = "normal";
        e.index = i;
        emps.push_back(e);
    }

    for (int i = 5; i < 7; i++)
    {
        Employee e;
        e.name = "aaa";
        e.role = "HR";
        e.index = i;
        emps.push_back(e);
    }

    for (int i = 7; i < 10; i++)
    {
        Employee e;
        e.name = "aaa";
        e.role = "Manager";
        e.index = i;
        emps.push_back(e);
    }

    EmployeeList::empList = emps;

    Report report;

    while (true)
    {
        int choice;
        cout << ("\nonly 10 employees available. Their empId is 0 to 9\n1.New Trip\n2.Total Cost per employee\n3.Total Cost per employee in given range\n4.Total cost per month\n5.Trips done by given employee\n6.Exit\n");
        cout << ("Enter your choice : ");
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            cout << ("Enter the employee id : ");
            int tmp;
            cin >> tmp;
            Employee e = EmployeeList::getEmpById(tmp);
            Date date;
            cout << ("Enter current day : ");
            cin >> date.day;
            cout << ("Enter current month : ");
            cin >> date.month;
            cout << ("Enter current year : ");
            cin >> date.year;

            vector<Trip> tripList = TripList::tripList;

            Cab c;
            Type t;
            if (e.role == ("normal"))
            {
                t.type = "normal";
                t.cost = 100;
            }
            else if (e.role == ("HR"))
            {
                t.type = "AC";
                t.cost = 200;
            }
            else
            {
                t.type = "luxury";
                t.cost = 300;
            }
            c.type = t;

            Trip trip;

            trip.cabId = c.id;
            trip.empId = tmp;
            trip.date = date;
            trip.cost = c.type.cost;

            e.totalCost = e.totalCost + trip.cost;
            EmployeeList::empList[e.index] = e;
            TripList::tripList.push_back(trip);

            break;
        }
        case 2:
            report.totalCostPerEmployee();
            break;

        case 3:
            cout << ("Enter the employee id : ");
            int empId;
            cin >> empId;

            cout << ("Enter the Start date : ");
            Date start;
            cout << ("Enter day : ");
            cin >> start.day;
            cout << ("Enter month : ");
            cin >> start.month;
            cout << ("Enter year : ");
            cin >> start.year;

            cout << ("Enter the End date : ");
            Date end;
            cout << ("Enter day : ");
            cin >> end.day;
            cout << ("Enter month : ");
            cin >> end.month;
            cout << ("Enter year : ");
            cin >> end.year;

            report.totalCostInGivenRange(empId, start, end);
            break;

        case 4:
            cout << ("Enter the month number to be calculated : ");
            int month;
            cin >> month;
            (report.totalCostOfMonth(month));
            break;

        case 5:
            cout << ("Enter the employee id : ");
            int tmp;
            cin >> tmp;
            report.tripsByEmployee(tmp);
            break;
        case 6:
            return 0;
        }
    }
    return 0;
}