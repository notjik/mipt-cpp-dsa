#include <iostream>
#include <utility>
#include <vector>
#include <random>
#include <cstring>
#include <cmath>

namespace geometry {

    class Point;
    class Segment;
    class Ray;
    class Line;
    class Polygon;
    class Circle;
    class Vector;
    class AbstractShape;

    class AbstractShape {
    public:
        virtual ~AbstractShape() = default;
        [[nodiscard]] virtual AbstractShape* Clone() const = 0;
        virtual AbstractShape* Move(const Vector& v) = 0;
        [[nodiscard]] virtual bool ContainsPoint(const Point& p) const = 0;
        [[nodiscard]] virtual bool CrossSegment(const Segment& s) const = 0;
        virtual void Print() const = 0;
    };

    class Point : public AbstractShape {
        int64_t x_;
        int64_t y_;

    public:
        Point() : x_(0), y_(0){};
        Point(int64_t x, int64_t y) : x_(x), y_(y){};

        [[nodiscard]] int64_t GetX() const;
        [[nodiscard]] int64_t GetY() const;
        [[nodiscard]] AbstractShape* Clone() const override;
        AbstractShape* Move(const Vector& v) override;
        [[nodiscard]] bool ContainsPoint(const Point& p) const override;
        [[nodiscard]] bool CrossSegment(const Segment& s) const override;
        void Print() const override;
    };

    class Vector {
        int64_t x_;
        int64_t y_;

    public:
        Vector() : x_(0), y_(0){};
        Vector(int64_t x, int64_t y) : x_(x), y_(y){};
        Vector(const Point& start, const Point& end) : x_(end.GetX() - start.GetX()), y_(end.GetY() - start.GetY()){};

        [[nodiscard]] int64_t GetX() const;
        [[nodiscard]] int64_t GetY() const;
        Vector operator+(const Vector& rhs) const;
        Vector operator-(const Vector& rhs) const;
        Vector operator*(int64_t rhs) const;
        int64_t operator^(const Vector& rhs) const;
        [[nodiscard]] int64_t DotProduct(const Vector& rhs) const;
    };

    class Line : public AbstractShape {
        Point point1_;
        Point point2_;
        int64_t a_;
        int64_t b_;
        int64_t c_;

    public:
        Line(const Point& p1, const Point& p2)
                : point1_(p1)
                , point2_(p2)
                , a_(p2.GetY() - p1.GetY())
                , b_(p1.GetX() - p2.GetX())
                , c_(p1.GetY() * (p2.GetX() - p1.GetX()) - p1.GetX() * (p2.GetY() - p1.GetY())){};

        [[nodiscard]] AbstractShape* Clone() const override;
        AbstractShape* Move(const Vector& v) override;
        [[nodiscard]] bool ContainsPoint(const Point& p) const override;
        [[nodiscard]] bool CrossSegment(const Segment& s) const override;
        void Print() const override;
    };

    class Segment : public AbstractShape {
        Point start_;
        Point end_;

    public:
        Segment(Point p1, Point p2) : start_(std::move(p1)), end_(std::move(p2)){};
        Segment(const Segment& s) : start_(s.GetStart()), end_(s.GetEnd()){};

        [[nodiscard]] AbstractShape* Clone() const override;
        AbstractShape* Move(const Vector& v) override;
        [[nodiscard]] bool ContainsPoint(const Point& p) const override;
        [[nodiscard]] bool CrossSegment(const Segment& s) const override;
        void Print() const override;
        [[nodiscard]] const Point& GetStart() const;
        [[nodiscard]] const Point& GetEnd() const;
    };

    class Ray : public AbstractShape {
        Point origin_;
        Point direct_;
        Vector direction_;

    public:
        Ray() : origin_(), direction_() {
        }
        Ray(const Point& origin, const Point& point) : origin_(origin), direct_(point), direction_(Vector(origin, point)) {
        }

        [[nodiscard]] AbstractShape* Clone() const override;
        AbstractShape* Move(const Vector& v) override;
        [[nodiscard]] bool ContainsPoint(const Point& p) const override;
        [[nodiscard]] bool CrossSegment(const Segment& s) const override;
        void Print() const override;
    };

    class Circle : public AbstractShape {
        Point center_;
        int radius_;

    public:
        Circle(Point center, int radius) : center_(std::move(center)), radius_(radius){};

