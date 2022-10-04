/* *
 * 
 * PROJECT NAME : TELEPHONE DIRECTORY/ PHONE BOOK
 * In the project we create records and display them.
 * We can search a particular record in the directory. 
 * We can also insert a new records in the directory.
 * We can delete a existing record in the directory.
 * We can show the number of records present in the directory.   
 * 
 * */
 
 
 /* *
 * 
 * This project is designed by 
 * GROUP NO. - 6
 * Roll No. 2464 - Sakshi Thawal
 * Roll No. 2467 - Vaishnavi Sinha
 * Roll No. 2468 - Vikusunuo Natso
 * Roll No. 2470 - Vidhya Waghmare
 * 
 * */
 
 
 /* *
  * Time Complexities of function :
  * Creating records - O(1)
  * Displaying records - O(n)
  * Searching records - O(n)
  * Inserting records - O(n)
  * Deleting records - O(n)
  * Updating record - O(n)
  * Sorting records - O(n)
  * 
  * */



#include <iostream>
#include <string>
#include <windows.h>

using namespace std;

class Node
{    
    public :
    int id;
    string name;
    string email;
    long int tele_no;
    Node *next;
    
    Node(int id, string name, long int tele_no, string email)   // Constructor for class Node
    {
        this->id = id;
        this->name = name;
        this->tele_no = tele_no;
        this->email = email;
    }
    
    //friend class PhoneDirectory;
};

class PhoneDirectory
{
    //PhoneDirectory class for adding functions 
    
    Node *head;
    Node *tail;
    
    public :
    
    PhoneDirectory()
    {
        head = NULL;          // Constructor of PhoneDirectory class
    }
    
    // Function declaration
    
    void create_record();
    void display_records();
    Node* search_record();
    Node* search_record(string n);
    void insert_record();
    void sorting();
    void delete_record();
    int count_records();
    int count_records(Node *n);
    void update_record();    
};

void PhoneDirectory :: create_record()
{
    // Function for creating records.
    // Time complexity of this function is O(1)
    
    int create_id;
    string create_name;
    long int create_tele_no;
    string create_mail;
    int choice;
    
    do
    {
        cout << "Enter the id (4 digits) : ";
        cin >> create_id;
        cout << "Enter the name : ";
        cin >> create_name;
        cout << "Enter the telephone number : ";
        cin >> create_tele_no;
        cout << "Enter the mail id : ";
        cin >> create_mail;
        
        Node *new_node = new Node(create_id,create_name,create_tele_no,create_mail);
        // new_node->id = create_id;
        // new_node->name = create_name; 
        // new_node->tele_no = create_tele_no;
        // new_node->email = create_mail; 
        // new_node->next = NULL;
        
        if(head == NULL)
        {
            head = tail = new_node;
        }
        else
        {
            // Node *temp = head;
            // while(temp->next!=NULL)
            // {
            //     temp = temp->next;
            // }
            // temp->next = new_node;


            tail->next = new_node;
            tail = new_node;
        }
        cout << "You want to add one more record? (0 or 1) : ";
        cin >> choice;
            
    }while(choice==1);
    
    //sorting();
}

void PhoneDirectory :: display_records()
{
    // Function for displaying records.
    
    sorting();
    
    Node *temp = head;
    while(temp!=NULL)
    {
        cout << temp->name << " \t\t\t " << temp->id << " \t\t\t " << temp->tele_no << " \t\t\t " << temp->email << endl;
        cout << "--------------------------------------------------------------------------------------------------------------\n";
        temp = temp->next;
    }    
}

Node* PhoneDirectory :: search_record()
{
    
     /* *
      * 
      * Function for searching records.
      * It searches by name
      * If given name and directory name are equal then it return address of that node.
      * Else it return the NUll value 
      * 
      * */
    
    string search_name;
    cout << "\nEnter the name you want to search : ";
    cin >> search_name;

    
    Node *temp = head;
    while(temp!=NULL)
    {
        if(search_name == temp->name)
        {
            return temp;
        }
        else
        {
            temp = temp->next;
        }
    }
    return NULL;
}

Node* PhoneDirectory :: search_record(string search_name2)
{
    /* *
     * 
     * This function is overloaded function 
     * It has string parameter.
     * It is used in a upadte_record function to updating the particular name.
     * 
     * */
    
    Node *temp = head;
    while(temp!=NULL)
    {
        if(search_name2==temp->name)
        {
            return temp;
        }
        else
        {
            temp = temp->next;
        }
    }
    return NULL;
}

