#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class taxi {
public:
    static int taxicount;
    int id;
    bool booked;
    int freetime;
    int totalearn;
    char currspot;
    vector<string> trips;

    taxi() {
        booked = false;
        currspot = 'A';
        freetime = 6;
        totalearn = 0;
        taxicount += 1;
        id = taxicount;
    }

    void setdetail(bool booked, char curr, int free, int totalearn, string trip) {
        this->booked = booked;
        currspot = curr;
        freetime = free;
        this->totalearn = totalearn;
        trips.push_back(trip);
    }

    void printdetails() {
        cout << "taxi:" << this->id << " total_earnings:" << this->totalearn << endl;
        cout << "TaxiID    BookingID    CustomerID    From    To    PickupTime    DropTime    Amount\n";

        for (string trip : trips) {
            cout << trip << endl;
        }
    }

    void printtaxi() {
        cout << "taxi:" << this->id << " total earning:" << this->totalearn << " curr spot:" << this->currspot << " free time:" << this->freetime << endl;
    }
};

class booking {
public:
    void book(int id, char pl, char dl, int pt, vector<taxi>& taxis) {
        int min = 999;
        int earn = 0;
        char nxtspo = 'z';
        taxi* bookedtaxi = nullptr;

        for (taxi& t : taxis) {
            if (!t.booked && t.freetime <= pt) {
                int mindist = abs(pl - t.currspot);

                if (mindist < min) {
                    bookedtaxi = &t;
                    earn = (abs(dl - pl) - 5) * 10 + 100;
                    int droptim = abs(dl - pl) / 15;
                    t.freetime += droptim;
                    t.currspot = dl;
                    min = mindist;
                    nxtspo = dl;
                }
            }
        }

        if (bookedtaxi != nullptr) {
            string tripdetail = to_string(bookedtaxi->id) + " " + to_string(id) + " " + pl + " " + dl + " " + to_string(pt) + " " + to_string(pt + abs(dl - pl) / 15) + " " + to_string(earn);
            bookedtaxi->setdetail(true, nxtspo, bookedtaxi->freetime, bookedtaxi->totalearn + earn, tripdetail);
            cout << "taxi is booked taxi id:" << bookedtaxi->id << endl;
        } else {
            cout << "No available taxis at the moment." << endl;
        }
    }

    vector<taxi> create(int n) {
        vector<taxi> taxis;
        for (int i = 1; i <= n; i++) {
            taxi t;
            taxis.push_back(t);
        }
        return taxis;
    }
};

int taxi::taxicount = 0;

int main() {
    cout << "Welcome to taxi booking" << endl;
    booking booker;
    vector<taxi> taxis = booker.create(5);

    bool loop = true;

    while (loop) {
        cout << "\n1. Booking\n2. Display\n3. Exit" << endl;
        int n;
        cin >> n;
        switch (n) {
            case 1: {
                cout << "Enter the pickup location: ";
                char picup;
                cin >> picup;
                cout << "Enter the drop location: ";
                char drop;
                cin >> drop;
                cout << "Enter the pickup time: ";
                int time;
                cin >> time;

                booker.book(taxi::taxicount + 1, picup, drop, time, taxis);
                break;
            }
            case 2: {
                for (taxi& t : taxis) {
                    t.printdetails();
                }
                break;
            }
            case 3: {
                loop = false;
                cout << "Thanks for using this" << endl;
                break;
            }
            default: {
                cout << "Enter the correct option" << endl;
                break;
            }
        }
    }
    return 0;
}