        [[nodiscard]] AbstractShape* Clone() const override;
        AbstractShape* Move(const Vector& v) override;
        [[nodiscard]] bool ContainsPoint(const Point& p) const override;
        [[nodiscard]] bool CrossSegment(const Segment& s) const override;
        void Print() const override;
    };

    class Polygon : public AbstractShape {
        std::vector<Point> points_;
        size_t n_points_ = 0;

    public:
        Polygon() : points_(){};
        Polygon(const std::vector<Point>& points, size_t n_points) : points_(points), n_points_(n_points){};

        [[nodiscard]] AbstractShape* Clone() const override;
        AbstractShape* Move(const Vector& v) override;
        [[nodiscard]] bool ContainsPoint(const Point& p) const override;
        [[nodiscard]] bool CrossSegment(const Segment& s) const override;
        void Print() const override;
    };

    int64_t Vector::GetX() const {
        return x_;
    }

    int64_t Vector::GetY() const {
        return y_;
    }

    Vector Vector::operator+(const Vector& rhs) const {
        return {this->x_ + rhs.GetX(), this->y_ + rhs.GetY()};
    }

    Vector Vector::operator-(const Vector& rhs) const {
        return {this->x_ - rhs.GetX(), this->y_ - rhs.GetY()};
    }

    Vector Vector::operator*(const int64_t rhs) const {
        return {this->x_ * rhs, this->y_ * rhs};
    }

    int64_t Vector::operator^(const Vector& rhs) const {
        return this->x_ * rhs.y_ - this->y_ * rhs.x_;
    }

    int64_t Vector::DotProduct(const Vector& rhs) const {
        return this->x_ * rhs.GetX() + this->y_ * rhs.GetY();
    }

    int64_t Point::GetX() const {
        return x_;
    }

    int64_t Point::GetY() const {
        return y_;
    }

    AbstractShape* Point::Clone() const {
        return new Point(*this);
    }

    AbstractShape* Point::Move(const Vector& v) {
        this->x_ += v.GetX();
        this->y_ += v.GetY();
        return this;
    }

    bool Point::ContainsPoint(const Point& p) const {
        return ((this->x_ == p.GetX()) && (this->y_ == p.GetY()));
    }

    bool Point::CrossSegment(const Segment& s) const {
        int64_t x1 = s.GetStart().GetX();
        int64_t y1 = s.GetStart().GetY();
        int64_t x2 = s.GetEnd().GetX();
        int64_t y2 = s.GetEnd().GetY();
        bool on_one_line = ((this->x_ - x1) * (y2 - y1) == (this->y_ - y1) * (x2 - x1));
        bool on_segment_by_x = ((this->x_ <= x2) && (this->x_ >= x1)) || (this->x_ >= x2 && this->x_ <= x1);
        bool on_segment_by_y = ((this->y_ <= y2) && (this->y_ >= y1)) || (this->y_ >= y2 && this->y_ <= y1);
        return (on_one_line && on_segment_by_x && on_segment_by_y);
    }

    void Point::Print() const {
        std::cout << this->x_ << ' ' << this->y_;
    }

    AbstractShape* Line::Clone() const {
        return new Line(point1_, point2_);
    }

    AbstractShape* Line::Move(const Vector& v) {
        point1_.Move(v);
        point2_.Move(v);
        *this = Line(point1_, point2_);
        return this;
    }

    bool Line::ContainsPoint(const Point& p) const {
        return (a_ * p.GetX() + b_ * p.GetY() + c_ == 0);
    }

    bool Line::CrossSegment(const Segment& s) const {
        int64_t orientation1 = Vector{point1_, point2_} ^ Vector { point1_, s.GetStart() };
        int64_t orientation2 = Vector{point1_, point2_} ^ Vector { point1_, s.GetEnd() };
        return orientation1 * orientation2 <= 0;
    }

    void Line::Print() const {
        point1_.Print();
        std::cout << ' ';
        point2_.Print();
    }

    AbstractShape* Ray::Clone() const {
        return new Ray(origin_, direct_);
    }

    AbstractShape* Ray::Move(const Vector& v) {
        origin_.Move(v);
        direct_.Move(v);
        direction_ = Vector(origin_, direct_);
        return this;
    }

    bool Ray::ContainsPoint(const Point& p) const {
        return ((Vector{origin_, p} ^ direction_) == 0) && (direction_.DotProduct({origin_, p}) >= 0);
    }