int PhoneDirectory :: count_records()
{
    /* * 
     * 
     * Function for counting the number of records present in the directory.
     * It return the integer value.
     * 
     * */
    
    int count = 0;
    Node *temp = head;
    if(head==NULL)
    {
        return 0;      // If head is NULL then it return 0 i.e. empty directory.
    }
    else
    {
        while(temp!=NULL)
        {
            temp = temp->next;
            count++;
        }
        return count;
    }    
}

int PhoneDirectory :: count_records(Node *n)
{
    /* *
     * 
     * This function is overloaded finction.
     * It return integer value.
     * It has Node as a parameter.
     * It return the number of records till that Node.
     * 
     * */
    
    int count = 0;
    Node *temp = head;
    if(head==NULL)
    {
        return 0;
    }
    else
    {
        while(temp!=n)
        {
            temp = temp->next;
            count++;
        }
        return count;
    }    
}

void PhoneDirectory :: update_record()
{
    //This function is for updating the existing record.
    
    int update_id;
    string update_name;
    long int update_tele_no;
    string update_mail;
    int choice;
    
    cout << "\nEnter the name you want to update : ";
    cin >> update_name;
    
    Node *temp;
    temp = search_record(update_name);   // Searching the name and it is present then store the address of that node in temp
   
    
    if(temp!=NULL)
    {
        cout << "\nThis name is already present. You want to update? ( 0 or 1) : ";
        cin >> choice;
        if(choice==1)    // name is already present and want to update it.
        {
            
            cout << "Enter the id (4 digits) : ";
            cin >> update_id;
            cout << "Enter the name : ";
            cin >> update_name;
            cout << "Enter the telephone number : ";
            cin >> update_tele_no;
            cout << "Enter the mail id : ";
            cin >> update_mail;
            
            temp->name = update_name;
            temp->id = update_id;
            temp->tele_no = update_tele_no;
            temp->email = update_mail;
            
        }
        else
        {
            cout << "\nRecord is not updated.\n";
        }

        cout<<"\n\n\n\tUpdating...";
        for(int i=1;i<=5;i++)
        {
            Sleep(500);
            cout<<".";
        }
        cout << "\nRecord updated.\n" << endl;
    }
    else
    {
        cout << "\nName not found\n";
    }
}

void PhoneDirectory :: delete_record()
{
    // This function is for deleting the particular record of the directory.
    
    string delete_name;
    cout << "\nEnter the name you want to delete : ";
    cin >> delete_name;
    
    Node *temp;
    // temp = search_record(delete_name);  // Searchinf the name.
    
    // if(temp!=NULL)
    // {        
        if(head==NULL)
        {
            cout << "\nDirectory is empty.";
        }
        else if(temp==head)  // Deleting fisrt record.
        {
            Node *temp2 = head;
            head = head->next;
            delete temp2;
        }
        else if(count_records(temp)==count_records())  // Deleteing last record.
        {
            Node *current;
            Node *previous;
            current = head;
            while(current->next!=NULL)
            {
                previous = current;
                current = current->next;
            }
            current = previous;
            previous->next = NULL;
            delete current;            
        }
        else
        {
            // Deleting the record between first and last.
            
            Node *current;
            Node *previous;
            current = head;
            
            for(int i=0;i<count_records(temp);i++)  // for loop till that record comes 
            {
              previous = current;
              current = current->next;
            }
            
            previous->next = current->next;
        }
        
        cout<<"\n\n\n\tDeleting...";  
        for(int i=1;i<=5;i++)
        {
            Sleep(500);
            cout<<".";
        }
        cout << endl;
        cout << "\n*************Record deleted.*************\n";
    // }
    // else
    // {
    //     cout << "\nName not found.\n";  // No records found.
    // }
}

