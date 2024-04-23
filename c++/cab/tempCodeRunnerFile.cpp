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