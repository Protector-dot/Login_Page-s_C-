#include <iostream>
#include <istream>
#include <fstream>
#include <stdlib.h>
#include <string.h>
using namespace std;

//try to write some function's for login and logout
void login();
void registr();
void forgot();

main()
{
    int choice;
    cout << "******************** LOGIN *********************" << endl;
    cout << "1.Login" << endl;
    cout << "2.Register" << endl;
    cout << "3.Forgot credentials" << endl;
    cout << "Enter your choice:";
    cin >> choice;

    switch (choice)
    {
    case 1:
        login();
        break;
    case 2:
        registr();
        break;
    case 3:
        forgot();
        break;
    case 4:
        cout << "Thanks for using the login page" << endl;
        break;
    default:
        cout << "Sorry, wrong choice selected" << endl;
        /*after this again call main() function.
            when my choice is wrong then again and again main function calling
            therefore here using main() function.
            */
        main();
    }
}

void registr()
{
    string reg_user, reg_pass;
    system("cls"); //for clear the screen
    cout << "Enter the username:";
    cin >> reg_user;
    cout << "Enter the password:";
    cin >> reg_pass;

    ofstream reg("database.txt", ios::app);
    reg << reg_user << ' ' << reg_pass << endl;
    system("cls");
    cout << "Registration is successfull" << endl;
    main();
}
void login()
{
    int exist;
    string user, pass, u, p;
    system("cls");
    cout << "Enter the username:";
    cin >> user;
    cout << "Enter the password:";
    cin >> pass;

    ifstream input("database.txt");
    while (input >> u >> p)
    {
        if (u == user && p == pass)
        {
            exist = 1;
        }
    }
    input.close();
    if (exist == 1)
    {
        cout << "Hello" << user << "\nWe are glad that you are here\n";
        cin.get();
        cin.get();
        main();
    }
    else
    {
        cout << "Sorry,Login Error!!!";
        cin.get();
        cin.get();
        main();
    }
}
void forgot()
{
    int ch;
    system("cls");
    cout << "1.Search your account by username" << endl;
    cout << "2.Search your account by password" << endl;
    cout << "3.Mainmenu" << endl;
    cout << "Enter your choice:" << endl;
    cin >> ch;

    switch (ch)
    {
    case 1:
    {
        int ex = 0;
        string searchuser, su, sp;
        cout << "Enter your remembered username:";
        cin >> searchuser;

        ifstream searchu("database.txt");
        while (searchu >> su >> sp)
        {
            if (su == searchuser)
            {
                ex = 1;
                break;
            }
        }
        searchu.close();
        if (ex == 1)
        {
            cout << "Hurray ! account found !" << endl;
            cout << "Your password is" << sp;
            cin.get();
            cin.get();
            main();
        }
        else
        {
            cout << "Sorry, your account is not found" << endl;
            cin.get();
            cin.get();
            main();
        }
        break;
    }

    case 2:
    {
        int exi = 0;
        string searchpass, su2, sp2;
        cout << "Enter the remembered password:";
        cin >> searchpass;

        ifstream searchp("database.txt");
        while (searchp >> su2 >> sp2)
        {
            if (sp2 == searchpass)
            {
                exi = 1;
            }
        }
        searchp.close();
        if (exi == 1)
        {
            cout << "Hurray ! the account found" << endl;
            cout << "YOUR USERNAME IS:" << su2;
            cout << "YOUR PASSWORD IS:" << sp2;
            cin.get();
            cin.get();
            main();
        }
        break;
    }
    case 3:
    {
        main();
        break;
    }
    default:
    {
        cout << "You have given a wrong choice. press a key to try again.";
        cin.get();
        cin.get();
        forgot();
    }
    }
}