void PhoneDirectory :: insert_record()
{
    // This function is for inserting the record.
    
    sorting();
    int insert_id;
    string insert_name;
    long int insert_tele_no;
    string insert_mail;
    
    // Taking details of inserting record from user 
    
    cout << "\nEnter the name you want to insert : ";
    cin >> insert_name;
    cout << "Enter the id you want to insert : ";
    cin >> insert_id;
    cout << "Enter the telephone number you want to insert : ";
    cin >> insert_tele_no;
    cout << "Enter the mail id you want to insert : ";
    cin >> insert_mail;
    
    Node *temp = new Node(insert_id,insert_name,insert_tele_no,insert_mail);
    // temp->name = insert_name;
    // temp->id =  insert_id;
    // temp->tele_no = insert_tele_no;
    // temp->email = insert_mail;
    // temp->next = NULL;
    
    if(head == NULL)
    {
        head = NULL;
    }
    else
    {
        Node *temphead = head;
        Node *previous = NULL;
        while(temphead!=NULL && insert_name > temphead->name)
        {
            previous = temphead;
            temphead = temphead->next;
        }
        if(previous == NULL) 
        {
            head = temp;
            temp->next = temphead;
        }
        else if(temphead == NULL)
        {
            previous->next = temp;
        }
        else
        {
            previous->next = temp;
            temp->next = temphead;
        }
    }
}

void PhoneDirectory :: sorting()
{
    // This function is for sorting the directory.
    
    int sort_id;
    string sort_name;
    long int sort_tele_no;
    string sort_email;
    
    Node *temphead = head;
    //temphead = head;
    
    for(int i = 0; i<count_records() ;i++)
    {
        while(temphead->next!=NULL)
        {
            if(temphead->name > temphead->next->name)
            {
                sort_name = temphead->name;
                temphead->name = temphead->next->name;    // Swapping the names. 
                temphead->next->name = sort_name;
                
                sort_id = temphead->id;
                temphead->id = temphead->next->id;     // Swapping the id's.
                temphead->next->id = sort_id;
                
                sort_tele_no = temphead->tele_no;
                temphead->tele_no = temphead->next->tele_no;     // Swapping the telephone numbers.
                temphead->next->tele_no = sort_tele_no;
                
                sort_email = temphead->email;
                temphead->email = temphead->next->email;     // Swapping the email id's.
                temphead->next->email = sort_email;
            }
            
            temphead = temphead->next;     // Pointing to next record
        }
        
        temphead = head;
    }
    
}

int main()
{
    // Main function
    
	PhoneDirectory *ph = new PhoneDirectory();  
    int choice = 0;
    Node *temp;
    do
    {
        cout << "**********MENU**********" << endl;
        cout << "1.CREATE RECORDS" << endl;
        cout << "2.DISPLAY RECORDS" << endl;
        cout << "3.SEARCH RECORD" << endl;
        cout << "4.INSERT RECORD" << endl;        // Menu for telephone directory.
        cout << "5.DELETE RECORDS" << endl;
        cout << "6.TOTAL RECORDS" << endl;
        cout << "7.UPDATE RECORD" << endl;
        cout << "8.SORT RECORDS" << endl;
        cout << "9.EXIT" << endl;
        
        cout << "Enter the choice : ";
        cin >> choice;
        
        switch(choice)
        {
            // Creating the records
            case 1 : ph->create_record();   
            break;
            
            // Displaying the records
            case 2 : cout<<"\n\n\n\tDisplaying...";
                     for(int i=1;i<=5;i++)
                     {
                        Sleep(500);
                        cout<<".";
                     }
                     cout << endl;
                     cout << "\n************************************************************************************************************\n";
                     cout << "\t\t\t DISPLAYING RECORDS \t\t\t\t\t\n";
                     cout << "\n************************************************************************************************************\n";
                     cout << "\nNAME \t\t\t ID \t\t\t TELEPHONE NO. \t\t\t EMAIL ID\n";
                     cout << "--------------------------------------------------------------------------------------------------------------\n";
                     ph->display_records();
            break;
            
            // Searching the records
            case 3 : temp = ph->search_record();
                     cout<<"\n\n\n\tSearching...";
                     for(int i=1;i<=5;i++)
                     {
                        Sleep(500);
                        cout<<".";
                     }
                     cout << endl;
                         if(temp!=NULL)
                         {
                            cout << "\n************************************************************************************************************\n";
                            cout << "\t\t\t RECORD FOUND \t\t\t\t\t\n";
                            cout << "\n************************************************************************************************************\n";
                            cout << "\nNAME \t\t\t ID \t\t\t TELEPHONE NO. \t\t\t EMAIL ID\n";
                            cout << "--------------------------------------------------------------------------------------------------------------\n";
                            cout << temp->name << " \t\t\t " << temp->id << " \t\t\t " << temp->tele_no << " \t\t\t " << temp->email << endl;
                            cout << "--------------------------------------------------------------------------------------------------------------\n";
                         }
                         else
                         {
                            cout << "\nNo records found! Sorry.\n";
                         }
            break;
            
            // Inserting the records
            case 4 : ph->insert_record();
                     cout<<"\n\n\n\tInserting...";
                     for(int i=1;i<=5;i++)
                     {
                        Sleep(500);
                        cout<<".";
                     }
                     cout << endl;
                     cout << "\n****************Record inserted.******************\n";
            break;
            
            // Deleting the records
            case 5 : ph->delete_record();
            break;
            
            // Counting the records
            case 6 : if(ph->count_records()==0)
                        {
                            cout << "\nDirectory is empty";
                        }
                        else
                        {
                            cout << "\nThere are total " << ph->count_records() << " records.\n";
                        }
            break;
            
            // Updating the records
            case 7 : ph->update_record();
            break;
            
            // Sorting the records
            case 8 : ph->sorting();
            break;
            
            // Exit
            case 9 : cout << "THANK YOU!" << endl;
            break;
            
            default : cout << "\nWRONG CHOICE" << endl;
        }
    }while(choice!=9);  // Repeat till choice is not equal to 9
   
    return 0;
}

