#include <iostream>
#include <algorithm>
#include <ctime>
#include <string>
using namespace std;
class Page{
    public:
    string url;
    time_t timestamp;
    Page *prev,*next;
    Page(string u){
        url=u;
        timestamp=time(0);
        prev=nullptr;
        next=nullptr;
    }
};

class Browser{
    Page *head,*current;

    public:

    Browser(){ head=nullptr; current=nullptr;}

    void addpage(string url){
        Page *p=new Page(url);

        if(head==nullptr){
            head=current=p;
        }
        else{
            Page *temp = current->next;

            while (temp!=nullptr){
                Page *del =  temp;
                temp=temp->next;
                delete del;
            }
            current->next = p;
            p->prev=current;
            current=p;
        }

        cout<<"Page visited "<< url <<"\n";
    }

    void visit(string url){
        addpage(url);
    }

    void backward(){
        if(current != nullptr && current->prev!=nullptr){ current=current->prev ;
        cout<< "Previous Page : "<<current->url<<"\n";
        }else{cout<<"Page not found ";}
    }

    void forward(){
        if(current != nullptr && current->next!=nullptr){ current=current->next ;
        cout<< "Next Page : "<<current->url<<"\n";
        }else{cout<<"Page not found ";}
    }

    void display(){
        Page *temp=head;
        if (temp==nullptr){ cout <<"History is empty ";
        return;
        }

        while(temp!=nullptr){
            cout << "Website : " << temp->url << "\n";
cout << "Timestamp : " << ctime(&temp->timestamp);
if (current == temp) {
    cout << "<----current page\n";
}
            temp=temp->next;
        }
    }
};


int main() 
{   Browser b;
    string url;
    int c;

    do{
        cout << "\n------ Browser History ------\n";
        cout << "1. Visit Page\n";
        cout << "2. Backward\n";
        cout << "3. Forward\n";
        cout << "4. Add Page\n";
        cout << "5. Display History\n";
        cout << "0. Exit\n";
        cout << "Enter choice: ";
        cin>>c;
        switch(c){

            case 1: cout <<"\nenter url : ";
                    cin>>url;
                    b.visit(url); break;

            case 2: b.backward(); break;

            case 3: b.forward();break;

            case 4: cout <<"\nenter url:";
                    cin>>url;
                    b.addpage(url);break;

            case 5: b.display(); break;

            case 0: cout<<"exiting"; break;
            default:cout<<"invalid option selected: ";


        }
    }while(c!=0);
    return 0;
}