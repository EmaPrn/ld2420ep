#include "text_sensor.h"
#include "esphome/core/helpers.h"
#include "esphome/core/log.h"

namespace esphome
{
  namespace ld2420ep
  {

    static const char *const TAG = "LD2420EP.text_sensor";

    void LD2420EPTextSensor::dump_config()
    {
      ESP_LOGCONFIG(TAG, "LD2420EP TextSensor:");
      LOG_TEXT_SENSOR("  ", "Firmware", this->fw_version_text_sensor_);
    }

  } // namespace ld2420ep
} // namespace esphome
