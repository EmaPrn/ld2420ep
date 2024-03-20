#include "gate_config_number.h"
#include "esphome/core/helpers.h"
#include "esphome/core/log.h"

static const char *const TAG = "LD2420EP.number";

namespace esphome
{
  namespace ld2420ep
  {

    void LD2420EPTimeoutNumber::control(float timeout)
    {
      this->publish_state(timeout);
      this->parent_->new_config.timeout = timeout;
    }

    void LD2420EPMinDistanceNumber::control(float min_gate)
    {
      if ((uint16_t)min_gate > this->parent_->new_config.max_gate)
      {
        min_gate = this->parent_->get_min_gate_distance_value();
      }
      else
      {
        this->parent_->new_config.min_gate = (uint16_t)min_gate;
      }
      this->publish_state(min_gate);
    }

    void LD2420EPMaxDistanceNumber::control(float max_gate)
    {
      if ((uint16_t)max_gate < this->parent_->new_config.min_gate)
      {
        max_gate = this->parent_->get_max_gate_distance_value();
      }
      else
      {
        this->parent_->new_config.max_gate = (uint16_t)max_gate;
      }
      this->publish_state(max_gate);
    }

    void LD2420EPGateSelectNumber::control(float gate_select)
    {
      const uint8_t gate = (uint8_t)gate_select;
      this->publish_state(gate_select);
      this->parent_->publish_gate_move_threshold(gate);
      this->parent_->publish_gate_still_threshold(gate);
    }

    void LD2420EPMoveSensFactorNumber::control(float move_factor)
    {
      this->publish_state(move_factor);
      this->parent_->gate_move_sensitivity_factor = move_factor;
    }

    void LD2420EPStillSensFactorNumber::control(float still_factor)
    {
      this->publish_state(still_factor);
      this->parent_->gate_still_sensitivity_factor = still_factor;
    }

    LD2420EPMoveThresholdNumbers::LD2420EPMoveThresholdNumbers(uint8_t gate) : gate_(gate) {}

    void LD2420EPMoveThresholdNumbers::control(float move_threshold)
    {
      this->publish_state(move_threshold);
      if (!this->parent_->is_gate_select())
      {
        this->parent_->new_config.move_thresh[this->gate_] = move_threshold;
      }
      else
      {
        this->parent_->new_config.move_thresh[this->parent_->get_gate_select_value()] = move_threshold;
      }
    }

    LD2420EPStillThresholdNumbers::LD2420EPStillThresholdNumbers(uint8_t gate) : gate_(gate) {}

    void LD2420EPStillThresholdNumbers::control(float still_threshold)
    {
      this->publish_state(still_threshold);
      if (!this->parent_->is_gate_select())
      {
        this->parent_->new_config.still_thresh[this->gate_] = still_threshold;
      }
      else
      {
        this->parent_->new_config.still_thresh[this->parent_->get_gate_select_value()] = still_threshold;
      }
    }

  } // namespace ld2420ep
} // namespace esphome
