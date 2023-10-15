#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "layout.h"


class Controller
{
public:
    Controller();
    Layout_ptr getLayout();

};

using Controller_ptr=std::shared_ptr<Controller>;

#endif // CONTROLLER_H
