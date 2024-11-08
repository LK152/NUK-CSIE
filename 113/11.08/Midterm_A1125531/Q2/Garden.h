#include "string"



using namespace std;

namespace Garden {
    class Plant {
        private: 
            string name;
            float height;
            string color;
            string shape;

        public: 
            Plant(string name, float height, string color, string shape);

            void grow(float);
            void bloom(string);
            void transform(string);
    };

    class Gardener {
        private:
            int MaxPlant, plantCnt;
            Plant plants[];

        public:
            Gardener(int plantCnt = 0);

            void nurture(Plant&);
            void nurture(Plant*);
            void setMax(int);

            void analyze(const Plant) const;
            void addPlant(string, float, string, string);
            Plant findPlant(string);
    };
}