//Jordan Poston
//CS 210-10308
//Assignment 5-2 World Temperatures

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <iomanip>

using namespace std;

int main() {    //Open input file "FahrenheitTemperature.txt"
    ifstream inputFile("FahrenheitTemperature.txt");
    //Check if the file is opened successfully
    if (!inputFile) {
        cerr << "Error: Unable to open input file." << endl;
        return 1;
    }
    //Open output file "CelsiusTemperature.txt"
    ofstream outputFile("CelsiusTemperature.txt");
    // Check if the file is opened successfully
    if (!outputFile) {
        cerr << "Error: Unable to open output file." << endl;
        return 1;
    }
	// Convert Fahrenheit to Celsius
    const double FAHRENHEIT_TO_CELSIUS = 5.0 / 9.0;

	//Read input file and convert temperatures
    string city;
    int fahrenheit;
    while (inputFile >> city >> fahrenheit) {
        //Convert Fahrenheit to Celsius 
        double celsius = (fahrenheit - 32.0) * FAHRENHEIT_TO_CELSIUS;
		//Write city name and Celsius temperature to the output file
        outputFile << city << " " << celsius << endl;
    }
    //Close files
    inputFile.close();
    outputFile.close();

    return 0;
} 
//End program