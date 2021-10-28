//Kodi Rogue, Beetle Game, MP2, 9am Dr. Estell, 10/28/21

#include <iostream>
#include<string>
#include<ctime>

using namespace std;

int rollDie(void);
bool isBodyPart(string currentBody, char c);
bool isBeetleComplete(string currentBody);
char getUserInput(void);
char convertDieToPart(int roll);
void consume(string player, char bodyPart);
void build(string &player, char bodypart);
bool allParts(string player, char bodyPart);
void displayBeetles(string playerBody);

int main()
{
    int roll;
    string player1;
    string player2;
    string player1body = "_____________";
    string player2body = "_____________";
    int dieRoll = 0;
    char userInput;
    char part;
    int currentPlayer = 1;
    srand(time(0));

    cout << "Welcome to the beetle game!!\n" << endl;
    cout << "This is a 2 player game. Before each turn You will be asked if you'd like to build upon your own beeetle or conusme your oppenets.\n";
    cout << "A complete beetle consists of a body, a head, 6 legs, 2 eyes, 2 antennas, and a tail. The beetle must have a body before any other body parts can be added. \nThe beetle must have a head before any eyes or antenna can be added. When consuming a\n";
    cout << "beetle, you can only eat the smaller body parts: leg, eye, antenna, or tail.\n";
    cout << "Rolling a 1 is the body of the beetle, rolling a 2 is the beetle's head, rolling a 3 is a leg, a 4 is an eye, rolling a 5 is an antenna and a 6 is the beetles tail \n " << endl;
    cout << "Lets begin!! \n";

    cout << "To start please enter your names.\n";
    cout << "Player 1 please enter your name: ";
    cin >> player1;
    cout << "Hi, " << player1 << "!\n" << endl;
    cout << "Player 2 please entire your name: ";
    cin >> player2;
    cout << "Hi, " << player2 << "!\n" << endl;

    while (isBeetleComplete(player1body) != true && isBeetleComplete(player2body) != true ){
        if (currentPlayer % 2 == 1) {
            cout << player1 << ", would you like to build your beetle or Consume your opponents? (type B to build or C to consume)";
            userInput = getUserInput();
            dieRoll = rollDie();
            cout << " You rolled a " << dieRoll << ".\n";
            part = convertDieToPart(dieRoll);
            if (userInput == 'B')
                build(player1body, part);
            else consume(player2body, part);

            cout << "*****" << player1 << "'s Beetle *****\n \n";
            displayBeetles(player1body);
            cout << "*****" << player2 << "'s Beetle *****\n \n";
            displayBeetles(player2body);
            if (isBeetleComplete(player1body)) {
                cout << "Congratulations " << player1 << ",you have won!!";
                return 0;
            }
            currentPlayer++;
        }
        else {
            cout << player2 << ", would you like to build your beetle or Consume your opponents? (type B to build or C to consume)";
            userInput = getUserInput();
            dieRoll = rollDie();
            cout << " You rolled a " << dieRoll << ".\n";
            part = convertDieToPart(dieRoll);
            if (userInput == 'B')
                build(player2body, part);
            else consume(player1body, part);

            cout << "*****" << player1 << "'s Beetle *****\n \n";
            displayBeetles(player1body);
            cout << "*****" << player2 << "'s Beetle *****\n \n";
            displayBeetles(player2body);

            if (isBeetleComplete(player2body)) {
                cout << "Congratulations " << player2 << ",you have won!!";
                return 0;
            }
            currentPlayer++;
           
        }
    }
}



int rollDie(void) {
    int die;
    die = rand() % 6 + 1;
    return die;
}

char getUserInput(void) {
    char BuildorConsume;
    A:
    cin >> BuildorConsume;
    if (cin.fail()) {
        cout << "Sorry your input could not be understood. Please try again.\n";
        goto A;
    }
    if (BuildorConsume == 'c' || BuildorConsume == 'C')
        return 'C';
    else if (BuildorConsume == 'b' || BuildorConsume == 'B')
        return 'B';
    else {
        cout << "Sorry your input could not be understood. Please try again.\n";
        goto A;
    }
}

