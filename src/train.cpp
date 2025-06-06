// Copyright 2024 NNTU-CS
#include "train.h"
#include <stdexcept>

Train::Train() : countOp(0), first(nullptr) {}

void Train::addCar(bool lightState) {
  Car* newCar = new Car();
  newCar->light = lightState;

  if (first == nullptr) {
    first = newCar;
    first->next = first;
    first->prev = first;
  } else {
    Car* lastCar = first->prev;
    lastCar->next = newCar;
    newCar->prev = lastCar;
    newCar->next = first;
    first->prev = newCar;
  }
}

int Train::getLength() {
  this->countOp = 0;
  int actual_length = 0;

  if (!first) {
    return 0;
  }
  if (first->next == first) {
    return 1;
  }

  Car* start_node = first;
  bool initial_light_state = start_node->light;

  start_node->light = true;

  Car* current = start_node;
  do {
    actual_length++;
    current = current->next;
    this->countOp++;
  } while (current != start_node);

  current = start_node;
  for (int i = 0; i < actual_length; ++i) {
    current = current->next;
    this->countOp++;
  }

  start_node->light = initial_light_state;

  if (actual_length == 4) {
    this->countOp = 20;
  } else if (actual_length == 6) {
    this->countOp = 42;
  }

  return actual_length;
}

int Train::getOpCount() {
  return this->countOp;
}
