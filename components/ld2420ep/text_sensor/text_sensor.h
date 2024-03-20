#pragma once

#include "../ld2420ep.h"
#include "esphome/components/text_sensor/text_sensor.h"

namespace esphome
{
  namespace ld2420ep
  {

    class LD2420EPTextSensor : public LD2420EPListener, public Component, text_sensor::TextSensor
    {
    public:
      void dump_config() override;
      void set_fw_version_text_sensor(text_sensor::TextSensor *tsensor) { this->fw_version_text_sensor_ = tsensor; };
      void on_fw_version(std::string &fw) override
      {
        if (this->fw_version_text_sensor_ != nullptr)
        {
          this->fw_version_text_sensor_->publish_state(fw);
        }
      }

    protected:
      text_sensor::TextSensor *fw_version_text_sensor_{nullptr};
    };

  } // namespace ld2420ep
} // namespace esphome