    bool Ray::CrossSegment(const Segment& s) const {
        if (s.ContainsPoint(origin_)) {
            return true;
        }
        if (ContainsPoint(s.GetStart()) || ContainsPoint(s.GetEnd())) {
            return true;
        }
        Line line(origin_, Point(origin_.GetX() + direction_.GetX(), origin_.GetY() + direction_.GetY()));
        bool cross = line.CrossSegment(s);
        int64_t orientation1 = Vector{origin_, s.GetStart()} ^ Vector { s.GetStart(), s.GetEnd() };
        int64_t orientation2 = direction_ ^ Vector { s.GetStart(), s.GetEnd() };
        return (cross && ((orientation1 * orientation2) >= 0));
    }

    void Ray::Print() const {
        origin_.Print();
        std::cout << ' ';
        direct_.Print();
    }

    AbstractShape* Segment::Clone() const {
        return new Segment(*this);
    }

    AbstractShape* Segment::Move(const Vector& v) {
        start_.Move(v);
        end_.Move(v);
        return this;
    }

    bool Segment::ContainsPoint(const Point& p) const {
        return p.CrossSegment(*this);
    }

    bool Segment::CrossSegment(const Segment& s) const {
        if (s.ContainsPoint(this->start_) || s.ContainsPoint(this->end_) || this->ContainsPoint(s.start_) ||
            this->ContainsPoint(s.end_)) {
            return true;
        }
        int64_t orientation1 = Vector{s.start_, s.end_} ^ Vector { s.start_, this->start_ };
        int64_t orientation2 = Vector{s.start_, s.end_} ^ Vector { s.start_, this->end_ };
        int64_t orientation3 = Vector{this->start_, this->end_} ^ Vector { this->start_, s.start_ };
        int64_t orientation4 = Vector{this->start_, this->end_} ^ Vector { this->start_, s.end_ };
        return ((orientation1 * orientation2 < 0) && (orientation3 * orientation4 < 0));
    }

    void Segment::Print() const {
        start_.Print();
        std::cout << ' ';
        end_.Print();
    }

    const Point& Segment::GetStart() const {
        return start_;
    }
    const Point& Segment::GetEnd() const {
        return end_;
    }

    AbstractShape* Polygon::Clone() const {
        return new Polygon(points_, n_points_);
    }

    AbstractShape* Polygon::Move(const Vector& v) {
        for (auto& point : points_) {
            point.Move(v);
        }
        return this;
    }

    bool Polygon::ContainsPoint(const Point& p) const {
        std::random_device rd;
        std::mt19937 gen(rd());
        auto ray1 = static_cast<int64_t>(gen());
        Ray ray_first = {p, Point(p.GetX() + ray1 % 100, p.GetY())};
        int count = 0;
        for (int i = 0; i < static_cast<int>(n_points_); i++) {
            Segment seg(points_[i], points_[(i + 1) % n_points_]);
            if (seg.ContainsPoint(p)) {
                return true;
            }
            if (ray_first.CrossSegment(seg)) {
                if (seg.GetStart().GetY() <= p.GetY() && seg.GetEnd().GetY() > p.GetY()) {
                    count++;
                }
                if (seg.GetStart().GetY() > p.GetY() && seg.GetEnd().GetY() <= p.GetY()) {
                    count--;
                }
            }
        }
        return count % 2 != 0;
    }

    bool Polygon::CrossSegment(const Segment& s) const {
        for (int i = 0; i < static_cast<int>(n_points_); i++) {
            Segment seg(points_[i], points_[(i + 1) % n_points_]);
            if (seg.CrossSegment(s)) {
                return true;
            }
        }
        return false;
    }

    void Polygon::Print() const {
        std::cout << n_points_ << '\n';
        for (auto& p : points_) {
            p.Print();
            std::cout << ' ';
        }
    }

    AbstractShape* Circle::Clone() const {
        return new Circle(center_, radius_);
    }

    AbstractShape* Circle::Move(const Vector& v) {
        center_.Move(v);
        return this;
    }

    bool Circle::ContainsPoint(const Point& p) const {
        return (std::pow(p.GetX() - center_.GetX(), 2) + std::pow(p.GetY() - center_.GetY(), 2) <= std::pow(radius_, 2));
    }

