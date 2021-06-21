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
    cout << "******************************************************"<<endl;
    getline(cin, searchname);

    

        for (auto element : donors) {
            if (element.name == searchname) {
                system("CLS");
                cout << "-----------------------------------------------------" << endl;
                cout << "\t\t" << element.name << endl;
                cout << "-----------------------------------------------------" << endl;
                cout << "\nSTREET ADDRESS: " << element.streetAddress<<", "<<element.suburb<<", "<<element.city<<endl;
                cout << "\nEMAIL: " << element.email << endl;
                cout << "\nCONTACT NUMBER: " << element.contactNumber<< endl;
                cout << "\nBLOOD TYPE: " << element.bloodType << endl;
                flag = 1;
                system("PAUSE");
                            }

}

        if (flag == 0) {
            system("CLS");
            cout << "THERE ARE NO DONORS FOUND WITH THAT NAME"<<endl;
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
            cout<<"\t\t" << element.name<<endl;
            cout << "-----------------------------------------------------"<<endl;
            
            cout << "\nSTREET ADDRESS: " << element.streetAddress<<", "<<element.suburb<<", "<<element.city<<endl;
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

        cout << "THERE ARE NO DONORS THAT LIVE IN: " << searchcity<<endl;
        system("PAUSE");
       
    }


    
    system("CLS");

}



























