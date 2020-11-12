//
// Created by Yang on 2020/11/12.
//

#ifndef RAYTRACE_AARECT_H
#define RAYTRACE_AARECT_H

#include "rtweekend.h"
#include "hittable.h"

class xy_rect : public hittable {

public:
    shared_ptr<material> mp;
    double x0, x1, y0, y1, k;
public:
    xy_rect() {}

    xy_rect(double _x0, double _x1, double _y0, double _y1, double _k, shared_ptr<material> mat)
            : x0(_x0), x1(_x1), y0(_y1), y1(_y1), k(_k), mp(mat) {}

            bool hit(const ray& r,double t_min,double t_max)
};


#endif //RAYTRACE_AARECT_H