/* *
 * OUTPUT :
 * 
 **********MENU**********
1.CREATE RECORDS
2.DISPLAY RECORDS
3.SEARCH RECORD
4.INSERT RECORD
5.DELETE RECORDS
6.TOTAL RECORDS
7.UPDATE RECORD
8.SORT RECORDS
9.EXIT
Enter the choice : 1
Enter the id (4 digits) : 2345
Enter the name : Aneri
Enter the telephone number : 243567
Enter the mail id : aneri@gmail.com
You want to add one more record? (0 or 1) : 1
Enter the id (4 digits) : 4567
Enter the name : Myra
Enter the telephone number : 283722
Enter the mail id : myra@gmail.com
You want to add one more record? (0 or 1) : 1
Enter the id (4 digits) : 2876
Enter the name : Ashley
Enter the telephone number : 299125
Enter the mail id : ashley@yahoo.com
You want to add one more record? (0 or 1) : 1
Enter the id (4 digits) : 4356
Enter the name : Elena
Enter the telephone number : 288344
Enter the mail id : elena@yahoo.com
You want to add one more record? (0 or 1) : 1
Enter the id (4 digits) : 5533
Enter the name : Bonnie
Enter the telephone number : 443355
Enter the mail id : bonnie@gamil.com
You want to add one more record? (0 or 1) : 1
Enter the id (4 digits) : 2490
Enter the name : Monica
Enter the telephone number : 363636
Enter the mail id : monica@gmail.com
You want to add one more record? (0 or 1) : 0
**********MENU**********
1.CREATE RECORDS
2.DISPLAY RECORDS
3.SEARCH RECORD
4.INSERT RECORD
5.DELETE RECORDS
6.TOTAL RECORDS
7.UPDATE RECORD
8.SORT RECORDS
9.EXIT
Enter the choice : 2



        Displaying........

************************************************************************************************************
                         DISPLAYING RECORDS

************************************************************************************************************

NAME                     ID                      TELEPHONE NO.                   EMAIL ID
--------------------------------------------------------------------------------------------------------------
Aneri                    2345                    243567                          aneri@gmail.com
--------------------------------------------------------------------------------------------------------------
Ashley                   2876                    299125                          ashley@yahoo.com
--------------------------------------------------------------------------------------------------------------
Bonnie                   5533                    443355                          bonnie@gamil.com
--------------------------------------------------------------------------------------------------------------
Elena                    4356                    288344                          elena@yahoo.com
--------------------------------------------------------------------------------------------------------------
Monica                   2490                    363636                          monica@gmail.com
--------------------------------------------------------------------------------------------------------------
Myra                     4567                    283722                          myra@gmail.com
--------------------------------------------------------------------------------------------------------------
**********MENU**********
1.CREATE RECORDS
2.DISPLAY RECORDS
3.SEARCH RECORD
4.INSERT RECORD
5.DELETE RECORDS
6.TOTAL RECORDS
7.UPDATE RECORD
8.SORT RECORDS
9.EXIT
Enter the choice : 3

Enter the name you want to search : Elena



        Searching........

************************************************************************************************************
                         RECORD FOUND

************************************************************************************************************

NAME                     ID                      TELEPHONE NO.                   EMAIL ID
--------------------------------------------------------------------------------------------------------------
Elena                    4356                    288344                          elena@yahoo.com
--------------------------------------------------------------------------------------------------------------
**********MENU**********
1.CREATE RECORDS
2.DISPLAY RECORDS
3.SEARCH RECORD
4.INSERT RECORD
5.DELETE RECORDS
6.TOTAL RECORDS
7.UPDATE RECORD
8.SORT RECORDS
9.EXIT
Enter the choice : 3

Enter the name you want to search : ankit



        Searching........

No records found! Sorry.
**********MENU**********
1.CREATE RECORDS
2.DISPLAY RECORDS
3.SEARCH RECORD
4.INSERT RECORD
5.DELETE RECORDS
6.TOTAL RECORDS
7.UPDATE RECORD
8.SORT RECORDS
9.EXIT
Enter the choice : 4

Enter the name you want to insert : Rachal
Enter the id you want to insert : 4444
Enter the telephone number you want to insert : 675789
Enter the mail id you want to insert : rachal@yahoo.com



        Inserting........

****************Record inserted.******************
**********MENU**********
1.CREATE RECORDS
2.DISPLAY RECORDS
3.SEARCH RECORD
4.INSERT RECORD
5.DELETE RECORDS
6.TOTAL RECORDS
7.UPDATE RECORD
8.SORT RECORDS
9.EXIT
Enter the choice : 2



        Displaying........

************************************************************************************************************
                         DISPLAYING RECORDS

************************************************************************************************************

NAME                     ID                      TELEPHONE NO.                   EMAIL ID
--------------------------------------------------------------------------------------------------------------
Aneri                    2345                    243567                          aneri@gmail.com
--------------------------------------------------------------------------------------------------------------
Ashley                   2876                    299125                          ashley@yahoo.com
--------------------------------------------------------------------------------------------------------------
Bonnie                   5533                    443355                          bonnie@gamil.com
--------------------------------------------------------------------------------------------------------------
Elena                    4356                    288344                          elena@yahoo.com
--------------------------------------------------------------------------------------------------------------
Monica                   2490                    363636                          monica@gmail.com
--------------------------------------------------------------------------------------------------------------
Myra                     4567                    283722                          myra@gmail.com
--------------------------------------------------------------------------------------------------------------
Rachal                   4444                    675789                          rachal@yahoo.com
--------------------------------------------------------------------------------------------------------------
**********MENU**********
1.CREATE RECORDS
2.DISPLAY RECORDS
3.SEARCH RECORD
4.INSERT RECORD
5.DELETE RECORDS
6.TOTAL RECORDS
7.UPDATE RECORD
8.SORT RECORDS
9.EXIT
Enter the choice : 5

Enter the name you want to delete : Ashley



        Deleting........

****************Record deleted.******************
* **********MENU**********
1.CREATE RECORDS
2.DISPLAY RECORDS
3.SEARCH RECORD
4.INSERT RECORD
5.DELETE RECORDS
6.TOTAL RECORDS
7.UPDATE RECORD
8.SORT RECORDS
9.EXIT
Enter the choice : 2



        Displaying........

************************************************************************************************************
                         DISPLAYING RECORDS

************************************************************************************************************

NAME                     ID                      TELEPHONE NO.                   EMAIL ID
--------------------------------------------------------------------------------------------------------------
Aneri                    2345                    243567                          aneri@gmail.com
--------------------------------------------------------------------------------------------------------------
Bonnie                   5533                    443355                          bonnie@gamil.com
--------------------------------------------------------------------------------------------------------------
Elena                    4356                    288344                          elena@yahoo.com
--------------------------------------------------------------------------------------------------------------
Monica                   2490                    363636                          monica@gmail.com
--------------------------------------------------------------------------------------------------------------
Myra                     4567                    283722                          myra@gmail.com
--------------------------------------------------------------------------------------------------------------
Rachal                   4444                    675789                          rachal@yahoo.com
--------------------------------------------------------------------------------------------------------------
**********MENU**********
1.CREATE RECORDS
2.DISPLAY RECORDS
3.SEARCH RECORD
4.INSERT RECORD
5.DELETE RECORDS
6.TOTAL RECORDS
7.UPDATE RECORD
8.SORT RECORDS
9.EXIT
Enter the choice : 5

Enter the name you want to delete : ankit

Name not found.
**********MENU**********
1.CREATE RECORDS
2.DISPLAY RECORDS
3.SEARCH RECORD
4.INSERT RECORD
5.DELETE RECORDS
6.TOTAL RECORDS
7.UPDATE RECORD
8.SORT RECORDS
9.EXIT
Enter the choice : 6

There are total 6 records.
**********MENU**********
1.CREATE RECORDS
2.DISPLAY RECORDS
3.SEARCH RECORD
4.INSERT RECORD
5.DELETE RECORDS
6.TOTAL RECORDS
7.UPDATE RECORD
8.SORT RECORDS
9.EXIT
Enter the choice : 7

Enter the name you want to update : Myra

This name is already present. You want to update? ( 0 or 1) : 1
Enter the id (4 digits) : 9090
Enter the name : Meira
Enter the telephone number : 212121
Enter the mail id : meira@yahoo.com



        Updating........

Record updated.
**********MENU**********
1.CREATE RECORDS
2.DISPLAY RECORDS
3.SEARCH RECORD
4.INSERT RECORD
5.DELETE RECORDS
6.TOTAL RECORDS
7.UPDATE RECORD
8.SORT RECORDS
9.EXIT
Enter the choice : 2



        Displaying........


************************************************************************************************************
                         DISPLAYING RECORDS

************************************************************************************************************

NAME                     ID                      TELEPHONE NO.                   EMAIL ID
--------------------------------------------------------------------------------------------------------------
Aneri                    2345                    243567                          aneri@gmail.com
--------------------------------------------------------------------------------------------------------------
Bonnie                   5533                    443355                          bonnie@gamil.com
--------------------------------------------------------------------------------------------------------------
Elena                    4356                    288344                          elena@yahoo.com
--------------------------------------------------------------------------------------------------------------
Meira                    9090                    212121                          meira@yahoo.com
--------------------------------------------------------------------------------------------------------------
Monica                   2490                    363636                          monica@gmail.com
--------------------------------------------------------------------------------------------------------------
Rachal                   4444                    675789                          rachal@yahoo.com
--------------------------------------------------------------------------------------------------------------
**********MENU**********
1.CREATE RECORDS
2.DISPLAY RECORDS
3.SEARCH RECORD
4.INSERT RECORD
5.DELETE RECORDS
6.TOTAL RECORDS
7.UPDATE RECORD
8.SORT RECORDS
9.EXIT
Enter the choice : 8
**********MENU**********
1.CREATE RECORDS
2.DISPLAY RECORDS
3.SEARCH RECORD
4.INSERT RECORD
5.DELETE RECORDS
6.TOTAL RECORDS
7.UPDATE RECORD
8.SORT RECORDS
9.EXIT
Enter the choice : 2



        Displaying........

************************************************************************************************************
                         DISPLAYING RECORDS

************************************************************************************************************

NAME                     ID                      TELEPHONE NO.                   EMAIL ID
--------------------------------------------------------------------------------------------------------------
Aneri                    2345                    243567                          aneri@gmail.com
--------------------------------------------------------------------------------------------------------------
Bonnie                   5533                    443355                          bonnie@gamil.com
--------------------------------------------------------------------------------------------------------------
Elena                    4356                    288344                          elena@yahoo.com
--------------------------------------------------------------------------------------------------------------
Meira                    9090                    212121                          meira@yahoo.com
--------------------------------------------------------------------------------------------------------------
Monica                   2490                    363636                          monica@gmail.com
--------------------------------------------------------------------------------------------------------------
Rachal                   4444                    675789                          rachal@yahoo.com
--------------------------------------------------------------------------------------------------------------
**********MENU**********
1.CREATE RECORDS
2.DISPLAY RECORDS
3.SEARCH RECORD
4.INSERT RECORD
5.DELETE RECORDS
6.TOTAL RECORDS
7.UPDATE RECORD
8.SORT RECORDS
9.EXIT
Enter the choice : 9
THANK YOU!
 * 
 * */