vector<Recipient>* recipient_landing_screen(vector<Recipient>* recip) {
    int choice;
    bool flag = 0;

    while (flag == 0) {
        system("CLS");
        cout << "\n\t\t\t\t\tWELCOME RECIPIENT\n";
        cout << "************************************************************************************************************\n\n";

        cout << "1. Find potential donors by blood type \n";
        cout << "2. Find potential donors by city\n";
        cout << "3. Find donor contact info\n";
        cout << "4. log out\n";
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

string update_detail_string(string attribute) { //small function to update string variables in donor and recipient screens, so as to avoid repeat code
    string s;
    cin.ignore();
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

vector<Donor>* donor_manage_info(vector<Donor>* donors, int p) {
    int n = 0, choice;
    bool flag = 0;

    //display current info and menu. using auto for loop because no other direct method of pointing to the vector would work
    for (auto element : *donors) {
        if (n == p) {
            while (flag == 0) {
                system("CLS");
                cout << "\nYour Current Info:\n\n";
                cout << "1.\tName:\t\t" << element.name << endl;
                cout << "2.\tEmail:\t\t" << element.email << endl;
                cout << "3.\tPassword:\t" << element.password << endl;
                cout << "4.\tAddress:\t" << element.streetAddress << ", " << element.suburb << ", " << element.city << endl;
                cout << "5.\tContact Number:\t" << element.contactNumber << endl;
                cout << "6.\tEthnicity:\t" << element.ethnicity << endl;
                cout << "7.\tGender:\t\t" << element.gender << endl;
                cout << "8.\tDate of Birth:\t" << element.dobDay << "/" << element.dobMonth << "/" << element.dobYear << endl;
                cout << "9.\tExit\n\n";

                //taking user input for editing info
                cout << "Enter Menu Option to Edit Information:\t";
                cin >> choice;

                switch (choice) {
                case 1:
                    element.name = update_detail_string("Name");
                    break;
                case 2:
                    element.email = update_detail_string("Email");
                    break;
                case 3:
                    element.password = update_detail_string("Password");
                    break;
                case 4:
                    element.streetAddress = update_detail_string("Street Address");
                    element.suburb = update_detail_string("Suburb");
                    element.city = update_detail_string("City");
                    break;
                case 5:
                    element.contactNumber = update_detail_int("Contact Number");
                    break;
                case 6:
                    element.ethnicity = update_detail_string("Ethnicity");
                    break;
                case 7:
                    element.gender = update_detail_string("Gender");
                    break;
                case 8:
                    cout << "\nEnter new Date of Birth:\n";
                    element.dobDay = update_detail_int("Day");
                    element.dobMonth = update_detail_int("Month");
                    element.dobYear = update_detail_int("Year");
                    break;
                case 9:
                    flag = 1;
                    return donors;
                    break;
                default:
                    cout << "\nPlease enter a valid menu option.\n\n";
                    system("PAUSE");
                }
            }
        }

        n++;
    }

    return donors;
}

Booking* book_donation(Booking* b) {
    system("CLS");
    int day, hour, i;
    ofstream myFile;
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
        book_donation(b);
    }
    else {
        cout << "\nThe following times are available of July " << day << ":\n";
        //outputting available booking times
        for (i = 0; i < 248; i++) {
            if ((b+i)->day == day && (b+i)->booked == 0) {
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
            book_donation(b);
        }
        else {
            //finding record to edit
            for (i = 0; i < 248; i++) {
                if ((b + i)->day == day && (b + i)->time == hour) {
                    if ((b + i)->booked == 0) { //Changes booked value in the timeslot to true.
                        (b + i)->booked = 1;
                        cout << "\nSuccessfully Booked for " << hour << ":00 on July " << day << endl;

                        //rewriting bookings array to bookings.csv
                        myFile.open("bookings.csv", ios::out);
                        for (int j = 0; j < 248; j++) {
                            myFile << (b + j)->day << ',' << (b + j)->time << ',' << (b + j)->booked << endl;
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

    system("PAUSE");
    system("CLS");
    return b;
}

vector<Donor>* donor_landing_screen(vector<Donor>* donors, int p, Booking* b) {
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
            donor_manage_info(donors, p);
            break;
        case 4:
            book_donation(b);
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

vector<Donor>* donor_login(vector<Donor>* donors, Booking* b) {
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
    for (auto element : *donors) {
        if (login == element.email) {
            Eflag = 1;
            pword = element.password;
            cin.ignore();
            while (attempt > 0) {
                cout << "\nEnter Password:\t";
                getline(cin, login);

                if (login == pword) {
                    donor_landing_screen(donors, position, b);
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

vector<Donor>* donor_registration(vector<Donor>* donors) {
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

    (*donors).push_back(reg);

    cout << "\nSuccessfully registered " << reg.name << " as Donor.\n\n";

    system("PAUSE");
    system("CLS");

    return donors;
}

vector<Recipient>* recipient_login(vector<Recipient>* recip) {
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
    for (auto element : *recip) {
        if (login == element.email) {
            Eflag = 1;
            pword = element.password;
            cin.ignore();
            while (attempt > 0) {
                cout << "\nEnter Password:\t";
                getline(cin, login);

                if (login == pword) {
                    recipient_landing_screen(recip);
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
            cout << "\nREGISTRATION NUMBER: " << element.registrationNumber<<endl;




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
    cout << "\nENTER DONORS NAME TO FIND REPORT" << endl;
    cout << "******************************************************" << endl;
    getline(cin, searchname);
    system("CLS");


    for (auto element : donors) {
        if (element.name == searchname) {

            cout << "-----------------------------------------------------" << endl;
            cout << "\t\t" << element.name << endl;
            cout << "-----------------------------------------------------" << endl;
            cout << "\nBLOOD TYPE: " << element.bloodType<<endl;
            cout << "\nSTREET ADDRESS: " << element.streetAddress<<endl;
            cout << "\nEMAIL: " << element.email << endl;
            cout << "\nCONTACT NUMBER: " << element.contactNumber << endl;
            cout << "\nDATE OF BIRTH: " << element.dobDay << "/" << element.dobMonth << "/" << element.dobYear<<endl;
            cout << "\nGENDER: " << element.gender << endl;
            cout << "\nETHNICITY: " << element.ethnicity << endl;


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


void admin_landing_screen()
{
    
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
        cout << "4. Logout\n";
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















int main()
{
    //reading files to vectors
    //declaring necessary variables
    vector<Donor> donors;
    vector<Recipient> recipients;
    Booking bookings[248];
    ifstream myFile;
    Donor transactionD;
    Recipient transactionR;
    Booking transactionB;
    string line;

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

        //Add structure to array 'bookings'.
        bookings[linenum] = transactionB;
        linenum ++;
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
            donor_registration(ptrdonors);
            break;
        case 4:
            donor_login(ptrdonors, ptrbookings);
            break;
        case 5:
            recipient_registration(ptrrecipients);
            break;
        case 6:
            recipient_login(ptrrecipients);
            break;
        case 7:
            admin_landing_screen();
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