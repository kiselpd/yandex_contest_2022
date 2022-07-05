#include <iostream>

class Field
{
private:
    char** field_;
    size_t height_;
    size_t width_;

public:
    Field(size_t height, size_t width);
    ~Field();
    void fillField();
    char** reflectField();

private:
    void drawHexagon(char** field, size_t position_h, size_t position_w);
};

Field::Field(size_t height, size_t width) : height_(height), width_(width)
{
    try
    {
        this->field_ = new char*[this->height_];

        for (size_t i = 0; i < this->height_; i++)
            this->field_[i] = new char[this->width_];
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}

Field::~Field()
{
    for (size_t i = 0; i < this->height_; i++)
        delete []this->field_[i];

    delete[] this->field_;
}

void Field::drawHexagon(char** field, size_t position_h, size_t position_w)
{
    field[position_h - 1][position_w] = field[position_h + 1][position_w] = '_';
    field[position_h][position_w - 1] = field[position_h + 1][position_w + 1] = '/';
    field[position_h][position_w + 1] = field[position_h + 1][position_w - 1] = '\\';
}

void Field::fillField()
{
    for (size_t i = 0; i < this->height_; i++)
        for (size_t j = 0; j < this->width_; j++)
            std::cin >> this->field_[i][j];
}

char** Field::reflectField()
{
    char **new_field;

    try
    {
        new_field = new char*[this->height_];

        for (size_t i = 0; i < this->height_; i++)
        {
            new_field[i] = new char[this->width_];

            for (size_t j = 0; j < this->width_; j++)
                new_field[i][j] = '.';
        }
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    for (size_t i = 0; i < this->height_; i++)
    {
        for (size_t j = 0; j < this->width_; j++)
        {
            if((this->field_[i][j] - 'A' >= 0) && ('Z' - this->field_[i][j]  >= 0))
            {
                new_field[this->height_ - i - 1][this->width_ - j - 1] = this->field_[i][j];
                drawHexagon(new_field, this->height_ - i - 1, this->width_ - j - 1);
            }
        }
    }

    return new_field;
}

void showField(char** field, size_t height, size_t width)
{
    for (size_t i = 0; i < height; i++)
    {
        for (size_t j = 0; j < width; j++)
            std::cout << field[i][j];

        std::cout << std::endl;
    }
}

int main()
{
    size_t height;
    size_t width;

    std::cin >> height >> width;

    Field solution(height, width);

    solution.fillField();

    char **answer_field = solution.reflectField();

    showField(answer_field, height, width);

    for (size_t i = 0; i < height; i++)
        delete []answer_field[i];

    delete[] answer_field;

    return 0;
}