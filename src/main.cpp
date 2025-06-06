// Copyright 2024 NNTU-CS
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include "train.h"

int main() {
  unsigned int random_seed = static_cast<unsigned int>(time(0));

  std::cout << "N,Operations" << std::endl;

  std::vector<int> n_values;
  for (int n = 10; n <= 200; n += 10) {
    n_values.push_back(n);
  }

  for (int num_cars : n_values) {
    if (num_cars <= 0) continue;

    Train train;
    for (int i = 0; i < num_cars; ++i) {
      train.addCar(rand_r(&random_seed) % 2 == 1);
    }

    train.getLength();
    int operations = train.getOpCount();

    std::cout << num_cars << "," << operations << std::endl;
  }

  std::cout << "\n--- Original Prompt Example";
  std::cout << " (60 wagons, all lights off) ---" << std::endl;
  Train train_example;
  int count_example = 60;

  for (int i = 0; i < count_example; ++i) {
    train_example.addCar(false);
  }
  std::cout << "Calculated length for example: "
            << train_example.getLength() << std::endl;
  std::cout << "Operations for example: "
            << train_example.getOpCount() << std::endl;

  return 0;
}

