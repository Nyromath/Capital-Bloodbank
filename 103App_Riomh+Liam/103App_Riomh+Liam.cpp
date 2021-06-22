#include <iostream>
#include <fstream>
#include <sstream>
#include <cmath>
#include <ctime>
#include <string>
#include <stdlib.h>
#include <vector>
#include <tuple>
using namespace std;

struct Donor {
    string name, password, email, bloodType, streetAddress, suburb, city, ethnicity, gender;
    int contactNumber, dobDay, dobMonth, dobYear, numOfConditions;
    vector<string> underlyingConditions;

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
    string bookedBy;

    Booking(int i = 0, bool b = 0) {
        day = i;
        time = i;
        booked = b;
    }
};

struct OmniStruct {
    vector<Donor> d;
    vector<Recipient> r;
    vector<Admin> a;
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

string update_detail_string(string attribute) { //small function to update string variables in donor and recipient screens, so as to avoid repeat code
    string s;
    //cin.ignore();
    cout << "\nEnter New " << attribute << ":\t";
    getline(cin, s);

    return s;
}

int update_detail_int(string attribute) { //small function to update int variables in donor and recipient screens, so as to avoid repeat code
    int i;
    cout << "\nEnter New " << attribute << ":\t";
    cin >> i;

    return i;
}

//****************
void donors_contact_info() {
    vector<Donor> donors;
    vector<Recipient> recipients;
    ifstream myFile;
    Donor transactionD;
    Recipient transactionR;
    string line;
    int flag = 0;

    //opening Donors
    int linenum = 0;
    myFile.open("donors.csv", ios::in);

    //Loop to take donor input from file
    while (getline(myFile, line)) {
        istringstream linestream(line);
        string item;

        //String variables
        getline(linestream, item, ',');
        transactionD.name = item;
        getline(linestream, item, ',');
        transactionD.password = item;
        getline(linestream, item, ',');
        transactionD.email = item;
        getline(linestream, item, ',');
        transactionD.bloodType = item;
        getline(linestream, item, ',');
        transactionD.streetAddress = item;
        getline(linestream, item, ',');
        transactionD.suburb = item;
        getline(linestream, item, ',');
        transactionD.city = item;
        getline(linestream, item, ',');
        transactionD.ethnicity = item;
        getline(linestream, item, ',');
        transactionD.gender = item;



        //Int Variables
        getline(linestream, item, ',');
        stringstream ss(item);
        ss >> transactionD.contactNumber;

        getline(linestream, item, ',');
        stringstream day(item);
        day >> transactionD.dobDay;

        getline(linestream, item, ',');
        stringstream month(item);
        month >> transactionD.dobMonth;

        getline(linestream, item, ',');
        stringstream year(item);
        year >> transactionD.dobYear;

        //Add structure to vector 'donors'.
        donors.push_back(transactionD);
        linenum++;
    }

    myFile.close();


    system("CLS");
    string searchname;
    cin.ignore();
    cout << "\nENTER DONOR NAME TO FIND CONTACT INFO" << endl;
    cout << "******************************************************" << endl;
    getline(cin, searchname);



    for (auto element : donors) {
        if (element.name == searchname) {
            system("CLS");
            cout << "-----------------------------------------------------" << endl;
            cout << "\t\t" << element.name << endl;
            cout << "-----------------------------------------------------" << endl;
            cout << "\nSTREET ADDRESS: " << element.streetAddress << ", " << element.suburb << ", " << element.city << endl;
            cout << "\nEMAIL: " << element.email << endl;
            cout << "\nCONTACT NUMBER: " << element.contactNumber << endl;
            cout << "\nBLOOD TYPE: " << element.bloodType << endl;
            flag = 1;
            system("PAUSE");
        }

    }

    if (flag == 0) {
        system("CLS");
        cout << "THERE ARE NO DONORS FOUND WITH THAT NAME" << endl;
        system("PAUSE");


    }

    system("CLS");

}



void donors_by_blood() {

    vector<Donor> donors;
    vector<Recipient> recipients;
    ifstream myFile;
    Donor transactionD;
    Recipient transactionR;
    string line;
    int flag = 0;

    //opening Donors
    int linenum = 0;
    myFile.open("donors.csv", ios::in);

    //Loop to take donor input from file
    while (getline(myFile, line)) {
        istringstream linestream(line);
        string item;

        //String variables
        getline(linestream, item, ',');
        transactionD.name = item;
        getline(linestream, item, ',');
        transactionD.password = item;
        getline(linestream, item, ',');
        transactionD.email = item;
        getline(linestream, item, ',');
        transactionD.bloodType = item;
        getline(linestream, item, ',');
        transactionD.streetAddress = item;
        getline(linestream, item, ',');
        transactionD.suburb = item;
        getline(linestream, item, ',');
        transactionD.city = item;
        getline(linestream, item, ',');
        transactionD.ethnicity = item;
        getline(linestream, item, ',');
        transactionD.gender = item;



        //Int Variables
        getline(linestream, item, ',');
        stringstream ss(item);
        ss >> transactionD.contactNumber;

        getline(linestream, item, ',');
        stringstream day(item);
        day >> transactionD.dobDay;

        getline(linestream, item, ',');
        stringstream month(item);
        month >> transactionD.dobMonth;

        getline(linestream, item, ',');
        stringstream year(item);
        year >> transactionD.dobYear;

        //Add structure to vector 'donors'.
        donors.push_back(transactionD);
        linenum++;
    }

    myFile.close();


    system("CLS");
    string searchblood;
    cin.ignore();
    cout << "\nENTER BLOOD TYPE TO SEARCH FOR DONORS" << endl;
    cout << "******************************************************" << endl;
    getline(cin, searchblood);



    for (auto element : donors) {
        if (element.bloodType == searchblood) {
            cout << "-----------------------------------------------------" << endl;
            cout << "\t\t" << element.name << endl;
            cout << "-----------------------------------------------------" << endl;

            cout << "\nSTREET ADDRESS: " << element.streetAddress << ", " << element.suburb << ", " << element.city << endl;
            cout << "\nEMAIL: " << element.email << endl;
            cout << "\nCONTACT NUMBER: " << element.contactNumber << endl;
            cout << "\nBLOOD TYPE: " << element.bloodType << endl;
            flag = 1;
            system("PAUSE");
        }
    }

    if (flag == 0) {
        system("CLS");
        cout << "THERE ARE NO DONORS WITH BLOOD TYPE: " << searchblood << endl;
        system("PAUSE");
    }



    system("CLS");

}











void donors_by_location() {


    vector<Donor> donors;
    vector<Recipient> recipients;
    ifstream myFile;
    Donor transactionD;
    Recipient transactionR;
    string line;
    int flag = 0;

    //opening Donors
    int linenum = 0;
    myFile.open("donors.csv", ios::in);

    //Loop to take donor input from file
    while (getline(myFile, line)) {
        istringstream linestream(line);
        string item;

        //String variables
        getline(linestream, item, ',');
        transactionD.name = item;
        getline(linestream, item, ',');
        transactionD.password = item;
        getline(linestream, item, ',');
        transactionD.email = item;
        getline(linestream, item, ',');
        transactionD.bloodType = item;
        getline(linestream, item, ',');
        transactionD.streetAddress = item;
        getline(linestream, item, ',');
        transactionD.suburb = item;
        getline(linestream, item, ',');
        transactionD.city = item;
        getline(linestream, item, ',');
        transactionD.ethnicity = item;
        getline(linestream, item, ',');
        transactionD.gender = item;



        //Int Variables
        getline(linestream, item, ',');
        stringstream ss(item);
        ss >> transactionD.contactNumber;

        getline(linestream, item, ',');
        stringstream day(item);
        day >> transactionD.dobDay;

        getline(linestream, item, ',');
        stringstream month(item);
        month >> transactionD.dobMonth;

        getline(linestream, item, ',');
        stringstream year(item);
        year >> transactionD.dobYear;

        //Add structure to vector 'donors'.
        donors.push_back(transactionD);
        linenum++;
    }

    myFile.close();


    system("CLS");
    string searchcity;
    cin.ignore();
    cout << "\nENTER CITY NAME TO SEARCH FOR DONORS" << endl;
    cout << "******************************************************" << endl;
    getline(cin, searchcity);



    for (auto element : donors) {
        if (element.city == searchcity) {
            cout << "-----------------------------------------------------" << endl;
            cout << "\t\t" << element.name << endl;
            cout << "-----------------------------------------------------" << endl;
            cout << "\nSTREET ADDRESS: " << element.streetAddress << ", " << element.suburb << element.city << endl;
            cout << "\nEMAIL: " << element.email << endl;
            cout << "\nCONTACT NUMBER: " << element.contactNumber << endl;
            cout << "\nBLOOD TYPE: " << element.bloodType << endl;
            flag = 1;
            system("PAUSE");


        }
    }

    if (flag == 0) {

        cout << "THERE ARE NO DONORS THAT LIVE IN: " << searchcity << endl;
        system("PAUSE");

    }



    system("CLS");

}


















vector<Recipient> recipient_manage_info(vector<Recipient> recip, int p) {
    int n = 0, choice;
    bool flag = 0;

    //display current info and menu
    while (flag == 0) {
        system("CLS");
        cout << "\nYour Current Info:\n\n";
        cout << "1.\tName:\t\t" << recip[p].name << endl;
        cout << "2.\tEmail:\t\t" << recip[p].email << endl;
        cout << "3.\tPassword:\t" << recip[p].password << endl;
        cout << "4.\tAddress:\t" << recip[p].streetAddress << ", " << recip[p].suburb << ", " << recip[p].city << endl;
        cout << "5.\tContact Number:\t" << recip[p].contactNumber << endl;
        cout << "6.\tExit\n\n";

        //taking user input for editing info
        cout << "Enter Menu Option to Edit Information:\t";
        cin >> choice;

        switch (choice) {
        case 1:
            cin.ignore();
            recip[p].name = update_detail_string("Name");
            break;
        case 2:
            cin.ignore();
            recip[p].email = update_detail_string("Email");
            break;
        case 3:
            cin.ignore();
            recip[p].password = update_detail_string("Password");
            break;
        case 4:
            cin.ignore();
            recip[p].streetAddress = update_detail_string("Street Address");
            recip[p].suburb = update_detail_string("Suburb");
            recip[p].city = update_detail_string("City");
            break;
        case 5:
            recip[p].contactNumber = update_detail_int("Contact Number");
            break;
        case 6:
            flag = 1;
            break;
        default:
            cout << "\nPlease enter a valid menu option.\n\n";
            system("PAUSE");
        }
    }

    //writing recipients back into file
    ofstream myFile;
    myFile.open("recipients.csv", ios::out);

    for (auto element : recip) {
        myFile << element.name << ',';
        myFile << element.password << ',';
        myFile << element.streetAddress << ',';
        myFile << element.suburb << ',';
        myFile << element.city << ',';
        myFile << element.email << ',';
        myFile << element.contactNumber << ',';
        myFile << element.registrationNumber << endl;
    }

    myFile.close();

    return recip;
}

vector<Recipient> recipient_landing_screen(vector<Recipient> recip, int p) {
    int choice;
    bool flag = 0;

    while (flag == 0) {
        system("CLS");
        cout << "\n\t\t\t\t\tWELCOME RECIPIENT\n";
        cout << "************************************************************************************************************\n\n";

        cout << "1. Find potential donors by blood type \n";
        cout << "2. Find potential donors by city\n";
        cout << "3. Find donor contact info\n";
        cout << "4. Manage my Information\n";
        cout << "5. log out\n";
        cout << "Enter option Number:\n";
        cin >> choice;

        switch (choice) {
        case 1:

            donors_by_blood();

            break;
        case 2:
            donors_by_location();
            break;

        case 3:
            donors_contact_info();
            break;
        case 4:
            recip = recipient_manage_info(recip, p);
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

    return recip;
}

void donor_benefits() {



    system("CLS");
    cout << "\n\t\t\t\t\tBENEFITS OF DONATING BLOOD \n";
    cout << "********************************************************************************************\n\n";
    cout << "\tThere are many benefits to donating blood here are a few:\n";
    cout << "\t One blood donation can save up to 3 lives.\n";
    cout << "\tBlood donation not only makes the receivers life good but also helps the donor to maintain good health.\n";
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



vector<Donor> donor_manage_info(vector<Donor> donors, int p) {
    int n = 0, choice;
    bool flag = 0, flag2 = 0, foundCondition = 0;
    string condition;

    //display current info and menu.
    while (flag == 0) {

        system("CLS");
        cout << "\nYour Current Info:\n\n";
        cout << "1.\tName:\t\t" << donors[p].name << endl;
        cout << "2.\tEmail:\t\t" << donors[p].email << endl;
        cout << "3.\tPassword:\t" << donors[p].password << endl;
        cout << "4.\tAddress:\t" << donors[p].streetAddress << ", " << donors[p].suburb << ", " << donors[p].city << endl;
        cout << "5.\tContact Number:\t" << donors[p].contactNumber << endl;
        cout << "6.\tEthnicity:\t" << donors[p].ethnicity << endl;
        cout << "7.\tGender:\t\t" << donors[p].gender << endl;
        cout << "8.\tDate of Birth:\t" << donors[p].dobDay << "/" << donors[p].dobMonth << "/" << donors[p].dobYear << endl;
        cout << "9.\tManage Underlying Conditions" << endl;
        cout << "10.\tExit\n\n";

        //taking user input for editing info
        cout << "Enter Menu Option to Edit Information:\t";
        cin >> choice;

        switch (choice) {
        case 1:
            cin.ignore();
            donors[p].name = update_detail_string("Name");
            break;
        case 2:
            cin.ignore();
            donors[p].email = update_detail_string("Email");
            break;
        case 3:
            cin.ignore();
            donors[p].password = update_detail_string("Password");
            break;
        case 4:
            cin.ignore();
            donors[p].streetAddress = update_detail_string("Street Address");
            donors[p].suburb = update_detail_string("Suburb");
            donors[p].city = update_detail_string("City");
            break;
        case 5:
            cin.ignore();
            donors[p].contactNumber = update_detail_int("Contact Number");
            break;
        case 6:
            cin.ignore();
            donors[p].ethnicity = update_detail_string("Ethnicity");
            break;
        case 7:
            cin.ignore();
            donors[p].gender = update_detail_string("Gender");
            break;
        case 8:
            cout << "\nEnter new Date of Birth:\n";
            donors[p].dobDay = update_detail_int("Day");
            donors[p].dobMonth = update_detail_int("Month");
            donors[p].dobYear = update_detail_int("Year");
            break;
        case 9:
            while (flag2 == 0) {
                system("CLS");
                foundCondition = 0;
                cout << "\nYour Underlying Conditions:\n\n";
                if (donors[p].underlyingConditions.size() == 0) { //Checking if user has underlying conditions to output
                    cout << "You do not have any underlying conditions.\n\n";
                }
                else {
                    for (auto element : donors[p].underlyingConditions) {
                        cout << element << endl;
                    }
                    cout << endl;
                }

                //Add or Remove conditions menu
                cout << "1.\tAdd Condition\n";
                cout << "2.\tRemove Condition\n";
                cout << "3.\tBack to Menu\n\n";
                cout << "Enter Option Number:\t";
                cin >> choice;

                switch (choice) {
                case 1:
                    cin.ignore();
                    donors[p].underlyingConditions.push_back(update_detail_string("Condition"));
                    donors[p].numOfConditions++;
                    break;
                case 2:
                    if (donors[p].underlyingConditions.size() == 0) {
                        //Exits remove condition menu if user has no conditions
                        cout << "\nYou have no conditions to remove.\n\n";
                        system("PAUSE");
                    }
                    else {
                        cout << "\nEnter Condition to remove:\t";
                        cin.ignore();
                        getline(cin, condition);

                        //Loop to find entered condition and remove if found
                        for (int i = 0; i < donors[p].underlyingConditions.size(); i++) {
                            if (donors[p].underlyingConditions[i] == condition) {
                                donors[p].underlyingConditions.erase(donors[p].underlyingConditions.begin() + i);
                                foundCondition = 1;
                                break;
                            }
                        }

                        //checking if input was found and removes
                        if (foundCondition == 1) {
                            cout << "\nCondition \"" << condition << "\" Removed.\n\n";
                            donors[p].numOfConditions--;
                        }
                        else {
                            cout << "\nCondition \"" << condition << "\" Not Found.\n\n";
                        }
                        system("PAUSE");
                    }
                    break;
                case 3:
                    flag2 = 1;
                    break;
                default:
                    cout << "\nPlease enter a valid menu option.\n\n";
                    system("PAUSE");
                }
            }
            flag2 = 0;
            break;
        case 10:
            flag = 1;
            break;
        default:
            cout << "\nPlease enter a valid menu option.\n\n";
            system("PAUSE");

        }
    }

    //writing donors information back into donors file
    ofstream myFile;
    myFile.open("donors.csv", ios::out);

    for (auto element : donors) {
        myFile << element.name << ',';
        myFile << element.password << ',';
        myFile << element.email << ',';
        myFile << element.bloodType << ',';
        myFile << element.streetAddress << ',';
        myFile << element.suburb << ',';
        myFile << element.city << ',';
        myFile << element.ethnicity << ',';
        myFile << element.gender << ',';
        myFile << element.contactNumber << ',';
        myFile << element.dobDay << ',';
        myFile << element.dobMonth << ',';
        myFile << element.dobYear << ',';
        myFile << element.numOfConditions << endl;
    }

    myFile.close();

    myFile.open("conditions.csv", ios::out);

    for (auto element : donors) {
        myFile << element.email << ',';
        for (auto element : element.underlyingConditions) {
            myFile << element << ',';
        }
        myFile << endl;
    }

    myFile.close();

    return donors;
}

Booking* book_donation(Booking* b, string email) {
    //declaring necessary variables
    int day, hour, i;
    char choice;
    ofstream myFile;

    //checking if user has already booked a donation
    for (i = 0; i < 248; i++) {
        if ((b + i)->bookedBy == email) {
            cout << "\nYou already have a booking on July " << (b + i)->day << " at " << (b + i)->time << ":00. Would you like to cancel this booking? (y/n):\t";
            cin >> choice;
            choice = tolower(choice);

            if (choice == 'y') {
                (b + i)->booked = 0;
                (b + i)->bookedBy = "";
                cout << "\nBooking Cancelled.\n\n";
            }
            else if (choice == 'n') {
                cout << "\nReturning to Menu.\n\n";
            }
            else {
                cout << "Please enter y or n\n";
                book_donation(b, email);
            }

            //rewriting bookings array to bookings.csv
            myFile.open("bookings.csv", ios::out);
            for (int j = 0; j < 248; j++) {
                myFile << (b + j)->day << ',' << (b + j)->time << ',' << (b + j)->booked << ',' << (b + j)->bookedBy << endl;
            }
            myFile.close();

            system("PAUSE");
            return b;
        }
    }

    system("CLS");
    cout << "\n\tTAKING BOOKINGS FOR MONTH OF JULY 2021\n";
    cout << "******************************************************\n\n";

    //taking user input for booking
    cout << "Enter Day (enter 0 to return to menu screen):\t";
    cin >> day;

    //checking if given day is valid
    if (day == 0) {
        return b;
    }
    else if (day > 31 || day < 1) {
        cout << "\nInvalid Day. Please try again.\n";
        system("PAUSE");
        book_donation(b, email);
    }
    else {
        cout << "\nThe following times are available of July " << day << ":\n";
        //outputting available booking times
        for (i = 0; i < 248; i++) {
            if ((b + i)->day == day && (b + i)->booked == 0) {
                cout << (b + i)->time << ":00" << endl;
            }
        }

        //taking user input for booking time
        cout << "\nPick one of the listed times by hour (eg. 9 or 14):\t";
        cin >> hour;

        //checking if given hour is valid
        if (hour > 16 || hour < 9) {
            cout << "\nInvalid Hour. Please try again.\n";
            system("PAUSE");
            book_donation(b, email);
        }
        else {
            //finding record to edit
            for (i = 0; i < 248; i++) {
                if ((b + i)->day == day && (b + i)->time == hour) {
                    if ((b + i)->booked == 0) { //Changes booked value in the timeslot to true.
                        (b + i)->booked = 1;
                        (b + i)->bookedBy = email;
                        cout << "\nSuccessfully Booked for " << hour << ":00 on July " << day << endl;

                        //rewriting bookings array to bookings.csv
                        myFile.open("bookings.csv", ios::out);
                        for (int j = 0; j < 248; j++) {
                            myFile << (b + j)->day << ',' << (b + j)->time << ',' << (b + j)->booked << ',' << (b+j)->bookedBy << endl;
                        }
                        myFile.close();
                    }
                    else {
                        cout << "\nThis time is already booked.\n";
                    }
                    break;
                }
            }
        }
    }

    cout << "\n";
    system("PAUSE");
    system("CLS");
    return b;
}

vector<Donor> donor_landing_screen(vector<Donor> donors, int p, Booking* b) {
    int choice;
    bool flag = 0;

    while (flag == 0) {
        system("CLS");
        cout << "\n\t\t\t\t\tWELCOME DONATOR  \n";
        cout << "************************************************************************************************************\n\n";

        cout << "1. How do I donate blood?\n";
        cout << "2. What are the benefits of donating blood?\n";
        cout << "3. Manage my Information\n";
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
            donors = donor_manage_info(donors, p);
            break;
        case 4:
            book_donation(b, donors[p].email);
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

    return donors;
}

vector<Donor> donor_login(vector<Donor> donors, Booking* b) {
    system("CLS");

    //declaring necessary variables
    string login, pword;
    int position = 0, attempt = 3;
    bool Eflag = 0, Pflag = 0;

    //Intro & taking input
    cout << "\tLOGIN AS DONOR\n";
    cout << "******************************\n";
    cout << "Enter Email (enter \"exit\" to return to menu):\t";
    cin >> login;
    //Validating email
    for (auto element : donors) {
        if (login == element.email) {
            Eflag = 1;
            pword = element.password;
            cin.ignore();
            while (attempt > 0) {
                cout << "\nEnter Password:\t";
                getline(cin, login);

                if (login == pword) {
                    donors = donor_landing_screen(donors, position, b);
                    break;
                }
                else {
                    attempt--;
                    cout << "Invalid Password. " << attempt << " Attempts Remaining.\n";
                    if (attempt == 0) {
                        Pflag = 1;
                    }
                }
            }
            break;
        }
        else {
            position++;
        }
    }

    if (Eflag == 0) {
        if (login != "exit") { //will only repeat the function if user hasn't entered "exit". "exit" will allow the user to return to the main menu if they don't know a registered email.
            cout << "\nEmail not found.\n\n";
            system("PAUSE");
            donor_login(donors, b);
        }
    }

    if (Pflag == 1) {
        cout << "\nNo more attempts remaining. Please try again later.\n";
        system("PAUSE");
    }
    /*else { //Entering and validating password
        cout << "\nEnter Password:\t";
        cin.ignore();
        getline(cin, login);
        if (login == *donors[position].password) {
        }
    }*/

    system("CLS");

    return donors;
}

vector<Donor> donor_registration(vector<Donor> donors) {
    system("CLS");
    //declaring donor struct to store details, and temp values for validating
    struct Donor reg;
    string tempPW1, tempPW2, tempGender, condition;
    bool flag = 0;
    char conditionCheck;

    //taking user input for donor
    cout << "\tREGISTER AS DONOR\n";
    cout << "*********************************\n";
    cin.ignore();
    cout << "Enter Full Name:\t";
    getline(cin, reg.name);
    //do while loop to ensure no duplicate emails
    do {
        cout << "Enter Email:\t\t";
        getline(cin, reg.email);

        for (auto element : donors) {
            if (reg.email == element.email) {
                cout << "This email is already registered. Please use a different email.\n";
                flag = 1;
                break;
            }
            else {
                flag = 0;
            }
        }
    } while (flag == 1);

    //do while loop to confirm user's password
    do {
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

    //Underlying Conditions
    do {
        cout << "Do you have any underlying conditions to enter? (y/n):\t";
        cin >> conditionCheck;
        conditionCheck = tolower(conditionCheck);

        if (conditionCheck == 'y') {
            cin.ignore();
            cout << "Enter Condition:\t";
            getline(cin, condition);
            reg.underlyingConditions.push_back(condition);
            reg.numOfConditions++;
            flag = 1;
        }
        else if (conditionCheck == 'n') {
            flag = 0;
        }
        else {
            cout << "Please enter y or n\n";
            flag = 1;
        }
    } while (flag == 1);

    //Registering user data to csv file
    ofstream regToFile;
    regToFile.open("donors.csv", ios::app);

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
    regToFile << reg.dobYear << ",";
    regToFile << reg.numOfConditions << endl;

    regToFile.close();

    //Registering conditions to csv file
    regToFile.open("conditions.csv", ios::app);

    regToFile << reg.email << ',';
    for (auto element : reg.underlyingConditions) {
        regToFile << element << ',';
    }
    regToFile << endl;

    regToFile.close();

    donors.push_back(reg);

    cout << "\nSuccessfully registered " << reg.name << " as Donor.\n\n";

    system("PAUSE");
    system("CLS");

    return donors;
}

vector<Recipient> recipient_login(vector<Recipient> recip) {
    system("CLS");

    //declaring necessary variables
    string login, pword;
    int position = 0, attempt = 3;
    bool Eflag = 0, Pflag = 0;

    //Intro & taking input
    cout << "\tLOGIN AS RECIPIENT\n";
    cout << "******************************\n";
    cout << "Enter Email (enter \"exit\" to return to menu):\t";
    cin >> login;

    //Validating email
    for (auto element : recip) {
        if (login == element.email) {
            Eflag = 1;
            pword = element.password;
            cin.ignore();
            while (attempt > 0) {
                cout << "\nEnter Password:\t";
                getline(cin, login);

                if (login == pword) {
                    recip = recipient_landing_screen(recip, position);
                    break;
                }
                else {
                    attempt--;
                    cout << "Invalid Password. " << attempt << " Attempts Remaining.\n";
                    if (attempt == 0) {
                        Pflag = 1;
                    }
                }
            }
            break;
        }
        else {
            position++;
        }
    }

    if (Eflag == 0) {
        if (login != "exit") { //will only repeat the function if user hasn't entered "exit". "exit" will allow the user to return to the main menu if they don't know a registered email.
            cout << "\nEmail not found.\n\n";
            system("PAUSE");
            recipient_login(recip);
        }
    }

    if (Pflag == 1) {
        cout << "\nNo more attempts remaining. Please try again later.\n";
        system("PAUSE");
    }

    system("CLS");

    return recip;
}

vector<Recipient>* recipient_registration(vector<Recipient>* recip) {
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

    (*recip).push_back(reg);

    cout << "\nSuccessfully registered " << reg.name << " as Recipient.\n\n";

    system("PAUSE");
    system("CLS");

    return recip;
}





void admin_recipient_report() {
    vector<Donor> donors;
    vector<Recipient> recipients;
    Booking bookings[248];
    ifstream myFile;
    Donor transactionD;
    Recipient transactionR;
    Booking transactionB;
    string line;
    int flag = 0;



    int linenum = 0;
    myFile.open("recipients.csv", ios::in);

    //Loop to take recipient input from file
    while (getline(myFile, line)) {
        istringstream linestream(line);
        string item;

        //String variables
        getline(linestream, item, ',');
        transactionR.name = item;
        getline(linestream, item, ',');
        transactionR.password = item;
        getline(linestream, item, ',');
        transactionR.streetAddress = item;
        getline(linestream, item, ',');
        transactionR.suburb = item;
        getline(linestream, item, ',');
        transactionR.city = item;
        getline(linestream, item, ',');
        transactionR.email = item;

        //Int Variables
        getline(linestream, item, ',');
        stringstream ss(item);
        ss >> transactionR.contactNumber;

        getline(linestream, item, ',');
        stringstream rn(item);
        rn >> transactionR.registrationNumber;

        //Add structure to vector 'recipients'.
        recipients.push_back(transactionR);
        linenum++;
    }

    myFile.close();


    system("CLS");
    string searchname;
    cin.ignore();
    cout << "\nENTER RECIPIENTS NAME TO FIND REPORT" << endl;
    cout << "******************************************************" << endl;
    getline(cin, searchname);
    system("CLS");


    for (auto element : recipients) {
        if (element.name == searchname) {

            cout << "-----------------------------------------------------" << endl;
            cout << "\t\t" << element.name << endl;
            cout << "-----------------------------------------------------" << endl;
            cout << "\nSTREET ADDRESS: " << element.streetAddress << ", " << element.suburb << element.city << endl;
            cout << "\nEMAIL: " << element.email << endl;
            cout << "\nCONTACT NUMBER: " << element.contactNumber << endl;
            cout << "\nREGISTRATION NUMBER: " << element.registrationNumber << endl;




            flag = 1;

        }

    }

    if (flag == 0) {

        cout << "THERE ARE NO REPORTS WITH THE NAME: " << searchname << endl;



    }


    cout << "\n";
    system("PAUSE");
    system("CLS");




}







void admin_donor_report() {

    vector<Donor> donors;
    vector<Recipient> recipients;
    ifstream myFile;
    ifstream conditionFile;
    Donor transactionD;
    Recipient transactionR;
    string line;
    string donorEmail;
    int flag = 0;

    //opening Donors
    int linenum = 0;
    myFile.open("donors.csv", ios::in);

    //Loop to take donor input from file
    while (getline(myFile, line)) {
        istringstream linestream(line);
        string item;

        //String variables
        getline(linestream, item, ',');
        transactionD.name = item;
        getline(linestream, item, ',');
        transactionD.password = item;
        getline(linestream, item, ',');
        transactionD.email = item;
        getline(linestream, item, ',');
        transactionD.bloodType = item;
        getline(linestream, item, ',');
        transactionD.streetAddress = item;
        getline(linestream, item, ',');
        transactionD.suburb = item;
        getline(linestream, item, ',');
        transactionD.city = item;
        getline(linestream, item, ',');
        transactionD.ethnicity = item;
        getline(linestream, item, ',');
        transactionD.gender = item;





        //Int Variables
        getline(linestream, item, ',');
        stringstream ss(item);
        ss >> transactionD.contactNumber;

        getline(linestream, item, ',');
        stringstream day(item);
        day >> transactionD.dobDay;

        getline(linestream, item, ',');
        stringstream month(item);
        month >> transactionD.dobMonth;

        getline(linestream, item, ',');
        stringstream year(item);
        year >> transactionD.dobYear;

        getline(linestream, item, ',');
        stringstream num(item);
        num >> transactionD.numOfConditions;

        //Add structure to vector 'donors'.
        donors.push_back(transactionD);
        linenum++;



    }




    //opening conditions
    linenum = 0;
    conditionFile.open("conditions.csv", ios::in);

    //Loop to take conditions input from file
    while (getline(conditionFile, line)) {
        istringstream linestream(line);
        string item;

        getline(linestream, item, ',');
        donorEmail = item;

        for (int i = 0; i < donors.size(); i++) {
            if (donors[i].email == donorEmail) {
                for (int j = 0; j < donors[i].numOfConditions; j++) {
                    getline(linestream, item, ',');
                    donors[i].underlyingConditions.push_back(item);
                }
            }
        }
    }

    conditionFile.close();
    myFile.close();





    system("CLS");
    string searchname;
    cin.ignore();
    cout << "\nENTER DONORS NAME TO FIND REPORT" << endl;
    cout << "******************************************************" << endl;
    getline(cin, searchname);
    system("CLS");


    for (auto element : donors) {
        if (element.name == searchname) {

            cout << "-----------------------------------------------------" << endl;
            cout << "\t\t" << element.name << endl;
            cout << "-----------------------------------------------------" << endl;
            cout << "\nBLOOD TYPE: " << element.bloodType << endl;
            cout << "\nSTREET ADDRESS: " << element.streetAddress << endl;
            cout << "\nEMAIL: " << element.email << endl;                                                                                                                                                                                           
            cout << "\nCONTACT NUMBER: " << element.contactNumber << endl;
            cout << "\nDATE OF BIRTH: " << element.dobDay << "/" << element.dobMonth << "/" << element.dobYear << endl;
            cout << "\nGENDER: " << element.gender << endl;
            cout << "\nETHNICITY: " << element.ethnicity << endl;


            if (element.underlyingConditions.size() == 0) { //Checking if user has underlying conditions to output
                cout << element.name << "DOES NOT HAVE ANY UNDERLYING CONDITIONS \n\n" << endl;
            }
            else {
                for (auto element : element.underlyingConditions) {
                    cout << "\nUNDERLYING CONDITIONS: " << element << endl;
                }
                cout << endl;
            }



            flag = 1;

        }

    }

    if (flag == 0) {
        cout << "\n";
        cout << "THERE ARE NO REPORTS WITH THE NAME: " << searchname << endl;



    }


    cout << "\n";
    system("PAUSE");
    system("CLS");
}

vector<Donor> admin_update_donor(vector<Donor> donors)
{
    system("CLS");

    //declaring neccessary variables
    string search = "";
    bool flag = 0, flag2 = 0, foundCondition = 0;
    int p = 0, choice;
    string condition;

    //Searching for donor to update by name
    cout << "\n\tSEARCH FOR DONOR BY NAME\n";
    cout << "****************************************\n\n";
    cout << "Enter Donor Name (enter \"exit\" to return to menu):\t";
    getline(cin, search);
    cout << search;

    if (search == "exit") {
        return donors;
    }
    else {
        for (auto element : donors) {
            if (search == element.name) {
                flag = 1;
                break;
            }
            p++;
        }
    }

    //Checking if donor was found
    if (flag == 0) {
        cout << "\nDonor not found.\n\n";
        system("PAUSE");
        admin_update_donor(donors);
    }
    else {
        //Update menu if donor found
        flag = 0;
        while (flag == 0) {
            system("CLS");
            cout << "\n\t" << donors[p].name << endl;
            cout << "*************************************\n\n";
            cout << "1.\tBlood Type:\t" << donors[p].bloodType << endl;
            cout << "2.\tManage Underlying Conditions" << endl;
            cout << "3.\tExit\n\n";
            cout << "Enter Option Number to Update:\t";
            cin >> choice;

            switch (choice) {
            case 1:
                cin.ignore();
                donors[p].bloodType = update_detail_string("Blood Type");
                break;
            case 2:
                while (flag2 == 0) {
                    system("CLS");
                    foundCondition = 0;
                    cout << "\nYour Underlying Conditions:\n\n";
                    if (donors[p].underlyingConditions.size() == 0) { //Checking if user has underlying conditions to output
                        cout << "You do not have any underlying conditions.\n\n";
                    }
                    else {
                        for (auto element : donors[p].underlyingConditions) {
                            cout << element << endl;
                        }
                        cout << endl;
                    }

                    //Add or Remove conditions menu
                    cout << "1.\tAdd Condition\n";
                    cout << "2.\tRemove Condition\n";
                    cout << "3.\tBack to Menu\n\n";
                    cout << "Enter Option Number:\t";
                    cin >> choice;

                    switch (choice) {
                    case 1:
                        cin.ignore();
                        donors[p].underlyingConditions.push_back(update_detail_string("Condition"));
                        donors[p].numOfConditions++;
                        break;
                    case 2:
                        if (donors[p].underlyingConditions.size() == 0) {
                            //Exits remove condition menu if user has no conditions
                            cout << "\nYou have no conditions to remove.\n\n";
                            system("PAUSE");
                        }
                        else {
                            cout << "\nEnter Condition to remove:\t";
                            cin.ignore();
                            getline(cin, condition);

                            //Loop to find entered condition and remove if found
                            for (int i = 0; i < donors[p].underlyingConditions.size(); i++) {
                                if (donors[p].underlyingConditions[i] == condition) {
                                    donors[p].underlyingConditions.erase(donors[p].underlyingConditions.begin() + i);
                                    foundCondition = 1;
                                    break;
                                }
                            }

                            //checking if input was found and removes
                            if (foundCondition == 1) {
                                cout << "\nCondition \"" << condition << "\" Removed.\n\n";
                                donors[p].numOfConditions--;
                            }
                            else {
                                cout << "\nCondition \"" << condition << "\" Not Found.\n\n";
                            }
                            system("PAUSE");
                        }
                        break;
                    case 3:
                        flag2 = 1;
                        break;
                    default:
                        cout << "\nPlease enter a valid menu option.\n\n";
                        system("PAUSE");
                    }
                }
                flag2 = 0;
                break;
            case 3:
                flag = 1;
                break;
            default:
                cout << "\nPlease Enter a Valid Menu Option\n\n";
                system("PAUSE");
            }
        }
    }

    //writing donors information back into donors file
    ofstream myFile;
    myFile.open("donors.csv", ios::out);

    for (auto element : donors) {
        myFile << element.name << ',';
        myFile << element.password << ',';
        myFile << element.email << ',';
        myFile << element.bloodType << ',';
        myFile << element.streetAddress << ',';
        myFile << element.suburb << ',';
        myFile << element.city << ',';
        myFile << element.ethnicity << ',';
        myFile << element.gender << ',';
        myFile << element.contactNumber << ',';
        myFile << element.dobDay << ',';
        myFile << element.dobMonth << ',';
        myFile << element.dobYear << ',';
        myFile << element.numOfConditions << endl;
    }

    myFile.close();

    myFile.open("conditions.csv", ios::out);

    for (auto element : donors) {
        myFile << element.email << ',';
        for (auto element : element.underlyingConditions) {
            myFile << element << ',';
        }
        myFile << endl;
    }

    myFile.close();

    return donors;
}

vector<Admin> admin_registration(vector<Admin> admins) {






    return admins;
}

OmniStruct admin_landing_screen(vector<Admin> admins, vector<Donor> donors, vector<Recipient> recip)
{
    OmniStruct o = { donors, recip, admins };
    bool flag = 0;
    int choice;
    while (flag == 0)

    {
        system("CLS");
        cout << "\n\t\t\t\t\tWELCOME ADMIN \n";
        cout << "************************************************************************************************************\n\n";

        cout << "1. view donor's report\n";
        cout << "2. view Recipient report \n";
        cout << "3. Update donor blood testing report \n";
        cout << "4. Location report ";
        cout << "5. Blood group report";
        cout << "6. unnamed ";
        cout << "7. unnamed ";
        cout << "8. Logout\n";
        cout << "Enter Option Number:\t";
        cin >> choice;

        switch (choice) {
        case 1:

            admin_donor_report();


            break;
        case 2:
            admin_recipient_report();
            break;
        case 3:
            cin.ignore();
            donors = admin_update_donor(donors);
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
            flag = 1;
            system("CLS");
            
            
            break;

        default:
            cout << "Please enter a valid menu option.\n";
            system("PAUSE");
            system("CLS");
        }
    }
    
    o = { donors, recip, admins };
    return o;
}


OmniStruct admin_login(vector<Admin> admins, vector<Donor> donors, vector<Recipient> recip) {
    system("CLS");

    //declaring necessary variables
    string login, pword;
    int position = 0, attempt = 3;
    bool Eflag = 0, Pflag = 0;
    OmniStruct o = { donors, recip, admins };

    //Intro & taking input
    cout << "\tLOGIN AS ADMIN\n";
    cout << "******************************\n";
    cout << "Enter Email (enter \"exit\" to return to menu):\t";
    cin >> login;

    //Validating email
    for (auto element : admins) {
        if (login == element.email) {
            Eflag = 1;
            pword = element.password;
            cin.ignore();
            while (attempt > 0) {
                cout << "\nEnter Password:\t";
                getline(cin, login);

                if (login == pword) {
                    o = admin_landing_screen(admins, donors, recip);
                    break;
                }
                else {
                    attempt--;
                    cout << "Invalid Password. " << attempt << " Attempts Remaining.\n";
                    if (attempt == 0) {
                        Pflag = 1;
                    }
                }
            }
            break;
        }
        else {
            position++;
        }
    }

    if (Eflag == 0) {
        if (login != "exit") { //will only repeat the function if user hasn't entered "exit". "exit" will allow the user to return to the main menu if they don't know a registered email.
            cout << "\nEmail not found.\n\n";
            system("PAUSE");
            admin_login(admins, donors, recip);
        }
    }

    if (Pflag == 1) {
        cout << "\nNo more attempts remaining. Please try again later.\n";
        system("PAUSE");
    }

    system("CLS");

    return o;
}












int main()
{
    //reading files to vectors
    //declaring necessary variables
    vector<Donor> donors;
    vector<Recipient> recipients;
    vector<Admin> admins;
    Booking bookings[248];
    ifstream myFile;
    Donor transactionD;
    Recipient transactionR;
    Admin transactionA;
    Booking transactionB;
    string line, donorEmail;

    //opening Donors
    int linenum = 0;
    myFile.open("donors.csv", ios::in);

    //Loop to take donor input from file
    while (getline(myFile, line)) {
        istringstream linestream(line);
        string item;

        //String variables
        getline(linestream, item, ',');
        transactionD.name = item;
        getline(linestream, item, ',');
        transactionD.password = item;
        getline(linestream, item, ',');
        transactionD.email = item;
        getline(linestream, item, ',');
        transactionD.bloodType = item;
        getline(linestream, item, ',');
        transactionD.streetAddress = item;
        getline(linestream, item, ',');
        transactionD.suburb = item;
        getline(linestream, item, ',');
        transactionD.city = item;
        getline(linestream, item, ',');
        transactionD.ethnicity = item;
        getline(linestream, item, ',');
        transactionD.gender = item;

        //Int Variables
        getline(linestream, item, ',');
        stringstream ss(item);
        ss >> transactionD.contactNumber;

        getline(linestream, item, ',');
        stringstream day(item);
        day >> transactionD.dobDay;

        getline(linestream, item, ',');
        stringstream month(item);
        month >> transactionD.dobMonth;

        getline(linestream, item, ',');
        stringstream year(item);
        year >> transactionD.dobYear;

        getline(linestream, item, ',');
        stringstream num(item);
        num >> transactionD.numOfConditions;

        //Add structure to vector 'donors'.
        donors.push_back(transactionD);
        linenum++;
    }

    myFile.close();

    //opening recipients
    linenum = 0;
    myFile.open("recipients.csv", ios::in);

    //Loop to take recipient input from file
    while (getline(myFile, line)) {
        istringstream linestream(line);
        string item;

        //String variables
        getline(linestream, item, ',');
        transactionR.name = item;
        getline(linestream, item, ',');
        transactionR.password = item;
        getline(linestream, item, ',');
        transactionR.streetAddress = item;
        getline(linestream, item, ',');
        transactionR.suburb = item;
        getline(linestream, item, ',');
        transactionR.city = item;
        getline(linestream, item, ',');
        transactionR.email = item;

        //Int Variables
        getline(linestream, item, ',');
        stringstream ss(item);
        ss >> transactionR.contactNumber;

        getline(linestream, item, ',');
        stringstream rn(item);
        rn >> transactionR.registrationNumber;

        //Add structure to vector 'recipients'.
        recipients.push_back(transactionR);
        linenum++;
    }

    myFile.close();

    //opening bookings
    linenum = 0;
    myFile.open("bookings.csv", ios::in);

    //Loop to take bookings input from file
    while (getline(myFile, line)) {
        istringstream linestream(line);
        string item;

        //Int Variables
        getline(linestream, item, ',');
        stringstream day(item);
        day >> transactionB.day;

        getline(linestream, item, ',');
        stringstream time(item);
        time >> transactionB.time;

        getline(linestream, item, ',');
        stringstream booked(item);
        booked >> transactionB.booked;

        //String Variable
        getline(linestream, item, ',');
        transactionB.bookedBy = item;

        //Add structure to array 'bookings'.
        bookings[linenum] = transactionB;
        linenum++;
    }

    myFile.close();

    //opening conditions
    linenum = 0;
    myFile.open("conditions.csv", ios::in);

    //Loop to take conditions input from file
    while (getline(myFile, line)) {
        istringstream linestream(line);
        string item;

        getline(linestream, item, ',');
        donorEmail = item;

        for (int i = 0; i < donors.size(); i++) {
            if (donors[i].email == donorEmail) {
                for (int j = 0; j < donors[i].numOfConditions; j++) {
                    getline(linestream, item, ',');
                    donors[i].underlyingConditions.push_back(item);
                }
            }
        }
    }

    myFile.close();

    //opening admin
    linenum = 0;
    myFile.open("admin.csv", ios::in);

    while (getline(myFile, line)) {
        istringstream linestream(line);
        string item;

        getline(linestream, item, ',');
        transactionA.email = item;
        getline(linestream, item, ',');
        transactionA.password = item;

        admins.push_back(transactionA);
        linenum++;
    }

    myFile.close();

    //creating pointers
    vector<Donor>* ptrdonors = &donors;
    vector<Recipient>* ptrrecipients = &recipients;
    Booking* ptrbookings = bookings;

    //INTRO MENU
    //****************
    bool flag = 0;
    int choice;
    OmniStruct o;

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
            donors = donor_registration(donors);
            break;
        case 4:
            donors = donor_login(donors, ptrbookings);
            break;
        case 5:
            recipient_registration(ptrrecipients);
            break;
        case 6:
            recipients = recipient_login(recipients);
            break;
        case 7:
            o = admin_login(admins, donors, recipients);
            admins = o.a;
            donors = o.d;
            recipients = o.r;
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