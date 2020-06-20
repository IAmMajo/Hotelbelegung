using namespace std;

#include <windows.h>
#include <iostream>
#include <string>

bool rooms[6][10];

int getInput(const string message, const int maximum) {
  cout <<
    endl <<
    message <<
    endl;
  string input;
  getline(cin, input);

  /* Rückgabe der Eingabe als Zahl, wenn die Eingabe eine Zahl zwischen 1 und
  maximum ist. Ansonsten erfolgt ein Selbstaufruf. */
  return (input.length() == 1 || input.length() == 2 && isdigit(input[1])) &&
    isdigit(input[0]) &&
    stoi(input) > 0 &&
    stoi(input) <= maximum
    ? stoi(input)
    : getInput(message, maximum);
}

void showRooms() {
  int i = 0;
  int j = 0;
  /*Die Zimmer der einzelnen Etagen werden nach und nach abgelaufen.*/
  while (i<6) 
  {
    cout<<i+1<<".Etage"<<endl;
    while (j<10) {
      if (rooms [i] [j] == 0)
      {
        cout<<j+1<<".Zimmer: frei"<<endl;
      }
      else
      {
        cout<<j+1<<".Zimmer: belegt"<<endl;
      }
    j++;
    }
  i++;
  }
}

void showRoom() {  
  int room = getInput(
    "Für welches Zimmer soll der Status überprüft werden?",
    60
  );
  /*Die Zimmernummer muss um 1 verkürzt werden, da das Array bei 0 0 beginnt und nicht bei 0 1. */
  room = room - 1;
  int floor = room / 10;
  int roomnumber = room % 10;
  /*Alle Zimmer, die mit false belegt sind, sind freie Zimmer.*/
  if (rooms [floor] [roomnumber] == 0)
  {
    cout<<"Das Zimmer ist noch nicht belegt!"<<endl;
  }
  else
  {
    cout<<"Das Zimmer ist bereits belegt!"<<endl;
  }
}

void checkIn() {}

void checkOut() {}

int main() {
  /* Ändern der von der Konsole benutzten Zeichenkodierung zu UTF-8, damit
  alle Zeichen richtig dargestellt werden. */
  SetConsoleCP(CP_UTF8);
  SetConsoleOutputCP(CP_UTF8);

  while (1) {
    const int action = getInput(
      "Was möchtest du tun?\n1: Den aktuellen Status des gesamten Hotels "
      "abrufen\n2: Den aktuellen Status eines einzelnen Zimmers (frei/belegt) "
      "abrufen\n3: Einchecken\n4: Auschecken",
      4
    );
    action == 1
      ? showRooms()
      : action == 2
      ? showRoom()
      : action == 3
      ? checkIn()
      : checkOut();
  }
}
