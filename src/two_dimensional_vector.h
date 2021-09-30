class TwoDimensionalVector {
public:
    TwoDimensionalVector(double x, double y) {}

    double x() const { }

    double y() const { }

    double length() const { }

    double dot(TwoDimensionalVector vec) const { }

    double cross(TwoDimensionalVector vec) const { }

    TwoDimensionalVector substract(TwoDimensionalVector vec) const { }

    std::string info() const { }
};