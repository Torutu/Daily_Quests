#include "../headers/updateCSV.hpp"

void printVector(const std::vector<std::string>& row) {
    for (const auto& cell : row) {
        std::cout << "row :" << cell;  // Print each element followed by a space
    }
    std::cout << std::endl;
}

void updateCSV(const std::string& day, const std::string quests[], int numQuests) {
    std::ifstream fileIn("Daily_Quests.csv");
    std::string line;
    std::vector<std::vector<std::string>> data;

    // Check if the file exists or is open. If not, create a new file with headers.
    if (!fileIn.is_open()) {
        std::cout << "File not found! Creating a new CSV file with headers." << std::endl;

        // Create a new CSV file with the necessary headers and structure
        std::ofstream fileOut("Daily_Quests.csv");
        fileOut << "Task,Monday,Tuesday,Wednesday,Thursday,Friday,Saturday,Sunday\n"; // Adding headers
        for (int i = 0; i < numQuests; ++i) {
            fileOut << quests[i] << ",FALSE,FALSE,FALSE,FALSE,FALSE,FALSE,FALSE\n"; // Default values (all FALSE)
        }
        fileOut.close();
        
        // Reopen the newly created file for reading and updating
        fileIn.open("Daily_Quests.csv");
    }

    // Read all lines of the CSV into a 2D vector
    while (std::getline(fileIn, line)) { //reads a line from the file and stores is in line
        std::stringstream ss(line); //allows us to treat line as a stream and process its contents, like splitting it by commas

        //std::cout << "line: " << line << std::endl;//debug

        std::string cell; //cell will temporarily hold each indicidual value from the line (split by commas)
        std::vector<std::string> row; //row is a container (vector) that will store each cell from the line as a string

        while (std::getline(ss, cell, ',')) { //reads each comma-separated value (cell) from the line

            //std::cout << "cell: " << cell << std::endl;//debug

            row.push_back(cell); //adds the current cell to the row
        }

        //printVector(row);//debug

        data.push_back(row); //adds the current row to the 2D vector
    }
    fileIn.close();

    // Find the index for the selected day
    // I know I could use map but I'm too tired to try now @_@
    int dayIndex = -1;
    if (day == "Monday" || day == "monday") dayIndex = 1;
    else if (day == "Tuesday" || day == "tuesday") dayIndex = 2;
    else if (day == "Wednesday" || day == "wednesday") dayIndex = 3;
    else if (day == "Thursday" || day == "thursday") dayIndex = 4;
    else if (day == "Friday" || day == "friday") dayIndex = 5;
    else if (day == "Saturday" || day == "saturday" ) dayIndex = 6;
    else if (day == "Sunday" || day == "sunday") dayIndex = 7;

    if (dayIndex == -1) {
        std::cout << "Invalid day!" << std::endl;
        return;
    }

    // Ask the user for their answers and update the CSV data
    for (int i = 0; i < numQuests; ++i) {
        std::string answer;
        std::cout << "Did you complete the task: " << quests[i] << " (yes/no)? ";
        std::cin >> answer;

        // Color the output based on the answer
        if (answer == "yes" || answer == "Yes" || answer == "y" || answer == "Y") {
            std::cout << "\033[32mTRUE\033[0m" << std::endl;  // Green for TRUE
            data[i + 1][dayIndex] = "TRUE";  // Set TRUE if completed
        } else if (answer == "no" || answer == "No" || answer == "n" || answer == "N") {
            std::cout << "\033[31mFALSE\033[0m" << std::endl;  // Red for FALSE
            data[i + 1][dayIndex] = "FALSE";  // Set FALSE if not completed
        } else {
            // Print in lighter blue color for invalid input
            std::cout << "\033[94mInvalid answer! Please enter 'yes' or 'no'.\033[0m" << std::endl; // Light Blue for invalid answers
            i--;  // Stay in the same iteration if input is invalid
            continue;
        }
    }

    std::ofstream fileOut("Daily_Quests.csv");

    // Write the data to the CSV
    for (const auto& row : data) {
        for (size_t i = 0; i < row.size(); ++i) {
            fileOut << row[i];  //output the values
            if (i < row.size() - 1) fileOut << ",";  // Separate columns with commas
        }
        fileOut << std::endl;  // Move to the next line after each row
    }

    fileOut.close();
    std::cout << "CSV file updated successfully!" << std::endl;
}
