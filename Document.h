#include <string> 
#include <vector>
#include <iostream>
using namespace std;

class Document
{
private:
vector<string> vectLines;
int cLine = 0; //current line
string lastSearchText="";

public:

// p  - prints the current line
void printsCurrentLine();

// n  - prints line number of current line followed by TAB followed by current line
void printsCLineNumTabCLine();

// %p  -prints all lines
void printsAllLines();

// 7   -makes line #7 the current line 
void goToCurrentLine(int numLine);

// a   -appends new text after the current line
void insertsTextAfterCLine();

// i   -inserts new text before the current line
void insertsTextBeforeCLine();

// c   -changes the current line for text that follows
void changesCurrentLine();

// d   -deletes the current line
void deletesCurrentLine();

// /text   -text searches forward after current line for the specified text
void searchesTextAfterCLine(string text);

// /   -Repeat search.
void repeatSearch();

// ?text   -text searches backward
void searchesBackward( string text);

//   s/old/new/   -replaces old string with new in current line (google: C++ split or token)
void replaceOldNew( string oldString , string newString);

// Q    - Quits the editor without saving
// void quitsWithoutSaving();



};