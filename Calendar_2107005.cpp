#include <bits/stdc++.h>
#include <conio.h>
#include <windows.h>
using namespace std;

//functions
//startPage- to start the program
//startDay- to find the first day of any year (here we used a well established formula)
//start- all the main task was performed here


void startPage() {
    cout << "\n\n\n\n" << endl;
    cout << "\t\tCalendar of any year" << endl;
    cout << "\nInput a valid year and month and get the calendar instant" << endl;
    cout << "Press any key to start";
}

//to find the start date of a year
int startDay(int y) {
    int s_date = (((y-1)*365) + ((y-1)/4) - ((y-1)/100) + ((y-1)/400) + 1) % 7;
    return s_date;
}

void start() {
   startPage();
   getch();

   int y, m, s_date, w = 0;

    label1 : {
        system("cls");
        cout << "\n\n\n\t\tEnter year : ";
        cin>>y;

        cout << "\t\tEnter month : ";
        cin >> m;
        if (cin.fail() || m>12 || m<=0 || y<0) {
                cin.clear(); 
                cin.ignore(512, '\n');
                goto label1;
            }

        label2 : {
        system("cls");

        //array used to store the names of the twelve months
        array <string, 12> month = {"JANUARY", "FEBRUARY", "MARCH", "APRIL", "MAY", "JUNE", "JULY",
        "AUGUST", "SEPTEMBER", "OCTOBER", "NOVEMBER", "DECEMBER"};

        //array to store days per every month individually
        array <int, 12> days_in_a_month = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

        if(y%400 == 0 || y%4 == 0 && y%100 != 0) {
            auto it = days_in_a_month.begin(); //begin() function is used here
            *(it+1) = 29; 
        }

        s_date = startDay(y);

        //printing the calendar
        for(int i=0; i<12; i++) {
            for(w=0; w<s_date; w++) {
                cout << " ";
            }

            if((m-1) == i) {
		        cout<<"\n\n\t\t\t     Monthly Calendar";
		        cout<<"\n\n\t_______________________" << month.at(i) << ", "<< y << "_______________________";
		        cout<<"\n\n\t    SUN    MON    TUE    WED    THR    FRI    SAT\n\t";

                for(w=0; w<s_date; w++) {
                    cout << "       ";
                }

                for(int j=1; j<=days_in_a_month.at(i); j++) {
                    if(j < 10) {
                        cout << "      " << j;
                    }
                    else {
				        cout<<"     " << j;
			        }
                    if(++w > 6) {
                     cout << "\n\t";
                        w = 0;
                    }
                    s_date = w;
                }
            }
            for(int k=0; k<days_in_a_month[i]; k++) {
                if(++w > 6) {
                w = 0;
                }
                s_date = w;
            }
        }
    }
    cout << "\n\n1. Next Month" << endl <<
        "2. Previous Month" << endl <<
        "3. Next Year" << endl <<
        "4. Previous Year" << endl <<
        "5. Go Back" << endl <<
        "0. Exit" << endl;
        cout << "Enter your choice : ";
        int decision;
        cin >> decision;
        if (cin.fail()) {
                cin.clear(); 
                cin.ignore(512, '\n');
                goto label2;
            }

        switch(decision) {
            case 1 :
                ++m;
                if(m > 12) {
                    m = 1;
                    ++y;
                }
                goto label2;
                break;

            case 2 :
                --m;
                if(m < 1) {
                    m = 12;
                    --y;
                }
                goto label2;
                break;

            case 3 :
                ++y;
                goto label2;
                break;

            case 4 :
                --y;
                goto label2;
                break;

            case 5 :
                goto label1;
                break;

            case 0 :
                exit(0);
            
            default :
                goto label2;
        }

    }
}

int main() {
    //system("Color 80");
    system("cls");
    start();

    getch();
    return 0;
}