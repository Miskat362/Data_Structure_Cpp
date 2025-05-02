#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <string>
using namespace std;

// Function to find the itinerary from the given tickets
void findItinerary(const unordered_map<string, string>& tickets) {
    // Start from the first ticket
    unordered_set<string> to;

    for(pair<string, string> ticket : tickets) {
        to.insert(ticket.second);
    }
    string start = "";
    for(pair<string, string> ticket : tickets) {
        if(to.find(ticket.first) == to.end()) {
            start = ticket.first;
        }
    }
    // Print the itinerary
    while(tickets.count(start)) {
        cout << start << " -> ";
        start = tickets.at(start);
    }
    cout << start << endl;
}

int main() {
    unordered_map<string, string> tickets;
    tickets["Chennai"] = "Bengaluru";
    tickets["Mumbai"] = "Delhi";
    tickets["Goa"] = "Chennai";
    tickets["Delhi"] = "Goa";

    findItinerary(tickets);

    return 0;
}