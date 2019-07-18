/*               ~~~~~~~~~~~~~DESIGNING AN OBJECT ORIENTED PARKING LOT~~~~~~~~~~~~~

************************************************************************************************************************************************************
For our purposes right now, we’ll make the following assumptions.
1) The parking lot can park motorcycles, cars, and buses.
2) It can park  a total of 20 cars, 10 buses and 80 two wheelers(scooties/bikes).
3) A typical car needs a parking space of 150 square feet, bus needs a parking space of 800 square feet and a 2 wheeler needs a parking space of 20 feet.
4) (20*150) + (10*800) + (80*20) = 3000+8000+1600 = 12600 square feet.
5) For easy parking and to maintain a good gap between vehicles, let the total parking space be 13,500 square feet.
6) The user exits with his/her own vehicle.
************************************************************************************************************************************************************

Done by- Akansha Agarwal
Date:20th March,2019

************************************************************************************************************************************************************ */

#include <iostream>
#include <conio.h>
#include <stdlib.h>
using namespace std;
int tcars=20,tbuses=10,t2wheelers=80; // stores total number of cars,buses and 2 wheelers parked currently
int choice;
int feedback();
int exit();//function to exit once you have successfully entered the parking lot with a vehicle
int main()
{
    system("CLS");
    entry:
    cout<<("*******************************************  W E L C O M E  T O   C M R I T  *******************************************")<<endl;
    cout<<("------------------------------------------------------------------------------------------------------------------------")<<endl;

    cout<<("Please enter which vehicle you want to park")<<endl;
    cout<<("1]A bus \n2]A car \n3]A two wheeler")<<endl;
    int n;// stores the equivalent number which corresponds to the type of vehicle being parked
    cin>>n;
    if(n!= 1 && n!= 2 && n!= 3)
    {
        cout<<("------------------------------------------------------------------------------------------------------------------------")<<endl;
        cout<<"Invalid entry!Please try again with valid entry...!!"<<endl;
        cout<<("------------------------------------------------------------------------------------------------------------------------")<<endl;
        label2:cout<<("Please enter \n1]For exiting\n2]For re-entry to the parking lot.\n3]To go to the feedback section for helping us improve ourselves!")<<endl;
        cin>>choice;
        switch (choice)
        {
            case 1:cout<<"Thank you! for visiting, hope to see you again...!!!!"<<endl;
                   cout<<("------------------------------------------------------------------------------------------------------------------------")<<endl;
                   return 0;
            case 2:system("CLS");
                   goto entry;
                   break;
            case 3:feedback();
                   break;
            default:cout<<"Invalid entry!Please try again with valid entry...!!!"<<endl;
                    cout<<("------------------------------------------------------------------------------------------------------------------------")<<endl;
                   break;
        }
    }
    else
    {
        switch(n)
        {
            case 1:cout<<("------------------------------------------------------------------------------------------------------------------------")<<endl;
                   cout<<"You have decided to park a bus."<<endl;
                   if(tbuses==0)
                   {
                       cout<<"Sorry,the parking space for buses is full...!"<<endl;
                       goto label2;
                   }
                   else
                   {
                       tbuses--;
                       cout<<("------------------------------------------------------------------------------------------------------------------------")<<endl;
                       cout<<"The number of cars already parked ="<<20-tcars<<endl;
                       cout<<"The number of cars that can be parked ="<<tcars<<endl;
                       cout<<"The number of buses already parked ="<<10-tbuses<<endl;
                       cout<<"The number of buses that can be parked ="<<tbuses<<endl;
                       cout<<"The number of two-wheelers already parked ="<<80-t2wheelers<<endl;
                       cout<<"The number of two-wheelers that can be parked ="<<t2wheelers<<endl;
                       cout<<("------------------------------------------------------------------------------------------------------------------------")<<endl;
                       exit();
                   }
                   break;
            case 2:cout<<("------------------------------------------------------------------------------------------------------------------------")<<endl;
                   cout<<"You have decided to park a car."<<endl;
                   if(tcars==0)
                   {
                       cout<<"Sorry,the parking space for buses is full...!"<<endl;
                       goto label2;
                   }
                   else
                   {
                       tcars--;
                       cout<<("------------------------------------------------------------------------------------------------------------------------")<<endl;
                       cout<<"The number of cars already parked ="<<20-tcars<<endl;
                       cout<<"The number of cars that can be parked ="<<tcars<<endl;
                       cout<<"The number of buses already parked ="<<10-tbuses<<endl;
                       cout<<"The number of buses that can be parked ="<<tbuses<<endl;
                       cout<<"The number of two-wheelers already parked ="<<80-t2wheelers<<endl;
                       cout<<("------------------------------------------------------------------------------------------------------------------------")<<endl;
                       exit();
                   }
                   break;
            case 3:cout<<("------------------------------------------------------------------------------------------------------------------------")<<endl;
                   cout<<"You have decided to park a two-wheeler."<<endl;
                   if(t2wheelers==0)
                   {
                       cout<<"Sorry,the parking space for two-wheelers is full...!"<<endl;
                       goto label2;
                   }
                   else
                   {
                       t2wheelers--;
                       cout<<("------------------------------------------------------------------------------------------------------------------------")<<endl;
                       cout<<"The number of cars already parked ="<<20-tcars<<endl;
                       cout<<"The number of cars that can be parked ="<<tcars<<endl;
                       cout<<"The number of buses already parked ="<<10-tbuses<<endl;
                       cout<<"The number of buses that can be parked ="<<tbuses<<endl;
                       cout<<"The number of two-wheelers already parked ="<<80-t2wheelers<<endl;
                       cout<<"The number of two-wheelers that can be parked ="<<t2wheelers<<endl;
                       cout<<("------------------------------------------------------------------------------------------------------------------------")<<endl;
                       exit();
                   }
                   break;
        }
    }
    return 0;
}
int feedback()
{
    cout<<("------------------------------------------------------------------------------------------------------------------------")<<endl;
    cout<<("*******************************  W E L C O M E  T O  F E E D B A C K  S E C T I O N  *******************************")<<endl;
    cout<<("------------------------------------------------------------------------------------------------------------------------")<<endl;
    cout<<("Please enter \n1]Good maintenance,Keep it up!\n2]Cleanliness needs to improved!!!\n3]Others... ")<<endl;
    int n1;
    string str;
    cin>>n1;
    switch(n1)
    {
        case 1:cout<<"Thank you!!!"<<endl;
               break;
        case 2:cout<<"Sorry for the inconvenience caused... !!!!Will definitely look into the matter...!!!"<<endl;
               break;
        case 3:cout<<"Please tell us how we can improve ourselves"<<endl;
               cin>>str;
               cout<<"Thank you for your valuable suggestion!!!!Will definitely look into the matter...!!!"<<endl;
               break;
        default:cout<<"Invalid entry!Please try again with valid entry...!!!"<<endl;
                break;
    }
    return 0;
}
int exit()//function to exit once you have successfully entered the parking lot with a vehicle
{
    cout<<("------------------------------------------------------------------------------------------------------------------------")<<endl;
    cout<<"How do you want to exit the parking lot????"<<endl;//assuming that user is kind enough to exit with his/her own vehicle!!!!
    cout<<"1]The dashing car,with which I entered the campus!!!"<<endl;
    cout<<"2]The fast two wheeler,with which I entered the campus!!!"<<endl;
    cout<<"3]The beast(bus),with which I entered the campus!!!"<<endl;
    cout<<"4]NO, I want to re-enter the parking lot!!!"<<endl;
    int n3;
    cin>>n3;
    switch(n3)
    {
        case 1:if(20-tcars !=0)
                {
                    tcars++;
                    cout<<("------------------------------------------------------------------------------------------------------------------------")<<endl;
                    cout<<"The number of cars already parked ="<<20-tcars<<endl;
                    cout<<"The number of cars that can be parked ="<<tcars<<endl;
                    cout<<"The number of buses already parked ="<<10-tbuses<<endl;
                    cout<<"The number of buses that can be parked ="<<tbuses<<endl;
                    cout<<"The number of two-wheelers already parked ="<<80-t2wheelers<<endl;
                    cout<<"The number of two-wheelers that can be parked ="<<t2wheelers<<endl;
                    cout<<"Thank you! for visiting, hope to see you again...!!!!"<<endl;
                    cout<<("------------------------------------------------------------------------------------------------------------------------")<<endl;
                }
                else
                {
                    cout<<"UH-OH there is currently no car parked in the parking layout...!!Please try exiting with your own vehicle!!!"<<endl;
                    exit();
                }
                break;
        case 3:if(10-tbuses!=0)
                {
                    tbuses++;
                    cout<<("------------------------------------------------------------------------------------------------------------------------")<<endl;
                    cout<<"The number of cars already parked ="<<20-tcars<<endl;
                    cout<<"The number of cars that can be parked ="<<tcars<<endl;
                    cout<<"The number of buses already parked ="<<10-tbuses<<endl;
                    cout<<"The number of buses that can be parked ="<<tbuses<<endl;
                    cout<<"The number of two-wheelers already parked ="<<80-t2wheelers<<endl;
                    cout<<"The number of two-wheelers that can be parked ="<<t2wheelers<<endl;
                    cout<<"Thank you! for visiting, hope to see you again...!!!!"<<endl;
                    cout<<("------------------------------------------------------------------------------------------------------------------------")<<endl;
                }
                else
                {
                     cout<<"UH-OH there is currently no bus parked in the parking layout...!!Please try exiting with your own vehicle!!!"<<endl;
                     exit();
                }
                break;
        case 2:if(80-t2wheelers!=0)
               {
                    t2wheelers++;
                    cout<<("------------------------------------------------------------------------------------------------------------------------")<<endl;
                    cout<<"The number of cars already parked ="<<20-tcars<<endl;
                    cout<<"The number of cars that can be parked ="<<tcars<<endl;
                    cout<<"The number of buses already parked ="<<10-tbuses<<endl;
                    cout<<"The number of buses that can be parked ="<<tbuses<<endl;
                    cout<<"The number of two-wheelers already parked ="<<80-t2wheelers<<endl;
                    cout<<"The number of two-wheelers that can be parked ="<<t2wheelers<<endl;
                    cout<<"Thank you! for visiting, hope to see you again...!!!!"<<endl;
                    cout<<("------------------------------------------------------------------------------------------------------------------------")<<endl;
               }
               else
               {
                    cout<<"UH-OH there is currently no two-wheeler parked in the parking layout...!!Please try exiting with your own vehicle!!!"<<endl;
                    exit();
               }
               break;
        case 4:main();
               break;
        default:cout<<"Invalid entry!Please try again with valid entry...!!!"<<endl;
                break;
    }
    return 0;
}

