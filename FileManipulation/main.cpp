#include <iostream>
#include<fstream>

using namespace std;

const string INPUT_FILE_NAME = "test.txt";


int main() {

    ifstream ins;
    ins.open("/Users/shivanigoel/CLionProjects/FileManipulation/test.txt");

    string word,word2;
    char operators;

   /* if (ins.fail())
    {
        cout << "Input file open failed: " << INPUT_FILE_NAME;
        return -1;
    }*/

    ins>>word>>operators>>word2;
    cout<<word<<" "<<operators<<" " <<word2<<endl;

    ins>>word>>operators>>word2;
    cout<<word<<" "<<operators<<" " <<word2;

    ins.close();
    return 0;
}