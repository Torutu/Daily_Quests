#include "../headers/updateCSV.hpp"
#include "../headers/quests.hpp"
#include "../headers/displayProgress.hpp"

using namespace std;

int main() {

    string quests[NUM_QUESTS];
    getQuests(quests);

    string answer;
    cout << "Do you want check your progress? ";
    cin >> answer;

    std::transform(answer.begin(), answer.end(), answer.begin(), ::tolower);
    cout << answer << endl;
    if (answer == "yes" || answer == "y") {
        displayProgress();
        return 0;
    } else if (answer == "no" || answer == "n") {
        
    string day;
    cout << "Enter the day: ";
    cin >> day;

    updateCSV(day, quests, NUM_QUESTS);

    }
    else { cout << "wrong input" << endl; }

    return 0;
}

