//
// Created by vitor on 05-07-2015.
//

#include "resistor.h"


resistor::resistor(const token& id, parser& p)
        : id_{to_string(id)},
          n1_{std::stoi(to_string(p.advance()))},
          n2_{std::stoi(to_string(p.advance()))},
          value_{std::stod(to_string(p.advance()))}
{
}
