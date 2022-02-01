class Solution {
    double radius, x_center,y_center;
public:    
    Solution(double radius, double x_center, double y_center) {
        this->radius = radius;
        this->x_center = x_center;
        this->y_center = y_center;
        srand(time(0));
    }
    
    double random () {
        return (double) rand()/RAND_MAX;
    }
    
    
    vector<double> randPoint() {
        double l = radius * sqrt(random());
        double deg = 2 * M_PI * random();
        double x = x_center + l * cos(deg);
        double y = y_center + l * sin(deg);
        return {x, y};
    }
};