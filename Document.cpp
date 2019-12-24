#include "Document.h"
using namespace std;

// p  - prints the current line
void Document::printsCurrentLine()
{
    cout << "p" <<endl;
  
    cout << vectLines[cLine-1] << endl;
    
}

// n  - prints line number of current line followed by TAB followed by current line
void Document::printsCLineNumTabCLine()
{
    cout << "n" <<endl;
   
    cout << cLine << "\t" << vectLines[cLine-1] <<endl;
}

// %p  -prints all lines
void Document::printsAllLines()
{
    cout << "%p" <<endl;
    
    for(int i=0; i<vectLines.size() ; i++)
    {
        cout << vectLines[i] << endl;
    }
}

// 7   -makes line #7 the current line 
void Document::goToCurrentLine(int numLine)
{
    cout << numLine <<endl;
    
    cLine=numLine;
    cout <<vectLines[cLine-1] << endl;

}

// a   -appends new text after the current line
void Document::insertsTextAfterCLine()
{
    cout << "a" <<endl;
 
    string appendString;
    getline(cin,appendString);

    while(!(appendString == "." ))
    {
        cout<<appendString<<endl;

            vectLines.insert(vectLines.begin() + cLine, appendString);
            cLine = cLine+1;   
         getline(cin,appendString);
    }
    cout<< "." << endl;
    
}

// i   -inserts new text before the current line
void Document::insertsTextBeforeCLine()
{
    cout << "i" <<endl;
  
    string insertString;
    getline(cin,insertString);
    while(!(insertString == "."))
    {
     vectLines.insert(vectLines.begin() + cLine-1,insertString);
     cLine = cLine+1;
     cout << insertString << endl ;
     getline(cin,insertString);
    }
    cout<< "." << endl;
   

}

// c   -changes the current line for text that follows
void Document::changesCurrentLine()
{
    cout << "c" <<endl;
    
    string changeString;
    getline(cin,changeString);
    if(!(changeString == "."))
    { 
        cout << changeString << endl;
        vectLines[cLine-1]=changeString;
    }
    //vectLines.replace(vectLines.begin()+cLine,vectLines.begin()+cLine+1,changeString);
    cout<< "." << endl;
    
   
    
}

// d   -deletes the current line
void Document::deletesCurrentLine()
{
    cout << "d" <<endl;
  
    vectLines.erase(vectLines.begin()+cLine-1);
    cLine=cLine-1;
   
}

// /text   -text searches forward after current line for the specified text
void Document::searchesTextAfterCLine(string text)
{
    cout << "/" << text <<endl;
   
    bool flag = true;
    int i = 0;
    for(i=cLine ; i<vectLines.size() && flag ;i++)
    {
        if(vectLines[i].find(text)!= string::npos )
        {
            cout<< vectLines[i] << endl;
            flag=false;
            cLine = i+1 ;
        }
    }

    if(flag)
    {
        for(i=0 ; i<cLine;i++)
        {
          if(vectLines[i].find(text)!= string::npos )
            {
                     cout<< vectLines[i] << endl;
                     flag=false;
                     cLine = i+1 ;
            }
        }
    }    
    lastSearchText = text;
   

}

// /   -Repeat search.
void Document::repeatSearch()
{
    cout << "/" <<endl;
    
    bool flag = true;
    int i=0;
    for(i=cLine ; i<vectLines.size() && flag ;i++)
    {
        if(vectLines[i].find(lastSearchText) != string::npos)
        {
            cout << vectLines[i] << endl;
            flag=false;
            cLine = i+1 ;
        }
    }
    
    if(flag)
        {
            for(i=0 ; i<cLine && flag ;i++)
            {
                if(vectLines[i].find(lastSearchText)!= string::npos )
                 {
                     cout<< vectLines[i] << endl;
                     flag=false;
                     cLine = i+1 ;
                }
            }
        }
  
}

// ?text   -text searches backward
void Document::searchesBackward(string text)
{
    cout << "?" << text <<endl;
    bool flag = true;
    int i=0;
    for(i=cLine-1 ; i>=0 && flag ;i--)
    {
        if(vectLines[i].find(text) != string::npos)
        {
            cout << vectLines[i] << endl;
            flag=false;
            cLine = i+1 ;
        }
    }
    if(flag)
    {
        for(i=vectLines.size()-1 ; i>cLine && flag ;i--)
        {
           if(vectLines[i].find(text)!= string::npos )
            {
                cout<< vectLines[i] << endl;
                flag=false;
                cLine = i+1 ;
             }
        }
    }
    
    
}

//   s/old/new/   -replaces old string with new in current line (google: C++ split or token)
void Document::replaceOldNew( string oldString , string newString)
{
    
    cout << "s/" << oldString << "/" << newString << "/" <<endl; 
    string vec = vectLines[cLine-1];
    vec.replace(vec.find(oldString),oldString.length(), newString);
    vectLines[cLine-1]= vec;
    
    

}

// Q    - Quits the editor without saving
// void Document::quitsWithoutSaving()
// {
//       cout << 'Q' <<endl;
// }