#include <iostream>
#include <fstream>
#include <limits>
using namespace std;

class Clock {
    public:
        int second;
        int minute;
        int hour;

        Clock(unsigned int h, unsigned int m, unsigned int s){
            this->hour = h;
            this->minute = m;
            this->second = s;
        }
        
        void addOneSecond(){
            if(this->second == 59){
                this->addOneMinute();
                this->second = 0;
            }else{
                this->second = this->second + 1;
            }
        };

        void addOneMinute(){
            if(this->minute == 59){
                this->addOneHour();
                this->minute = 0;
            }else{
                this->minute = this->minute + 1;
            }
        };

        void addOneHour(){
            if(this->hour == 23){
                this->hour = 0;
            }else{
                this->hour += 1;
            }
        };
};

string twoDigitString(unsigned int n){
    string outputStr = "";
    if(n < 10){
        outputStr = "0" + to_string(n);
    }else{
        outputStr = to_string(n);
    }

    return outputStr;
}

string nCharString(size_t n, char c){
    string outputStr = "";

    for(int i = 0; i < n; i++){
        outputStr += c;
    }

    return outputStr;
}

string formatTime24(unsigned int h, unsigned int m, unsigned int s){
    string outputStr = "";
    outputStr += twoDigitString(h);
    outputStr += ":";
    outputStr += twoDigitString(m);
    outputStr += ":";
    outputStr += twoDigitString(s);
    return outputStr;
}

string formatTime12(unsigned int h, unsigned int m, unsigned int s){
    string outputStr = "";
    string amPm = "";
    if(h > 12){
        outputStr += twoDigitString(h-12);
        amPm = "P M";
    }else if(h == 0){
        outputStr += "12";
        amPm = "A M";
    }else{
        if(h == 12){
            amPm = "P M";
        }else{
            amPm = "A M";
        }
        outputStr += twoDigitString(h);
    }

    outputStr += ":";
    outputStr += twoDigitString(m);
    outputStr += ":";
    outputStr += twoDigitString(s);

    outputStr += " " + amPm;

    return outputStr;
}

void printMenu(string strings[], unsigned int numStrings, unsigned int width){
    cout << nCharString(15, ' ') << nCharString(width, '*') << nCharString(15, ' ') << endl;
    for(int i = 0; i < numStrings; i++){
        int endLineLength = width - strings[i].length() - 7;
        cout <<  nCharString(15, ' ') << "* " << i+1 << " - " << strings[i] << nCharString(endLineLength, ' ') << "*" << nCharString(15, ' ') << endl;
        if(i != numStrings - 1){
            cout << endl;
        }
    }
    cout << nCharString(15, ' ') << nCharString(width, '*') <<  nCharString(15, ' ') << endl;
}

unsigned int getMenuChoice(unsigned int maxChoice){
    int userInput;
    bool inputValid = false;

    while(!inputValid){
        cin >> userInput;
        if(cin.fail()){
            userInput = -1;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        if(userInput > 0 && userInput <= maxChoice){
            inputValid = true;
            break;
        }
        
    }
    return userInput;
}

void displayClocks(unsigned int h, unsigned int m, unsigned int s){
    cout << nCharString(27, '*') << nCharString(3, ' ') << nCharString(27, '*') << endl;
    cout << "*" << nCharString(6, ' ') << "12-HOUR CLOCK" << nCharString(6, ' ') << "*" << nCharString(3, ' ');
    cout << "*" << nCharString(6, ' ') << "24-HOUR CLOCK" << nCharString(6, ' ') << "*" << endl;
    cout << endl;
    cout << "*" << nCharString(6, ' ') << formatTime12(h, m, s) << nCharString(7, ' ') << "*" << nCharString(3, ' ');
    cout << "*" << nCharString(8, ' ') << formatTime24(h, m, s) << nCharString(9, ' ') << "*" << endl;
    cout << nCharString(27, '*') << nCharString(3, ' ') << nCharString(27, '*') << endl;
}

int main() {
    Clock clock1 = Clock(13, 50, 11);
    string menuOptions[] = {"Add One Hour", "Add One Minute", "Add One Second", "Exit Program"};
    unsigned int menuChoice = 0;

    while(menuChoice != 4){
        displayClocks(clock1.hour, clock1.minute, clock1.second);
        printMenu(menuOptions, 4, 27);
        menuChoice = getMenuChoice(4);
        switch(menuChoice){
            case 1:
                clock1.addOneHour();
                break;
            case 2:
                clock1.addOneMinute();
                break;
            case 3:
                clock1.addOneSecond();
                break;
            default:
                break;
        }
    }

    return 0;
}
