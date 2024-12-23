#include <iostream>
#include <windows.h>
#include <mysql.h>
#include <iomanip>
#include <sstream>
#include <ctype.h>
#include <string>

using namespace std;

void addRec(string ipAdd);
void delRec(string ipAdd);
void viewRec(string ipAdd);
void editRec(string ipAdd);
void viewSort(string ipAdd);
MYSQL* connect(string ipAdd);
int main()
{
    /*MYSQL* conn;
    conn = mysql_init(0);
    conn = mysql_real_connect(conn, "10.214.3.15", "admin", "admin", "test1", 0, NULL, 0);
    if(conn)
        cout<<"CONNECTED\n";
    else
        cout<<"ERROR";


    int qstate = 0;
    stringstream ss;

    string name = "rhuel gwapo";

    ss<<"INSERT INTO testt1(name) VALUES('"<< name <<"')";

    string query = ss.str();
    const char* q = query.c_str();
    qstate = mysql_query(conn, q);

    if(qstate == 0)
    {
        cout<<"RECORD INSERTED...";
    }
    else
        cout<<"FAILED to insert";
    */
    string ipAdd;
    cout<<"Enter Ip Address: ";
    cin>>ipAdd;

    int checkRun = 0;
    while(checkRun == 0)
    {
        int choice;

        cout<<"STUDENT MANAGEMENT SYSTEM"<<endl<<"[1]ADD"<<endl<<"[2]DELETE"<<endl<<"[3]EDIT"<<endl<<"[4]VIEW"<<endl<<"[5]EXIT"<<endl;

        cin>>choice;

        switch(choice)
        {
        case 1:
            addRec(ipAdd);
            system("pause");
            system("cls");
            break;
        case 2:
            delRec(ipAdd);
            system("pause");
            system("cls");
            break;
        case 3:
            editRec(ipAdd);
            system("pause");
            system("cls");
            break;
        case 4:
            viewRec(ipAdd);
            system("pause");
            system("cls");
            break;
        case 5:
            checkRun = 1;
            break;
        default:
            cout<<"Command not Available...\n";
            system("pause");
            system("cls");
            break;
        }
        cin.ignore();
    }
}
MYSQL* connect(string ipAdd)
{
    MYSQL* conn;
    conn = mysql_init(0);

    const char* q = ipAdd.c_str();
    conn = mysql_real_connect(conn, q, "admin", "admin", "dbms", 0, NULL, 0);

    return conn;
}
void addRec(string ipAdd)
{
    MYSQL* checkCon = connect(ipAdd);
    if(checkCon)
    {
        string studentID, surname, firstname, birthdate, address, gender;
        int qstate = 0;

        cout << "Enter Student Id(XX-X-XXXXX): ";
        cin >> studentID;

        cout << "Enter Surname: ";
        cin.ignore();
        getline(cin, surname);

        cout << "Enter Firstname: ";
        getline(cin, firstname);

        cout << "Enter Birthdate(MM-DD-YYYY): ";
        getline(cin, birthdate);

        cout << "Enter Address(Baranggay, Town, Province): ";
        getline(cin, address);

        cout << "Enter Gender(M/F): ";
        cin >> gender;

        if(studentID.length() > 10 || studentID.length() < 10)
        {
            cout<<"Record failed to insert. Invalid input on Student Id.\n";
            return;
        }
        else if(birthdate.length() > 10 || birthdate.length() < 10)
        {
            cout<<"Record failed to insert. Invalid input on Birthdate.\n";
            return;
        }
        else if(gender.length() > 1 || gender.length() < 1)
        {
            cout<<"Record failed to insert. Invalid input on Gender.\n";
            return;
        }

        stringstream ss;

        ss<<"INSERT INTO student(studentID, surname, firstname, birthdate, address, gender) VALUES('"<<studentID<<"','"
        <<surname<<"','"<<firstname<<"','"<<birthdate<<"','"<<address<<"','"<<gender<<"')";

        string query = ss.str();
        const char* q = query.c_str();
        qstate = mysql_query(checkCon, q);

        cout<<endl;

        if(qstate == 0)
            cout<<"RECORD INSERTED...\n"<<endl;
        else
            cout<<"FAILED TO INSERT...\n"<<endl;
    }
    else
        cout<<"FAILED TO ESTABLISH CONNECTION...\n";
}
void viewRec(string ipAdd)
{
    MYSQL* checkCon = connect(ipAdd);
    MYSQL_ROW row;
    MYSQL_RES* res;
    char ans;

    if(checkCon)
    {
        int qstate = mysql_query(checkCon, "SELECT studentID, firstname, surname, birthdate, gender, address FROM student");

        if(!qstate)
        {
            res = mysql_store_result(checkCon);

            while((row = mysql_fetch_row(res)))
                cout<<setw(10)<<left<<row[0]<<" | "<<setw(15)<<left<<row[1]<<" | "<<setw(15)<<left<<row[2]<<" |   "<<setw(10)<<left<<row[3]<<" |  "<<setw(2)<<left<<row[4]<<" | "<<setw(15)<<left<<row[5]<<endl;
        }
        cout<<"\nDo you wish to sort data? (y/n): ";
        cin>>ans;

        if(ans == 'y')
        {
            system("cls");
            viewSort(ipAdd);
        }
    }
}
void delRec(string ipAdd)
{
    MYSQL* checkCon = connect(ipAdd);

    if(checkCon)
    {
        viewSort(ipAdd);
        string studentID;

        cout<<"\n Enter StudentId to delete: ";
        cin>>studentID;

        stringstream ss;

        ss<<"DELETE FROM student WHERE studentID = '"+ studentID +"'";
        string query = ss.str();
        const char* q = query.c_str();

        int qstate = mysql_query(checkCon,q);

        if(qstate == 0)
            cout<<"ROW DELETED...\n";
        else
            cout<<"ROW FAILED TO DELETE...\n";
    }
    else
        cout<<"FAILED TO ESTABLISH CONNECTION...\n";
}
void editRec(string ipAdd)
{
    MYSQL *checkCon = connect(ipAdd);
    if(checkCon)
    {
        viewRec(ipAdd);

        string studentIDTE, studentID, surname, firstname, birthdate, address, gender;
        int qstate = 0;

        cout<<"Enter Record to Edit: ";
        cin>>studentIDTE;

        cout << "Enter Student Id(XX-XX-XXXXX): ";
        cin >> studentID;

        cout << "Enter Surname: ";
        cin.ignore();
        getline(cin, surname);

        cout << "Enter Firstname: ";
        getline(cin, firstname);

        cout << "Enter Birthdate: ";
        getline(cin, birthdate);

        cout << "Enter Address: ";
        getline(cin, address);

        cout << "Enter Gender(M/F): ";
        cin >> gender;

        stringstream ss;

        ss << "UPDATE student SET studentID = '" << studentID << "', surname = '" << surname << "', firstname = '" << firstname << "', birthdate = '" << birthdate << "', address = '" << address << "', gender = '" << gender << "' WHERE studentID = '" << studentIDTE << "'";

        string query = ss.str();
        const char* q = query.c_str();
        qstate = mysql_query(checkCon, q);

        cout<<endl;

        if(qstate == 0)
            cout<<"CHANGES MADE...\n"<<endl;
        else
            cout<<"FAILED TO CHANGE DATA...\n"<<endl;
    }
    else
        cout<<"FAILED TO ESTABLISH DATA...\n";
}
void viewSort(string ipAdd)
{
    MYSQL *checkCon = connect(ipAdd);
    MYSQL_ROW row;
    MYSQL_RES* res;

    if(checkCon)
    {
        int qstate = mysql_query(checkCon, "SELECT studentID, firstname, surname, birthdate, gender, address FROM student ORDER BY surname");

        if(!qstate)
        {
            res = mysql_store_result(checkCon);

            while((row = mysql_fetch_row(res)))
                cout<<setw(10)<<left<<row[0]<<" | "<<setw(15)<<left<<row[1]<<" | "<<setw(15)<<left<<row[2]<<" |   "<<setw(10)<<left<<row[3]<<" |  "<<setw(2)<<left<<row[4]<<" | "<<setw(15)<<left<<row[5]<<endl;
        }
    }
    else
        cout<<"FAILED TO ESTABLISH DATA...\n";
}
