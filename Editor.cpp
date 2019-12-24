#include "Editor.h"
#include <sstream>
using namespace std;


void Editor::loop()
{
    while(flagInput) 
    {
        getline (cin,strInput);
        input(strInput);
    }
    
    
}

void Editor::input(string input)
{
    int strInputSize = input.size();
    strInput = input;
    if(isdigit(input[0])) //the input is a number
    {
        for(int i=0 ; i<input.size(); i++)
        {
            if(!(isdigit(input[i])))
            {
                break;
            }
        }
        int inputNum = stoi(input);
        d.goToCurrentLine(inputNum);
    }
    else if(strInputSize == 1)  // Input consisting of one character
    {
        if(strInput.at(0) == 'p')
        {
            d.printsCurrentLine();
        }
        if(strInput.at(0) == 'n')
        {
            d.printsCLineNumTabCLine();
        }
        if(strInput.at(0) == 'a')
        {
            d.insertsTextAfterCLine();
        }
        if(strInput.at(0) == 'i')
        {
            d.insertsTextBeforeCLine();
        }
         if(strInput.at(0) == 'c')
        {
            d.changesCurrentLine();
        }
        if(strInput.at(0) == 'd')
        {
            d.deletesCurrentLine();
        }
        if(strInput.at(0) == '/')
        {
            d.repeatSearch();
        }
        if(strInput.at(0) == 'Q')  //Quits the editor without saving
        {
            cout <<'Q' <<endl;
            flagInput=false;  
        }
        
    }

    else if(strInputSize == 2 && strInput.at(0) == '%' && strInput.at(1) == 'p')  //Input consisting of two characters
    {
        d.printsAllLines();
    }

    else if(strInput.at(0) == '?' ) //Input contains more than two characters
    {   
        string text= strInput.substr(1,strInputSize);
        d.searchesBackward(text);
    }
    else if(strInput.at(0) == '/'  ) 
    {
        string text2=strInput.substr(1,strInputSize);
        d.searchesTextAfterCLine(text2);
    }
     else if(strInput.at(0) == 's' && strInput.at(1) == '/' ) 
    { 
        vector<string> result;
        string oldString = " ";
        string newString = " ";

        istringstream old(strInput);
        while(getline(old,newString,'/'))
        {
            result.push_back(newString);
        }
        oldString=result[1];
        newString= result[2];
        
        d.replaceOldNew(oldString,newString);
    }
    // else  //Invalid input
    // {
    //     cout << endl;
    //     cout << "?" << endl;
    // }


}