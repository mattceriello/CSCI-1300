#include <string>
using namespace std;

class Planet{
    
    private:
        string planetName;
        double planetRadius;
    
    public:
        Planet();
        Planet(string, double);
        string getName();
        void setName(string);
        double getRadius();
        void setRadius(double);
        double getVolume();
    
    
};