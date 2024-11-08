#include "iostream"
#include "Garden.h"

using namespace std;

int main() {
    Garden::Gardener gardener;

    int N;
    string name, color, shape, cmd;
    float height;
    cin >> N;
    gardener.setMax(N);

    while (1) {
        cin >> cmd;
        if (cmd == "end") return 0;

        if (cmd == "add") {
            cin >> name >> height >> color >> shape;
            gardener.addPlant();
        }

        if (cmd == "grow")

        if (cmd == "bloom") 

        if (cmd == "transform")

        if (cmd == "analyze") {

        }

        if (cmd == "nurtureH") 

        if (cmd == "nurtureS")
    }

    return 0;
}