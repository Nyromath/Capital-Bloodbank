#include <iostream>
#include <fstream>
#include <cmath>
#include <ctime>
#include <string>
#include <stdlib.h>
#include <vector>
using namespace std;

struct Donor {
    string name, password, email, bloodType, streetAddress, suburb, city, ethnicity, gender;
    int contactNumber, dobDay, dobMonth, dobYear;
    //vector<string> underlyingConditions; UNDERLYING CONDITIONS TO BE WORKED ON

    Donor(string s = " ", int i = 0) {
        name = s;
        password = s;
        email = s;
        bloodType = s;
        streetAddress = s;
        suburb = s;
        city = s;
        ethnicity = s;
        gender = s;
        contactNumber = i;
        dobDay = i;
        dobMonth = i;
        dobYear = i;
    }
};

struct Recipient {
    string name, password, streetAddress, suburb, city, email;
    int contactNumber, registrationNumber;

    Recipient(string s = " ", int i = 0) {
        name = s;
        password = s;
        streetAddress = s;
        suburb = s;
        city = s;
        email = s;
        contactNumber = i;
        registrationNumber = i;
    }
};

struct Admin {
    string email, password;

    Admin(string s = " ") {
        email = s;
        password = s;
    }
};

struct Booking {
    int day, time;
    bool booked;

    Booking(int i = 0, bool b = 0) {
        day = i;
        time = i;
        booked = b;
    }
};

//INFO FUNCTION
//****************
void intro_function() {
    cout << "\nWho are we?" << endl;
    cout << "Capital Blood Bank is a New Zealand based bloodbank with locations across the north and south island.";
    cout << "As a bloodbank we ask that those who are able to donate blood to donate it as many peole in New Zealand could use that blood for opperations and other blood repuired practices";
    cout << "If you are interested in donating blood or are in need of blood please register and visit the contact tab for furthur information";

}
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

void donor_registration() {
    system("CLS");
    //declaring donor struct to store details, and temp values for validating
    struct Donor reg;
    string tempPW1, tempPW2, condition;
    char tempGender, conditionCheck;
    bool flag = 0;

    //taking user input for donor
    cout << "\tREGISTER AS DONOR\n";
    cout << "*********************************\n";
    cin.ignore();
    cout << "Enter Full Name:\t";
    getline(cin, reg.name);
    cout << "Enter Email:\t\t";
    cin >> reg.email;
    //do while loop to confirm user's password
    do {
        cin.ignore();
        cout << "Enter Password:\t\t";
        getline(cin, tempPW1);
        cout << "Confirm Password:\t";
        getline(cin, tempPW2);

        if (tempPW2 == tempPW1) {
            reg.password = tempPW1;
            flag = 0;
        }
        else {
            cout << "Password does not match. Please enter password again.\n";
            flag = 1;
        }
    } while (flag == 1);

    cout << "Enter Contact Number:\t";
    cin >> reg.contactNumber;
    cin.ignore();
    cout << "Enter Street Address:\t";
    getline(cin, reg.streetAddress);
    cout << "Enter Suburb:\t\t";
    getline(cin, reg.suburb);
    cout << "Enter City:\t\t";
    getline(cin, reg.city);
    cout << "\nEnter Date of Birth (dd mm yyyy):\n"; //DOB does not yet check for valid date of birth. Will not prevent someone born on 32/13/3021, for example.
    cout << "day:\t";
    cin >> reg.dobDay;
    cout << "month:\t";
    cin >> reg.dobMonth;
    cout << "year:\t";
    cin >> reg.dobYear;
    cin.ignore();
    cout << "Enter Ethnicity:\t";
    getline(cin, reg.ethnicity);

    //checking for valid gender
    do {
        cout << "Enter Gender (Male/Female/Other):\t";
        cin >> tempGender;
        tempGender = tolower(tempGender);
        switch (tempGender) {
        case 'm':
            reg.gender = "Male";
            flag = 0;
            break;
        case 'f':
            reg.gender = "Female";
            flag = 0;
            break;
        case 'o':
            reg.gender = "Other";
            flag = 0;
            break;
        default:
            cout << "Please enter valid gender.\n";
            flag = 1;
        }
    } while (flag == 1);

    cout << "Enter Blood Type:\t"; //Blood type does not yet check for valid blood type. Will not prevent someone having the blood type "Banana", for example.
    cin >> reg.bloodType;

    //UNDERLYING CONDITIONS TO BE WORKED ON
    /*do {
        cout << "Do you have any underlying conditions? (y/n):\t";
        cin >> conditionCheck;
        conditionCheck = tolower(conditionCheck);

        if (conditionCheck == 'y') {
            cout << "Enter Condition:\t";
            getline(cin, condition);
            reg.underlyingConditions.push_back(condition);

        }
        else if (conditionCheck == 'n') {
            flag = 0;
        }
        else {
            cout << "Please enter y or n\n";
            flag = 1;
        }
    } while (flag == 1);*/


    system("PAUSE");
    system("CLS");
}

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
            donor_registration();
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