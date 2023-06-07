/*****************************************************************************
                             Workshop - 2
Full Name  : Gleison Vieira Dutra
Student ID#: 119237220

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
*****************************************************************************/
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
using namespace std;
#include "Customer.h"
#include "Tools.h"
#include<string.h>

namespace sdds {

    // complete

    void read(char* str, int len) {  // Fully provided
        if (cin.peek() == '\n') {
            cin.ignore();
        }
        cin.getline(str, len);
    }

    
    // complete
   
   // The below function, EmptyRecord will set customer data members to an empty state.
    void EmptyRecord(Customers& custumer)
    {
        custumer.likes_count = 0;
        custumer.replies_count = 0;
        custumer.retweets_count = 0;
        custumer.share_videos = 0;
        custumer.user_name[0] = '\0';
        
        return;
    }

    // The below function will set CustomersRecord data members to an empty state.
    void EmptyRecord(CustomersRecord& customerRec)
    {

        customerRec.ptr_rec = nullptr;

        return;
    }
    
    // The function below will request from the user the 'user name' of the twitter account, if a valid user name is entered, the function will ask the rest of the customer's information.
    bool read(Customers& rec)
    {
        bool check = true;

        cout << " Enter User name: ";
        read(rec.user_name, 21);

        if (rec.user_name[0] == '\0')
        {
            check = false;
        }
        else
        {
            cout << " Enter likes_count: ";
            cin >> rec.likes_count;

            cout << " Enter retweets_count: ";
            cin >> rec.retweets_count;

            cout << " Enter replies_count: ";
            cin >> rec.replies_count;
            
            cout << " Enter share videos (y/n): ";
            cin >> rec.share_videos;
        }

        return check;
    }
        
    //This function will add the customer entered by the user in the dynamic array of customers.
    void addCustomer(CustomersRecord& t_rec, const Customers& c_rec)
    {
        
        ++t_rec.noOfRecords;
        allocation(t_rec);

        t_rec.ptr_rec[t_rec.noOfRecords - 1].likes_count = c_rec.likes_count;
        t_rec.ptr_rec[t_rec.noOfRecords - 1].retweets_count = c_rec.retweets_count;
        t_rec.ptr_rec[t_rec.noOfRecords - 1].replies_count = c_rec.replies_count;

        t_rec.ptr_rec[t_rec.noOfRecords - 1].share_videos = c_rec.share_videos;
        strcpy(t_rec.ptr_rec[t_rec.noOfRecords - 1].user_name, c_rec.user_name);
        
        return;
    }
       
    //Each time that the function addCustomer is called to add a customer to the records, this function will increase the size of the array by one.
    void allocation(CustomersRecord& t_rec)
    {
        if (t_rec.noOfRecords == 1)
        {
            t_rec.ptr_rec = new Customers[t_rec.noOfRecords];
        }
        else
        {
            CustomersRecord temp_rec;
            EmptyRecord(temp_rec);
            
            temp_rec.ptr_rec = new Customers[t_rec.noOfRecords - 1];

            for (int i = 0; i < t_rec.noOfRecords - 1; i++)
            {
                temp_rec.ptr_rec[i].likes_count = t_rec.ptr_rec[i].likes_count;
                temp_rec.ptr_rec[i].replies_count = t_rec.ptr_rec[i].replies_count;
                temp_rec.ptr_rec[i].retweets_count = t_rec.ptr_rec[i].retweets_count;
                temp_rec.ptr_rec[i].share_videos = t_rec.ptr_rec[i].share_videos;
                strcpy(temp_rec.ptr_rec[i].user_name, t_rec.ptr_rec[i].user_name);
            }
            delete[] t_rec.ptr_rec;
            t_rec.ptr_rec = new Customers[t_rec.noOfRecords];

            for (int i = 0; i < t_rec.noOfRecords - 1; i++)
            {
                t_rec.ptr_rec[i].likes_count = temp_rec.ptr_rec[i].likes_count;
                t_rec.ptr_rec[i].replies_count = temp_rec.ptr_rec[i].replies_count;
                t_rec.ptr_rec[i].retweets_count = temp_rec.ptr_rec[i].retweets_count;
                t_rec.ptr_rec[i].share_videos = temp_rec.ptr_rec[i].share_videos;
                strcpy(t_rec.ptr_rec[i].user_name, temp_rec.ptr_rec[i].user_name);
            }

            //for (int i = 0; i < t_rec.noOfRecords - 1; i++)
            //{
            //    delete temp_rec.ptr_rec[i].user_name;

            //}

            delete[] temp_rec.ptr_rec;
            //delete[] t_rec.ptr_rec;
        }

        return;
    }

    //This function will display user information on screen
    void display(const Customers& c_rec)
    {
        
        cout << c_rec.user_name << ", "
            << c_rec.likes_count << ", "
            << c_rec.retweets_count << ", "
            << c_rec.replies_count << ", "
            << c_rec.share_videos
            << endl << endl;

        return;
    }

    //Displays the row number for each user. 
    void display(const CustomersRecord& t_rec)
    {

        for (int i = 0; i < t_rec.noOfRecords; i++)
        {
            cout << i + 1 << ". ";
            display(t_rec.ptr_rec[i]);
        }
    }

  }

