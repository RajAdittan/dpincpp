//
// Created by rajam on 8/17/2018.
//

#include <iostream>
#include <vector>

using namespace std;
//using namespace boost;

enum class Color { red, green, blue };
enum class Size { small, medium, large };

struct Product {
    string name;
    Color color;
    Size size;
};

struct ProductFilter {
    typedef vector<Product*> Items;
    Items by_color(Items items, const Color color) {
        Items result;
        for(auto & item : items) {
            if(item->color == color) {
                result.push_back(item);
            }
        }
        return result;
    }

    Items by_size(Items items, const Size size) {
        Items result;
        for(auto & item : items) {
            if(item->size == size) {
                result.push_back(item);
            }
        }
        return result;
    }

    Items by_size_and_color(Items items, const Color color, const Size size) {
        Items result;
        for(auto & item : items) {
            if(item->color == color && item->size == size) {
                result.push_back(item);
            }
        }
        return result;
    }
};


struct ProductPrinter {
    typedef vector<Product*> Items;
    static void print(Product* item) {
        cout << '\t' << "name:" << item->name << ',';
        cout << '\t' << "size:" << (int)item->size << ',';
        cout << '\t' << "color:" << (int)item->color << '\n';
    }

    static void print(Items const &items) {
        for(auto & item : items) {
            print(item);
        }
    }
};
template <typename T> struct AndSpecification;
template <typename T> struct OrSpecification;

template <typename T> struct Specification {
    virtual bool is_satisfied(T* item) const = 0;
};

template <typename T> AndSpecification<T> operator && (
        const Specification<T>& lhs,
        const Specification<T>& rhs) {
    return AndSpecification<T>(lhs, rhs);
}

template <typename T> OrSpecification<T> operator || (
        const Specification<T>& lhs,
        const Specification<T>& rhs) {
    return OrSpecification<T>(lhs, rhs);
}

template <typename T> struct AndSpecification : Specification<T> {
    const Specification<T>& lhs;
    const Specification<T>& rhs;

    AndSpecification(const Specification<T> &lhs,
            const Specification<T> &rhs) : lhs(lhs), rhs(rhs) {}

    bool is_satisfied(T *item) const override {
        if(item == nullptr) return false;
        return lhs.is_satisfied(item) && rhs.is_satisfied(item);
    }
};

template <typename T> struct OrSpecification : Specification<T> {
    const Specification<T>& lhs;
    const Specification<T>& rhs;

    OrSpecification(const Specification<T> &lhs,
                     const Specification<T> &rhs) : lhs(lhs), rhs(rhs) {}

    bool is_satisfied(T *item) const override {
        if(item == nullptr) return false;
        return lhs.is_satisfied(item) || rhs.is_satisfied(item);
    }
};

template <typename T> struct Filter {
    virtual vector<T*> apply(vector<T*> items, Specification<T>& spec) = 0;
};

struct ProductFilter2 : Filter<Product> {
    vector<Product *> apply(vector<Product *> items, Specification<Product> &spec) override {
        vector<Product *> result;
        for(auto & item : items) {
            if(spec.is_satisfied(item)) {
                result.push_back(item);
            }
        }
        return result;
    }
};

struct ColorSpec : Specification<Product> {
    Color color;
    ColorSpec(Color color) : color(color) {}

    bool is_satisfied(Product *item) const override {
        if(nullptr == item) return false;
        return item->color==this->color;
    }
};

struct SizeSpec : Specification<Product> {
    Size size;
    SizeSpec(Size size) : size(size) {}

    bool is_satisfied(Product *item) const override {
        if(nullptr==item) return false;
        return item->size==this->size;
    }
};

int main(int argc, char* argv[]) {

    Product apple{"Apple", Color::blue, Size::large};
    Product tree{"Tree", Color::green, Size::large};
    Product house{"House", Color::red, Size::medium};
    Product ferrari{"Ferrari", Color ::red, Size::medium};

    ProductFilter::Items items {&apple, &tree, &house, &ferrari};

    ProductFilter productFilter;
    auto result = productFilter.by_size(items, Size::large);
    if(result.size()) {
        cout << "large items found:" << '\n';
        ProductPrinter::print(result);
    }

    ProductFilter2 productFilter2;

    ColorSpec redColor(Color::red);
    SizeSpec largeSize(Size::large);

    auto result2 = productFilter2.apply(items, redColor);
    if(result2.size()) {
        cout << "red color products: " << '\n';
        ProductPrinter::print(result2);
    }

    auto redOrLargeSpec = ColorSpec(Color::red)
            || SizeSpec(Size::large);
    auto result3 = productFilter2.apply(items, redOrLargeSpec);
    if(result2.size()) {
        cout << "red color or large size products: " << '\n';
        ProductPrinter::print(result2);
    }

    return 0;
}
