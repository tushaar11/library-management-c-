#include<iostream>
#include<fstream>
#include<string.h>
#include<ctime>
#include<stdlib.h>
using namespace std;
class books
{
    public:
    int bookid;
    char bookname[100];
    char author[100];
    float price;
    int status;
    void acceptbook()
    {
        cout<<"ENTER BOOK ID     :";
        cin>>bookid;
        cout<<"ENTER BOOK NAME   :";
        cin>>bookname;
        cout<<"ENTER AUTHOR NAME :";
        cin>>author;
        cout<<"ENTER PRICE       :";
        cin>>price;
        status=0;
    }
    void viewbook()
    {
        cout<<"BOOK ID      :"<<bookid<<endl;
        cout<<"BOOK NAME   :"<<bookname<<endl;
        cout<<"AUTHOR NAME :"<<author<<endl;
        cout<<"PRICE       :"<<price<<endl;
        cout<<"STATUS      :";
        (status==0)?cout<<"NOT ISSUED"<<endl:cout<<"ISSUED TO MEMBER ID "<<status<<endl;
    }
};
books bookobj;
class members
{
    public:
    int memberid;
    char mname[100];
    int age;
    long long mobileno;
    void acceptmember()
    {
        cout<<endl<<"ENTER MEMBER ID     :";
        cin>>memberid;
        cout<<endl<<"ENTER MEMBER'S NAME :";
        cin>>mname;
        cout<<endl<<"ENTER AGE           :";
        cin>>age;
        cout<<endl<<"ENTER MOBILE NUMBER :";
        cin>>mobileno;
    }
    void viewmember()
    {
        cout<<"MEMBER ID           :"<<memberid<<endl;
        cout<<"MEMBER NAME         :"<<mname<<endl;
        cout<<"MEMBER'S AGE        :"<<age<<endl;
        cout<<"MOBILE NUMBER       :"<<mobileno<<endl;
    }
};
members memberobj;
main()
{
    int e=1;
    while(e!=0)
    {
    cout<<"1.  ADD BOOK"<<endl;
    cout<<"2.  VIEW ALL BOOKS"<<endl;
    cout<<"3.  SEARCH BOOK"<<endl;
    cout<<"4.  EDIT BOOK"<<endl;
    cout<<"5.  REMOVE BOOK"<<endl;
    cout<<"6.  ADD MEMBER"<<endl;
    cout<<"7.  VIEW MEMBERS"<<endl;
    cout<<"8.  SEARCH MEMBER"<<endl;
    cout<<"9.  EDIT MEMBER"<<endl;
    cout<<"10. REMOVE MEMBER"<<endl;
    cout<<"11. ISSUE BOOK"<<endl;
    cout<<"12. RETURN BOOK"<<endl;
    cout<<"13. EXIT"<<endl;
    cout<<"ENTER YOUR CHOICE :";
    int choice;
    cin>>choice;
    switch(choice)
    {
    case 1:
        {   //adding books
            bookobj.acceptbook();
            fstream wr;
            wr.open("library.txt",ios::app);
               wr.write((char*)&bookobj,sizeof(bookobj));
            cout<<"BOOK ADDED SUCCESSFULLY"<<endl;

            break;
        }
    case 2:
        {
            //viewing file
            fstream rd;
            rd.open("library.txt",ios::in);
            rd.seekg(0,ios::end);
            int n=rd.tellg()/sizeof(bookobj);
            rd.seekg(0,ios::beg);
            for(int i=1;i<=n;i++)
            {
                rd.read((char*)&bookobj,sizeof(bookobj));
                bookobj.viewbook();
                cout<<endl<<"******************"<<endl;
            }
            break;
        }
    case 3:
        {
            fstream rd;
            rd.open("library.txt",ios::in);
            rd.seekg(0,ios::end);
            int n=rd.tellg()/sizeof(bookobj);
            rd.seekg(0,ios::beg);
            cout<<"ENTER BOOK ID :";
            int bkid;
            cin>>bkid;
            int i;
            for(i=1;i<=n;i++)
            {
                rd.read((char*)&bookobj,sizeof(bookobj));
                if(bookobj.bookid==bkid)
                {
                    bookobj.viewbook();
                    cout<<endl<<"******************"<<endl;
                }
            }
            if(i==n+1)
                cout<<"BOOK NOT FOUND"<<endl;
            break;
        }
    case 4:
        {
            fstream rd,wr;
            rd.open("library.txt",ios::in);
            wr.open("temp.txt",ios::out);
            rd.seekg(0,ios::end);
            int n=rd.tellg()/sizeof(bookobj);
            rd.seekg(0,ios::beg);
            int bkid;
            cout<<"ENTER BOOK ID :";
            cin>>bkid;
            for(int i=1;i<=n;i++)
            {
                rd.read((char*)&bookobj,sizeof(bookobj));
                if(bookobj.bookid==bkid)
                {
                    bookobj.acceptbook();
                    wr.write((char*)&bookobj,sizeof(bookobj));
                    cout<<"BOOK EDIT DONE"<<endl;
                }
                else
                {
                wr.write((char*)&bookobj,sizeof(bookobj));
                }
            }
            rd.close();
            wr.close();
            remove("library.txt");
            rename("temp.txt","library.txt");
            cout<<endl<<"***********************"<<endl;
            break;
        }
    case 5:
        {
            fstream rd,wr;
            rd.open("library.txt",ios::in);
            wr.open("temp.txt",ios::out);
            rd.seekg(0,ios::end);
            int n=rd.tellg()/sizeof(bookobj);
            rd.seekg(0,ios::beg);
            int bkid;
            cout<<"ENTER BOOK ID :";
            cin>>bkid;
            for(int i=1;i<=n;i++)
            {
                rd.read((char*)&bookobj,sizeof(bookobj));
                if(bookobj.bookid==bkid)
                {
                    cout<<"BOOK REMOVED"<<endl;
                }
                else
                {
                wr.write((char*)&bookobj,sizeof(bookobj));
                }
            }
            rd.close();
            wr.close();
            remove("library.txt");
            rename("temp.txt","library.txt");
            cout<<endl<<"***********************"<<endl;
            break;
        }
    case 6:
        {
            memberobj.acceptmember();
            fstream wr;
            wr.open("library2.txt",ios::app);
            wr.write((char*)&memberobj,sizeof(memberobj));
            cout<<"MEMBER ADDED SUCCESSFULLY"<<endl;
            break;
        }
    case 7:
        {
            fstream rd;
            rd.open("library2.txt",ios::in);
            rd.seekg(0,ios::end);
            int n=rd.tellg()/sizeof(memberobj);
            rd.seekg(0,ios::beg);
            for(int i=1;i<=n;i++)
            {
                rd.read((char*)&memberobj,sizeof(memberobj));
                memberobj.viewmember();
                cout<<endl<<"******************"<<endl;
            }
            break;
        }
    case 8:
        {
            fstream rd;
            rd.open("library2.txt",ios::in);
            rd.seekg(0,ios::end);
            int n=rd.tellg()/sizeof(memberobj);
            rd.seekg(0,ios::beg);
            cout<<"ENTER MEMBER'S ID :";
            int mid;
            cin>>mid;
            int i;
            for(i=1;i<=n;i++)
            {
                rd.read((char*)&memberobj,sizeof(memberobj));
                if(memberobj.memberid==mid)
                {
                    memberobj.viewmember();
                    cout<<endl<<"******************"<<endl;
                }
            }
            if(i==n+1)
                cout<<"MEMBER NOT FOUND"<<endl;
            break;
        }
    case 9:
        {
            fstream rd,wr;
            rd.open("library2.txt",ios::in);
            wr.open("temp.txt",ios::out);
            rd.seekg(0,ios::end);
            int n=rd.tellg()/sizeof(memberobj);
            rd.seekg(0,ios::beg);
            int mid;
            cout<<"ENTER MEMBER'S ID :";
            cin>>mid;
            for(int i=1;i<=n;i++)
            {
                rd.read((char*)&memberobj,sizeof(memberobj));
                if(mid==memberobj.memberid)
                {
                    memberobj.acceptmember();
                    wr.write((char*)&memberobj,sizeof(memberobj));
                    cout<<"MEMBER EDIT DONE"<<endl;
                }
                else
                {
                wr.write((char*)&memberobj,sizeof(memberobj));
                }
            }
            rd.close();
            wr.close();
            remove("library2.txt");
            rename("temp.txt","library2.txt");
            cout<<endl<<"***********************"<<endl;
            break;
        }
    case 10:
        {
            fstream rd,wr;
            rd.open("library2.txt",ios::in);
            wr.open("temp.txt",ios::out);
            rd.seekg(0,ios::end);
            int n=rd.tellg()/sizeof(memberobj);
            rd.seekg(0,ios::beg);
            int mid;
           cout<<"ENTER MEMBER'S ID :";
            cin>>mid;
            for(int i=1;i<=n;i++)
            {
                rd.read((char*)&memberobj,sizeof(memberobj));
                if(mid==memberobj.memberid)
                {
                    cout<<"MEMBER REMOVED"<<endl;
                }
                else
                {
                wr.write((char*)&memberobj,sizeof(memberobj));
                }
            }
            rd.close();
            wr.close();
            remove("library2.txt");
            rename("temp.txt","library2.txt");
            cout<<endl<<"***********************"<<endl;
            break;
        }
    case 11:
        {
            int bkid;
            cout<<"ENTER BOOK ID TO ISSUE";
            cin>>bkid;

            fstream rd;
            rd.open("library.txt");
            rd.seekg(0,ios::end);
            int n=rd.tellg()/sizeof(bookobj);
            rd.seekg(0,ios::beg);

            for(int i=1;i<=n;i++)
            {
                rd.read((char*)&bookobj,sizeof(bookobj));
                if(bookobj.bookid==bkid&&bookobj.status==0)
                {
                    bookobj.viewbook();
                    break;
                }
            }
            rd.close();
            if(bookobj.status==0)
            {
                int memberid;
                cout<<endl<<"ENTER MEMBER ID TO ISSUE BOOK";
                cin>>memberid;

                fstream rd1,wr1;
                rd1.open("library.txt",ios::in);
                wr1.open("temp.txt",ios::out);

                rd1.seekg(0,ios::end);
                int n1=rd1.tellg()/sizeof(bookobj);
                rd1.seekg(0,ios::beg);
                for(int j=1;j<=n1;j++)
                {
                    rd1.read((char*)&bookobj,sizeof(bookobj));
                    if(bookobj.bookid==bkid)
                    {
                        bookobj.status=memberid;
                    }
                    wr1.write((char*)&bookobj,sizeof(bookobj));
                }
                rd1.close();
                remove("library.txt");
                wr1.close();
                rename("temp.txt","library.txt");
                cout<<endl<<"BOOK ISSUED SUCCESSFULLY"<<endl;
            }
            else
            {
                cout<<endl<<"BOOK ALREADY ISSUED";
            }
            break;
        }
    case 12:
        {
            int bkid;
            cout<<"enter book id";
            cin>>bkid;
            fstream rd,wr;
            rd.open("library.txt",ios::in);
            wr.open("temp.txt",ios::out);
            rd.seekg(0,ios::end);
            int n=rd.tellg()/sizeof(bookobj);
            rd.seekg(0,ios::beg);
            for(int i=1;i<=n;i++)
            {
                rd.read((char*)&bookobj,sizeof(bookobj));
                    if(bookobj.bookid==bkid)
                    {
                        bookobj.status=0;
                    }
                    wr.write((char*)&bookobj,sizeof(bookobj));
            }
                rd.close();
                wr.close();
                remove("library.txt");
                rename("temp.txt","library.txt");
                cout<<endl<<"BOOK RETURN DONE"<<endl;
                break;
        }
    case 13:
        {
            e=0;
            break;
        }
    }
    if(choice!=13)
    {
    system("pause");
    system("cls");
    }
    }

}

