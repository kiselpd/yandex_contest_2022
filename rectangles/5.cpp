#include <iostream>
#include <map>
#include <vector>
#include <algorithm>  

struct Rectangle
{
    int x1_;
    int y1_;
    int x2_;
    int y2_;

    bool operator!=(const Rectangle r);
};

bool Rectangle::operator!=(const Rectangle r)
{
    return ((this->x1_ != r.x1_) || (this->x2_ != r.x2_) || (this->y1_ != r.y1_) || (this->y2_ != r.y2_));
}

bool isRectToRect(const Rectangle r1, const Rectangle r2)
{
    return (r1.x1_ < r2.x2_) && (r2.x1_ < r1.x2_) && (r1.y1_ < r2.y2_) && (r2.y1_ < r1.y2_);
}

bool comparator (std::pair<Rectangle, size_t> a, std::pair<Rectangle, size_t> b)
{
    return (a.first.x1_ < b.first.x1_) && (a.first.y1_ < b.first.y1_);
}

int main()
{
    size_t count;

    std::cin>>count;

    std::vector<std::pair<Rectangle, size_t>> vec_r(count);

    for (size_t i = 0; i < count; i++)
    {
        int x1, y1, x2, y2;

        std::cin >> x1 >> y1 >> x2 >> y2;
        vec_r[i].first.x1_ = x1;
        vec_r[i].first.y1_ = y1;
        vec_r[i].first.x2_ = x2;
        vec_r[i].first.y2_ = y2;
        vec_r[i].second = 0;
    }
    
    std::vector<std::pair<Rectangle, size_t>> vec_r_sort(vec_r);

    sort(vec_r_sort.begin(), vec_r_sort.end(), comparator);

    for (size_t i = 0; i < count; i++)
    {
        size_t j = 0;
        while(((vec_r[i].first.x2_ > vec_r_sort[j].first.x1_) || (vec_r[i].first.y2_ > vec_r_sort[j].first.y1_)) && (j < count))
        {
            if (isRectToRect(vec_r[i].first, vec_r_sort[j].first) && (vec_r[i].first != vec_r_sort[j].first))
            {
                vec_r[i].second++;
            }
            j++;
        }
    }
    
    for (size_t i = 0; i < count; i++)
    {
        std::cout << vec_r[i].second << " ";
    }

    return 0;
}