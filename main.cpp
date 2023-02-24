#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

unsigned long long calcNum(float initial);

int main(int argc, const char* argv[]) {
    // Sanity check
    if (argc == 0){cout << "This program requires an input and output filename to run. Please see README" << endl;}
    // Variable definitions
    ifstream inFile(argv[1]);
    ofstream outFile(argv[2]);
    string line; unsigned long long outNum = 0;

    // Begin file readin
    if (inFile.is_open()){
        if (outFile.is_open()){
            while (!inFile.eof()){
                getline(inFile, line);
                if (stoi(line) == 0){break;}
                outNum = calcNum(stoi(line));
                cout << line << " days means " << outNum << " gifts." << endl;
                outFile << outNum << endl;
            }
            inFile.close();
            outFile.close();
        } else {cout << "Input filename incorrect. Please confirm that " << argv[2] << " is the correct filename." << endl;}
    } else {cout << "Input filename incorrect. Please confirm that " << argv[1] << " is the correct filename." << endl;}
}


unsigned long long calcNum(float initial){ // Calculate the number of gifts. Using long long to handle extremely long output
    double x = 6.0;
    if (initial == 0){return 0LL;}
    else if (initial == 1){return 1LL;}
    else{return round((initial / x) * (initial + 1) * (initial + 2));}
}
