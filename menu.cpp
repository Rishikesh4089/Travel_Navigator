#include <iostream>
#include "cities.h"
#include "details.cpp"
using namespace std;

class onlyDisplay{
    public:
    void menu();
    void esc();
    void map();
};

class TravelNavigator{
    public:
    void Data();
    void tour_select();
};


void TravelNavigator::tour_select(){
    Graph g;
    g.createMap();
    node n;
    g.pathFinder(n.tourDays(), n.startNode(), n.endNode());
    if(g.pathFinder(n.tourDays(), n.startNode(), n.endNode())==true){
        if(g.totalWeight*100<n.budgetDisplay()){
            cout<<"The cost of the tour is "<<g.totalWeight*100<<endl<<endl;;
            cout<<"                                                          CONGRATULATIONS !                                                             "<<endl<<endl;
        }else{
            cout<<"The selected tour exceeds your budget\n"<<endl;
            cout<<"                                                 SORRY! TRY SELECTING YOUR TOUR AGAIN                                           "<<endl;
            return;
        }
    }
}

void TravelNavigator::Data(){
    onlyDisplay od;
    system("clear");
    int x;
    cout<<">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>"<<endl;
    cout<<">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>"<<endl;
    cout<<"                                                                                                                                     "<<endl;
    cout<<"                                                            USER DETAILS                                                             "<<endl;
    cout<<"                                                                                                                                     "<<endl;
    user_details();
    tour_select();
    cout<<"         Enter 0 For Home                                                                                                            "<<endl;
    cout<<">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>"<<endl;
    cout<<">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>"<<endl;
    cin>>x;
    switch(x){
        case 0:
            od.menu();
            break;
    }

}

void onlyDisplay::menu(){
    TravelNavigator tn;
    system("clear");
    int choice;
    cout<<endl;
    cout<<">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>"<<endl;
    cout<<">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>"<<endl;
    cout<<"**                                                                                                                                   **"<<endl;
    cout<<"**                                                           WELCOME TO                                                              **"<<endl;
    cout<<"**                                                        TRAVEL NAVIGATOR                                                           **"<<endl;
    cout<<"**                                                                                                                                   **"<<endl;
    cout<<"**                    Press Your Option :-                                                                                           **"<<endl;
    cout<<"**                                                                                                                                   **"<<endl;
    cout<<"**                                     1.Choose your itinerary                                                                       **"<<endl;
    cout<<"**                                     2.List of countries offered                                                                   **"<<endl;
    cout<<"**                                     3.Exit                                                                                        **"<<endl;
    cout<<"**                                                                                                                                   **"<<endl;
    cout<<">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>"<<endl;
    cout<<">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>"<<endl;
    cout<<endl<<"Enter your choice - ", cin>>choice;
    if(choice>0 && choice<4){
        switch(choice){
            case 1:
                system("clear");
                tn.Data();
                break;
            case 2:
                map();
                break;
            case 3:
                esc();
                break;
        }
        
    }
}

void onlyDisplay::esc(){
    system("clear");
    cout<<">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>"<<endl;
    cout<<">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>"<<endl;
    cout<<"**                                                                                                                                   **"<<endl;
    cout<<"**                                                                                                                                   **"<<endl;
    cout<<"**                                                                                                                                   **"<<endl;
    cout<<"**                                                                                                                                   **"<<endl;
    cout<<"**                                                                                                                                   **"<<endl;
    cout<<"**                                         Thank You for using our service, have a good day!                                         **"<<endl;
    cout<<"**                                                                                                                                   **"<<endl;
    cout<<"**                                                                                                                                   **"<<endl;
    cout<<"**                                                                                                                                   **"<<endl;
    cout<<"**                                                                                                                                   **"<<endl;
    cout<<"**                                                                                                                                   **"<<endl;
    cout<<">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>"<<endl;
    cout<<">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>"<<endl;
    exit(0);
}

void onlyDisplay::map(){
    system("clear");
    int x;
    cout<<">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>"<<endl;
    cout<<">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>"<<endl;
    cout<<"**                                                                                                                                   **"<<endl;
    cout<<"**                                                    STATES and CITIES Available                                                    **"<<endl;
    cout<<"**                                                                                                                                   **"<<endl;
    cout<<"**                                                             Rajasthan                                                             **"<<endl;
    cout<<"**                                              Jaisalmer       Udaipur        Jodhpur                                               **"<<endl;
    cout<<"**                                                                                                                                   **"<<endl;
    cout<<"**                                                         Himachal Pradesh                                                          **"<<endl;
    cout<<"**                                                 Shimla        Kullu      Manali                                                   **"<<endl;
    cout<<"**                                                                                                                                   **"<<endl;
    cout<<"**                                                           Jammu & Kashmir                                                         **"<<endl;
    cout<<"**                                              Leh Ladakh       Gulmarg      Srinagar                                               **"<<endl;
    cout<<"**                                                                                                                                   **"<<endl;
    cout<<"**       Enter 0 For Home                                                                                                            **"<<endl;
    cout<<">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>"<<endl;
    cout<<">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>"<<endl;
    cin>>x;
    switch(x){
        case 0: 
            menu();
            break;
    }
}

