//Program by Shivani Mangal
#include <iostream>
#include "Calculator.h"

int main() {
    Calculator cal;
    char ch,c,equals_operator;
    cout<<"Expression? ";
    cin>>ch;
    while(ch!='.')
    {
        cin.putback(ch);
        try
        {
            cout<<cal.expression()<<endl;
            if(cin.peek() != '=')
            {
                cout<<"***** Unexpected "<<(char)c<<endl;
            }
            while(1)
            {

                if(cin.peek() == '=')
                {
                    break;
                }
                cin>>c;
            }
        }
        catch(exception &e)
        {
            cout <<e.what()<<endl;
        }
        cin>>equals_operator;
        cout<<"\nExpression? ";
        cin>>ch;
    }
    cout<<endl<<"Done!";



    return 0;
}

