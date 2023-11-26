// Problem - 03

# include <iostream>

using namespace std;

class Clock{
    private:
        int hour, minute, second;
        string meridian;

    public:
    // Set the clock to the specified time
        void setClock(int h, int m, int s, string mer){
            if(h>=0 and h<=23)
                hour = h;
            else
                cout<<"Invalid Hour Format"<<endl;
            if(m>=0 and m<=59)
                minute = m;
            else
                cout<<"Invalid Minute Format"<<endl;
            if(s>=0 and s<=59)
                second = s;
            else
                cout<<"Invalid Second Format"<<endl;
            
            if(mer == "AM" or mer == "PM")
                meridian = mer;
            else
                cout<<"Invalid Meridian Format"<<endl;

        }
    // Display the time in  standard notation
        void displayStandard(){
            int h = hour;
            cout<<"Standard Format"<<endl;
            cout<<hour%12<<":"<<minute<<":"<<second<<":"<<meridian<<endl;
        }
    // Display the time in military notation
        void displayMilitary(){
            int h = hour;
            int m = minute;
            int s = second;
            cout<<"Military Format"<<endl;
            if(meridian == "PM" and hour < 12){
                h += 12;
            }
            cout<<h<<":"<<m<<":"<<s<<endl;
        }
};


int main(){
    
    Clock c;

        int choice = -1;

        int h, m, s;
        string mer;

        cout<<"Set Your Clock"<<endl;
        cout<<"Enter Hour (0-23) : ";cin>>h;
        cout<<"Enter Minuite (0-59) : ";cin>>m;
        cout<<"Enter Second (0-59) : ";cin>>s;
        cout<<"Enter Meridian (AM/PM) : ";cin>>mer;

        c.setClock(h,m,s, mer);

        do{
            
            cout
            <<"1. Display Standard"<<endl
            <<"2. Display Meridian"<<endl
            <<"3. Exit"<<endl;
            
            cin>>choice;
            switch(choice){
                case 1:
                    c.displayStandard();
                    break;
                case 2:
                    c.displayMilitary();
                    break;
                default:
                    cout<<"Exiting..."<<endl;
                    break;
            }

        }while(choice < 3);

    return 0;
}