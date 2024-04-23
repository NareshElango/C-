#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class passenger {
public:
    string name;
    int age;
    string berth_perf;

    passenger(const string &n, int a, const string &bp) {
        name = n;
        age = a;
        berth_perf = bp;
    }
};

class ticketbooker {
    static int availlow, availmed, availhigh, availrpc, availwait;

    static vector<int> lowerberth, midberth, higherberth, rpc, waiting;

    unordered_map<int, passenger> passanger;

    static void bookTicket(passenger p);
    static void addToRAC(passenger p, int position, const std::string &type);
    static void addToWaitingList(passenger p, int position, const std::string &type);
    static void cancelTicket(int id);
    static void printAvailable();
    static void printPassengers();
};

int ticketbooker::availlow = 10;
int ticketbooker::availmed = 10;
int ticketbooker::availhigh = 10;
int ticketbooker::availrpc = 10;
int ticketbooker::availwait = 10;

vector<int> ticketbooker::lowerberth(10, 0);
vector<int> ticketbooker::midberth(10, 0);
vector<int> ticketbooker::higherberth(10, 0);
vector<int> ticketbooker::rpc(10, 0);
vector<int> ticketbooker::waiting(10, 0);

void ticketbooker::bookTicket(passenger p) {
    if (availwait == 0)
        cout << "No tickets available";

    if ((p.berth_perf == "L" && availlow > 0) || (p.berth_perf == "M" && availmed > 0) || (p.berth_perf == "U" && availhigh > 0)) {
        cout << "Preferred berth available";
        if (p.berth_perf == "L") {
            cout << "Lower berth given";
            rpc.push_back(lowerberth[0]);
            lowerberth.erase(lowerberth.begin());
            availlow--;
        } else if (p.berth_perf == "M") {
            cout << "Middle berth given";
            rpc.push_back(midberth[0]);
            midberth.erase(midberth.begin());
            availmed--;
        } else if (p.berth_perf == "U") {
            cout << "Upper berth given";
            rpc.push_back(higherberth[0]);
            higherberth.erase(higherberth.begin());
            availhigh--;
        }
    } else if (availlow > 0) {
        cout << "Lower berth given";
        rpc.push_back(lowerberth[0]);
        lowerberth.erase(lowerberth.begin());
        availlow--;
    } else if (availmed > 0) {
        cout << "Middle berth given";
        rpc.push_back(midberth[0]);
        midberth.erase(midberth.begin());
        availmed--;
    } else if (availhigh > 0) {
        cout << "Upper berth given";
        rpc.push_back(higherberth[0]);
        higherberth.erase(higherberth.begin());
        availhigh--;
    } else if (availrpc > 0) {
        cout << "RAC given";
        addToRAC(p, rpc[0], "RAC");
    } else if (availwait > 0) {
        cout << "Added to waiting ";
        addToWaitingList(p, waiting[0], "WL");
    }
}


