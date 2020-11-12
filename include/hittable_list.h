//
// Created by Yang on 2020/11/10.
//

#ifndef RAYTRACE_HITTABLE_LIST_H
#define RAYTRACE_HITTABLE_LIST_H


#include "hittable.h"
#include <memory>
#include <utility>
#include <vector>

using std::shared_ptr;
using std::make_shared;

class hittable_list : public hittable {

public:
    std::vector<shared_ptr<hittable>> objects;
public:
    hittable_list() = default;

    hittable_list(shared_ptr<hittable> object) { add(std::move(object)); }

    void clear() { objects.clear(); }

    void add(const shared_ptr<hittable> &object) { objects.push_back(object); }

    bool hit(
            const ray &r, double t_min, double t_max, hit_record &rec
    ) const override;

    bool bounding_box(
            double time0, double time1, aabb &output_box
    ) const override;


};

bool hittable_list::hit(const ray &r, double t_min, double t_max, hit_record &rec) const {
    hit_record temp_rec;
    bool hit_anything = false;
    double closet_so_far = t_max;

    for (const auto &object:objects) {
        if (object->hit(r, t_min, closet_so_far, temp_rec)) {
            hit_anything = true;
            closet_so_far = temp_rec.t;
            rec = temp_rec;
        }
    }
    return hit_anything;
}

bool hittable_list::bounding_box(double time0, double time1, aabb &output_box) const {
    if (objects.empty()) return false;

    aabb temp_box;
    bool first_box = true;

    for (const auto &object : objects) {
        if (!object->bounding_box(time0, time1, temp_box)) return false;
        output_box = first_box ? temp_box : surrounding_box(output_box, temp_box);
        first_box = false;
    }

    return true;
}


#endif //RAYTRACE_HITTABLE_LIST_H
