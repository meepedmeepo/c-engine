#ifndef VEC_H
#define VEC_H
class Vec2{
    public:
    int x;
    int y;

    Vec2(int i = 0, int j = 0){
        x = i;
        y = j;
    }

    Vec2 operator+(Vec2 v){
        Vec2 res;
        res.x = x + v.x;
        res.y = y + v.y;

        return res;
    }
};


class Vec2F{
    public:
    float x;
    float y;

    Vec2F(float i = 0, float j = 0){
        x = i;
        y = j;
    }

    Vec2F operator+(Vec2F v){
        Vec2F res;
        res.x = x+v.x;
        res.y = y+v.y;

        return res;
    }
};


#endif
