#include <iostream>
#include <string>
#include <exception>
#include <stdexcept>

using namespace std;

class BadLuckError : public runtime_error
{
public:
   BadLuckError();
};

BadLuckError::BadLuckError() : runtime_error("") {}
void process(int arg, int& result, string& error);
int mystery(int x);

/*
  Complete this function that passes the argument to the
  mystery function. If the mystery function returns without throwing
  an exception, set result to its result. Otherwise, if the function
  throws a std::invalid_argument exception or std::range_error,
  set error to the what string of the exception object.
  If the function throws a different kind of std::logic_error or
  std::runtime_error, set error to "logic_error" or "runtime_error".
  Otherwise, set error to the string "unknown exception".
*/


void process(int arg, int& result, string& error)
{
    try{
        result= mystery(arg);
    }
    catch (invalid_argument  e)
    {
        error=e.what();
    }
    catch(range_error e)
    {
        error = e.what();
    }
    catch(logic_error e)
    {
        error="logic_error";
    }
    catch(runtime_error e)
    {
        error="runtime_error";
    }
    catch(...)
    {
        error="unknown exception";
    }


}

int mystery(int x)
{
   if (x == 0) throw invalid_argument("No zero please");
   if (x < 0) throw range_error("Let's not be negative");
   if (x == 99) throw x;
   if (x > 100) throw out_of_range("");
   if (x == 13) throw BadLuckError();
   if (x == 1) return x;
   if (x % 2 == 0) return mystery(x / 2);
   return mystery(3 * x + 1);
}



void test(int a, int r, string e)
{
   try
   {
      int result = -1;
      string error;
      process(a, result, error);
      if (error != "") cout << error << endl;
      else cout << result << endl;
      if (e != "") cout << "Expected: " << e << endl;
      else cout << "Expected: " << r << endl;
   }
   catch (...)
   {
      cout << "process threw exception" << endl;
      if (e != "") cout << "Expected: " << e << endl;
      else cout << "Expected: " << r << endl;
   }
}

int main()
{
   test(-1, -1, "Let's not be negative");
   test(0, -1, "No zero please");
   test(30, -1, "logic_error");
   test(32, 1, "");
   test(33, -1, "runtime_error");
   test(34, -1, "runtime_error");
   test(35, -1, "logic_error");
   test(13, -1, "runtime_error");
   test(96, 1, "");
   test(99, 1, "unknown exception");
}

