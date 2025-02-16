#include "../headers/updateCSV.hpp"
#include "../headers/quests.hpp"

using namespace std;

int main() {
    string quests[NUM_QUESTS];
    getQuests(quests);

    string day;
    cout << "Enter the day: ";
    cin >> day;

    updateCSV(day, quests, NUM_QUESTS);

    return 0;
}

