/*****************************************************************************
                             Workshop - 2
Full Name  : Gleison Vieira Dutra
Student ID#: 119237220

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
*****************************************************************************/

#ifndef SDDS_CUSTOMER_H_
#define SDDS_CUSTOMER_H_

namespace sdds {

    struct Customers {
        char user_name[21];
        int retweets_count;;
        int likes_count;
        int replies_count;
        char share_videos;
    };

    struct CustomersRecord {
        Customers* ptr_rec;  // Dynamically holds the customers' tweets' report.
        int noOfRecords = 0;
    };
    
       
    void read(char* str, int len);
   
    // to be completed

    // The below function, EmptyRecord will set customer data members to an empty state.
    void EmptyRecord(Customers& custumer);
    
    // The below function, EmptyRecord will set customer **record** data members to an empty state.
    void EmptyRecord(CustomersRecord& customerRec);

    // The function below will request from the user the 'user name' of the twitter account, if a valid user name is entered, the function will ask the rest of the customer's information.
    bool read(Customers& rec);
 
    //This function will add the customer entered by the user in the dynamic array of customers.
    void addCustomer(CustomersRecord& t_rec, const Customers& c_rec);
 
    //Each time that the function addCustomer is called to add a customer to the records, this function will increase the size of the array by one.
    void allocation(CustomersRecord& t_rec);

    //This function will display user information on screen
    void display(const Customers& c_rec);

    //Displays the row number for each user. 
    void display(const CustomersRecord& t_rec);
}

#endif 
