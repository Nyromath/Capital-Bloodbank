#include <iostream>
#include <fstream>
#include <sstream>
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
    system("CLS");
    cout << "\n\t\t\t\t\tABOUT US\n";
    cout << "********************************************************************************************\n\n";
    cout << "\tCapital Blood Bank is a New Zealand based bloodbank with locations across the north and south island.\n";
    cout << "\tas a blood bank we have been running for over 25 years obtaining over 100,000 liters of blood\n";
    cout << "\tthe blood is sent to all local centers to use for those who require it\n";
    cout << "\tWe ask that those who are able to donate blood to donate it as many people in New Zealand need blood\n";
    cout << "\tIf you are interested in donating blood or are in need of blood please register and contact us for more info\n";
    cout << "\tIf you are unsure if you are eligable to donate blood please call us or email us to book a time at one of\n";
    cout << "\tour locations for an interview.\n";
    cout << "\tAll of our contact information can be found on the contact info tab found in the main menu.\n";
    cout << "********************************************************************************************\n\n";
    system("PAUSE");
    system("CLS");
}
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

void recipient_landing_screen() {
    int choice;
    bool flag = 0;

    while (flag == 0) {
        system("CLS");
        cout << "\n\t\t\t\t\tWELCOME RECIPIENT\n";
        cout << "************************************************************************************************************\n\n";

        cout << "1. Find potential donors by blood type \n";
        cout << "2. Find potential donors by location\n";
        cout << "3. Find donor contact info\n";
        cout << "4. log out\n";
        cout << "Enter option Number:\n";
        cin >> choice;

        switch (choice) {
        case 1:


            break;
        case 2:

            break;

        case 3:
            break;
        case 4:
            flag = 1;
            system("CLS");
            break;
        default:
            cout << "Please enter a valid menu option.\n";
            system("PAUSE");
            system("CLS");
        }

    }


}

void donor_benefits() {



    system("CLS");
    cout << "\n\t\t\t\t\tBENEFITS OF DONATING BLOOD \n";
    cout << "********************************************************************************************\n\n";
    cout << "\tThere are many benefits to donating blood here are a few:\n";
    cout << "\t One blood donation can save up to 3 lives.\n";
    cout << "\tBlood donation not only makes the receiver�s life good but also helps the donor to maintain good health.\n";
    cout << "\tHealth benefits of blood donation include reduced risk of hemochromatosis. \n";
    cout << "\tBlood donation helps in lowering the risk of cancer. By donating blood the iron stores in the body are\n";
    cout << "\tmaintained at healthy levels.\n";
    cout << "\tA reduction in the iron level in the body is linked with low cancer risk. \n";


    cout << "********************************************************************************************\n\n";
    system("PAUSE");
    system("CLS");


}

void donor_how_i_donate() {


    system("CLS");
    cout << "\n\t\t\t\t\tHOW DO I DONATE BLOOD? \n";
    cout << "********************************************************************************************\n\n";
    cout << "\tThere are many ways you can donate blood.\n";
    cout << "\tThe easiest way to donate is by booking a donation by selecting the book a donation tab\n";
    cout << "\ton the donator menu.\n";
    cout << "\tOtherwise you can find our conatct info menu on the home page by logging out\n";
    cout << "\tTo book a time to donate your blood.\n";
    cout << "\tTo be eligable to donate blood you will be required to awnser some breief yes/no questions to ensure that\n";
    cout << "\tThose receiving your blood will be safe from any diseases and viruses\n";
    cout << "********************************************************************************************\n\n";
    system("PAUSE");
    system("CLS");



}

void donor_landing_screen() {
    int choice;
    bool flag = 0;

    while (flag == 0) {
        system("CLS");
        cout << "\n\t\t\t\t\tWELCOME DONATOR  \n";
        cout << "************************************************************************************************************\n\n";

        cout << "1. How do I donate blood?\n";
        cout << "2. What are the benefits of donating blood?\n";
        cout << "3. Manage my information\n";
        cout << "4. Book a donation\n";
        cout << "5. log out\n";
        cout << "Enter option Number:\n";
        cin >> choice;

        switch (choice) {
        case 1:
            donor_how_i_donate();

            break;
        case 2:
            donor_benefits();
            break;

        case 3:
            break;
        case 4:
            break;
        case 5:
            flag = 1;
            system("CLS");
            break;
        default:
            cout << "Please enter a valid menu option.\n";
            system("PAUSE");
            system("CLS");
        }

    }


}

void donor_registration() {
    system("CLS");
    //declaring donor struct to store details, and temp values for validating
    struct Donor reg;
    string tempPW1, tempPW2, tempGender;
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
        if (tempGender == "Male" || tempGender == "male" || tempGender == "m") { //allowing multiple casing versions
            reg.gender = "Male";
            flag = 0;
        }
        else if (tempGender == "Female" || tempGender == "female" || tempGender == "f") { //allowing multiple casing versions
            reg.gender = "Female";
            flag = 0;
        }
        else if (tempGender == "Other" || tempGender == "other" || tempGender == "o") { //allowing multiple casing versions
            reg.gender = "Other";
            flag = 0;
        }
        else {
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

    //Registering user data to csv file
    ofstream regToFile;
    regToFile.open ("donors.csv", ios::app);

    regToFile << reg.name << ",";
    regToFile << reg.password << ",";
    regToFile << reg.email << ",";
    regToFile << reg.bloodType << ",";
    regToFile << reg.streetAddress << ",";
    regToFile << reg.suburb << ",";
    regToFile << reg.city << ",";
    regToFile << reg.ethnicity << ",";
    regToFile << reg.gender << ",";
    regToFile << reg.contactNumber << ",";
    regToFile << reg.dobDay << ",";
    regToFile << reg.dobMonth << ",";
    regToFile << reg.dobYear << endl;

    regToFile.close();

    cout << "\nSuccessfully registered " << reg.name << " as Donor.\n\n";

    system("PAUSE");
    system("CLS");
}

void recipient_registration() {
    system("CLS");
    //declaring struct to register recipient, and temp values for validation
    struct Recipient reg;
    string tempPW1, tempPW2, tempGender;
    bool flag = 0;

    //taking user input for recipient
    cout << "\tREGISTER AS RECIPIENT\n";
    cout << "*************************************\n";
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
    cout << "Enter Registration Number:\t";
    cin >> reg.registrationNumber;

    //Registering recipient data to file
    ofstream regToFile;
    regToFile.open("recipients.csv", ios::app);

    regToFile << reg.name << ",";
    regToFile << reg.password << ",";
    regToFile << reg.streetAddress << ",";
    regToFile << reg.suburb << ",";
    regToFile << reg.city << ",";
    regToFile << reg.email << ",";
    regToFile << reg.contactNumber << ",";
    regToFile << reg.registrationNumber << endl;

    regToFile.close();

    cout << "\nSuccessfully registered " << reg.name << " as Recipient.\n\n";

    system("PAUSE");
    system("CLS");
}

int main()
{
    //reading files to vectors
    vector<Donor> donors;
    vector<Recipient> recipients;
    ifstream myFile;
    myFile.open("donors.csv", ios::in);

    myFile.close();
    myFile.open("recipients.csv", ios::in);

    myFile.close();

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
            intro_function();
            break;
        case 2:
            display_contact_info();
            break;
        case 3:
            donor_registration();
            break;
        case 4:
            donor_landing_screen();
            break;
        case 5:
            recipient_registration();
            break;
        case 6:
            recipient_landing_screen();
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