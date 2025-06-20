#include <iostream>
#include <string>

void CheckPlate(std::string plate) {
  if (plate.size() != 6) {
    std::cout << "No";
    return;
  }

  if (plate[0] >= 'A' && plate[0] <= 'Z') {
    for (int i = 1; i < 4; i++) {
      if (plate[i] < '0' || plate[i] > '9') {
        std::cout << "No";
        return;
      }
    }
    if ((plate[4] >= 'A' && plate[4] <= 'Z') && (plate[5] >= 'A' && plate[5] <= 'Z')) {
          std::cout << "Yes";
    } else {
      std::cout << "No";
    }
  } else{
    std::cout << "No";
  }
}

int main() {
  std::string plate;
  std::cin >> plate;
  CheckPlate(plate);
}
