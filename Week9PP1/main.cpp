#include <iostream>
#include <string>
#include <exception>
#include <stdexcept>
#include <cctype>


using namespace std;

class ParseError : public runtime_error
{
public:
    ParseError(const string& what);
};

ParseError::ParseError(const string& what) : runtime_error(what) {}

void parse_time(string time, int& hours, int& minutes);

void test(string time, int h, int m, string e)
{
    int hours = -1;
    int minutes = -1;
    try
    {
        parse_time(time, hours, minutes);
        cout << hours << ":" << minutes << endl;
        if (e == "")
            cout << "Expected: " << h << ":" << m << endl;
        else
            cout << "Expected: " << e << endl;

    }
    catch (ParseError& ex) {
        cout << ex.what() << endl;
        cout << "Expected: ";
        if (e == "") cout << h << ":" << m << endl;
        else cout << e << endl;
    }
    catch (range_error& ex) {
        cout << "range_error" << endl;
        cout << "Expected: ";
        if (e == "") cout << h << ":" << m << endl;
        else cout << e << endl;
    }
    catch (out_of_range& ex) {
        cout << "out_of_range" << endl;
        cout << "Expected: ";
        if (e == "") cout << h << ":" << m << endl;
        else cout << e << endl;
    }
    catch (...)
    {
        cout << "Unexpected exception" << endl;
        cout << "Expected: ";
        if (e == "") cout << h << ":" << m << endl;
        else cout << e << endl;
    }
}

int main()
{
    test("1:23 am", 1, 23, "");
    test("1:23 pm", 13, 23, "");
    test("12:23 pm", 12, 23, "");
    test("12:23 am", 0, 23, "");
    test("1:23 qm", -1, -1, "time not valid: 1:23 qm");
    test("1:23am", -1, -1, "time not valid: 1:23am");
    test("1:23 am ", -1, -1, "time not valid: 1:23 am");
    test("1:23", -1, -1, "out_of_range");
    test("1", -1, -1, "out_of_range");
    test("1:63 am", -1, -1, "range_error");
    test("0:13 am", -1, -1, "range_error");
    test("13:13 am", -1, -1, "range_error");

    return 0;
}

void parse_time(string time, int& hours, int& minutes)
{
    // Implementation without error checking


    string space=" ";
    string colon=":";

    size_t spacePos = time.find(space);
    if(spacePos==string::npos)
        throw ParseError("time is invalid : "+time);

    string dayNightIndicator=time.substr(spacePos+1,2);

    if((dayNightIndicator!="am" && dayNightIndicator!="pm"))
        throw ParseError("time is invalid : "+time);

    size_t colonPos = time.find(colon);
    if(colonPos==string::npos)
        throw ParseError("time is invalid : "+time);

    int h=stoi(time.substr(0,colonPos));
    int m = stoi(time.substr(colonPos+1,2));

    if(h<1 || h>12 )
        throw range_error("Error in range");
    if(m<0 || m>59 )
        throw range_error("Error in range");

    //int spaceIndex = static_cast<int>(spacePos);
    if(time.at(time.length()-1)!='m')
        throw out_of_range("Out of range");

    int i = 1;
    if (isdigit(time[i])) {
        hours = 10 * (time[i - 1] - '0') + time[i] - '0';
        i++;
    } else {
        hours = time[i - 1] - '0';
    }
    i += 2;
    minutes = 10 * (time[i - 1] - '0') + time[i] - '0';
    i += 2;
    if (time[i] == 'a') {
        if (hours == 12) hours = 0;
    } else {
        if (hours != 12) hours += 12;
    }

}