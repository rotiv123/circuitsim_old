//
// Created by vitor on 12-07-2015.
//

#include "current_source.h"

current_source::current_source(const token &id, parser &p)
        : id_{to_string(id)},
          plus_n_{std::stoi(to_string(p.advance()))},
          minus_n_{std::stoi(to_string(p.advance()))},
          type_{to_string(p.advance())},
          value_{std::stod(to_string(p.advance()))}
{
}
