#include "Document.h"
using namespace std;

class Editor
{

private:
Document d;
string strInput;
bool flagInput = true;
//int strInputSize = strInput.size();

public:
void loop();
void input(string input);

};