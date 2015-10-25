//
// Created by vitor on 27-06-2015.
//


#include <string>
#include <algorithm>
#include <vector>

#include "simulation.h"
#include "utils.h"


simulation::simulation()
        : solution_{}, components_{}, mat_{}, n_{0}
{
}

simulation::~simulation()
{
}

void simulation::load(const char* circuit) noexcept
{
    no_throw([=]()
             {
                 unsigned m = 0, n = 0;
                 parser p{circuit};
                 auto t = p.advance();
                 while (t)
                 {
                     auto c = *t.begin();
                     switch (c)
                     {
                         case 'R':
                             this->components_.emplace_back(resistor{t, p});
                             n = std::max(n, this->components_.back().max_node());
                             break;
                         case 'V':
                             this->components_.emplace_back(voltage_source{t, p, m++});
                             n = std::max(n, this->components_.back().max_node());
                             break;
                         case 'I':
                             this->components_.emplace_back(current_source{t, p});
                             n = std::max(n, this->components_.back().max_node());
                             break;
                         default:
                             break;
                     }

                     t = p.advance();
                 }

                 if (n > 0)
                 {
                     this->mat_.reset(new matrix{n + m, n + m + 1});
                 }

                 this->n_ = n;
             });
}

void simulation::dc_solve(circuitsim_simulation_cb cb) noexcept
{
    no_throw([=]()
             {
                 auto& mat = *this->mat_.get();

                 for (auto& c : this->components_)
                 {
                     c.stamp(mat, this->n_);
                 }

                 //dump(*this->mat_.get());
                 reduced_row_echelon(*this->mat_.get());
                 //dump(*this->mat_.get());

                 this->solution_.reserve(mat.rows());
                 for (unsigned i = 0; i < mat.rows(); ++i)
                 {
                     this->solution_.push_back(mat.at(i, mat.cols() - 1));
                 }

                 cb(this->solution_.data(), (int)this->solution_.size());
                 this->solution_.clear();
             });
}
