#include <iostream>
#include <numeric>
#include <vector>
#include <map>
#include <iterator>
#include <random>

template <typename T>
std::ostream& operator<<(std::ostream& os, std::vector<T> vector) {
    os << '[';
    std::copy(std::begin(vector), std::prev(std::end(vector)),
              std::ostream_iterator<T>(os, ", "));
    return os << *std::prev(std::end(vector)) << ']';
}

int main() {
    std::vector<int> nums{5, 10, 37, 2, 15, 8, 106, 42};

    for(auto it = std::begin(nums); it != std::end(nums); it++) {
        std::cout << *it << ' ';
    }
    std::cout << std::endl;

    // Sum of elements
    std::cout << "Sum = " <<
    std::accumulate(std::next(std::begin(nums), 5), std::end(nums), 0)
    << std::endl;
    std::cout << "Product = " <<
    std::accumulate(std::begin(nums), std::end(nums), 1ll,
                    [](auto lhs, auto rhs){return lhs * rhs;})
                    << std::endl;

    std::vector<int> nums_r(std::size(nums));
    std::copy(std::begin(nums), std::end(nums), std::begin(nums_r));

    std::reverse(std::begin(nums_r), std::end(nums_r));

    for(auto item: nums_r) {
        std::cout << item << ' ';
    }
    std::cout << std::endl;

    std::cout << "Inner product: " << std::inner_product(
            std::begin(nums),
            std::end(nums),
            std::begin(nums_r),
            0
            ) << std::endl;

    std::cout << "Max element: " << *std::max_element(
            std::begin(nums), std::end(nums)) << std::endl;
    std::cout << "Min element: " << *std::min_element(
            std::begin(nums), std::end(nums)) << std::endl;
    auto [min, max] = std::minmax_element(std::begin(nums), std::end(nums));
    std::cout << *min << ' ' << *max << std::endl;

    auto to_delete = std::remove_if(std::begin(nums), std::end(nums),
                   [](auto element){return element < 10;});
    nums.erase(to_delete, std::end(nums));

    for(auto it = std::begin(nums); it != std::end(nums); it++) {
        std::cout << *it << ' ';
    }
    std::cout << std::endl;

    std::vector<int> rotated;
    std::rotate_copy(std::begin(nums),
                     std::next(std::begin(nums), 2),
                     std::end(nums), std::back_inserter(rotated));

    std::cout << rotated << std::endl;

    std::transform(std::begin(rotated), std::end(rotated),
                   std::begin(rotated),
                   [](auto elem){return elem + 1;});

    std::cout << rotated << std::endl;

    std::vector<int> products;
    std::transform(std::begin(rotated), std::end(rotated),
                   std::begin(rotated), std::back_inserter(products),
                   [](auto lhs, auto rhs) {return lhs * rhs;});
    std::cout << "Products are " << products << std::endl;
    std::cout << "Square of length is " <<
    std::accumulate(std::begin(products), std::end(products), 0)
    << std::endl;


    std::default_random_engine generator(0);

    std::shuffle(std::begin(products), std::end(products), generator);

    std::cout << products << std::endl;

    // 1. iota
    // 3. shuffle ?
    // 4. unique + .erase (удаление последовательных дубликатов)
    // 5. count_if
    // 7. find_if
    // 8. transform
    // 9. generate_n + rand()
    // 11. replace_if
    // 12. transform
    // 13. replace_if
    // 14. remove + erase
    // 15. reverse
    // 16. partial_sort | nth_element
    // 17. sort
    // 18. merge -- для отсортированных
    // 19. equal_range -- для отсортированных
    return 0;
}
