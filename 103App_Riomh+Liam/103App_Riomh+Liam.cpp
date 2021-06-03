#include <iostream>
#include <fstream>
#include <cmath>
#include <ctime>
#include <string>
#include <stdlib.h>
using namespace std;

//INFO FUNCTION
//****************
//hello this is a test-liam
//****************

//CONTACT FUNCTION
//****************
void display_contact_info()
{
    system("CLS");
    cout << "\n\t\t\t\t\tCONTACT INFO\n";
    cout << "********************************************************************************************\n\n";
    cout << "\tPhone:\t\t0800 448 325\n";
    cout << "\tFacebook:\tfacebook.com/NewZealandBloodService\n";
    cout << "\tYouTube:\tyoutube.com/user/savelivesgiveblood\n";
    cout << "\tInstagram:\tinstagram.com/nzbloodservice\n";
    cout << "\tLinkedIn:\tlinkedin.com/company/new-zealand-blood-service\n\n";
    cout << "********************************************************************************************\n\n";
    system("PAUSE");
    system("CLS");
}
//****************

int main()
{
    //INTRO MENU
    //****************
    bool flag = 0;
    int choice;
    while (flag == 0) {
        cout << "\n\t\t\t\t\tWELCOME TO CAPITAL BLOODBANK\n";
        cout << "************************************************************************************************************\n\n";

        cout << "1. About Us\n";
        cout << "2. Contact Info\n";
        cout << "3. Register as Donor\n";
        cout << "4. Login as Donor\n";
        cout << "5. Register as Recipient\n";
        cout << "6. Login as Recipient\n";
        cout << "7. Login as Administrator\n";
        cout << "8. Exit\n\n";
        cout << "Enter Option Number:\t";
        cin >> choice;

        switch (choice) {
        case 1:
            break;
        case 2:
            display_contact_info();
            break;
        case 3:
            break;
        case 4:
            break;
        case 5:
            break;
        case 6:
            break;
        case 7:
            break;
        case 8:
            cout << "Thank you for using Capital Bloodbank!\n";
            return 0;
            break;
        default:
            cout << "Please enter a valid menu option.\n";
            system("PAUSE");
            system("CLS");
        }
    }
    //****************
}