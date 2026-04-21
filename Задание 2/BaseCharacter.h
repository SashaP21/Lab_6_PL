#ifndef _2_BASECHARACTER_H
#define _2_BASECHARACTER_H

class BaseCharacter {
protected:
    double pos_x;
    double pos_y;
    double hp;
public:
    virtual ~BaseCharacter() = default;
    BaseCharacter(double pos_x = 0, double pos_y = 0, double hp = 100);
    void move(double delta_x, double delta_y);
    bool is_alive() const;
    void get_damage(double amount);
    double get_x() const;
    double get_y() const;
    double get_hp() const;
};

double distance(const BaseCharacter& c1, const BaseCharacter& c2);

#endif //_2_BASECHARACTER_H