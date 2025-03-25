class Shape {
    protected:
        string color;
        pair<double, double> position;
        double borderThickness;
    
    public:
        Shape(string c, pair<double, double> pos, double border = 1.0)
            : color(c), position(pos), borderThickness(border) {}
    
        virtual void draw() {
            cout << "Drawing a generic shape at (" << position.first << ", " << position.second << ")" << endl;
        }
    
        virtual double calculateArea() = 0;
        virtual double calculatePerimeter() = 0;
    };
    
    class Circle : public Shape {
        double radius;
    
    public:
        Circle(string c, pair<double, double> pos, double r, double border = 1.0)
            : Shape(c, pos, border), radius(r) {}
    
        void draw() override {
            cout << "Drawing a " << color << " circle with radius " << radius << endl;
        }
    
        double calculateArea() override {
            return 3.14159 * radius * radius;
        }
    
        double calculatePerimeter() override {
            return 2 * 3.14159 * radius;
        }
    };
    
    class Rectangle : public Shape {
        double width;
        double height;
    
    public:
        Rectangle(string c, pair<double, double> pos, double w, double h, double border = 1.0)
            : Shape(c, pos, border), width(w), height(h) {}
    
        void draw() override {
            cout << "Drawing a " << color << " rectangle " << width << "x" << height << endl;
        }
    
        double calculateArea() override {
            return width * height;
        }
    
        double calculatePerimeter() override {
            return 2 * (width + height);
        }
    };