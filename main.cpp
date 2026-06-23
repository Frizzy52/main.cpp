#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <iomanip>

using namespace std;

// ---------------- STRUCT ----------------
struct Event {
    int id;
    string title;
    string date;
    string location;
};

// ---------------- GLOBAL DATA ----------------
vector<Event> events;
const string filename = "events.txt";

// ===================================================
// LOAD DATA
// ===================================================
void loadData() {
    events.clear();
    ifstream file(filename);

    if (!file.is_open()) {
        cout << "No data file found. Starting fresh.\n";
        return;
    }

    Event e;
    while (file >> e.id) {
        file.ignore();
        getline(file, e.title, '|');
        getline(file, e.date, '|');
        getline(file, e.location);

        if (!e.title.empty())
            events.push_back(e);
    }

    file.close();
}

// ===================================================
// SAVE DATA
// ===================================================
void saveData() {
    ofstream file(filename);

    for (auto &e : events) {
        file << e.id << " "
             << e.title << "|"
             << e.date << "|"
             << e.location << "\n";
    }

    file.close();
}

// ===================================================
// ADD EVENT
// ===================================================
void addEvent() {
    Event e;

    cout << "\n--- ADD EVENT ---\n";

    cout << "Enter ID: ";
    cin >> e.id;

    cin.ignore();

    cout << "Enter title: ";
    getline(cin, e.title);

    cout << "Enter date (YYYY-MM-DD): ";
    getline(cin, e.date);

    cout << "Enter location: ";
    getline(cin, e.location);

    events.push_back(e);
    saveData();

    cout << "Event successfully added!\n";
}

// ===================================================
// SHOW ALL EVENTS
// ===================================================
void showAll() {
    cout << "\n--- ALL EVENTS ---\n";

    if (events.empty()) {
        cout << "No events available.\n";
        return;
    }

    for (const auto &e : events) {
        cout << "\nID: " << e.id;
        cout << "\nTitle: " << e.title;
        cout << "\nDate: " << e.date;
        cout << "\nLocation: " << e.location;
        cout << "\n----------------------";
    }
    cout << "\n";
}

// ===================================================
// SEARCH EVENT
// ===================================================
void searchEvent() {
    cout << "\n--- SEARCH EVENT ---\n";

    string key;
    cout << "Enter title keyword: ";
    getline(cin >> ws, key);

    bool found = false;

    for (const auto &e : events) {
        if (e.title.find(key) != string::npos) {
            cout << "\nFOUND EVENT:";
            cout << "\nID: " << e.id;
            cout << "\nTitle: " << e.title;
            cout << "\nDate: " << e.date;
            cout << "\nLocation: " << e.location;
            cout << "\n----------------------";
            found = true;
        }
    }

    if (!found) {
        cout << "No matching events found.\n";
    }
}

// ===================================================
// DELETE EVENT
// ===================================================
void deleteEvent() {
    cout << "\n--- DELETE EVENT ---\n";

    int id;
    cout << "Enter ID to delete: ";
    cin >> id;

    auto it = remove_if(events.begin(), events.end(),
                        [id](Event &e) {
                            return e.id == id;
                        });

    if (it != events.end()) {
        events.erase(it, events.end());
        saveData();
        cout << "Event deleted successfully!\n";
    } else {
        cout << "Event with this ID not found.\n";
    }
}

// ===================================================
// COUNT EVENTS
// ===================================================
void countEvents() {
    cout << "\nTotal events: " << events.size() << "\n";
}

// ===================================================
// MENU
// ===================================================
void menu() {
    int choice;

    do {
        cout << "\n=============================\n";
        cout << "      EVENT MANAGER\n";
        cout << "=============================\n";
        cout << "1. Add event\n";
        cout << "2. Show all events\n";
        cout << "3. Search event\n";
        cout << "4. Delete event\n";
        cout << "5. Count events\n";
        cout << "0. Exit\n";
        cout << "Choose: ";

        cin >> choice;

        switch (choice) {
            case 1: addEvent(); break;
            case 2: showAll(); break;
            case 3: searchEvent(); break;
            case 4: deleteEvent(); break;
            case 5: countEvents(); break;
            case 0: cout << "Goodbye!\n"; break;
            default: cout << "Invalid option!\n";
        }

    } while (choice != 0);
}

// ===================================================
// MAIN
// ===================================================
int main() {
    loadData();
    menu();
    return 0;
}
