#pragma once

#include <iostream>

class Menu {
public:
    void create_figure();

    void display();

    void display_with_perimeters();

    void display_sum();

    void sort_figures();

    void delete_figure_by_number();

    void delete_figures_by_perimeter();

    ~Menu();
}