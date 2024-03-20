#include "ld2420ep_binary_sensor.h"
#include "esphome/core/helpers.h"
#include "esphome/core/log.h"

namespace esphome
{
  namespace ld2420ep
  {

    static const char *const TAG = "LD2420EP.binary_sensor";

    void LD2420EPBinarySensor::dump_config()
    {
      ESP_LOGCONFIG(TAG, "LD2420EP BinarySensor:");
      LOG_BINARY_SENSOR("  ", "Presence", this->presence_bsensor_);
    }

  } // namespace ld2420ep
} // namespace esphome
