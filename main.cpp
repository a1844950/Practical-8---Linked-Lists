#include <iostream>
#include <sstream>
#include "LinkedList.h"
#include "string"
using namespace std;

bool isNumeric(std::string const& str)
{
    auto it = str.begin();
    while (it != str.end() && std::isdigit(*it)) {
        it++;
    }
    return !str.empty() && it == str.end();
}

int main() {
   
    string strs[100+3];
    string commend;
    bool exist = false;
    int numsize=0, argsize = 0;

    string line = "start";
   
        getline(cin, line);
        istringstream sin(line); 
        string field;

        while (sin>> field)
        {
            if (isNumeric(field))
            {
                strs[numsize++] = field;
                if (exist)
                    argsize++;
            }
            else
            {
                commend = field;
                exist = true;
            }
        }

        int arrsize = numsize - argsize;
        int* arr = new int[arrsize];
        for (int i = 0; i < arrsize; i++)
            arr[i] = atoi(strs[i].c_str());

        LinkedList* list = new LinkedList(arr, arrsize);

        if (commend=="AF")
        {
            int i = numsize - argsize;
            int arg = atoi(strs[i].c_str());
            list->addFront(arg);
        }
        else if (commend == "AE")
        {
            int i = numsize - argsize;
            int arg = atoi(strs[i].c_str());
            list->addEnd(arg);
        }
        else if (commend == "AP")
        {
            int i = numsize - argsize;
            int position = atoi(strs[i].c_str());
            int arg = atoi(strs[i+1].c_str());

            list->addAtPosition(position,arg);
        }
        else if (commend == "S")
        {
            int i = numsize - argsize;
            int arg = atoi(strs[i].c_str());
            list->search(arg);
        }
        else if (commend == "DF")
            list->deleteFront();
        else if (commend == "DE")
            list->deleteEnd();
        else if (commend == "DP")
        {
            int i = numsize - argsize;
            int arg = atoi(strs[i].c_str());
            list->deletePosition(arg);
        }
        else if (commend == "GI")
        {
            int i = numsize - argsize;
            int arg = atoi(strs[i].c_str());
            list->getItem(arg);
        }


        list->printItems();

        return 0;
}