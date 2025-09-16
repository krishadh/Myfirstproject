#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
using namespace std;
class librarymanagement
{
protected:
    int bookid[20], eachbooknumber;
    string bookname[20];

public:
    librarymanagement(int a[20], int b, string c[20])
    {
        eachbooknumber = b;
        for (int i = 0; i < eachbooknumber; i++)
        {
            bookid[i] = a[i];
            bookname[i] = c[i];
        }
    }
};
class student : public librarymanagement
{
protected:
    int stdid;
    string stdname;

public:
    student(int a[20], int b, string c[20], int d, string f) : librarymanagement(a, b, c)
    {
        stdid = d;
        stdname = f;
    }
};
class date : public student
{
    int days, issuemonth[20], issuedate[20], returnmonth[20], returndate[20];

public:
    date(int a[20], int b, string c[20], int d, string f, int i[20], int j[20]) : student(a, b, c, d, f)
    {
        int daysinmonth[] = {31, 28, 31, 30, 31, 30, 31, 30, 31, 30, 31, 30};
        for (int m = 0; m < eachbooknumber; m++)
        {
            issuemonth[m] = i[m];
            issuedate[m] = j[m];
            returnmonth[m] = issuemonth[m];
            returndate[m] = issuedate[m] + 7;
            if (returndate[m] > daysinmonth[issuemonth[m] - 1])
            {
                returndate[m] -= daysinmonth[issuemonth[m] - 1];
                returnmonth[m]++;
                if (returnmonth[m] > 12)
                {
                    returnmonth[m] = 1;
                }
            }
        }
    }
    void display()
    {
        cout << "The student whose name is " << stdname << "having id " << stdid << " has taken: " << endl
             << eachbooknumber << " books" << endl;
        if (eachbooknumber > 1)
        {
            cout << "you have taken one book whose detail is:" << endl;
        }
        else
        {
            cout << "you have taken " << eachbooknumber << " books whose details are:" << endl;
        }
        for (int j = 0; j < eachbooknumber; j++)
        {
            cout << "Name: " << bookname[j] << endl;
            cout << "bookid: " << bookid[j] << endl;
            cout << "The issue date for the book " << bookname[j] << "is: " << issuemonth[j] << " / " << issuedate[j] << endl;
            cout << "You should have returned this book by 7 days that is date is:" << endl;
            cout << "the returndate for the book:" << bookname[j] << "is " << returnmonth[j] << " / " << returndate[j] << endl;
        }
    }
};
struct library
{
    int sid, bid[20], ebn, im[20], id[20], rm[20], rd[20];
    string sname, bname[20];
};
int main()
{
    library s[20];
    int a, i, j;
    cout << "small library management system for maximum 20 student so how many student tell me" << endl;
    cin >> a;
    cin.ignore();
    for (i = 0; i < a; i++)
    {
        cout << "Enter the name of the student " << endl;
       getline(cin, s[i].sname);
        cout << "Enter the id of the student" << endl;
        cin >> s[i].sid;
        cout << "enter how many  books " << endl;
        cin >> s[i].ebn;
        cin.ignore();
        for (j = 0; j < s[i].ebn; j++)
        {
            cout << " enter the name of your book " <<j+1<< endl;
           getline(cin, s[i].bname[j]);
            cout << "enter the id of your book "<<j+1 << endl;
            cin >> s[i].bid[j];
            cout << "Enter the issue month for " << s[i].bname[j]<<" book" << endl;
            cin >> s[i].im[j];
            cout << "enter the issue date for " << s[i].bname[j] <<" book"<< endl;
            cin >> s[i].id[j];
            cin.ignore();
        }
                date z(s[i].bid, s[i].ebn, s[i].bname, s[i].sid, s[i].sname, s[i].im, s[i].id);
                z.display();
            }
    return 0;
}