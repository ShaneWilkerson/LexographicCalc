/*  Author: Shane Wilkerson 
 *  Date: 9-3-24
 *  Purpose: How many words are lexographic with a given amount of letters in the English dictionary
 */

#include <iostream>
#include <cstring>
#include <fstream>
using namespace std;
const char fname[] = "/home/fac/gordon/public_html/3350/dictionary.txt"; //file name

bool isOrdered(char word[]); //function prototype
int length; //declare global variable for word length
int linelength = 0;            

    

int main(int argc, char *argv[]) 
{    
    if (argc > 1) {
        length = atoi(argv[1]);        
    } 
    else {
        cout << "\nUsage: ./a.out <word length>\n";
        cout << "Length is the desired amount of letters that you want your words to be.\n";
        return 0; 
    }
        
    int n = 0;
    ifstream fin(fname); //opens file that is already declared above
    char word[100]; //the word that is chosen from the file can be up to 100 letters
    fin >> word;
    while (!fin.eof()) {
        if ((int)strlen(word) == length) {            
            if (isOrdered(word)) {
                linelength = linelength + length + 1;
                    if (linelength >= 75) {
                    cout << "\n";
                    linelength = 0; 
               
                    }
                ++n;
                cout << word << " ";                 
            }
        }
        fin >> word;       
    }
    cout << "\nThe number of words that are in lexicographic order is: " << n << "." << endl;
    fin.close();
    return 0;
}

bool isOrdered(char word[])
{
    for (int i = 0; i < length - 1; i++) { //increment through each index
        if (word[i] > word[i+1]) {   //compare current index with next index
           return false;
        }
                 
    }
    return true; 
}
            
    

