#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include "interface.h"
#include <string.h>
#include <limits.h>

using namespace std;


int main(int argc, char *argv[]){
    cout << "Welcome to Biquadris" << endl;

    // Command Line arguments
    bool textOnly = false;
    bool seed = false;
    string seq1 = "biquadris_sequence1.txt";
    string seq2 = "biquadris_sequence2.txt";
    int level = 0;
    int seedValue = INT_MAX;


    for (int i = 0; i < argc; i++) {
	    
        if (strcmp(argv[i], "-text") == 0)  { 
            textOnly = true;
        }

        if (strcmp(argv[i], "-seed") == 0) {
            istringstream iss{argv[i + 1]};
            iss >> seedValue; 
        }

        if (strcmp(argv[i], "-scriptfile1") == 0) {
            seq1 = argv[i+1];
        }

        if (strcmp(argv[i], "-scriptfile2") == 0) {
            seq2 = argv[i+1];
        }

        if (strcmp(argv[i], "-level") == 0) {
            istringstream iss{argv[i + 1]};
            iss >> level;
        }
	

    }

        Interface game(textOnly, seedValue, level, seq1, seq2);
        game.initialize();
}
