//
// Created by preben on 23.03.18.
//

#ifndef IMPERFGPS_POINT_H
#define IMPERFGPS_POINT_H
class vec {
private:

public:
    double x,y;

    vec(double, double);

    void times(double);

    void minus(vec);

    void add(vec);

    double dot_prod(vec);

    double dist(vec,vec);
};
#endif //IMPERFGPS_POINT_H