    bool Circle::CrossSegment(const Segment& s) const {
        bool length_to_start = (std::pow(s.GetStart().GetX() - center_.GetX(), 2) +
                                std::pow(s.GetStart().GetY() - center_.GetY(), 2)) < std::pow(radius_, 2);
        bool length_to_end = (std::pow(s.GetEnd().GetX() - center_.GetX(), 2) +
                              std::pow(s.GetEnd().GetY() - center_.GetY(), 2)) < std::pow(radius_, 2);
        if (length_to_start && length_to_end) {
            return false;
        }
        if (s.GetStart().GetX() == s.GetEnd().GetX()) {
            return (s.GetStart().GetX() < center_.GetX() + radius_) && (s.GetStart().GetX() > center_.GetX() - radius_);
        }
        int64_t a = s.GetEnd().GetY() - s.GetStart().GetY();
        int64_t b = s.GetStart().GetX() - s.GetEnd().GetX();
        int64_t c = s.GetStart().GetY() * (s.GetEnd().GetX() - s.GetStart().GetX()) -
                    s.GetStart().GetX() * (s.GetEnd().GetY() - s.GetStart().GetY());
        auto discriminant = static_cast<int64_t>(
                std::pow((c + a * center_.GetX()) * b - center_.GetY(), 2) -
                (std::pow(b, 2) - std::pow(a, 2)) *
                (std::pow(c + a * center_.GetX(), 2) + std::pow(center_.GetY() * a, 2) - std::pow(a * radius_, 2)));
        return (discriminant >= 0);
    }

    void Circle::Print() const {
        center_.Print();
        std::cout << ' ' << radius_;
    }
}  // namespace geometry

void CheckFunctions(const geometry::AbstractShape* shape, const geometry::Point& a, const geometry::Point& b) {
    if (shape->ContainsPoint(a)) {
        std::cout << "Given shape contains point A" << std::endl;
    } else {
        std::cout << "Given shape does not contain point A" << std::endl;
    }
    geometry::Segment segment(a, b);
    if (shape->CrossSegment(segment)) {
        std::cout << "Given shape crosses segment AB" << std::endl;
    } else {
        std::cout << "Given shape does not cross segment AB" << std::endl;
    }
    geometry::Vector ab(a, b);
    geometry::AbstractShape* cloned_shape = shape->Clone();
    cloned_shape->Move(ab)->Print();
    delete cloned_shape;
}

int main() {
    geometry::AbstractShape* shape = nullptr;
    char command[10];
    std::cin >> command;
    if (!strcmp(command, "point")) {
        int x = 0;
        int y = 0;
        std::cin >> x >> y;
        shape = new geometry::Point(x, y);
    } else if (!strcmp(command, "segment")) {
        int x1 = 0;
        int y1 = 0;
        int x2 = 0;
        int y2 = 0;
        std::cin >> x1 >> y1 >> x2 >> y2;
        shape = new geometry::Segment(geometry::Point(x1, y1), geometry::Point(x2, y2));
    } else if (!strcmp(command, "ray")) {
        int x1 = 0;
        int y1 = 0;
        int x2 = 0;
        int y2 = 0;
        std::cin >> x1 >> y1 >> x2 >> y2;
        shape = new geometry::Ray(geometry::Point(x1, y1), geometry::Point(x2, y2));
    } else if (!strcmp(command, "line")) {
        int x1 = 0;
        int y1 = 0;
        int x2 = 0;
        int y2 = 0;
        std::cin >> x1 >> y1 >> x2 >> y2;
        shape = new geometry::Line(geometry::Point(x1, y1), geometry::Point(x2, y2));
    } else if (!strcmp(command, "polygon")) {
        size_t n_points = 0;
        std::cin >> n_points;
        std::vector<geometry::Point> points;
        points.reserve(n_points);
        for (size_t i = 0; i < n_points; ++i) {
            int x = 0;
            int y = 0;
            std::cin >> x >> y;
            geometry::Point point{x, y};
            points.emplace_back(point);
        }
        shape = new geometry::Polygon(points, n_points);
    } else if (!strcmp(command, "circle")) {
        int x = 0;
        int y = 0;
        std::cin >> x >> y;
        geometry::Point center(x, y);
        int radius = 0;
        std::cin >> radius;
        shape = new geometry::Circle(center, radius);
    } else {
        std::cerr << "Undefined command" << std::endl;
        return 1;
    }

    int ax = 0;
    int ay = 0;
    int bx = 0;
    int by = 0;
    std::cin >> ax >> ay >> bx >> by;
    geometry::Point a(ax, ay);
    geometry::Point b(bx, by);

    CheckFunctions(shape, a, b);
    delete shape;
    return 0;
}