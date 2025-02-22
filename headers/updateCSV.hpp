#ifndef UPDATE_CSV_HPP
#define UPDATE_CSV_HPP

#include <string>
#include <algorithm>
#include <iostream>
#include <cctype>
#include <fstream>
#include <sstream>
#include <vector>
#include <iomanip>  // Include for setw() and setfill()
#include <SFML/Graphics.hpp>

void updateCSV(const std::string& day, const std::string quests[], int numQuests);

#endif  // UPDATE_CSV_HPP
