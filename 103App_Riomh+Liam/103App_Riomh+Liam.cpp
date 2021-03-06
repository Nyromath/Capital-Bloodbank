#include <iostream>
#include <fstream>
#include <sstream>
#include <cmath>
#include <ctime>
#include <string>
#include <stdlib.h>
#include <vector>
using namespace std;

//defining structures for Donor, Recipient, Admin & Booking
struct Donor {
    string name, password, email, bloodType, streetAddress, suburb, city, ethnicity, gender, contactNumber;
    int dobDay, dobMonth, dobYear, numOfConditions;
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
        contactNumber = s;
        dobDay = i;
        dobMonth = i;
        dobYear = i;
        numOfConditions = i;
    }
};

struct Recipient {
    string name, password, streetAddress, suburb, city, email, contactNumber, registrationNumber;

    Recipient(string s = " ", int i = 0) {
        name = s;
        password = s;
        streetAddress = s;
        suburb = s;
        city = s;
        email = s;
        contactNumber = s;
        registrationNumber = s;
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

//structure with vectors for all 3 user types to return through admin functions
struct OmniStruct {
    vector<Donor> d;
    vector<Recipient> r;
    vector<Admin> a;
};


void intro_function() { //Displays About Us info
    system("CLS");
    cout << "\n\t\t\t\t\tABOUT US\n";
    cout << "********************************************************************************************\n\n";
    cout << "\tCapital Blood Bank is a New Zealand based Blood Bank with locations across the north\n";
    cout << "\tand south island.\n\n";
    cout << "\tAs a blood bank we have been running for over 25 years, and have obtained over\n";
    cout << "\t100,000 litres of blood\n\n";
    cout << "\tThe blood is sent to all local centers to use for those who require it\n";
    cout << "\tWe ask that those who are able to donate blood to donate it as many people in New\n";
    cout << "\tZealand need blood\n\n";
    cout << "\tIf you are interested in donating blood or are in need of blood please register and\n";
    cout << "\tcontact us for more info\n\n";
    cout << "\tIf you are unsure if you are eligible to donate blood please call us or email us to\n";
    cout << "\tbook a time at one of our locations for an interview.\n\n";
    cout << "\tAll of our contact information can be found on the contact info tab found in the\n";
    cout << "\tmain menu.\n\n";
    cout << "********************************************************************************************\n\n";
    system("PAUSE");
    system("CLS");
}

void display_contact_info()
{   //displays contact info
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

void donors_contact_info() { //allows for search and display of Donor's contact info through Recipient menu
    //declaring variables
    vector<Donor> donors;
    ifstream myFile;
    Donor transactionD;
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
        getline(linestream, item, ',');
        transactionD.contactNumber = item;


        //Int Variables
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

    //taking user input
    system("CLS");
    string searchname;
    cin.ignore();
    cout << "\nENTER DONOR NAME TO FIND CONTACT INFO" << endl;
    cout << "******************************************************" << endl;
    getline(cin, searchname);


    //searching and displaying donor info
    for (auto element : donors) {
        if (element.name == searchname) {
            system("CLS");
            cout << "-----------------------------------------------------" << endl;
            cout << "\t\t" << element.name << endl;
            cout << "-----------------------------------------------------" << endl;
            cout << "\nADDRESS: " << element.streetAddress << ", " << element.suburb << ", " << element.city << endl;
            cout << "\nEMAIL: " << element.email << endl;
            cout << "\nCONTACT NUMBER: " << element.contactNumber << endl;
            cout << "\nBLOOD TYPE: " << element.bloodType << endl;
            cout << "-----------------------------------------------------" << "\n\n";
            flag = 1;
            system("PAUSE");
        }

    }

    //shows appropriate message if no donor is found with given name
    if (flag == 0) {
        cout << "\nTHERE ARE NO DONORS FOUND WITH THAT NAME" << "\n\n";
        system("PAUSE");
    }

    system("CLS");

}



void donors_by_blood() { //searches for donor by given Blood Type
    //declaring variables
    vector<Donor> donors;
    ifstream myFile;
    Donor transactionD;
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
        getline(linestream, item, ',');
        transactionD.contactNumber = item;


        //Int Variables
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

    //taking user input
    system("CLS");
    string searchblood;
    cin.ignore();
    cout << "\nENTER BLOOD TYPE TO SEARCH FOR DONORS" << endl;
    cout << "******************************************************" << endl;
    getline(cin, searchblood);


    //searches and displays donor info
    for (auto element : donors) {
        if (element.bloodType == searchblood) {
            cout << "\n-----------------------------------------------------" << endl;
            cout << "\t\t" << element.name << endl;
            cout << "-----------------------------------------------------" << endl;

            cout << "\nADDRESS: " << element.streetAddress << ", " << element.suburb << ", " << element.city << endl;
            cout << "\nEMAIL: " << element.email << endl;
            cout << "\nCONTACT NUMBER: " << element.contactNumber << endl;
            cout << "\nBLOOD TYPE: " << element.bloodType << endl;
            cout << "-----------------------------------------------------" << "\n\n";
            flag = 1;
            system("PAUSE");
        }
    }

    //displays appropriate message if no donors with given blood type exist
    if (flag == 0) {
        cout << "\nTHERE ARE NO DONORS WITH BLOOD TYPE: " << searchblood << "\n\n";
        system("PAUSE");
    }



    system("CLS");

}











void donors_by_location() { //searches for donor by given City
    vector<Donor> donors;
    ifstream myFile;
    Donor transactionD;
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
        getline(linestream, item, ',');
        transactionD.contactNumber = item;


        //Int Variables
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

    //taking user input
    system("CLS");
    string searchcity;
    cin.ignore();
    cout << "\nENTER CITY NAME TO SEARCH FOR DONORS" << endl;
    cout << "******************************************************" << endl;
    getline(cin, searchcity);


    //searches and displays donor info
    for (auto element : donors) {
        if (element.city == searchcity) {
            cout << "\n-----------------------------------------------------" << endl;
            cout << "\t\t" << element.name << endl;
            cout << "-----------------------------------------------------" << endl;
            cout << "\nADDRESS: " << element.streetAddress << ", " << element.suburb << ", " << element.city << endl;
            cout << "\nEMAIL: " << element.email << endl;
            cout << "\nCONTACT NUMBER: " << element.contactNumber << endl;
            cout << "\nBLOOD TYPE: " << element.bloodType << endl;
            cout << "-----------------------------------------------------" << "\n\n";
            flag = 1;
            system("PAUSE");


        }
    }

    //displays appropriate message if no donors in given city exist
    if (flag == 0) {

        cout << "\nTHERE ARE NO DONORS THAT LIVE IN: " << searchcity << "\n\n";
        system("PAUSE");

    }



    system("CLS");

}


vector<Recipient> recipient_manage_info(vector<Recipient> recip, int p) { //allows recipient to view and update their information
    //declaring variables
    int n = 0, choice;
    bool flag = 0;

    //display current info and menu
    while (flag == 0) {
        system("CLS");
        cout << "\nIMPORTANT: Do NOT include any COMMAS ( , ) in your registration information.\n";
        cout << "Due to the programming of this database system, it will break your entry.\n";
        cout << "If this happens, contact an Admin to fix your info.\n";

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
            recip[p].streetAddress = update_detail_string("Street Address (e.g. 1 Main Street)");
            recip[p].suburb = update_detail_string("Suburb");
            recip[p].city = update_detail_string("City");
            break;
        case 5:
            recip[p].contactNumber = update_detail_string("Contact Number");
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

vector<Recipient> recipient_landing_screen(vector<Recipient> recip, int p) { //main menu for user logged in as a Recipient
    //declaring variables
    int choice;
    bool flag = 0;

    //menu
    while (flag == 0) {
        system("CLS");
        cout << "\n\t\t\t\t\tWelcome, " << recip[p].name << "\n";
        cout << "************************************************************************************************************\n\n";
        cout << "You are logged in as a RECIPIENT\n\n";
        cout << "1. Find Potential Donors by Blood Type \n";
        cout << "2. Find Potential Donors by City\n";
        cout << "3. Find Donor Contact Info\n";
        cout << "4. Manage my Information\n";
        cout << "5. Log Out\n\n";
        cout << "Enter Option Number:\t";
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
            cout << "\nPlease enter a valid menu option.\n";
            system("PAUSE");
            system("CLS");
        }

    }

    return recip;
}

void donor_benefits() { //displays benefits of donating blood information to donor
    system("CLS");
    cout << "\n\t\t\t\t\tBENEFITS OF DONATING BLOOD \n";
    cout << "********************************************************************************************\n\n";
    cout << "\tThere are many benefits to donating blood. Here are a few:\n\n";
    cout << "\t* One blood donation can save up to 3 lives!\n\n";
    cout << "\t* Blood donation not only saves lives, but also helps the donor to maintain good\n";
    cout << "\t  health.\n\n";
    cout << "\t* Health benefits of blood donation include reduced risk of hemochromatosis.\n\n";
    cout << "\t* Blood donation helps in lowering the risk of cancer. By donating blood the iron\n";
    cout << "\t  stores in the body are maintained at healthy levels.\n\n";
    cout << "\t* A reduction in the iron level in the body is linked with low cancer risk.\n\n";
    cout << "********************************************************************************************\n\n";
    system("PAUSE");
    system("CLS");
}

void donor_how_i_donate() { //displays instructions on how to donate to donor
    system("CLS");
    cout << "\n\t\t\t\t\tHOW DO I DONATE BLOOD? \n";
    cout << "********************************************************************************************\n\n";
    cout << "\tThere are many ways you can donate blood.\n\n";
    cout << "\tThe easiest way to donate is by booking a donation by selecting the book a donation\n";
    cout << "\ttab on the donor menu.\n\n";
    cout << "\tOtherwise you can find our contact info menu on the home page by logging out to book\n";
    cout << "\ta time to donate blood.\n\n";
    cout << "\tTo be eligible to donate blood you will be required to answer some brief yes/no\n";
    cout << "\tquestions to ensure that those receiving your blood will be safe from any diseases\n";
    cout << "\tand viruses\n\n";
    cout << "********************************************************************************************\n\n";
    system("PAUSE");
    system("CLS");
}



vector<Donor> donor_manage_info(vector<Donor> donors, int p) { //allows donor to view and edit their information
    //declaring variables
    int n = 0, choice;
    bool flag = 0, flag2 = 0, foundCondition = 0;
    string condition;

    //display current info and menu.
    while (flag == 0) {

        system("CLS");
        cout << "\nIMPORTANT: Do NOT include any COMMAS ( , ) in your registration information.\n";
        cout << "Due to the programming of this database system, it will break your entry.\n";
        cout << "If this happens, contact an Admin to fix your info.\n";

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
            donors[p].streetAddress = update_detail_string("Street Address (e.g. 1 Main Street)");
            donors[p].suburb = update_detail_string("Suburb");
            donors[p].city = update_detail_string("City");
            break;
        case 5:
            cin.ignore();
            donors[p].contactNumber = update_detail_string("Contact Number");
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

Booking* book_donation(Booking* b, string email) { //allows donor to book a donation to donate blood
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

vector<Donor> donor_landing_screen(vector<Donor> donors, int p, Booking* b) { //main menu for user logged in as donor
    //declaring variables
    int choice;
    bool flag = 0;

    //menu
    while (flag == 0) {
        system("CLS");
        cout << "\n\t\t\t\t\tWelcome, " << donors[p].name <<"\n";
        cout << "************************************************************************************************************\n\n";
        cout << "You are logged in as a DONOR\n\n";

        cout << "1. How do I donate blood?\n";
        cout << "2. What are the benefits of donating blood?\n";
        cout << "3. Manage my Information\n";
        cout << "4. Book a Donation\n";
        cout << "5. Log Out\n\n";
        cout << "Enter option Number:\t";
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
            cout << "\nPlease enter a valid menu option.\n";
            system("PAUSE");
            system("CLS");
        }

    }

    return donors;
}

vector<Donor> donor_login(vector<Donor> donors, Booking* b) { //log in screen for donor users
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

    system("CLS");

    return donors;
}

vector<Donor> donor_registration(vector<Donor> donors) { //allows user to register a donor account
    system("CLS");

    //declaring donor struct to store details, and temp values for validating
    struct Donor reg;
    string tempPW1, tempPW2, tempGender, condition;
    bool flag = 0;
    char conditionCheck;

    //intro message
    cout << "\tREGISTER AS DONOR\n";
    cout << "*********************************\n\n";
    cout << "IMPORTANT: Do NOT include any COMMAS ( , ) in your registration information.\n";
    cout << "Due to the programming of this database system, it will break your entry.\n";
    cout << "If this happens, contact an Admin to fix your info.\n\n";
    
    system("PAUSE");
    system("CLS");

    cout << "\tREGISTER AS DONOR\n";
    cout << "*********************************\n\n";

    //taking user input for donor
    cin.ignore();
    cout << "Enter Full Name (enter \"exit\" to return to menu):\t";
    getline(cin, reg.name);

    //exit clause
    if (reg.name == "exit") {
        system("CLS");
        return donors;
    }

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
    getline(cin, reg.contactNumber);
    cout << "Enter Street Address (e.g. 1 Main Street):\t";
    getline(cin, reg.streetAddress);
    cout << "Enter Suburb:\t\t";
    getline(cin, reg.suburb);
    cout << "Enter City:\t\t";
    getline(cin, reg.city);
    cout << "\nEnter Date of Birth (dd mm yyyy):\n";
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

    do {
        cout << "Enter Blood Type:\t"; //Blood type does not yet check for valid blood type. Will not prevent someone having the blood type "Banana", for example.
        cin >> reg.bloodType;

        string bloodTypes[8] = { "A+", "A-", "B+", "B-", "O+", "O-", "AB+", "AB-" };
        for(int i = 0; i < 8; i++) {
            if (reg.bloodType == bloodTypes[i]) {
                flag = 0;
            }
            else {
                flag = 1;
            }
        }

        if (flag == 1) {
            cout << "Invalid Blood Type. Please Enter one of the following: A+, A-, B+, B-, O+, O-, AB+, AB-\n";
        }
    } while (flag == 1);

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

vector<Recipient> recipient_login(vector<Recipient> recip) { //login screen for recipient users
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

    //intro message
    cout << "\tREGISTER AS RECIPIENT\n";
    cout << "*************************************\n\n";

    cout << "IMPORTANT: Do NOT include any COMMAS ( , ) in your registration information.\n";
    cout << "Due to the programming of this database system, it will break your entry.\n";
    cout << "If this happens, contact an Admin to fix your info.\n\n";

    system("PAUSE");
    system("CLS");

    cout << "\tREGISTER AS RECIPIENT\n";
    cout << "*************************************\n";

    //taking user input for recipient
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
    getline(cin, reg.contactNumber);
    cout << "Enter Street Address (e.g. 1 Main Street):\t";
    getline(cin, reg.streetAddress);
    cout << "Enter Suburb:\t\t";
    getline(cin, reg.suburb);
    cout << "Enter City:\t\t";
    getline(cin, reg.city);
    cout << "Enter Registration Number:\t";
    getline(cin, reg.registrationNumber);

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


void admin_recipient_report() { //allows administrator to search for recipient info by name
    //declaring variables
    vector<Recipient> recipients;
    ifstream myFile;
    Recipient transactionR;
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
        getline(linestream, item, ',');
        transactionR.contactNumber = item;
        getline(linestream, item, ',');
        transactionR.registrationNumber = item;

        //Add structure to vector 'recipients'.
        recipients.push_back(transactionR);
        linenum++;
    }

    myFile.close();

    //taking user input
    system("CLS");
    string searchname;
    cin.ignore();
    cout << "\nENTER RECIPIENTS NAME TO FIND REPORT" << endl;
    cout << "******************************************************" << endl;
    getline(cin, searchname);

    //search and display recipient information
    for (auto element : recipients) {
        if (element.name == searchname) {

            cout << "-----------------------------------------------------" << endl;
            cout << "\t\t" << element.name << endl;
            cout << "-----------------------------------------------------" << endl;
            cout << "\nADDRESS: " << element.streetAddress << ", " << element.suburb << ", " << element.city << endl;
            cout << "\nEMAIL: " << element.email << endl;
            cout << "\nCONTACT NUMBER: " << element.contactNumber << endl;
            cout << "\nREGISTRATION NUMBER: " << element.registrationNumber << "\n\n";

            flag = 1;
        }

    }

    //displays appropriate message if no recipients with given name exist
    if (flag == 0) {
        cout << "\nTHERE ARE NO REPORTS WITH THE NAME: " << searchname << "\n\n";
    }

    system("PAUSE");
    system("CLS");
}


void admin_donor_report() { //allows administrator to search for donor info by name
    //declaring variables
    vector<Donor> donors;
    ifstream myFile;
    ifstream conditionFile;
    Donor transactionD;
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
        getline(linestream, item, ',');
        transactionD.contactNumber = item;


        //Int Variables
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


    //taking user input
    system("CLS");
    string searchname;
    cin.ignore();
    cout << "\nENTER DONORS NAME TO FIND REPORT" << endl;
    cout << "******************************************************" << endl;
    getline(cin, searchname);

    //search and display donor info
    for (auto element : donors) {
        if (element.name == searchname) {

            cout << "\n-----------------------------------------------------" << endl;
            cout << "\t\t" << element.name << endl;
            cout << "-----------------------------------------------------" << endl;
            cout << "\nBLOOD TYPE: " << element.bloodType << endl;
            cout << "\nADDRESS: " << element.streetAddress << ", " << element.suburb << ", " << element.city << endl;
            cout << "\nEMAIL: " << element.email << endl;
            cout << "\nCONTACT NUMBER: " << element.contactNumber << endl;
            cout << "\nDATE OF BIRTH: " << element.dobDay << "/" << element.dobMonth << "/" << element.dobYear << endl;
            cout << "\nGENDER: " << element.gender << endl;
            cout << "\nETHNICITY: " << element.ethnicity << endl;

            int numOfCond = element.underlyingConditions.size();
            if (numOfCond == 0) { //Checking if user has underlying conditions to output
                cout << element.name << " does not have any underlying conditions\n\n" << endl;
            }
            else {
                int n = 1;
                cout << "\nUNDERLYING CONDITIONS: ";
                for (auto element : element.underlyingConditions) {
                    cout << element;
                    if (n != numOfCond) {
                        cout << ", ";
                    }
                    n++;
                }
                cout << "\n\n";
            }
            flag = 1;
        }
    }

    //displays appropriate message if no donors with given name exist
    if (flag == 0) {
        cout << "\n";
        cout << "THERE ARE NO REPORTS WITH THE NAME: " << searchname << "\n\n";
    }

    system("PAUSE");
    system("CLS");
}


void admin_blood_report() { //allows adminstrator to search for donors based on blood type
    //declaring variables
    vector<Donor> donors;
    ifstream myFile;
    Donor transactionD;
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
        getline(linestream, item, ',');
        transactionD.contactNumber = item;


        //Int Variables
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

    //taking user input
    system("CLS");
    string searchblood;
    cin.ignore();
    cout << "\nENTER BLOOD TYPE TO SEARCH FOR DONOR REPORTS" << endl;
    cout << "******************************************************" << endl;
    getline(cin, searchblood);


    //search and display donor info by blood type
    for (auto element : donors) {
        if (element.bloodType == searchblood) {
            cout << "-----------------------------------------------------" << endl;
            cout << "\t\t" << element.name << endl;
            cout << "-----------------------------------------------------" << endl;
            cout << "\nADDRESS: " << element.streetAddress << ", " << element.suburb << element.city << endl;
            cout << "\nEMAIL: " << element.email << endl;
            cout << "\nCONTACT NUMBER: " << element.contactNumber << endl;
            cout << "\nETHNICITY: " << element.ethnicity << endl;
            cout << "\nGENDER: " << element.gender << endl;
            cout << "\nDOB: " << element.dobDay << "/" << element.dobMonth << "/" << element.dobYear << endl;

            system("PAUSE");
        }
    }

    //displays appropriate message if no donors with given blood type exist
    if (flag == 0) {
        system("CLS");
        cout << "THERE ARE NO DONORS WITH BLOOD TYPE: " << searchblood << endl;
        system("PAUSE");
    }

    system("CLS");
}


void admin_location_report() { //allows administrator to search for donors based on their city of residence
    //declaring variables
    vector<Donor> donors;
    ifstream myFile;
    Donor transactionD;
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
        getline(linestream, item, ',');
        transactionD.contactNumber = item;


        //Int Variables
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

    //taking user input
    system("CLS");
    string searchcity;
    cin.ignore();
    cout << "\nENTER CITY NAME TO SEARCH FOR DONOR REPORTS" << endl;
    cout << "******************************************************" << endl;
    getline(cin, searchcity);


    //search and display donor info by city
    for (auto element : donors) {
        if (element.city == searchcity) {
            cout << "\n-----------------------------------------------------" << endl;
            cout << "\t\t" << element.name << endl;
            cout << "-----------------------------------------------------" << endl;
            cout << "\nADDRESS: " << element.streetAddress << ", " << element.suburb << ", " << element.city << endl;
            cout << "\nEMAIL: " << element.email << endl;
            cout << "\nCONTACT NUMBER: " << element.contactNumber << endl;
            cout << "\nETHNICITY: " << element.ethnicity << endl;
            cout << "\nGENDER: " << element.gender << endl;
            cout << "\nDOB: " << element.dobDay << "/" << element.dobMonth << "/" << element.dobYear << endl;
            cout << "-----------------------------------------------------" << "\n\n";

            flag = 1;
            system("PAUSE");


        }
    }

    //displays appropriate message if no donors that live in given city exist
    if (flag == 0) {

        cout << "\nTHERE ARE NO DONORS THAT LIVE IN: " << searchcity << "\n\n";
        system("PAUSE");

    }

    system("CLS");
}


vector<Donor> admin_update_donor(vector<Donor> donors) //allows administrator to update donor blood test information such as blood type or underlying conditions
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

vector<Admin> admin_registration(vector<Admin> admins) { //allows adminstrator to register a new admin account
    //declaring variables
    Admin reg;
    bool flag = 0;
    string tempPW1, tempPW2;

    system("CLS");
    cout << "\n\tRegister New Admin Account\n";
    cout << "******************************************\n\n";

    cout << "IMPORTANT: Do NOT include any COMMAS ( , ) in your registration information.\n";
    cout << "Due to the programming of this database system, it will break your entry.\n\n";

    system("PAUSE");
    system("CLS");

    cout << "\n\tRegister New Admin Account\n";
    cout << "******************************************\n\n";

    //do while loop to ensure no duplicate emails
    do {
        cout << "Enter Email:\t\t";
        cin.ignore();
        getline(cin, reg.email);

        for (auto element : admins) {
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

    //registering new admin to file
    ofstream myFile;
    myFile.open("admin.csv", ios::app);
    
    myFile << reg.email << ',' << reg.password << endl;
    myFile.close();


    admins.push_back(reg);

    return admins;
}

vector<Donor> admin_delete_donor(vector<Donor> donors) { //allows adminstrator to delete a donor account
    //declaring variables
    string inEmail;
    int position = 0;
    bool flag = 0;
    char choice;

    //taking user input
    cin.ignore();
    cout << "\nEnter Donor Email:\t";
    getline(cin, inEmail);
    
    //search and display donor info by given email
    for (auto element : donors) {
        if (element.email == inEmail) {
            system("CLS");
            cout << "\n\t\t" << element.name << "\n\n";
            cout << "\t" << element.email << endl;
            cout << "\t" << element.contactNumber << endl;
            cout << "\t" << element.streetAddress << ", " << element.suburb << ", " << element.city << endl;
            cout << "\t" << element.dobDay << "/" << element.dobMonth << "/" << element.dobYear << endl;
            flag = 1;
        }
        else {
            position++;
        }
    }

    //checks if donor with given email was found
    if (flag == 0) {
        cout << "\nDonor with this email not found.\n\n";
        system("PAUSE");
    }
    else {
        flag = 0;
        while (flag == 0) { //while loop to ensure valid y/n input
            cout << "\nDo you want to delete this user? (y/n)\t";
            cin >> choice;

            switch (tolower(choice)) {
            case 'y':

                while (flag == 0) { //second while loop to ensure valid y/n input, also gives admin another chance to make sure they're deleting the right account
                    cout << "\nWARNING: This will PERMANENTLY delete this Donor's record. Are you sure? (y/n)\t";
                    cin >> choice;

                    switch (tolower(choice)) {
                    case 'y':
                        //deletes donor record at position email was found
                        donors.erase(donors.begin() + position);
                        cout << "\nRecord Deleted.\n\n";
                        flag = 1;
                        system("PAUSE");
                        break;
                    case 'n':
                        cout << "\nReturning to menu.\n\n";
                        flag = 1;
                        system("PAUSE");
                        break;
                    default:
                        cout << "\nPlease enter a valid menu option.\n";
                    }
                }

                flag = 1;
                break;
            case 'n':
                cout << "\nReturning to menu.\n\n";
                flag = 1;
                system("PAUSE");
                break;
            default:
                cout << "\nPlease enter a valid menu option.\n";
            }
        }
    }

    //rewrite donor vector to file
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

vector<Recipient> admin_delete_recipient(vector<Recipient> recip) { //allows administrator to delete recipient account
    //declaring vairables
    string inEmail;
    int position = 0;
    bool flag = 0;
    char choice;

    //taking user input
    cin.ignore();
    cout << "\nEnter Recipient Email:\t";
    getline(cin, inEmail);

    //search and display recipient information by given email
    for (auto element : recip) {
        if (element.email == inEmail) {
            system("CLS");
            cout << "\n\t\t" << element.name << "\n\n";
            cout << "\t" << element.email << endl;
            cout << "\t" << element.contactNumber << endl;
            cout << "\t" << element.streetAddress << ", " << element.suburb << ", " << element.city << endl;
            flag = 1;
        }
        else {
            position++;
        }
    }

    //checks if recipient with given email was found
    if (flag == 0) {
        cout << "\nRecipient with this email not found.\n\n";
        system("PAUSE");
    }
    else {
        flag = 0;
        while (flag == 0) { //while loop to ensure valid y/n input
            cout << "\nDo you want to delete this user? (y/n)\t";
            cin >> choice;

            switch (tolower(choice)) {
            case 'y':

                while (flag == 0) { //second while loop to ensure valid y/n input, also gives admin another chance to make sure they're deleting the right account
                    cout << "\nWARNING: This will PERMANENTLY delete this Recipient's record. Are you sure? (y/n)\t";
                    cin >> choice;

                    switch (tolower(choice)) {
                    case 'y':
                        //deletes recipient record at position email was found
                        recip.erase(recip.begin() + position);
                        cout << "\nRecord Deleted.\n\n";
                        flag = 1;
                        system("PAUSE");
                        break;
                    case 'n':
                        cout << "\nReturning to menu.\n\n";
                        flag = 1;
                        system("PAUSE");
                        break;
                    default:
                        cout << "\nPlease enter a valid menu option.\n";
                    }
                }

                flag = 1;
                break;
            case 'n':
                cout << "\nReturning to menu.\n\n";
                flag = 1;
                system("PAUSE");
                break;
            default:
                cout << "\nPlease enter a valid menu option.\n";
            }
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

vector<Admin> admin_delete_admin(vector<Admin> admins, int p) { //allows administrator to delete another admin account
    //declaring variables
    string inEmail;
    int position = 0;
    bool flag = 0, flag2 = 0;
    char choice;

    //taking user input
    cin.ignore();
    cout << "\nEnter Admin Email:\t";
    getline(cin, inEmail);

    //search and display admin information based on given email
    for (auto element : admins) {
        if (element.email == inEmail) {
            if (element.email == admins[p].email) { //checks if given email is the same email admin is logged in with, to ensure the admin does not delete their own account
                cout << "\nYou cannot delete your own account!\n\n";
                system("PAUSE");
                flag2 = 1;
            }
            else {
                system("CLS");
                cout << "\t" << element.email << endl;
                flag = 1;
            }
            break;
        }
        else {
            position++;
        }
    }

    //checking if admin with given email was found
    if (flag == 0 && flag2 == 0) { //displays not found message only if email was not found. skips this message if email belongs to the admin currently logged in
        cout << "\nAdmin with this email not found.\n\n";
        system("PAUSE");
    }
    else if (flag == 1){
        flag = 0;
        while (flag == 0) { //while loop to ensure valid y/n input
            cout << "\nDo you want to delete this admin account? (y/n)\t";
            cin >> choice;

            switch (tolower(choice)) {
            case 'y':

                while (flag == 0) { //second while loop to ensure valid y/n input, also gives admin another chance to make sure they're deleting the right account
                    cout << "\nWARNING: This will PERMANENTLY delete this Admin Account. Are you sure? (y/n)\t";
                    cin >> choice;

                    switch (tolower(choice)) {
                    case 'y':
                        //deletes admin record at position email was found
                        admins.erase(admins.begin() + position);
                        cout << "\nAccount Deleted.\n\n";
                        flag = 1;
                        system("PAUSE");
                        break;
                    case 'n':
                        cout << "\nReturning to menu.\n\n";
                        flag = 1;
                        system("PAUSE");
                        break;
                    default:
                        cout << "\nPlease enter a valid menu option.\n";
                    }
                }

                flag = 1;
                break;
            case 'n':
                cout << "\nReturning to menu.\n\n";
                flag = 1;
                system("PAUSE");
                break;
            default:
                cout << "\nPlease enter a valid menu option.\n";
            }
        }
    }

    //writing admins back into file
    ofstream myFile;
    myFile.open("admin.csv", ios::out);

    for (auto element : admins) {
        myFile << element.email << ',';
        myFile << element.password << endl;
    }

    myFile.close();

    return admins;
}

OmniStruct admin_delete_user(vector<Admin> admins, vector<Donor> donors, vector<Recipient> recip, int p){ //menu screen for admin deleting user accounts
    //declaring variables
    bool flag = 0;
    int choice;

    //menu
    while (flag == 0) {
        system("CLS");
        cout << "\n\tDelete a User\n";
        cout << "*****************************\n\n";
        cout << "1. Delete Donor\n";
        cout << "2. Delete Recipient\n";
        cout << "3. Delete Admin\n";
        cout << "4. Exit\n\n";

        cout << "Enter Option Number:\t";
        cin >> choice;

        switch (choice) {
        case 1:
            donors = admin_delete_donor(donors);
            break;
        case 2:
            recip = admin_delete_recipient(recip);
            break;
        case 3:
            if (admins.size() == 1) { //checks to make sure there is more than one admin account. admin cannot delete last account.
                cout << "\nThis is the only Admin Account. You cannot delete it.\n\n";
                system("PAUSE");
            }
            else {
                admins = admin_delete_admin(admins, p);
            }
            break;
        case 4:
            flag = 1;
            break;
        default:
            cout << "\nPlease enter a valid menu option.\n";
            system("PAUSE");
        }
    }

    OmniStruct o = { donors, recip, admins };
    return o;
}

OmniStruct admin_landing_screen(vector<Admin> admins, vector<Donor> donors, vector<Recipient> recip, int p){ //menu screen for users logged in as administrators
    //declaring variables
    OmniStruct o = { donors, recip, admins };
    bool flag = 0;
    int choice;

    //menu
    while (flag == 0)
    {
        system("CLS");
        cout << "\n\t\t\t\t\tWELCOME ADMIN \n";
        cout << "************************************************************************************************************\n\n";

        cout << "1. View Donor's Report\n";
        cout << "2. View Recipient Report \n";
        cout << "3. Update Donor Blood Testing Report \n";
        cout << "4. Location Report\n";
        cout << "5. Blood Group Report\n";
        cout << "6. Register New Admin\n";
        cout << "7. Delete a User\n";
        cout << "8. Logout\n\n";
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
            admin_location_report();
            break;
        case 5:
            admin_blood_report();
            break;
        case 6:
            admins = admin_registration(admins);
            break;
        case 7:
            o = admin_delete_user(admins, donors, recip, p);
            admins = o.a;
            donors = o.d;
            recip = o.r;
            break;
        case 8:
            flag = 1;
            system("CLS");
            break;
        default:
            cout << "\nPlease enter a valid menu option.\n";
            system("PAUSE");
        }
    }

    o = { donors, recip, admins };
    return o;
}


OmniStruct admin_login(vector<Admin> admins, vector<Donor> donors, vector<Recipient> recip) { //allows user to log in as administrator
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
                    o = admin_landing_screen(admins, donors, recip, position);
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

    //reading files to vectors

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
        getline(linestream, item, ',');
        transactionD.contactNumber = item;

        //Int Variables
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
        getline(linestream, item, ',');
        transactionR.contactNumber = item;
        getline(linestream, item, ',');
        transactionR.registrationNumber = item;

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

    //declaring menu variables
    bool flag = 0;
    int choice;
    OmniStruct o;

    //menu
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
            cout << "\nThank you for using Capital Bloodbank!\n";
            return 0;
            break;
        default:
            cout << "\nPlease enter a valid menu option.\n";
            system("PAUSE");
            system("CLS");
        }
    }
}
