#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include<bits/stdc++.h>

class Passenger {
public:
    int passengerId;
    std::string name;
    int age;
    int number;
    std::string alloted;

    Passenger() : passengerId(0), age(0) {} // Default constructor

    Passenger(std::string n, int a, std::string b) : name(n), age(a), alloted(b) {}
};

class TicketBooker {
public:
    static int availableLowerBerths;
    static int availableMiddleBerths;
    static int availableUpperBerths;
    static int availableRacTickets;
    static int availableWaitingList;

    static std::queue<int> waitingList;
    static std::queue<int> racList;
    static std::vector<int> bookedTicketList;

    static std::vector<int> lowerBerthsPositions;
    static std::vector<int> middleBerthsPositions;
    static std::vector<int> upperBerthsPositions;
    static std::vector<int> racPositions;
    static std::vector<int> waitingListPositions;

    static std::unordered_map<int, Passenger> passengers;

    void bookTicket(Passenger p, int berthInfo, std::string allotedBerth) {
        p.number = berthInfo;
        p.alloted = allotedBerth;
        passengers[p.passengerId] = p;
        bookedTicketList.push_back(p.passengerId);

        std::cout << "--------------------------Booked Successfully" << std::endl;
    }

    void addToRAC(Passenger p, int racInfo, std::string allotedRAC) {
        p.number = racInfo;
        p.alloted = allotedRAC;
        passengers[p.passengerId] = p;
        racList.push(p.passengerId);
        availableRacTickets--;
        racPositions.erase(racPositions.begin());

        std::cout << "--------------------------added to RAC Successfully" << std::endl;
    }

    void addToWaitingList(Passenger p, int waitingListInfo, std::string allotedWL) {
        p.number = waitingListInfo;
        p.alloted = allotedWL;
        passengers[p.passengerId] = p;
        waitingList.push(p.passengerId);
        availableWaitingList--;
        waitingListPositions.erase(waitingListPositions.begin());

        std::cout << "-------------------------- added to Waiting List Successfully" << std::endl;
    }

    void cancelTicket(int passengerId) {
        Passenger p = passengers[passengerId];
        passengers.erase(passengerId);
        bookedTicketList.erase(std::remove(bookedTicketList.begin(), bookedTicketList.end(), passengerId), bookedTicketList.end());

        int positionBooked = p.number;

        std::cout << "---------------cancelled Successfully" << std::endl;

        if (p.alloted == "L") {
            availableLowerBerths++;
            lowerBerthsPositions.push_back(positionBooked);
        } else if (p.alloted == "M") {
            availableMiddleBerths++;
            middleBerthsPositions.push_back(positionBooked);
        } else if (p.alloted == "U") {
            availableUpperBerths++;
            upperBerthsPositions.push_back(positionBooked);
        }

        if (!racList.empty()) {
            Passenger passengerFromRAC = passengers[racList.front()];
            int positionRac = passengerFromRAC.number;
            racPositions.push_back(positionRac);
            racList.pop();
            availableRacTickets++;

            if (!waitingList.empty()) {
                Passenger passengerFromWaitingList = passengers[waitingList.front()];
                int positionWL = passengerFromWaitingList.number;
                waitingListPositions.push_back(positionWL);
                waitingList.pop();

                passengerFromWaitingList.number = racPositions.front();
                passengerFromWaitingList.alloted = "RAC";
                racPositions.erase(racPositions.begin());
                racList.push(passengerFromWaitingList.passengerId);

                availableWaitingList++;
                availableRacTickets--;
            }
            bookTicket(passengerFromRAC);
        }
    }

    void printAvailable() {
        std::cout << "Available Lower Berths " << availableLowerBerths << std::endl;
        std::cout << "Available Middle Berths " << availableMiddleBerths << std::endl;
        std::cout << "Available Upper Berths " << availableUpperBerths << std::endl;
        std::cout << "Available RACs " << availableRacTickets << std::endl;
        std::cout << "Available Waiting List " << availableWaitingList << std::endl;
        std::cout << "--------------------------" << std::endl;
    }

    void printPassengers() {
        if (passengers.empty()) {
            std::cout << "No details of passengers" << std::endl;
            return;
        }

        for (const auto& p : passengers) {
            std::cout << "PASSENGER ID " << p.second.passengerId << std::endl;
            std::cout << " Name " << p.second.name << std::endl;
            std::cout << " Age " << p.second.age << std::endl;
            std::cout << " Status " << p.second.number << p.second.alloted << std::endl;
            std::cout << "--------------------------" << std::endl;
        }
    }
};

int TicketBooker::availableLowerBerths = 1;
int TicketBooker::availableMiddleBerths = 1;
int TicketBooker::availableUpperBerths = 1;
int TicketBooker::availableRacTickets = 1;
int TicketBooker::availableWaitingList = 1;

