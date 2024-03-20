#pragma once

#include "esphome/components/number/number.h"
#include "../ld2420ep.h"

namespace esphome
{
  namespace ld2420ep
  {

    class LD2420EPTimeoutNumber : public number::Number, public Parented<LD2420EPComponent>
    {
    public:
      LD2420EPTimeoutNumber() = default;

    protected:
      void control(float timeout) override;
    };

    class LD2420EPMinDistanceNumber : public number::Number, public Parented<LD2420EPComponent>
    {
    public:
      LD2420EPMinDistanceNumber() = default;

    protected:
      void control(float min_gate) override;
    };

    class LD2420EPMaxDistanceNumber : public number::Number, public Parented<LD2420EPComponent>
    {
    public:
      LD2420EPMaxDistanceNumber() = default;

    protected:
      void control(float max_gate) override;
    };

    class LD2420EPGateSelectNumber : public number::Number, public Parented<LD2420EPComponent>
    {
    public:
      LD2420EPGateSelectNumber() = default;

    protected:
      void control(float gate_select) override;
    };

    class LD2420EPMoveSensFactorNumber : public number::Number, public Parented<LD2420EPComponent>
    {
    public:
      LD2420EPMoveSensFactorNumber() = default;

    protected:
      void control(float move_factor) override;
    };

    class LD2420EPStillSensFactorNumber : public number::Number, public Parented<LD2420EPComponent>
    {
    public:
      LD2420EPStillSensFactorNumber() = default;

    protected:
      void control(float still_factor) override;
    };

    class LD2420EPStillThresholdNumbers : public number::Number, public Parented<LD2420EPComponent>
    {
    public:
      LD2420EPStillThresholdNumbers() = default;
      LD2420EPStillThresholdNumbers(uint8_t gate);

    protected:
      uint8_t gate_;
      void control(float still_threshold) override;
    };

    class LD2420EPMoveThresholdNumbers : public number::Number, public Parented<LD2420EPComponent>
    {
    public:
      LD2420EPMoveThresholdNumbers() = default;
      LD2420EPMoveThresholdNumbers(uint8_t gate);

    protected:
      uint8_t gate_;
      void control(float move_threshold) override;
    };

  } // namespace ld2420ep
} // namespace esphome
