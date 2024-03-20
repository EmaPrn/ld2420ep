#pragma once

#include "../ld2420ep.h"
#include "esphome/components/select/select.h"

namespace esphome
{
  namespace ld2420ep
  {

    class LD2420EPSelect : public Component, public select::Select, public Parented<LD2420EPComponent>
    {
    public:
      LD2420EPSelect() = default;

    protected:
      void control(const std::string &value) override;
    };

  } // namespace ld2420ep
} // namespace esphome