std::queue<int> TicketBooker::waitingList;
std::queue<int> TicketBooker::racList;
std::vector<int> TicketBooker::bookedTicketList;

std::vector<int> TicketBooker::lowerBerthsPositions(1, 1);
std::vector<int> TicketBooker::middleBerthsPositions(1, 1);
std::vector<int> TicketBooker::upperBerthsPositions(1, 1);
std::vector<int> TicketBooker::racPositions(1, 1);
std::vector<int> TicketBooker::waitingListPositions(1, 1);

std::unordered_map<int, Passenger> TicketBooker::passengers;

void bookTicket(Passenger p) {
    TicketBooker booker;
    if (TicketBooker::availableWaitingList == 0) {
        std::cout << "No Tickets Available" << std::endl;
        return;
    }

    if ((p.alloted == "L" && TicketBooker::availableLowerBerths > 0) ||
        (p.alloted == "M" && TicketBooker::availableMiddleBerths > 0) ||
        (p.alloted == "U" && TicketBooker::availableUpperBerths > 0)) {
        std::cout << "Preferred Berth Available" << std::endl;
        if (p.alloted == "L") {
            std::cout << "Lower Berth Given" << std::endl;
            booker.bookTicket(p, TicketBooker::lowerBerthsPositions[0], "L");
            TicketBooker::lowerBerthsPositions.erase(TicketBooker::lowerBerthsPositions.begin());
            TicketBooker::availableLowerBerths--;

        } else if (p.alloted == "M") {
            std::cout << "Middle Berth Given" << std::endl;
            booker.bookTicket(p, TicketBooker::middleBerthsPositions[0], "M");
            TicketBooker::middleBerthsPositions.erase(TicketBooker::middleBerthsPositions.begin());
            TicketBooker::availableMiddleBerths--;

        } else if (p.alloted == "U") {
            std::cout << "Upper Berth Given" << std::endl;
            booker.bookTicket(p, TicketBooker::upperBerthsPositions[0], "U");
            TicketBooker::upperBerthsPositions.erase(TicketBooker::upperBerthsPositions.begin());
            TicketBooker::availableUpperBerths--;
        }
    } else if (TicketBooker::availableLowerBerths > 0) {
        std::cout << "Lower Berth Given" << std::endl;
        booker.bookTicket(p, TicketBooker::lowerBerthsPositions[0], "L");
        TicketBooker::lowerBerthsPositions.erase(TicketBooker::lowerBerthsPositions.begin());
        TicketBooker::availableLowerBerths--;

    } else if (TicketBooker::availableMiddleBerths > 0) {
        std::cout << "Middle Berth Given" << std::endl;
        booker.bookTicket(p, TicketBooker::middleBerthsPositions[0], "M");
        TicketBooker::middleBerthsPositions.erase(TicketBooker::middleBerthsPositions.begin());
        TicketBooker::availableMiddleBerths--;

    } else if (TicketBooker::availableUpperBerths > 0) {
        std::cout << "Upper Berth Given" << std::endl;
        booker.bookTicket(p, TicketBooker::upperBerthsPositions[0], "U");
        TicketBooker::upperBerthsPositions.erase(TicketBooker::upperBerthsPositions.begin());
        TicketBooker::availableUpperBerths--;

    } else if (TicketBooker::availableRacTickets > 0) {
        std::cout << "RAC available" << std::endl;
        booker.addToRAC(p, TicketBooker::racPositions[0], "RAC");

    } else if (TicketBooker::availableWaitingList > 0) {
        std::cout << "Added to Waiting List" << std::endl;
        booker.addToWaitingList(p, TicketBooker::waitingListPositions[0], "WL");
    }
}

void cancelTicket(int id) {
    TicketBooker booker;
    if (booker.passengers.find(id) == booker.passengers.end()) {
        std::cout << "Passenger detail Unknown" << std::endl;
    } else {
        booker.cancelTicket(id);
    }
}

int main() {
    bool loop = true;
    while (loop) {
        std::cout << " 1. Book Ticket \n 2. Cancel Ticket \n 3. Available Tickets \n 4. Booked Tickets \n 5. Exit" << std::endl;
        int choice;
        std::cin >> choice;

        switch (choice) {
            case 1: {
                std::cout << "Enter Passenger name, age, and berth preference (L, M, or U)" << std::endl;
                std::string name;
                int age;
                std::string berthPreference;
                std::cin >> name >> age >> berthPreference;

                Passenger p(name, age, berthPreference);
                bookTicket(p);
            }
                break;

            case 2: {
                std::cout << "Enter passenger Id to cancel" << std::endl;
                int id;
                std::cin >> id;
                cancelTicket(id);
            }
                break;

            case 3: {
                TicketBooker booker;
                booker.printAvailable();
            }
                break;

            case 4: {
                TicketBooker booker;
                booker.printPassengers();
            }
                break;

            case 5: {
                loop = false;
            }
                break;

            default:
                break;
        }
    }

    return 0;
}
