#include <iostream>
#include <fstream>
#include <string>
 // To-Do:
 // Reading dial turns from file
 // If the line in the file contains an L rotate/minus startDial "X" amount e.g. Dial starts at 50, L32 means rotate the dial 32 clicks to the left
 // Now, the dial is pointing at 18
 // The dial ranges from 0 - 99
 // If the dial goes over 99, it wraps around to 0. If the dial goes less than 0, it will wrap around to 99
 // 1. Read from file, line by line
 // 2. Find strings that contain the character "L" or "R" and extract the digits after it
 // 3. Have logic to wrap around to 99 or 0 (depending where the dial is pointing at)
 // 4. Determine rotating Left (subtract?) and Right (Addition?)
 // 5. Determine when the currentDial is pointing to 0 (This will determine the password, depending on how many times it clicks to 0)
 
int main() {

 const int dialSize = 100;
 int currentDial = 50;
 int counter = 0;

 std::ifstream file("dialPassword.txt");
 std::string str;

 while (std::getline(file, str)) {
 if(str.empty()) continue;
  char direction = str[0]; // L or R
  int magnitude  = std::stoi(str.substr(1));

  if(direction == 'L') {
   currentDial -= magnitude;
  }
  else if(direction == 'R') {
   currentDial += magnitude;
  }
  else {
   continue;
  }
 // TO DO:
 // Everytime currentDial turns 100 times. E.g. R731, everytime it passes 0, add 1 to the counter, so the counter in this example would be 7 
 // std::floor(magnitude);
  currentDial = ((currentDial % dialSize) + dialSize) % dialSize;

  if(currentDial == 0) {
   counter++;
  }

}

 std::cout << "\nTotal Zeros:" << counter; 
 return 0;
}