#include <iostream>
#include "cities.h"
#include "details.cpp"
using namespace std;

class onlyDisplay{
    public:
    void menu();
    void esc();
    void map();
};

class TravelNavigator{
    public:
    void Data();
    void tour_select();
};

void TravelNavigator::Data(){
    system("clear");
    cout<<">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>"<<endl;
    cout<<">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>"<<endl;
    cout<<"                                                                                                                                     "<<endl;
    cout<<"                                                            USER DETAILS                                                             "<<endl;
    cout<<"                                                                                                                                     "<<endl;
    user_details();
    cout<<">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>"<<endl;
    cout<<">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>"<<endl;

}

void onlyDisplay::menu(){
    TravelNavigator tn;
    system("clear");
    int choice;
    cout<<endl;
    cout<<">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>"<<endl;
    cout<<">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>"<<endl;
    cout<<"**                                                                                                                                   **"<<endl;
    cout<<"**                                                           WELCOME TO                                                              **"<<endl;
    cout<<"**                                                        TRAVEL NAVIGATOR                                                           **"<<endl;
    cout<<"**                                                                                                                                   **"<<endl;
    cout<<"**                    Press Your Option :-                                                                                           **"<<endl;
    cout<<"**                                                                                                                                   **"<<endl;
    cout<<"**                                     1.Choose your itinerary                                                                       **"<<endl;
    cout<<"**                                     2.List of countries offered                                                                   **"<<endl;
    cout<<"**                                     3.Exit                                                                                        **"<<endl;
    cout<<"**                                                                                                                                   **"<<endl;
    cout<<">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>"<<endl;
    cout<<">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>"<<endl;
    cout<<endl<<"Enter your choice - ", cin>>choice;
    if(choice>0 && choice<4){
        switch(choice){
            case 1:
                system("clear");
                tn.Data();
                break;
            case 2:
                map();
                break;
            case 3:
                esc();
                break;
        }
        
    }
}

void onlyDisplay::esc(){
    system("clear");
    cout<<">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>"<<endl;
    cout<<">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>"<<endl;
    cout<<"**                                                                                                                                   **"<<endl;
    cout<<"**                                                                                                                                   **"<<endl;
    cout<<"**                                                                                                                                   **"<<endl;
    cout<<"**                                                                                                                                   **"<<endl;
    cout<<"**                                                                                                                                   **"<<endl;
    cout<<"**                                         Thank You for using our service, have a good day!                                         **"<<endl;
    cout<<"**                                                                                                                                   **"<<endl;
    cout<<"**                                                                                                                                   **"<<endl;
    cout<<"**                                                                                                                                   **"<<endl;
    cout<<"**                                                                                                                                   **"<<endl;
    cout<<"**                                                                                                                                   **"<<endl;
    cout<<">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>"<<endl;
    cout<<">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>"<<endl;
    exit(0);
}

void onlyDisplay::map(){
    system("clear");
    int x;
    cout<<">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>"<<endl;
    cout<<">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>"<<endl;
    cout<<"**                                                                                                                                   **"<<endl;
    cout<<"**                                                    STATES and CITIES Available                                                    **"<<endl;
    cout<<"**                                                                                                                                   **"<<endl;
    cout<<"**                                                             Rajasthan                                                             **"<<endl;
    cout<<"**                                              Jaisalmer       Udaipur        Jodhpur                                               **"<<endl;
    cout<<"**                                                                                                                                   **"<<endl;
    cout<<"**                                                         Himachal Pradesh                                                          **"<<endl;
    cout<<"**                                                 Shimla        Kullu      Manali                                                   **"<<endl;
    cout<<"**                                                                                                                                   **"<<endl;
    cout<<"**                                                           Jammu & Kashmir                                                         **"<<endl;
    cout<<"**                                              Leh Ladakh       Gulmarg      Srinagar                                               **"<<endl;
    cout<<"**                                                                                                                                   **"<<endl;
    cout<<"**       Enter 0 For Home                                                                                                            **"<<endl;
    cout<<">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>"<<endl;
    cout<<">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>"<<endl;
    cin>>x;
    switch(x){
        case 0: 
            menu();
            break;
    }
}

