#pragma once

#include "esphome/components/button/button.h"
#include "../ld2420ep.h"

namespace esphome
{
  namespace ld2420ep
  {

    class LD2420EPApplyConfigButton : public button::Button, public Parented<LD2420EPComponent>
    {
    public:
      LD2420EPApplyConfigButton() = default;

    protected:
      void press_action() override;
    };

    class LD2420EPRevertConfigButton : public button::Button, public Parented<LD2420EPComponent>
    {
    public:
      LD2420EPRevertConfigButton() = default;

    protected:
      void press_action() override;
    };

    class LD2420EPRestartModuleButton : public button::Button, public Parented<LD2420EPComponent>
    {
    public:
      LD2420EPRestartModuleButton() = default;

    protected:
      void press_action() override;
    };

    class LD2420EPFactoryResetButton : public button::Button, public Parented<LD2420EPComponent>
    {
    public:
      LD2420EPFactoryResetButton() = default;

    protected:
      void press_action() override;
    };

  } // namespace ld2420ep
} // namespace esphome
