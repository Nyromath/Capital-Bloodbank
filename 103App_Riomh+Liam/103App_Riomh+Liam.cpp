#include <iostream>
#include <fstream>
#include <cmath>
#include <ctime>
#include <string>
#include <stdlib.h>
using namespace std;

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
    cout << "\tBlood donation not only makes the receiver’s life good but also helps the donor to maintain good health.\n";
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
            intro_function();
            break;
        case 2:
            display_contact_info();
            break;
        case 3:
            break;
        case 4:
            donor_landing_screen();
            break;
        case 5:
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