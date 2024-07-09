#ifndef USERS_H
#define USERS_H

#include <QObject>
#include <iostream>

class Users
{
public:
    QString name, family_name, username, password, age, email, gender;
    Users();
    friend std::ostream &operator<<(std::ostream &output, Users &u)
    {
        output << u.password.toStdString() << std::endl
               << "Name :" << u.name.toStdString() << std::endl
               << "Family Name :" << u.family_name.toStdString() << std::endl
               << "Age:" << u.age.toStdString() << std::endl
               << "Email:" << u.email.toStdString() << std::endl
               << "Gender:" << u.gender.toStdString() << std::endl;
        return output;
    }
};

#endif // USERS_H