bool isBeetleComplete(string currentBody) {
    if (currentBody == "BHLLLLLLEEAAT")
        return true;
    else return false;

}

char convertDieToPart(int roll) {
    switch (roll) {
    case 1: return 'B'; 
    case 2: return 'H';
    case 3: return 'L';
    case 4: return 'E';
    case 5: return 'A';
    case 6: return 'T';
    }
}
bool isBodyPart(string currentBody, char c) {
    string str = currentBody;
    
    if (c == 'B')   
        if (str.at(0) == 'B')
            return true;

    if (c == 'H')
        if (str.at(1) == 'H')
            return true;

    if (c == 'L')
            for (int i = 2; i < 8; i++) 
             if (str.at(i) == 'L')
                return true;
           
    if (c == 'E')
        for (int i = 8; i < 10; i++) 
            if (str.at(i) == 'E')
                return true;

    if ( c == 'A')
        for (int i = 10; i < 12; i++)
            if (str.at(i) == 'A')
                return true;

    if (c == 'T')
        if (str.at(12) == 'T')
            return true;
    
    return false;

}

void consume(string player, char bodyPart) {
    switch (bodyPart) {
    case 'B': cout << "You cant consume the body."; return;
    case 'H': cout << "You cant consume the head."; return;
    case 'L':
        if (isBodyPart(player, bodyPart)) {
            for (int i = 7; i >= 2; i--) {
                if (player.at(i) == 'L') {
                    player.replace(i, i, "_");
                    cout << " You have consumed a leg\n";
                    return;
                }
            }
        }
        else cout << "Opponent does not have a Leg to consume.\n";
        return;

    case 'E':
        if (isBodyPart(player, bodyPart)) {
            for (int i = 9; i >= 8; i--) {
                if (player.at(i) == 'E') {
                    player.replace(i, i, "_");
                    cout << "You have consumed an eye.\n";
                    return;
                }
            }
        }
        else
        {
            cout << "Opponent does not have an eye to consume.\n";
        }
        return;

    case 'A':
        if (isBodyPart(player, bodyPart)) {
            for (int i = 11; i >= 10; i--) {
                if (player.at(i) == 'A') {
                    player.replace(i, i, "_");
                    cout << "you have consumed an antenna.\n";
                    return;
                }

            }
        }
        else
            cout << "Opponent does not have an eye to consume.\n";
        return;


    case 'T':
        if (isBodyPart(player, bodyPart)) {
            if (player.at(12) == 'T') {
                player.replace(12, 12, "_");
                cout << "You have consumed the tail.";
                return;
            }
        }
        else cout << "Opponent does not have a tail to consume.";
        return;
    }
}
    void build(string &player, char bodyPart) {
        switch (bodyPart) {
        case 'B':
            if (isBodyPart(player, bodyPart)) {
            cout << "You already have this part.\n";
            return;
        }
            else {
                player.replace(0, 0, "B");
                cout << "You have built the body.\n";
            }
            return;
        case 'H': 
            if (isBodyPart(player, 'B')) {
                if (isBodyPart(player, bodyPart)) {
                    cout << "You already have this part.\n";
                }
                else {
                    player.replace(1, 1, "H");
                    cout << "You have built the head.";
                }
                return;
            }
            else cout << "You need a Body first\n";
            return;
        case 'L':
            if (isBodyPart(player, 'B')) {
                if (allParts(player, bodyPart)) {
                    cout << "You already have all your legs.\n";
                    return;
                }
                else {
                    for (int i = 2; i < 8; i++) {
                        if (player.at(i) == '_') {
                            player.replace(i, i, "L");
                            cout << " You have built a leg\n";
                            return;
                        }

                    }
                }
            }
            else cout << "You need a body first\n";
            return;
           

        case 'E':
            if (isBodyPart(player, 'H')) {
                if (allParts(player, bodyPart)) {
                    cout << "You already have all your eyes.\n";
                    return;
                }
                else {
                    for (int i = 8; i < 10; i++) {
                        if (player.at(i) == '_') {
                            player.replace(i, i, "E");
                            cout << "You have built an eye.\n";
                        }
                    }
                }

            }
            else {
                cout << "You need a head first\n";
            }
            return;
        case 'A':
            if (isBodyPart(player, 'H')) {
                if (allParts(player, bodyPart)) {
                    cout << "You already have all your antennas";
                    return;
                }
                else {
                    for (int i = 10; i < 12; i++) {
                        if (player.at(i) == '_') {
                            player.replace(i, i, "E");
                            cout << "You have built an antenna.\n";
                            return;
                        }

                    }
                }
            }
            else cout << "You need a Head first.\n"; 
            return;
        case 'T':
            if (isBodyPart(player, 'B')) {
                if (isBodyPart(player, bodyPart)) {
                    cout << "You already have a tail.\n";
                }
                else {
                    player.replace(12, 12, "T");
                    cout << "You have built a tail.\n";
                    return;
                }
            }
            else cout << "You need a body first.\n";
            return;
        }
    }
    

    bool allParts(string player, char bodyPart) {
        if (bodyPart == 'L')
            for (int i = 2; i < 8; i++)
                if (player.at(i) == '_')
                    return false;

        if (bodyPart == 'E')
            for (int i = 8; i < 10; i++)
                if (player.at(i) == '_')
                    return false;

        if (bodyPart == 'A')
            for (int i = 10; i < 12; i++)
                if (player.at(i) == '_')
                    return false;
        return true;
    }
    void displayBeetles(string playerBody) {
        
        for (int i = 0;  i < 4; i++) {
            cout << "         ";
            if (playerBody.at(10) == 'A') cout << "A";
            else cout << " ";
            cout << " ";
            if (playerBody.at(11) == 'A')cout<< "A\n";
            else cout << " \n";
        }
        if (isBodyPart(playerBody, 'H')) {
            cout << "       HHHHHHH\n";
            cout << "       H     H\n";
            cout << "       H ";
            if (playerBody.at(8) == 'E')cout << "O ";
            else cout << "  ";
            if (playerBody.at(9) == 'E') cout << "O H\n";
            else cout << "  H\n";
            cout << "       H  V  H\n";
            cout << "       HHHHHHH\n";
            cout << "         N N\n";
            cout << "         N N\n";
        }
        else "\n \n \n \n \n \n";
        if (isBodyPart(playerBody, 'B')) {
            cout << "    BBBBBBBBBBBB\n";
            cout << "    B          B\n";
            cout << "    B          B\n";
            if (isBodyPart(playerBody, 'T')) {
                cout << "TTTT";
            }
            else
            {
                cout << "    ";
            }
            cout << "B          B\n";
            cout << "    B          B\n";
            cout << "    B          B\n";
            cout << "    BBBBBBBBBBBB\n";

            if (playerBody.at(7) == 'L') {
                cout << "     L L L L L L\n";
                cout << "     L L L L L L\n";
            }
            else if (playerBody.at(6) == 'L') {
                cout << "     L L L L L \n";
                cout << "     L L L L L \n";
            }
            else if (playerBody.at(5) == 'L') {
                cout << "     L L L L \n";
                cout << "     L L L L \n";
            }
            else if (playerBody.at(4) == 'L') {
                cout << "     L L L  \n";
                cout << "     L L L \n";
            }
            else if (playerBody.at(3) == 'L') {
                cout << "     L L   \n";
                cout << "     L L  \n";
            }
            else if (playerBody.at(2) == 'L') {
                cout << "     L   \n";
                cout << "     L   \n";
            }
            else cout << "\n \n";
            }
        }
    
            
