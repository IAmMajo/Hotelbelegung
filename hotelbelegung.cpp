using namespace std;

#include <windows.h>
#include <iostream>
#include <string>

bool rooms[6][10];

int getInput(const string message, const int maximum) {
  cout << endl << message << endl;
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

bool* getRoom() {
  /* Abfragen der Etagen- und Zimmernummer und Rückgabe eines Pointers zum
  dadurch ermittelten Zimmer */
  return &rooms[getInput("Wie lautet die Etagennummer?", 6) - 1][
    getInput("Wie lautet die Zimmernummer?", 10) - 1
  ];
}

void showRooms() {
  int i = 0;
  int j = 0;
  /*Die Zimmer der einzelnen Etagen werden nach und nach abgelaufen.*/
  while (i<6) 
  {
    j = 0;
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
  /*Alle Zimmer, die mit false belegt sind, sind freie Zimmer.*/
  if (*getRoom() == 0)
  {
    cout<<"Das Zimmer ist noch nicht belegt!"<<endl;
  }
  else
  {
    cout<<"Das Zimmer ist bereits belegt!"<<endl;
  }
}

void checkInNext() {
  for (int i = 0; i < 6; i++) {
    for (int j = 0; j < 10; j++) {
      if (!rooms[i][j]) {
        rooms[i][j] = 1;
        printf(
          "\nDas nächste freie Zimmer wurde belegt. Es hat die Etagennummer %d "
          "und die Zimmernummer %d.\n",
          i + 1,
          j + 1
        );
        return;
      }
    }
  }
}

void checkInSpecific() {
  bool* room = getRoom();
  puts(
    *room
      ? "\nDas Zimmer ist voll!"
      : "\nDas Zimmer wurde belegt."
  );
  *room = 1;
}

void checkIn() {
  for (const auto& floorRooms: rooms) {
    for (const bool room: floorRooms) {
      if (!room) {
        getInput(
          "In welches Zimmer soll eingecheckt werden?\n1: Das nächste freie "
          "Zimmer\n2: Ein bestimmtes Zimmer",
          2
        ) == 1
          ? checkInNext()
          : checkInSpecific();
        return;
      }
    }
  }
  puts("\nAlle Zimmer sind voll!"); 
}

void checkOut() {
  bool* room = getRoom();
  puts(
    *room
      ? "\nDas Zimmer wurde als frei gespeichert."
      : "\nDas eingegebene Zimmer ist bereits frei!"
  );
  *room = 0;
}

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
