# Daily Quest Tracker
The Daily Quest Tracker is a simple C++ application designed to help users manage and track their daily tasks and quests. The application uses a CSV file to store quest data and allows users to update the status of each task on a daily basis.

## Features
- Track Daily Quests: Each quest can be marked as completed or not for each day of the week (Monday to Sunday).
- CSV-based Storage: Quest data is stored in a CSV file, making it easy to view and manage.
- User Interaction: The program prompts users for input to track the completion of tasks.
- Color-Coded Feedback: Positive and negative feedback is shown in color for easy identification.
- File Management: If the CSV file does not exist, it will be automatically created with default quests and headers.

## Setup for Linux(Debian, Ubuntu, etc...)

1. Clone the repository:
```bash
git clone git@github.com:Torutu/Daily_Quests.git
cd Daily_Quests
```
2. Build the project: The project uses a Makefile:
```bash
make
```
3. Run the program: Once the project is built, you can run the executable:
```bash
./Daily_Quest_Tracker
```
4. Clean up: To remove compiled object files and the executable, run:
```bash
make clean
```
to fully clean everything:
```bash
make fclean
```

## File Structure

```bash
Daily_Quest_Tracker/
├── src/
│   ├── main.cpp         # Main program logic
│   ├── quests.cpp       # contains the quest array
│   ├── updateCSV.cpp    # Most of the program's logic
├── obj/                 # Object files will be stored here
├── Daily_Quest_Tracker  # Executable file
├── Makefile             # Makefile for building the project
└── Daily_Quests.csv     # CSV file storing quest data <-- this will be created after using the program
```
