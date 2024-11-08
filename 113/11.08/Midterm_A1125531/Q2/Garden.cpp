#include "iostream"
#include "Garden.h"

using namespace Garden;

Plant::Plant(string name, float height, string color, string shape) : name(name), height(height), color(color), shape(shape) {};

void Plant::grow(float h) {
    height += h;
}

void Plant::bloom(string c) {
    color = c;
}

void Plant::transform(string s) {
    shape = s;
}

Gardener::Gardener(int plantCnt) : plantCnt(plantCnt) {};

void Gardener::nurture(Plant& plant) {

}

void Gardener::nurture(Plant* plant) {

}

void Gardener::setMax(int max) {
    MaxPlant = max;
}

void Gardener::analyze(const Plant plant) const {
    cout << plant.name << " " << plant.height << " " << plant.color << " " << plant.shape << "\n";
}

void Gardener::addPlant(string name, float height, string color, string shape) {
    
}

Plant Gardener::findPlant(string plantName) {

}