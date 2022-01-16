//
// Created by abder on 16/01/2022.
//
#pragma once

#include <vector>
#include <ostream>

using Vertex = std::pair<int, int>;

class Polygon
{
    friend std::ostream& operator<<(std::ostream& stream, const Polygon& polygon);

public:
    void add_vertex(int x, int y);
    static int                 fcn_static();
    const Vertex& get_vertex(size_t idx) const;


private:
    std::vector<Vertex> _vertices;
};

